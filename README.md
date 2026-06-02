# Sistem de Gestionare a Bibliotecii

**Grupa:** 3122A  
**Student:** Baltei Marian

---

## 1. Cerinta Proiectului

**Descriere:**  
Implementarea unui sistem pentru o biblioteca virtuala, cu clase pentru carti, utilizatori si imprumuturi.

**Cerinte obligatorii:**
- Clase: Carte (titlu, autor, ISBN), Utilizator (nume, ID, lista imprumuturi), Biblioteca (adaugare/eliminare carti, imprumut/returnare)
- Mostenire: Clase derivate pentru tipuri de carti si utilizatori
- Polimorfism: Metode virtuale pentru afisare detalii
- Encapsulare: Atribute private, getteri/setteri
- Evenimente logate: imprumut/returnare
- Teste unitare pentru verificarea stocului
- Git: Cel putin 5 commit-uri descriptive, branch "develop"

**Cerinte facultative:**
- Sabloane: O clasa generica pentru stocare
- Exceptii: Tratare erori (ex: carte indisponibila)
- Interfata consola cu meniu

---

## 2. Motivare

Am ales aceasta tema deoarece o biblioteca reprezinta un sistem complex dar bine organizat pe categorii, ceea ce o face potrivita pentru a demonstra conceptele de Programare Orientata pe Obiecte. Diversitatea entitatilor (carti de tipuri diferite, utilizatori cu roluri diferite) permite aplicarea naturala a mostenirii si polimorfismului, iar gestionarea imprumuturilor adauga o logica reala si interesanta sistemului.

---

## 3. Structura Claselor

### Clasa de baza: Carte
| Camp | Tip | Descriere |
|------|-----|-----------|
| titlu | string | Titlul cartii |
| autor | string | Numele autorului |
| ISBN | string | Codul unic international (10 sau 13 cifre) |
| anAparitie | int | Anul publicarii |
| status | string | Disponibila / Imprumutata / Rezervata / Doar in sala |
| stare | string | Noua / Buna / Uzata / Deteriorata |
| timpImprumut | int | Numarul de zile permise (1-90) |

### Ierarhia cartilor:

```
Carte (baza)
├── CarteFizica
│   ├── CarteFictiune
│   ├── CarteTehnica
│   └── CarteRara
├── CarteDigitala
└── Revista
```

### Clase derivate din Carte:

**CarteFizica** (deriva din Carte)
| Camp | Tip | Descriere |
|------|-----|-----------|
| nrExemplare | int | Numarul de exemplare disponibile |
| localizare | string | Raftul/sectiunea [A-H][1-3] |

**CarteFictiune** (deriva din CarteFizica)
| Camp | Tip | Descriere |
|------|-----|-----------|
| gen | string | Fantasy, Thriller, Romance, etc. |
| varstaMinima | int | Varsta minima recomandata |

**CarteTehnica** (deriva din CarteFizica)
| Camp | Tip | Descriere |
|------|-----|-----------|
| domeniu | string | Informatica, Matematica, Fizica, etc. |
| nivelDificultate | string | Incepator / Intermediar / Avansat |

**CarteDigitala** (deriva din Carte)
| Camp | Tip | Descriere |
|------|-----|-----------|
| format | string | PDF, EPUB, MOBI |
| marimeFisier | float | Marimea in MB |

**Revista** (deriva din Carte)
| Camp | Tip | Descriere |
|------|-----|-----------|
| numar | int | Numarul editiei |
| periodicitate | string | Saptamanala / Lunara / Anuala |

**CarteRara** (deriva din CarteFizica)
| Camp | Tip | Descriere |
|------|-----|-----------|
| anEstimat | int | Anul estimat al manuscrisului |
| origine | string | Provenienta cartii |
| esteManuscris | bool | Manuscris sau carte rara tiparita |

---

### Clasa de baza: Utilizator
| Camp | Tip | Descriere |
|------|-----|-----------|
| nume | string | Numele de familie |
| prenume | string | Prenumele |
| id | int | Identificator unic |
| email | string | Adresa de email |
| telefon | string | Numar de contact |
| status | string | Activ / Penalizat / Suspendat |
| cartiActive | int | Numarul de carti imprumutate in prezent |

### Ierarhia utilizatorilor:

```
Utilizator (baza)
├── UtilizatorStudent
├── UtilizatorElev
├── UtilizatorAdult
├── UtilizatorProfesor
├── UtilizatorPensionar
└── UtilizatorCercetator
```

### Clasa Biblioteca
| Camp | Tip | Descriere |
|------|-----|-----------|
| nume | string | Numele bibliotecii |
| inventarCarti | Depozit<Carte*> | Lista tuturor cartilor |
| listaUtilizatori | Depozit<Utilizator*> | Lista tuturor utilizatorilor |
| cladire | Cladire* | Cladirea bibliotecii |

**Metode principale:**
- Adaugare / eliminare carti si utilizatori
- Imprumut si returnare carte
- Cautare dupa titlu, autor, ISBN
- Afisare inventar
- Logare evenimente in log.txt

### Clasa Camera si Cladire

Biblioteca are o cladire cu mai multe camere:
- **Sala de Lectura** - carti care nu pot fi scoase din incinta
- **Depozit** - stoc de carti
- **Receptie** - ghiseul de imprumuturi
- **Sala Calculatoare** - resurse digitale
- **Sala Copii** - sectiune dedicata

---

## 4. Functionalitati Implementate

### Autentificare
- Login cu username si parola
- Parola criptata XOR salvata in fisier `utilizatori.dat`
- Doua tipuri de conturi: **staff** si **normal**
- Optiune "Ramai logat" (localStorage)

### Permisiuni
- **Staff**: acces complet (gestionare carti, utilizatori, imprumuturi, statistici)
- **Normal**: acces limitat (cautare, imprumut/returnare, profil, wishlist)

### Sistem de Exemplare
- Fiecare carte are un numar de exemplare
- Fiecare exemplar are un cod unic (ex: EX-00001)
- Imprumuturile se fac per exemplar, nu per titlu

### Validari
- ISBN: exact 10 sau 13 cifre
- Localizare raft: format [A-H][1-3] (ex: A1, B2, H3)
- Timp imprumut: intre 1 si 90 de zile
- Input numeric: protectie impotriva textului gresit

### Tratare Erori (Exceptii)
- `CarteIndisponibila` - carte deja imprumutata
- `CarteNegasita` - ISBN inexistent
- `UtilizatorNegasit` - utilizator inexistent
- `UtilizatorSuspendat` - utilizator fara drepturi

### Sabloane
- Clasa generica `Depozit<T>` pentru stocarea cartilor si utilizatorilor

### Persistenta Datelor
- Cartile salvate automat in `date.txt` la iesire
- Datele incarcate automat la pornire
- Istoricul imprumuturilor salvat in localStorage (interfata web)

### Interfata Grafica Web
- Login cu imagine de fundal si efect blur
- Navigare prin topbar orizontal
- Dashboard cu statistici si joc interactiv
- Gestiune carti cu cautare si filtrare pe tip
- Gestiune utilizatori (doar staff)
- Gestiune imprumuturi cu cod exemplar
- Cautare avansata cu filtre multiple
- Statistici cu filtrare interactiva pe tip
- Anunturi expandabile
- Profil utilizator cu schimbare parola
- Wishlist personal
- Istoric imprumuturi
- Sectiune Despre biblioteca

---

## 5. Structura Proiectului

```
biblioteca/
├── README.md
├── Makefile
├── main.cpp
├── seed.cpp
├── Carte.h / Carte.cpp
├── CarteFizica.h / CarteFizica.cpp
├── CarteFictiune.h / CarteFictiune.cpp
├── CarteTehnica.h / CarteTehnica.cpp
├── CarteDigitala.h / CarteDigitala.cpp
├── CarteRara.h / CarteRara.cpp
├── Revista.h / Revista.cpp
├── Utilizator.h / Utilizator.cpp
├── UtilizatorStudent.h / UtilizatorStudent.cpp
├── UtilizatorElev.h / UtilizatorElev.cpp
├── UtilizatorAdult.h / UtilizatorAdult.cpp
├── UtilizatorProfesor.h / UtilizatorProfesor.cpp
├── UtilizatorPensionar.h / UtilizatorPensionar.cpp
├── UtilizatorCercetator.h / UtilizatorCercetator.cpp
├── Biblioteca.h / Biblioteca.cpp
├── Camera.h / Camera.cpp
├── Cladire.h / Cladire.cpp
├── Meniu.h / Meniu.cpp
├── Autentificare.h / Autentificare.cpp
├── Depozit.h
├── Exceptii.h
├── Validare.h
├── Teste.cpp
├── date.txt
├── exemplare.txt
├── utilizatori.dat
├── log.txt
└── gui/
    ├── index.html
    ├── style.css
    └── app.js
```

---

## 6. Instructiuni Build si Run

### Cerinte
- Linux / WSL (Ubuntu)
- g++ cu suport C++17
- make
- python3 (pentru interfata web)

### Generare date initiale
```bash
g++ -o seed seed.cpp && ./seed
```

### Compilare aplicatie consola
```bash
make
```

### Rulare aplicatie consola
```bash
./biblioteca
```

### Rulare teste unitare
```bash
make test
```

### Rulare interfata grafica web
```bash
python3 -m http.server 8080
```
Deschide `http://localhost:8080/gui/` in browser.

### Credentiale implicite
- **Staff:** admin / parola123
- **Normal:** marian / parola123

### Curatare
```bash
make clean
```

---

## 7. Structura Git

- Branch principal: **main**
- Branch dezvoltare: **develop**
- Commit-uri descriptive pentru fiecare functionalitate adaugata