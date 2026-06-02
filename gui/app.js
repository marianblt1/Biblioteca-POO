// ===== DATE =====
const utilizatori = [
    { username: "admin", parola: "parola123", tip: "staff" },
    { username: "ionescu", parola: "parola123", tip: "staff" },
    { username: "bogdan", parola: "parola123", tip: "staff" },
    { username: "popescu", parola: "parola123", tip: "normal" },
    { username: "marian", parola: "parola123", tip: "normal" },
    { username: "andreea", parola: "parola123", tip: "normal" },
    { username: "george", parola: "parola123", tip: "normal" },
    { username: "elena", parola: "parola123", tip: "normal" },
    { username: "stefan", parola: "parola123", tip: "normal" },
    { username: "ana", parola: "parola123", tip: "normal" }
];

const camere = [
    { nume: "Sala de Lectură", tip: "SALA_LECTURA", capacitate: 50, program: "08:00 - 20:00", icon: "📖" },
    { nume: "Depozit", tip: "DEPOZIT", capacitate: 1000, program: "08:00 - 16:00", icon: "📦" },
    { nume: "Recepție", tip: "RECEPTIE", capacitate: 10, program: "08:00 - 20:00", icon: "🏛️" },
    { nume: "Sala Calculatoare", tip: "SALA_CALCULATOARE", capacitate: 20, program: "09:00 - 18:00", icon: "💻" },
    { nume: "Sala Copii", tip: "SALA_COPII", capacitate: 30, program: "09:00 - 17:00", icon: "🎨" }
];

let carti = [];
let currentUser = null;
let imprumuturi = [];

// ===== INCARCARE DATE =====
async function incarcaCarti() {
    try {
        const response = await fetch('../date.txt');
        const text = await response.text();
        const linii = text.trim().split('\n');
        
        carti = linii.map(linie => {
            const parts = linie.split('|');
            return {
                tip: parts[0] || '',
                titlu: parts[1] || '',
                autor: parts[2] || '',
                isbn: parts[3] || '',
                an: parts[4] || '',
                stare: parts[5] || '',
                timpImprumut: parts[6] || '',
                nrExemplare: parts[7] || '',
                localizare: parts[8] || '',
                status: parts[9] || 'Disponibila'
            };
        });
        
        afiseazaCarti(carti);
    } catch(e) {
        console.log('Eroare incarcare carti:', e);
    }
}

// ===== LOGIN =====
function login() {
    const username = document.getElementById('username').value.trim();
    const password = document.getElementById('password').value.trim();
    
    const user = utilizatori.find(u => u.username === username && u.parola === password);
    
    if (user) {
        currentUser = user;
        document.getElementById('loginPage').classList.add('hidden');
        document.getElementById('mainApp').classList.remove('hidden');
        document.getElementById('userInfo').textContent = `👤 ${username} (${user.tip})`;
        
        incarcaCarti();
        afiseazaUtilizatori();
        afiseazaCamere();

        // daca e normal, ascunde utilizatori si camere
        if (user.tip === 'normal') {
            document.getElementById('nav-utilizatori').style.display = 'none';
            document.getElementById('nav-camere').style.display = 'none';
        }
    } else {
        document.getElementById('loginError').textContent = 'Username sau parolă incorectă!';
    }
}

// ===== LOGOUT =====
function logout() {
    currentUser = null;
    document.getElementById('mainApp').classList.add('hidden');
    document.getElementById('loginPage').classList.remove('hidden');
    document.getElementById('username').value = '';
    document.getElementById('password').value = '';
    document.getElementById('loginError').textContent = '';
    document.getElementById('nav-utilizatori').style.display = '';
    document.getElementById('nav-camere').style.display = '';
}

// ===== NAVIGARE =====
function showSection(sectiune) {
    document.querySelectorAll('.section').forEach(s => s.classList.add('hidden'));
    document.querySelectorAll('.nav-item').forEach(n => n.classList.remove('active'));
    
    document.getElementById('sectiune' + sectiune.charAt(0).toUpperCase() + sectiune.slice(1)).classList.remove('hidden');
    document.getElementById('nav-' + sectiune).classList.add('active');
}

// ===== CARTI =====
function afiseazaCarti(lista) {
    const body = document.getElementById('bodyCarti');
    body.innerHTML = '';
    
    lista.forEach(carte => {
        const tr = document.createElement('tr');
        
        let badgeClass = 'badge-disponibila';
        let statusText = carte.status;
        if (carte.status === 'Imprumutata') badgeClass = 'badge-imprumutata';
        if (carte.status === 'Doar in sala') { badgeClass = 'badge-sala'; statusText = 'Doar în sală'; }
        if (carte.tip === 'CarteRara') badgeClass = 'badge-rara';
        
        tr.innerHTML = `
            <td>${carte.titlu} ${carte.tip === 'CarteRara' ? '⭐' : ''}</td>
            <td>${carte.autor}</td>
            <td><code>${carte.isbn}</code></td>
            <td>${carte.an}</td>
            <td>${carte.stare}</td>
            <td>${carte.nrExemplare}</td>
            <td>${carte.localizare}</td>
            <td><span class="badge ${badgeClass}">${statusText}</span></td>
        `;
        body.appendChild(tr);
    });
}

function filtreazaCarti() {
    const termen = document.getElementById('searchCarti').value.toLowerCase();
    const filtrate = carti.filter(c => 
        c.titlu.toLowerCase().includes(termen) ||
        c.autor.toLowerCase().includes(termen) ||
        c.isbn.toLowerCase().includes(termen)
    );
    afiseazaCarti(filtrate);
}

// ===== UTILIZATORI =====
function afiseazaUtilizatori() {
    const body = document.getElementById('bodyUtilizatori');
    body.innerHTML = '';
    
    utilizatori.forEach(u => {
        const tr = document.createElement('tr');
        tr.innerHTML = `
            <td>${u.username}</td>
            <td><span class="badge ${u.tip === 'staff' ? 'badge-sala' : 'badge-disponibila'}">${u.tip}</span></td>
        `;
        body.appendChild(tr);
    });
}

// ===== IMPRUMUTURI =====
function imprumuta() {
    const username = document.getElementById('impUsername').value.trim();
    const isbn = document.getElementById('impISBN').value.trim();
    const mesaj = document.getElementById('mesajImprumut');
    
    const user = utilizatori.find(u => u.username === username);
    if (!user) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ Utilizatorul "${username}" nu a fost găsit!`;
        return;
    }
    
    const carte = carti.find(c => c.isbn === isbn);
    if (!carte) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ Cartea cu ISBN "${isbn}" nu a fost găsită!`;
        return;
    }
    
    if (carte.tip === 'CarteRara' || carte.status === 'Doar in sala') {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ "${carte.titlu}" este o carte rară și nu poate fi împrumutată!`;
        return;
    }
    
    if (carte.status === 'Imprumutata') {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ "${carte.titlu}" este deja împrumutată!`;
        return;
    }
    
    carte.status = 'Imprumutata';
    imprumuturi.push({ username, isbn, titlu: carte.titlu, data: new Date().toLocaleDateString('ro-RO') });
    afiseazaCarti(carti);
    
    mesaj.className = 'mesaj success';
    mesaj.textContent = `✅ "${carte.titlu}" a fost împrumutată lui ${username}!`;
}

function returneaza() {
    const username = document.getElementById('retUsername').value.trim();
    const isbn = document.getElementById('retISBN').value.trim();
    const mesaj = document.getElementById('mesajImprumut');
    
    const carte = carti.find(c => c.isbn === isbn);
    if (!carte) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ Cartea cu ISBN "${isbn}" nu a fost găsită!`;
        return;
    }
    
    carte.status = 'Disponibila';
    afiseazaCarti(carti);
    
    mesaj.className = 'mesaj success';
    mesaj.textContent = `✅ "${carte.titlu}" a fost returnată cu succes!`;
}

// ===== CAMERE =====
function afiseazaCamere() {
    const grid = document.getElementById('gridCamere');
    grid.innerHTML = '';
    
    camere.forEach(camera => {
        const div = document.createElement('div');
        div.className = 'camera-card';
        div.innerHTML = `
            <h3>${camera.icon} ${camera.nume}</h3>
            <p>📋 Tip: ${camera.tip.replace('_', ' ')}</p>
            <p>👥 Capacitate: ${camera.capacitate} persoane</p>
            <p>🕐 Program: ${camera.program}</p>
        `;
        grid.appendChild(div);
    });
}

// Enter la login
document.addEventListener('keypress', function(e) {
    if (e.key === 'Enter' && !document.getElementById('loginPage').classList.contains('hidden')) {
        login();
    }
});