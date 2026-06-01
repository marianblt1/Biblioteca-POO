# Sistem de gestionare a bibliotecii


**Grupa:** 3122A  
**Student:** Baltei Marian


## 1. Cerinta Proiectului

**Descriere:**  
Implementarea unui sistem pentru o biblioteca virtuala, cu clase pentru carti, utilizatori si imprumuturi.

**Cerinte obligatorii:**
- Clase: Carte (titlu, autor, ISBN), Utilizator (nume, ID, lista imprumuturi), Biblioteca (adaugare/eliminare carti, imprumut/returnare)
- Mostenire: Clase derivate pentru tipuri de carti si utilizatori
- Polimorfism: Metode virtuale pentru afișare detalii
- Encapsulare: Atribute private, getteri/setteri
- Evenimente logate: împrumut/returnare
- Teste unitare pentru verificarea stocului
- Git: Cel puțin 5 commit-uri descriptive, branch "develop"

**Cerinte facultative:**
- Șabloane: O clasă generică pentru stocare
- Excepții: Tratare erori (ex: carte indisponibilă)
- Interfață consolă cu meniu


## 2. Motivare

Am ales această temă deoarece o bibliotecă reprezintă un sistem complex dar bine organizat pe categorii, 
ceea ce o face potrivită pentru a demonstra conceptele de Programare Orientată pe Obiecte. 
Diversitatea entităților (cărți de tipuri diferite, utilizatori cu roluri diferite) 
permite aplicarea naturală a moștenirii și polimorfismului, 
iar gestionarea împrumuturilor adaugă o logică reală și interesantă sistemului.


## 3. Structura Claselor

### Clasa de bază: Carte
| Câmp | Tip | Descriere |
|<---->|<-->|<-------->|
| titlu | string | Titlul cărții |
| autor | string | Numele autorului |
| ISBN | string | Codul unic internațional |
| anAparitie | int | Anul publicării |
| status | string | Disponibila / Imprumutata / Rezervata |
| stare | string | Noua / Buna / Uzata / Deteriorata |
| timpImprumut | int | Numărul de zile permise pentru împrumut |

- timpImprumut - va fi diferit pentru fiecare tip de carte — 

- **CarteFizica** → derivă din Carte
  - **CarteFictiune** → derivă din CarteFizica
  - **CarteTehnica** → derivă din CarteFizica
- **CarteDigitala** → derivă din Carte
- **Revista** → derivă din Carte


### Clase derivate din Carte:

**CarteFizica** (derivă din Carte)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| nrExemplare | int | Numărul de exemplare disponibile |
| localizare | string | Raftul/sectiunea din biblioteca |

**CarteFictiune** (derivă din CarteFizica)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| gen | string | Fantasy, Thriller, Romance, etc. |
| varstaminima | int | Varsta minima recomandata |

**CarteTehnica** (derivă din CarteFizica)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| domeniu | string | Informatica, Matematica, Fizica, etc. |
| nivelDificultate | string | Incepator / Intermediar / Avansat |

**CarteDigitala** (derivă din Carte)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| format | string | PDF, EPUB, MOBI |
| marimeFisier | float | Marimea in MB |

**Revista** (derivă din Carte)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| numar | int | Numarul editiei |
| periodicitate | string | Saptamanala, Lunara, Anuala |


### Clasa de bază: Utilizator
| Câmp | Tip | Descriere |
|------|-----|-----------|
| nume | string | Numele de familie |
| prenume | string | Prenumele |
| id | int | Identificator unic |
| email | string | Adresa de email |
| telefon | string | Număr de contact |
| tip | string | Tipul utilizatorului |
| status | string | Activ / Penalizat / Suspendat |
| cartiActive | int | Numărul de cărți împrumutate în prezent |

### Clase derivate din Utilizator:

**UtilizatorStudent** (derivă din Utilizator)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| facultate | string | Facultatea la care este înscris |
| anStudiu | int | Anul de studiu |
| nrMatricol | string | Numărul matricol |

**UtilizatorElev** (derivă din Utilizator)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| scoala | string | Școala la care învață |
| clasa | string | Clasa (ex: a-9-a) |

**UtilizatorAdult** (derivă din Utilizator)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| ocupatie | string | Ocupatia adultului |

**UtilizatorProfesor** (derivă din Utilizator)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| materie | string | Materia predată |
| institutie | string | Școala/Universitatea |

**UtilizatorPensionar** (derivă din Utilizator)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| varstaPensionare | int | Vârsta la care s-a pensionat |

**UtilizatorCercetator** (derivă din Utilizator)
| Câmp | Tip | Descriere |
|------|-----|-----------|
| domeniuCercetare | string | Domeniul de cercetare |
| institutie | string | Instituția de cercetare |


### Clasa Biblioteca
| Câmp | Tip | Descriere |
|------|-----|-----------|
| nume | string | Numele bibliotecii |
| inventarCarti | vector<Carte*> | Lista tuturor cărților |
| listaUtilizatori | vector<Utilizator*> | Lista tuturor utilizatorilor |

**Metode principale:**
- Adaugare / eliminare cărți
- Adaugare / eliminare utilizatori
- Împrumut carte
- Returnare carte
- Afișare inventar
- Logare evenimente (împrumut/returnare)


## 4. Structura Proiectului
```
biblioteca/
├── README.md
├── main.cpp
├── Carte.h
├── Carte.cpp
├── Utilizator.h
├── Utilizator.cpp
├── Biblioteca.h
└── Biblioteca.cpp
```

## 5. Structura Git

- Branch principal: **main**
- Branch dezvoltare: **develop**
- Minimum 5 commit-uri descriptive

## 6. Funcționalități Implementate

### Autentificare
- Login cu username și parolă
- Parolă criptată cu algoritmul XOR salvată în fișier `utilizatori.dat`
- Două tipuri de conturi: **staff** și **normal**
- Cont admin implicit creat la prima rulare (username: admin, parola: admin123)

### Permisiuni
- **Staff**: acces complet (adăugare/ștergere cărți și utilizatori, împrumuturi)
- **Normal**: acces limitat (căutare și împrumut/returnare cărți)

### Meniu Interactiv
- Gestionare cărți (adăugare, afișare, ștergere)
- Gestionare utilizatori (adăugare, afișare)
- Căutare cărți (după titlu, autor, ISBN)
- Gestionare împrumuturi (împrumut, returnare)

### Validări
- ISBN: exact 10 sau 13 cifre
- Localizare raft: format [A-H][1-3] (ex: A1, B2, H3)
- Timp împrumut: între 1 și 90 de zile
- Input numeric: protecție împotriva textului introdus greșit

### Persistența Datelor
- Cărțile sunt salvate automat în `date.txt` la ieșire
- Datele sunt încărcate automat la pornirea programului

### Tratare Erori (Excepții)
- `CarteIndisponibila` - carte deja împrumutată
- `CarteNegasita` - ISBN inexistent
- `UtilizatorNegasit` - ID utilizator inexistent
- `UtilizatorSuspendat` - utilizator fără drepturi de împrumut

### Șabloane
- Clasa generică `Depozit<T>` folosită pentru stocarea cărților și utilizatorilor

## 7. Instrucțiuni Build și Run

### Compilare
```bash
make
```

### Rulare
```bash
./biblioteca
```

### Rulare Teste
```bash
make test
```

### Curățare
```bash
make clean
```

## 8. Structura Git
- Branch principal: **main**
- Branch dezvoltare: **develop**
- Commit-uri descriptive pentru fiecare funcționalitate adăugată