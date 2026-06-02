// ===== DATE =====
const utilizatori = [
    { username: "admin", parola: "parola123", tip: "staff", nume: "Admin", email: "admin@usv.ro" },
    { username: "ionescu", parola: "parola123", tip: "staff", nume: "Ionescu Alexandru", email: "ionescu@usv.ro" },
    { username: "bogdan", parola: "parola123", tip: "staff", nume: "Bogdan Mihai", email: "bogdan@usv.ro" },
    { username: "popescu", parola: "parola123", tip: "normal", nume: "Popescu Maria", email: "popescu@student.usv.ro" },
    { username: "marian", parola: "parola123", tip: "normal", nume: "Baltei Marian", email: "marian@student.usv.ro" },
    { username: "andreea", parola: "parola123", tip: "normal", nume: "Andreea Constantin", email: "andreea@student.usv.ro" },
    { username: "george", parola: "parola123", tip: "normal", nume: "George Popa", email: "george@student.usv.ro" },
    { username: "elena", parola: "parola123", tip: "normal", nume: "Elena Ionescu", email: "elena@student.usv.ro" },
    { username: "stefan", parola: "parola123", tip: "normal", nume: "Stefan Dumitru", email: "stefan@student.usv.ro" },
    { username: "ana", parola: "parola123", tip: "normal", nume: "Ana Rusu", email: "ana@student.usv.ro" }
];

const anunturi = [
    { data: "15-20 Iunie 2026", titlu: "Săptămâna Cărții 2026", desc: "Vă invităm la evenimentele din cadrul Săptămânii Cărții: lansări, dezbateri și expoziții tematice în holul principal al bibliotecii.", tag: "eveniment" },
    { data: "1 Iunie 2026", titlu: "Colecție Nouă — Informatică", desc: "Biblioteca a achiziționat 50 de titluri noi de informatică și inteligență artificială. Disponibile de acum la Sala Calculatoare.", tag: "colectie" },
    { data: "Iulie — August 2026", titlu: "Program Extins de Vară", desc: "În perioada iulie-august, biblioteca va funcționa cu program prelungit: 08:00-22:00 în zilele lucrătoare.", tag: "program" },
    { data: "10 Iunie 2026", titlu: "Club de Lectură — Tolkien", desc: "Lansăm un nou club de lectură dedicat operelor lui J.R.R. Tolkien. Întâlnirile vor avea loc în fiecare vineri la ora 18:00.", tag: "club" },
    { data: "5 Iunie 2026", titlu: "Semnătură de Carte — Mircea Cărtărescu", desc: "Scriitorul Mircea Cărtărescu va fi prezent la bibliotecă pentru o sesiune de autografe și dialog cu cititorii.", tag: "eveniment" },
    { data: "20 Mai 2026", titlu: "Acces Baze de Date Internaționale", desc: "Biblioteca pune la dispoziție acces gratuit la bazele de date JSTOR, Springer și Elsevier pentru toți studenții USV.", tag: "colectie" },
    { data: "Permanent", titlu: "Reguli Împrumut", desc: "Studenții pot împrumuta maxim 5 cărți simultan pe o perioadă de 21 de zile. Taxă întârziere: 0.50 lei/zi.", tag: "program" },
];

let carti = [];
let exemplare = [];
let imprumuturi = JSON.parse(localStorage.getItem('imprumuturi') || '[]');
let wishlist = JSON.parse(localStorage.getItem('wishlist') || '[]');
let currentUser = null;

// ===== INCARCARE DATE =====
async function incarcaDate() {
    try {
        // Incarca carti
        const rCarti = await fetch('../date.txt');
        const textCarti = await rCarti.text();
        carti = textCarti.trim().split('\n').filter(l => l.trim()).map(linie => {
            const p = linie.split('|');
            return {
                tipCarte: p[0] || '',
                tip: p[1] || '',
                titlu: p[2] || '',
                autor: p[3] || '',
                isbn: p[4] || '',
                an: p[5] || '',
                stare: p[6] || '',
                timpImprumut: p[7] || '',
                nrExemplare: parseInt(p[8]) || 0,
                disponibile: parseInt(p[9]) || 0,
                localizare: p[10] || ''
            };
        });

        // Incarca exemplare
        const rEx = await fetch('../exemplare.txt');
        const textEx = await rEx.text();
        exemplare = textEx.trim().split('\n').filter(l => l.trim()).map(linie => {
            const p = linie.split('|');
            return { cod: p[0] || '', isbn: p[1] || '', status: p[2] || 'Disponibil' };
        });

        afiseazaCarti(carti);
        afiseazaDashboard();
        afiseazaStatistici();
        setTimeout(initGame, 500);
    } catch (e) {
        console.log('Eroare:', e);
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
        document.getElementById('sidebarUsername').textContent = user.nume;
        document.getElementById('userAvatar').textContent = user.nume.charAt(0).toUpperCase();
        document.getElementById('sidebarBadge').textContent = user.tip.toUpperCase();

    if (user.tip === 'normal') {
        document.querySelectorAll('.staff-only').forEach(el => el.style.display = 'none');
        document.getElementById('nav-imprumuturi').style.display = 'none';
        document.getElementById('nav-utilizatori').style.display = 'none';
        document.getElementById('nav-statistici').style.display = 'none';
    }

        incarcaDate();
        afiseazaUtilizatori();
        afiseazaAnunturi();
        afiseazaProfil();
        afiseazaWishlist();
        afiseazaIstoric();
        afiseazaCartiMele();
    } else {
        document.getElementById('loginError').textContent = 'Username sau parolă incorectă!';
    }
}

function logout() {
    currentUser = null;
    document.getElementById('mainApp').classList.add('hidden');
    document.getElementById('loginPage').classList.remove('hidden');
    document.getElementById('username').value = '';
    document.getElementById('password').value = '';
    document.getElementById('loginError').textContent = '';
    document.querySelectorAll('.staff-only').forEach(el => el.style.display = '');
}

// ===== NAVIGARE =====
function showSection(sectiune) {
    document.querySelectorAll('.section').forEach(s => s.classList.add('hidden'));
    document.querySelectorAll('.nav-item').forEach(n => n.classList.remove('active'));

    const sId = 'sectiune' + sectiune.charAt(0).toUpperCase() + sectiune.slice(1);
    const el = document.getElementById(sId);
    if (el) el.classList.remove('hidden');

    const navEl = document.getElementById('nav-' + sectiune);
    if (navEl) navEl.classList.add('active');

    if (sectiune === 'imprumuturi') afiseazaImprumuturiActive();
    if (sectiune === 'info') afiseazaInfo();
    if (sectiune === 'cartiMele') afiseazaCartiMele();
    if (sectiune === 'istoric') afiseazaIstoric();
    if (sectiune === 'wishlist') afiseazaWishlist();
}

// ===== DASHBOARD =====
function afiseazaDashboard() {
    document.getElementById('dashboardWelcome').textContent = 'Bun venit, ' + currentUser.nume + '!';

    const totalCarti = carti.reduce((s, c) => s + c.nrExemplare, 0);
    const imprumutateActiv = imprumuturi.filter(i => !i.returnat).length;
    const autori = new Set(carti.map(c => c.autor)).size;

    document.getElementById('statsGrid').innerHTML = `
        <div class="stat-card"><span class="stat-num">${carti.length}</span><span class="stat-label">Titluri</span></div>
        <div class="stat-card"><span class="stat-num">${utilizatori.length}</span><span class="stat-label">Utilizatori</span></div>
        <div class="stat-card"><span class="stat-num">${autori}</span><span class="stat-label">Autori</span></div>
        <div class="stat-card"><span class="stat-num">${imprumutateActiv}</span><span class="stat-label">Împrumutate</span></div>
    `;

    const rec = document.getElementById('anunturiRecente');
    rec.innerHTML = anunturi.slice(0, 3).map(a => `
        <div class="anunt-item">
            <div class="anunt-data">${a.data}</div>
            <div class="anunt-titlu">${a.titlu}</div>
            <div class="anunt-desc">${a.desc.substring(0, 100)}...</div>
        </div>
    `).join('');
}

// ===== CARTI =====
function getBadgeCarti(tip) {
    const map = {
        'FICTIUNE': 'badge-fictiune', 'TEHNICA': 'badge-tehnica',
        'STIINTA': 'badge-stiinta', 'REVISTA': 'badge-revista',
        'DIGITALA': 'badge-digitala', 'RARA': 'badge-rara'
    };
    return map[tip] || 'badge-normal';
}

function afiseazaCarti(lista) {
    const body = document.getElementById('bodyCarti');
    if (!body) return;
    body.innerHTML = '';

    lista.forEach(carte => {
        const impAct = imprumuturi.filter(i => i.isbn === carte.isbn && !i.returnat).length;
        const disponibile = Math.max(0, carte.nrExemplare - impAct);
        const dispClass = disponibile > 0 ? 'disponibil-ok' : 'disponibil-zero';

        const tr = document.createElement('tr');
        tr.innerHTML = `
            <td><strong>${carte.titlu}</strong>${carte.tipCarte === 'CarteRara' ? ' ⭐' : ''}</td>
            <td>${carte.autor}</td>
            <td><span class="badge ${getBadgeCarti(carte.tip)}">${carte.tip}</span></td>
            <td>${carte.an}</td>
            <td><code style="font-size:11px;color:var(--text-dim)">${carte.isbn}</code></td>
            <td><span class="disponibil-num ${dispClass}">${disponibile}</span></td>
            <td>${carte.nrExemplare}</td>
            <td>
                ${disponibile > 0 && carte.tipCarte !== 'CarteRara'
                ? `<button class="btn-gold btn-sm" onclick="selecteazaImprumut('${carte.isbn}')">ÎMPRUMUTĂ</button>`
                : carte.tipCarte === 'CarteRara'
                    ? `<span style="color:var(--red-light);font-size:12px">Doar în sală</span>`
                    : `<span style="color:var(--text-dim);font-size:12px">Indisponibil</span>`
            }
            </td>
        `;
        body.appendChild(tr);
    });
}

function filtreazaCarti() {
    const termen = document.getElementById('searchCarti').value.toLowerCase();
    const tip = document.getElementById('filterTip').value;
    const filtrate = carti.filter(c =>
        (c.titlu.toLowerCase().includes(termen) ||
            c.autor.toLowerCase().includes(termen) ||
            c.isbn.toLowerCase().includes(termen)) &&
        (tip === '' || c.tip === tip)
    );
    afiseazaCarti(filtrate);
}

function selecteazaImprumut(isbn) {
    showSection('imprumuturi');
    const carte = carti.find(c => c.isbn === isbn);
    if (!carte) return;
    document.getElementById('impCautare').value = carte.titlu;
    const ex = exemplare.find(e => e.isbn === isbn && e.status === 'Disponibil');
    if (ex) document.getElementById('impExemplar').value = ex.cod;
    document.getElementById('impUsername').value = currentUser.username;
}

// ===== UTILIZATORI =====
function afiseazaUtilizatori() {
    const body = document.getElementById('bodyUtilizatori');
    if (!body) return;
    body.innerHTML = '';
    utilizatori.forEach(u => {
        const activ = imprumuturi.filter(i => i.username === u.username && !i.returnat).length;
        const tr = document.createElement('tr');
        tr.innerHTML = `
            <td>${u.nume}<br><small style="color:var(--text-dim)">${u.email}</small></td>
            <td><span class="badge badge-${u.tip}">${u.tip.toUpperCase()}</span></td>
            <td>${activ}</td>
            <td><span class="badge badge-disponibila">Activ</span></td>
        `;
        body.appendChild(tr);
    });
}

// ===== IMPRUMUTURI =====
function cautaImprumutat() {
    const termen = document.getElementById('impCautare').value.toLowerCase();
    const div = document.getElementById('rezultateImp');
    if (termen.length < 2) { div.innerHTML = ''; return; }

    const rezultate = carti.filter(c =>
        (c.titlu.toLowerCase().includes(termen) || c.isbn.toLowerCase().includes(termen)) &&
        c.tipCarte !== 'CarteRara'
    ).slice(0, 8);

    div.innerHTML = rezultate.map(c => {
        const impAct = imprumuturi.filter(i => i.isbn === c.isbn && !i.returnat).length;
        const disp = Math.max(0, c.nrExemplare - impAct);
        return `
            <div class="rezultat-item" onclick="selecteazaCartePentruImprumut('${c.isbn}')">
                <div class="rezultat-titlu">${c.titlu}</div>
                <div class="rezultat-info">${c.autor} · ${c.an} · Disponibile: ${disp}</div>
            </div>
        `;
    }).join('');
}

function selecteazaCartePentruImprumut(isbn) {
    const carte = carti.find(c => c.isbn === isbn);
    if (!carte) return;
    document.getElementById('impCautare').value = carte.titlu;
    document.getElementById('rezultateImp').innerHTML = '';
    const ex = exemplare.find(e => e.isbn === isbn && e.status === 'Disponibil' &&
        !imprumuturi.find(i => i.codExemplar === e.cod && !i.returnat));
    if (ex) document.getElementById('impExemplar').value = ex.cod;
}

function imprumuta() {
    const username = document.getElementById('impUsername').value.trim();
    const codExemplar = document.getElementById('impExemplar').value.trim();
    const mesaj = document.getElementById('mesajImprumut');

    const user = utilizatori.find(u => u.username === username);
    if (!user) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ Utilizatorul "${username}" nu a fost găsit!`;
        return;
    }

    const ex = exemplare.find(e => e.cod === codExemplar);
    if (!ex) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ Codul de exemplar "${codExemplar}" nu există!`;
        return;
    }

    const deja = imprumuturi.find(i => i.codExemplar === codExemplar && !i.returnat);
    if (deja) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ Acest exemplar este deja împrumutat!`;
        return;
    }

    const carte = carti.find(c => c.isbn === ex.isbn);
    const imp = {
        id: Date.now(),
        codExemplar, isbn: ex.isbn,
        titlu: carte ? carte.titlu : 'Necunoscut',
        username, data: new Date().toLocaleDateString('ro-RO'),
        returnat: false
    };

    imprumuturi.push(imp);
    localStorage.setItem('imprumuturi', JSON.stringify(imprumuturi));

    mesaj.className = 'mesaj success';
    mesaj.textContent = `✅ "${carte ? carte.titlu : codExemplar}" împrumutat lui ${user.nume}!`;
    afiseazaImprumuturiActive();
    afiseazaDashboard();
    afiseazaCartiMele();
}

function returneaza() {
    const codExemplar = document.getElementById('retExemplar').value.trim();
    const username = document.getElementById('retUsername').value.trim();
    const mesaj = document.getElementById('mesajImprumut');

    const idx = imprumuturi.findIndex(i => i.codExemplar === codExemplar && i.username === username && !i.returnat);
    if (idx === -1) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = `❌ Nu s-a găsit un împrumut activ pentru aceste date!`;
        return;
    }

    imprumuturi[idx].returnat = true;
    imprumuturi[idx].dataReturnare = new Date().toLocaleDateString('ro-RO');
    localStorage.setItem('imprumuturi', JSON.stringify(imprumuturi));

    mesaj.className = 'mesaj success';
    mesaj.textContent = `✅ "${imprumuturi[idx].titlu}" returnat cu succes!`;
    afiseazaImprumuturiActive();
    afiseazaDashboard();
    afiseazaCartiMele();
}

function afiseazaImprumuturiActive() {
    const body = document.getElementById('bodyImprumuturi');
    if (!body) return;
    const active = imprumuturi.filter(i => !i.returnat);
    body.innerHTML = active.length === 0
        ? '<tr><td colspan="4" style="text-align:center;color:var(--text-dim)">Nu există împrumuturi active</td></tr>'
        : active.map(i => `
            <tr>
                <td><code>${i.codExemplar}</code></td>
                <td>${i.titlu}</td>
                <td>${i.username}</td>
                <td>${i.data}</td>
            </tr>
        `).join('');
}

// ===== CAUTARE AVANSATA =====
function cautareAvansata() {
    const termen = document.getElementById('searchAvansata').value.toLowerCase();
    const tip = document.getElementById('searchTip').value;
    const status = document.getElementById('searchStatus').value;

    if (termen.length < 1 && tip === '' && status === '') {
        document.getElementById('rezultateCautare').innerHTML = '';
        return;
    }

    let filtrate = carti.filter(c =>
        (termen === '' ||
            c.titlu.toLowerCase().includes(termen) ||
            c.autor.toLowerCase().includes(termen) ||
            c.isbn.toLowerCase().includes(termen) ||
            c.an.toString().includes(termen)) &&
        (tip === '' || c.tip === tip)
    );

    document.getElementById('rezultateCautare').innerHTML = `
        <table>
            <thead><tr>
                <th>Titlu</th><th>Autor</th><th>Tip</th><th>An</th><th>ISBN</th><th>Localizare</th><th>Disponibile</th>
            </tr></thead>
            <tbody>
                ${filtrate.map(c => {
        const impAct = imprumuturi.filter(i => i.isbn === c.isbn && !i.returnat).length;
        const disp = Math.max(0, c.nrExemplare - impAct);
        return `<tr>
                        <td>${c.titlu}</td>
                        <td>${c.autor}</td>
                        <td><span class="badge ${getBadgeCarti(c.tip)}">${c.tip}</span></td>
                        <td>${c.an}</td>
                        <td><code style="font-size:11px">${c.isbn}</code></td>
                        <td>${c.localizare}</td>
                        <td><span class="disponibil-num ${disp > 0 ? 'disponibil-ok' : 'disponibil-zero'}">${disp}</span></td>
                    </tr>`;
    }).join('')}
            </tbody>
        </table>
        <p style="padding:12px;color:var(--text-dim);font-size:13px">${filtrate.length} rezultate găsite</p>
    `;
}

// ===== STATISTICI =====
function afiseazaStatistici() {
    const div = document.getElementById('continutStatistici');
    if (!div) return;

    const totalEx = carti.reduce((s, c) => s + c.nrExemplare, 0);
    const impActive = imprumuturi.filter(i => !i.returnat).length;
    const impTotale = imprumuturi.length;
    const autori = new Set(carti.map(c => c.autor)).size;

    const perTip = {};
    carti.forEach(c => { perTip[c.tip] = (perTip[c.tip] || 0) + 1; });

    div.innerHTML = `
        <div class="stats-grid">
            <div class="stat-card"><span class="stat-num">${carti.length}</span><span class="stat-label">Titluri</span></div>
            <div class="stat-card"><span class="stat-num">${totalEx}</span><span class="stat-label">Exemplare Total</span></div>
            <div class="stat-card"><span class="stat-num">${autori}</span><span class="stat-label">Autori</span></div>
            <div class="stat-card"><span class="stat-num">${utilizatori.length}</span><span class="stat-label">Utilizatori</span></div>
            <div class="stat-card"><span class="stat-num">${impActive}</span><span class="stat-label">Împrumutate Activ</span></div>
            <div class="stat-card"><span class="stat-num">${impTotale}</span><span class="stat-label">Total Împrumuturi</span></div>
            <div class="stat-card"><span class="stat-num">${utilizatori.filter(u => u.tip === 'staff').length}</span><span class="stat-label">Staff</span></div>
            <div class="stat-card"><span class="stat-num">${utilizatori.filter(u => u.tip === 'normal').length}</span><span class="stat-label">Membri</span></div>
        </div>
        <div class="card">
            <h3>📊 Filtrează după tip</h3>
            <div class="tip-filter-btns">
                <button class="tip-btn activ" onclick="filtreazaStatisticiTip('', this)">Toate</button>
                ${Object.keys(perTip).map(tip => `
                    <button class="tip-btn ${getBadgeCarti(tip)}" onclick="filtreazaStatisticiTip('${tip}', this)">${tip} (${perTip[tip]})</button>
                `).join('')}
            </div>
            <div class="table-container" id="tabelStatistici">
                ${genereazaTabelStatistici(carti)}
            </div>
        </div>
    `;
}

function filtreazaStatisticiTip(tip, btn) {
    document.querySelectorAll('.tip-btn').forEach(b => b.classList.remove('activ'));
    btn.classList.add('activ');
    const filtrate = tip === '' ? carti : carti.filter(c => c.tip === tip);
    document.getElementById('tabelStatistici').innerHTML = genereazaTabelStatistici(filtrate);
}

function genereazaTabelStatistici(lista) {
    return `<table>
        <thead><tr><th>Titlu</th><th>Autor</th><th>Tip</th><th>An</th><th>Exemplare</th></tr></thead>
        <tbody>
            ${lista.map(c => `<tr>
                <td>${c.titlu}</td>
                <td>${c.autor}</td>
                <td><span class="badge ${getBadgeCarti(c.tip)}">${c.tip}</span></td>
                <td>${c.an}</td>
                <td>${c.nrExemplare}</td>
            </tr>`).join('')}
        </tbody>
    </table>`;
}

// ===== ANUNTURI =====
function afiseazaAnunturi() {
    const div = document.getElementById('listaAnunturi');
    if (!div) return;
    const tagLabels = { eveniment: 'EVENIMENT', colectie: 'COLECȚIE NOUĂ', program: 'PROGRAM', club: 'CLUB LECTURĂ' };
    div.innerHTML = anunturi.map((a, idx) => `
        <div class="anunt-card" id="anunt-${idx}">
            <span class="anunt-tag tag-${a.tag}">${tagLabels[a.tag] || a.tag.toUpperCase()}</span>
            <div class="anunt-data">${a.data}</div>
            <div class="anunt-titlu">${a.titlu}</div>
            <div class="anunt-body">${a.desc}</div>
            <button class="anunt-toggle" onclick="toggleAnunt(${idx})">▼ Citește mai mult</button>
        </div>
    `).join('');
}

function toggleAnunt(idx) {
    const card = document.getElementById('anunt-' + idx);
    const btn = card.querySelector('.anunt-toggle');
    card.classList.toggle('expanded');
    btn.textContent = card.classList.contains('expanded') ? '▲ Restrânge' : '▼ Citește mai mult';
}

function afiseazaInfo() {
    const div = document.getElementById('sectiuneInfo');
    if (!div) return;
    div.innerHTML = `
        <div class="page-header">
            <h1>Despre Noi</h1>
            <p class="subtitle">Biblioteca Universitară Suceava</p>
        </div>
        <div class="despre-hero">
            <h2>Biblioteca Universitară „Gheorghe Asachi"</h2>
            <p>Instituție de cultură și educație în slujba comunității academice din Suceava din 1963</p>
        </div>
        <div class="two-col">
            <div class="card">
                <h3>📍 Contact & Locație</h3>
                <p><strong>Adresă:</strong> Str. Universității nr. 13, Suceava, 720229, România</p>
                <p><strong>Telefon:</strong> +40 230 216 147</p>
                <p><strong>Email:</strong> biblioteca@usv.ro</p>
                <p><strong>Rectorat:</strong> rectorat@usv.ro</p>
                <p><strong>Website USV:</strong> <a href="https://www.usv.ro" target="_blank" style="color:var(--amber)">www.usv.ro</a></p>
            </div>
            <div class="card">
                <h3>🕐 Program de Funcționare</h3>
                <p><strong>Luni — Vineri:</strong> 08:00 — 20:00</p>
                <p><strong>Sâmbătă:</strong> 09:00 — 14:00</p>
                <p><strong>Duminică:</strong> Închis</p>
                <p><strong>Sărbători legale:</strong> Închis</p>
                <p style="margin-top:12px;font-style:italic;color:var(--text-light)">Iulie — August: program prelungit 08:00 — 22:00</p>
            </div>
        </div>
        <div class="card">
            <h3>🏛️ Despre Bibliotecă</h3>
            <p>Biblioteca Universitară „Gheorghe Asachi" din Suceava este una dintre cele mai importante instituții de cultură și educație din regiune. Fondată odată cu Universitatea „Ștefan cel Mare", biblioteca pune la dispoziția studenților, cadrelor didactice și cercetătorilor o colecție vastă de resurse documentare.</p>
            <p>Cu peste 500.000 de volume, periodice, resurse electronice și baze de date internaționale precum JSTOR, Springer și Elsevier, biblioteca sprijină procesul didactic și de cercetare al comunității academice sucevene.</p>
            <div class="stats-grid" style="margin-top:24px">
                <div class="stat-card"><span class="stat-num">500.000+</span><span class="stat-label">Volume</span></div>
                <div class="stat-card"><span class="stat-num">1963</span><span class="stat-label">Înființată</span></div>
                <div class="stat-card"><span class="stat-num">5</span><span class="stat-label">Săli Lectură</span></div>
                <div class="stat-card"><span class="stat-num">200+</span><span class="stat-label">Locuri</span></div>
            </div>
        </div>
        <div class="card">
            <h3>📚 Servicii Oferite</h3>
            <p>✅ Împrumut la domiciliu — până la 5 cărți simultan, 21 de zile</p>
            <p>✅ Sală de lectură — acces la colecțiile de referință</p>
            <p>✅ Acces internet și baze de date internaționale</p>
            <p>✅ Sala de calculatoare — 20 de stații disponibile</p>
            <p>✅ Secție pentru copii și tineret</p>
            <p>✅ Colecție de carte rară și manuscrise</p>
            <p>✅ Evenimente culturale, lansări de carte, cluburi de lectură</p>
        </div>
    `;
}

// ===== PROFIL =====
function afiseazaProfil() {
    const div = document.getElementById('profilInfo');
    if (!div || !currentUser) return;
    const impMele = imprumuturi.filter(i => i.username === currentUser.username);
    const impActive = impMele.filter(i => !i.returnat).length;
    const impTotale = impMele.length;

    div.innerHTML = `
        <div class="profil-info-row"><span class="profil-label">Username</span><span class="profil-value">${currentUser.username}</span></div>
        <div class="profil-info-row"><span class="profil-label">Nume</span><span class="profil-value">${currentUser.nume}</span></div>
        <div class="profil-info-row"><span class="profil-label">Email</span><span class="profil-value">${currentUser.email}</span></div>
        <div class="profil-info-row"><span class="profil-label">Tip cont</span><span class="profil-value"><span class="badge badge-${currentUser.tip}">${currentUser.tip.toUpperCase()}</span></span></div>
        <div class="profil-info-row"><span class="profil-label">Împrumuturi active</span><span class="profil-value" style="color:var(--gold)">${impActive}</span></div>
        <div class="profil-info-row"><span class="profil-label">Total împrumuturi</span><span class="profil-value">${impTotale}</span></div>
        <div class="profil-info-row"><span class="profil-label">Wishlist</span><span class="profil-value">${wishlist.filter(w => w.username === currentUser.username).length} cărți</span></div>
    `;
}

function schimbaParola() {
    const veche = document.getElementById('parolaVeche').value;
    const nova = document.getElementById('parolaNova').value;
    const confirm = document.getElementById('parolaConfirm').value;
    const mesaj = document.getElementById('mesajParola');

    if (veche !== currentUser.parola) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = '❌ Parola veche este incorectă!';
        return;
    }
    if (nova !== confirm) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = '❌ Parolele noi nu coincid!';
        return;
    }
    if (nova.length < 6) {
        mesaj.className = 'mesaj error';
        mesaj.textContent = '❌ Parola trebuie să aibă minim 6 caractere!';
        return;
    }

    currentUser.parola = nova;
    const idx = utilizatori.findIndex(u => u.username === currentUser.username);
    if (idx !== -1) utilizatori[idx].parola = nova;

    mesaj.className = 'mesaj success';
    mesaj.textContent = '✅ Parola a fost schimbată cu succes!';
}

// ===== CARTILE MELE =====
function afiseazaCartiMele() {
    const div = document.getElementById('cartiMeleContent');
    if (!div || !currentUser) return;
    const active = imprumuturi.filter(i => i.username === currentUser.username && !i.returnat);

    if (active.length === 0) {
        div.innerHTML = '<div class="card"><p style="text-align:center;color:var(--text-dim)">Nu ai cărți împrumutate în prezent.</p></div>';
        return;
    }

    div.innerHTML = `
        <div class="table-container">
            <table>
                <thead><tr><th>Exemplar</th><th>Titlu</th><th>Data Împrumut</th><th>Termen</th></tr></thead>
                <tbody>
                    ${active.map(i => {
        const carte = carti.find(c => c.isbn === i.isbn);
        return `<tr>
                            <td><code>${i.codExemplar}</code></td>
                            <td>${i.titlu}</td>
                            <td>${i.data}</td>
                            <td>${carte ? carte.timpImprumut + ' zile' : '-'}</td>
                        </tr>`;
    }).join('')}
                </tbody>
            </table>
        </div>
    `;
}

// ===== ISTORIC =====
function afiseazaIstoric() {
    const div = document.getElementById('istoricContent');
    if (!div || !currentUser) return;
    const impMele = imprumuturi.filter(i => i.username === currentUser.username);
    const returnate = impMele.filter(i => i.returnat);
    const active = impMele.filter(i => !i.returnat);

    div.innerHTML = `
        <div class="stats-grid" style="grid-template-columns:repeat(3,1fr)">
            <div class="stat-card"><span class="stat-num">${impMele.length}</span><span class="stat-label">TOTAL ÎMPRUMUTURI</span></div>
            <div class="stat-card"><span class="stat-num">${returnate.length}</span><span class="stat-label">RETURNATE</span></div>
            <div class="stat-card"><span class="stat-num">${active.length}</span><span class="stat-label">ACTIVE</span></div>
        </div>
        <div class="card">
            <h3>🕐 Istoric Complet</h3>
            ${impMele.length === 0
            ? '<p style="color:var(--text-dim)">Nu ai niciun împrumut înregistrat.</p>'
            : `<table>
                    <thead><tr><th>Titlu</th><th>Data Împrumut</th><th>Data Returnare</th><th>Status</th></tr></thead>
                    <tbody>
                        ${impMele.map(i => `<tr>
                            <td>${i.titlu}</td>
                            <td>${i.data}</td>
                            <td>${i.dataReturnare || '-'}</td>
                            <td><span class="badge ${i.returnat ? 'badge-disponibila' : 'badge-imprumutata'}">${i.returnat ? 'Returnat' : 'Activ'}</span></td>
                        </tr>`).join('')}
                    </tbody>
                </table>`
        }
        </div>
    `;
}

// ===== WISHLIST =====
function cautaWishlist() {
    const termen = document.getElementById('wishlistSearch').value.toLowerCase();
    const div = document.getElementById('wishlistResults');
    if (termen.length < 2) { div.innerHTML = ''; return; }

    const rezultate = carti.filter(c =>
        c.titlu.toLowerCase().includes(termen) || c.autor.toLowerCase().includes(termen)
    ).slice(0, 8);

    div.innerHTML = rezultate.map(c => `
        <div class="rezultat-item" onclick="adaugaWishlist('${c.isbn}')">
            <div class="rezultat-titlu">${c.titlu}</div>
            <div class="rezultat-info">${c.autor} · ${c.an}</div>
        </div>
    `).join('');
}

function adaugaWishlist(isbn) {
    const carte = carti.find(c => c.isbn === isbn);
    if (!carte || !currentUser) return;

    const exista = wishlist.find(w => w.isbn === isbn && w.username === currentUser.username);
    if (exista) return;

    wishlist.push({ isbn, titlu: carte.titlu, autor: carte.autor, username: currentUser.username });
    localStorage.setItem('wishlist', JSON.stringify(wishlist));
    document.getElementById('wishlistSearch').value = '';
    document.getElementById('wishlistResults').innerHTML = '';
    afiseazaWishlist();
}

function stergeWishlist(isbn) {
    wishlist = wishlist.filter(w => !(w.isbn === isbn && w.username === currentUser.username));
    localStorage.setItem('wishlist', JSON.stringify(wishlist));
    afiseazaWishlist();
}

function afiseazaWishlist() {
    const div = document.getElementById('wishlistContent');
    if (!div || !currentUser) return;
    const mele = wishlist.filter(w => w.username === currentUser.username);

    div.innerHTML = mele.length === 0
        ? '<p style="color:var(--text-dim)">Lista ta de lectură este goală. Caută cărți mai sus!</p>'
        : mele.map(w => `
            <div class="wishlist-item">
                <div>
                    <div style="color:var(--text-primary)">${w.titlu}</div>
                    <div style="color:var(--text-dim);font-size:12px">${w.autor}</div>
                </div>
                <button class="btn-remove" onclick="stergeWishlist('${w.isbn}')">Elimină</button>
            </div>
        `).join('');
}

// ===== GAME =====
let gameCarti = [];
let gameRaspuns = '';
let gameScore = 0;

function initGame() {
    if (carti.length === 0) return;
    gameCarti = carti.filter(c => c.titlu.length > 3 && c.titlu.length < 20);
    newGameRound();
}

function newGameRound() {
    if (gameCarti.length === 0) return;
    const carte = gameCarti[Math.floor(Math.random() * gameCarti.length)];
    gameRaspuns = carte.titlu.toLowerCase();
    const amestecat = carte.titlu.split('').sort(() => Math.random() - 0.5).join('');
    document.getElementById('gameWord').textContent = amestecat.toUpperCase();
    document.getElementById('gameInput').value = '';
    document.getElementById('gameMsg').textContent = '';
}

function checkGameAnswer() {
    const input = document.getElementById('gameInput').value.trim().toLowerCase();
    const msg = document.getElementById('gameMsg');
    if (input === gameRaspuns) {
        gameScore += 10;
        document.getElementById('gameScore').textContent = gameScore;
        msg.style.color = 'var(--green)';
        msg.textContent = '✅ Corect! +10 puncte';
        setTimeout(newGameRound, 1200);
    } else {
        msg.style.color = 'var(--red)';
        msg.textContent = '❌ Incorect, mai încearcă!';
    }
}

function skipGameRound() {
    document.getElementById('gameMsg').textContent = `Răspuns: ${gameRaspuns}`;
    document.getElementById('gameMsg').style.color = 'var(--text-mid)';
    setTimeout(newGameRound, 1500);
}

// ===== DESPRE =====
function afiseazaDesprere() {
    const div = document.getElementById('sectiuneInfo');
    if (!div) return;
}

// Enter la login
document.addEventListener('keypress', e => {
    if (e.key === 'Enter' && !document.getElementById('loginPage').classList.contains('hidden')) login();
});