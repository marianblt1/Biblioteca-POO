#include "Meniu.h"
#include <iostream>
#include <string>
#include <limits>

using namespace std;

Meniu::Meniu(Biblioteca& biblioteca) : biblioteca(biblioteca) {}

void Meniu::ruleaza() {
    int optiune;
    do {
        cout << "\n==========================" << endl;
        cout << "   BIBLIOTECA CENTRALA    " << endl;
        cout << "==========================" << endl;
        cout << "1. Gestionare Carti" << endl;
        cout << "2. Gestionare Utilizatori" << endl;
        cout << "3. Cautare Carti" << endl;
        cout << "4. Gestionare Imprumuturi" << endl;
        cout << "0. Iesire" << endl;
        cout << "==========================" << endl;
        cout << "Optiune: ";
        cin >> optiune;

        switch(optiune) {
            case 1: meniuCarti(); break;
            case 2: meniuUtilizatori(); break;
            case 3: meniuCautare(); break;
            case 4: meniuImprumuturi(); break;
            case 0: cout << "La revedere!" << endl; break;
            default: cout << "Optiune invalida!" << endl;
        }
    } while(optiune != 0);
}

void Meniu::meniuCarti() {
    int optiune;
    cout << "\n--- Gestionare Carti ---" << endl;
    cout << "1. Adauga carte" << endl;
    cout << "2. Afiseaza toate cartile" << endl;
    cout << "0. Inapoi" << endl;
    cout << "Optiune: ";
    cin >> optiune;

    switch(optiune) {
        case 1: adaugaCarte(); break;
        case 2: biblioteca.afisareCarti(); break;
        case 0: break;
        default: cout << "Optiune invalida!" << endl;
    }
}

void Meniu::meniuUtilizatori() {
    int optiune;
    cout << "\n--- Gestionare Utilizatori ---" << endl;
    cout << "1. Adauga utilizator" << endl;
    cout << "2. Afiseaza toti utilizatorii" << endl;
    cout << "0. Inapoi" << endl;
    cout << "Optiune: ";
    cin >> optiune;

    switch(optiune) {
        case 1: adaugaUtilizator(); break;
        case 2: biblioteca.afisareUtilizatori(); break;
        case 0: break;
        default: cout << "Optiune invalida!" << endl;
    }
}

void Meniu::meniuCautare() {
    int optiune;
    string termen;
    cout << "\n--- Cautare Carti ---" << endl;
    cout << "1. Cauta dupa titlu" << endl;
    cout << "2. Cauta dupa autor" << endl;
    cout << "3. Cauta dupa ISBN" << endl;
    cout << "0. Inapoi" << endl;
    cout << "Optiune: ";
    cin >> optiune;

    if(optiune >= 1 && optiune <= 3) {
        cout << "Termen cautare: ";
        cin.ignore();
        getline(cin, termen);
        biblioteca.cautaCarte(optiune, termen);
    }
}

void Meniu::meniuImprumuturi() {
    int optiune;
    cout << "\n--- Gestionare Imprumuturi ---" << endl;
    cout << "1. Imprumuta carte" << endl;
    cout << "2. Returneaza carte" << endl;
    cout << "0. Inapoi" << endl;
    cout << "Optiune: ";
    cin >> optiune;

    int idUtilizator, idCarte;
    switch(optiune) {
        case 1:
            cout << "ID Utilizator: ";
            cin >> idUtilizator;
            cout << "ID Carte: ";
            cin >> idCarte;
            try {
                biblioteca.imprumutaCarte(idUtilizator, idCarte);
            } catch (exception& e) {
                cout << "Eroare: " << e.what() << endl;
            }
            break;
        case 2:
            cout << "ID Utilizator: ";
            cin >> idUtilizator;
            cout << "ID Carte: ";
            cin >> idCarte;
            try {
                biblioteca.returneazaCarte(idUtilizator, idCarte);
            } catch (exception& e) {
                cout << "Eroare: " << e.what() << endl;
            }
            break;
        case 0: break;
        default: cout << "Optiune invalida!" << endl;
    }
}

void Meniu::adaugaCarte() {
    int tip;
    cout << "\nTip carte:" << endl;
    cout << "1. Carte Fictiune" << endl;
    cout << "2. Carte Tehnica" << endl;
    cout << "3. Carte Digitala" << endl;
    cout << "4. Revista" << endl;
    cout << "Optiune: ";
    cin >> tip;
    cin.ignore();

    string titlu, autor, isbn, stare;
    int anAparitie, timpImprumut;

    cout << "Titlu: "; getline(cin, titlu);
    cout << "Autor: "; getline(cin, autor);
    cout << "ISBN: "; getline(cin, isbn);
    cout << "An aparitie: "; cin >> anAparitie;
    cin.ignore();
    cout << "Stare (Noua/Buna/Uzata/Deteriorata): "; getline(cin, stare);
    cout << "Timp imprumut (zile): "; cin >> timpImprumut;
    cin.ignore();

    if(tip == 1) {
        string localizare, gen;
        int nrExemplare, varstaMinima;
        cout << "Nr exemplare: "; cin >> nrExemplare;
        cin.ignore();
        cout << "Localizare (raft): "; getline(cin, localizare);
        cout << "Gen (Fantasy/Thriller/Romance/etc): "; getline(cin, gen);
        cout << "Varsta minima: "; cin >> varstaMinima;
        biblioteca.adaugaCarte(new CarteFictiune(titlu, autor, isbn, anAparitie, 
                               stare, timpImprumut, nrExemplare, localizare, gen, varstaMinima));
    } else if(tip == 2) {
        string localizare, domeniu, nivel;
        int nrExemplare;
        cout << "Nr exemplare: "; cin >> nrExemplare;
        cin.ignore();
        cout << "Localizare (raft): "; getline(cin, localizare);
        cout << "Domeniu: "; getline(cin, domeniu);
        cout << "Nivel (Incepator/Intermediar/Avansat): "; getline(cin, nivel);
        biblioteca.adaugaCarte(new CarteTehnica(titlu, autor, isbn, anAparitie,
                               stare, timpImprumut, nrExemplare, localizare, domeniu, nivel));
    } else if(tip == 3) {
        string format;
        float marime;
        cout << "Format (PDF/EPUB/MOBI): "; getline(cin, format);
        cout << "Marime fisier (MB): "; cin >> marime;
        biblioteca.adaugaCarte(new CarteDigitala(titlu, autor, isbn, anAparitie,
                               stare, timpImprumut, format, marime));
    } else if(tip == 4) {
        string periodicitate;
        int numar;
        cout << "Numar editie: "; cin >> numar;
        cin.ignore();
        cout << "Periodicitate (Saptamanala/Lunara/Anuala): "; getline(cin, periodicitate);
        biblioteca.adaugaCarte(new Revista(titlu, autor, isbn, anAparitie,
                               stare, timpImprumut, numar, periodicitate));
    }
}

void Meniu::adaugaUtilizator() {
    int tip;
    cout << "\nTip utilizator:" << endl;
    cout << "1. Student" << endl;
    cout << "2. Elev" << endl;
    cout << "3. Adult" << endl;
    cout << "4. Profesor" << endl;
    cout << "5. Pensionar" << endl;
    cout << "6. Cercetator" << endl;
    cout << "Optiune: ";
    cin >> tip;
    cin.ignore();

    string nume, prenume, email, telefon;
    int id;

    cout << "Nume: "; getline(cin, nume);
    cout << "Prenume: "; getline(cin, prenume);
    cout << "ID: "; cin >> id;
    cin.ignore();
    cout << "Email: "; getline(cin, email);
    cout << "Telefon: "; getline(cin, telefon);

    if(tip == 1) {
        string facultate, nrMatricol;
        int anStudiu;
        cout << "Facultate: "; getline(cin, facultate);
        cout << "An studiu: "; cin >> anStudiu;
        cin.ignore();
        cout << "Nr matricol: "; getline(cin, nrMatricol);
        biblioteca.adaugaUtilizator(new UtilizatorStudent(nume, prenume, id, 
                                    email, telefon, facultate, anStudiu, nrMatricol));
    } else if(tip == 2) {
        string scoala, clasa;
        cout << "Scoala: "; getline(cin, scoala);
        cout << "Clasa: "; getline(cin, clasa);
        biblioteca.adaugaUtilizator(new UtilizatorElev(nume, prenume, id,
                                    email, telefon, scoala, clasa));
    } else if(tip == 3) {
        string ocupatie;
        cout << "Ocupatie: "; getline(cin, ocupatie);
        biblioteca.adaugaUtilizator(new UtilizatorAdult(nume, prenume, id,
                                    email, telefon, ocupatie));
    } else if(tip == 4) {
        string materie, institutie;
        cout << "Materie: "; getline(cin, materie);
        cout << "Institutie: "; getline(cin, institutie);
        biblioteca.adaugaUtilizator(new UtilizatorProfesor(nume, prenume, id,
                                    email, telefon, materie, institutie));
    } else if(tip == 5) {
        int varsta;
        cout << "Varsta pensionare: "; cin >> varsta;
        biblioteca.adaugaUtilizator(new UtilizatorPensionar(nume, prenume, id,
                                    email, telefon, varsta));
    } else if(tip == 6) {
        string domeniu, institutie;
        cout << "Domeniu cercetare: "; getline(cin, domeniu);
        cout << "Institutie: "; getline(cin, institutie);
        biblioteca.adaugaUtilizator(new UtilizatorCercetator(nume, prenume, id,
                                    email, telefon, domeniu, institutie));
    }
}