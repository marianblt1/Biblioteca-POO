#include "Biblioteca.h"
#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Biblioteca::Biblioteca(string nume)
{
    this->nume = nume;
    this->cladire = nullptr;
}

void Biblioteca::adaugaCarte(Carte *carte)
{
    inventarCarti.adauga(carte);
    cout << "Cartea '" << carte->getTitlu() << "' a fost adaugata." << endl;
    logEveniment("Adaugata cartea: " + carte->getTitlu());
}

void Biblioteca::eliminaCarte(int idCarte)
{
    for (int i = 0; i < inventarCarti.dimensiune(); i++)
    {
        if (inventarCarti.get(i)->getISBN() == to_string(idCarte))
        {
            logEveniment("Eliminata cartea: " + inventarCarti.get(i)->getTitlu());
            delete inventarCarti.get(i);
            inventarCarti.elimina(i);
            cout << "Cartea a fost eliminata." << endl;
            return;
        }
    }
    cout << "Cartea nu a fost gasita." << endl;
}

void Biblioteca::eliminaCarteISBN(string isbn)
{
    for (int i = 0; i < inventarCarti.dimensiune(); i++)
    {
        if (inventarCarti.get(i)->getISBN() == isbn)
        {
            logEveniment("Eliminata cartea: " + inventarCarti.get(i)->getTitlu());
            delete inventarCarti.get(i);
            inventarCarti.elimina(i);
            cout << "Cartea a fost eliminata cu succes." << endl;
            return;
        }
    }
    cout << "Cartea cu ISBN-ul '" << isbn << "' nu a fost gasita." << endl;
}

void Biblioteca::afisareCarti() const
{
    cout << "\n=== Inventar Carti - " << nume << " ===" << endl;
    for (int i = 0; i < inventarCarti.dimensiune(); i++)
    {
        cout << "\n--- Carte " << i + 1 << " ---" << endl;
        inventarCarti.get(i)->afisareDetalii();
    }
}

void Biblioteca::adaugaUtilizator(Utilizator *utilizator)
{
    listaUtilizatori.adauga(utilizator);
    cout << "Utilizatorul '" << utilizator->getNume() << " "
         << utilizator->getPrenume() << "' a fost adaugat." << endl;
    logEveniment("Adaugat utilizatorul: " + utilizator->getNume() + " " + utilizator->getPrenume());
}

void Biblioteca::eliminaUtilizator(int idUtilizator)
{
    for (int i = 0; i < listaUtilizatori.dimensiune(); i++)
    {
        if (listaUtilizatori.get(i)->getId() == idUtilizator)
        {
            logEveniment("Eliminat utilizatorul: " + listaUtilizatori.get(i)->getNume());
            delete listaUtilizatori.get(i);
            listaUtilizatori.elimina(i);
            cout << "Utilizatorul a fost eliminat." << endl;
            return;
        }
    }
    cout << "Utilizatorul nu a fost gasit." << endl;
}

void Biblioteca::afisareUtilizatori() const
{
    cout << "\n=== Lista Utilizatori - " << nume << " ===" << endl;
    for (int i = 0; i < listaUtilizatori.dimensiune(); i++)
    {
        cout << "\n--- Utilizator " << i + 1 << " ---" << endl;
        listaUtilizatori.get(i)->afisareDetalii();
    }
}

void Biblioteca::imprumutaCarte(string identificatorUtilizator, string isbn)
{
    Utilizator *utilizator = nullptr;
    Carte *carte = nullptr;

    for (int i = 0; i < listaUtilizatori.dimensiune(); i++)
    {
        if (listaUtilizatori.get(i)->getEmail() == identificatorUtilizator ||
            listaUtilizatori.get(i)->getNume() == identificatorUtilizator)
        {
            utilizator = listaUtilizatori.get(i);
            break;
        }
    }

    for (int i = 0; i < inventarCarti.dimensiune(); i++)
    {
        if (inventarCarti.get(i)->getISBN() == isbn)
        {
            carte = inventarCarti.get(i);
            break;
        }
    }

    if (utilizator == nullptr)
        throw std::runtime_error("Utilizatorul '" + identificatorUtilizator + "' nu a fost gasit!");

    if (carte == nullptr)
        throw CarteNegasita(isbn);

    if (!carte->poateFiImprumutata())
        throw CarteIndisponibila(carte->getTitlu() + " (carte rara - doar in sala de lectura)");

    if (carte->getStatus() != "Disponibila")
        throw CarteIndisponibila(carte->getTitlu());

    if (utilizator->getStatus() == "Suspendat")
        throw UtilizatorSuspendat(utilizator->getNume());

    carte->setStatus("Imprumutata");
    utilizator->adaugaImprumut(0);
    cout << "Cartea '" << carte->getTitlu() << "' a fost imprumutata lui "
         << utilizator->getNume() << "." << endl;
    logEveniment("Imprumut: " + utilizator->getNume() + " -> " + carte->getTitlu());
}

void Biblioteca::returneazaCarte(string identificatorUtilizator, string isbn)
{
    Utilizator *utilizator = nullptr;
    Carte *carte = nullptr;

    for (int i = 0; i < listaUtilizatori.dimensiune(); i++)
    {
        if (listaUtilizatori.get(i)->getEmail() == identificatorUtilizator ||
            listaUtilizatori.get(i)->getNume() == identificatorUtilizator)
        {
            utilizator = listaUtilizatori.get(i);
            break;
        }
    }

    for (int i = 0; i < inventarCarti.dimensiune(); i++)
    {
        if (inventarCarti.get(i)->getISBN() == isbn)
        {
            carte = inventarCarti.get(i);
            break;
        }
    }

    if (utilizator == nullptr || carte == nullptr)
    {
        cout << "Date invalide." << endl;
        return;
    }

    carte->setStatus("Disponibila");
    utilizator->eliminaImprumut(0);
    cout << "Cartea '" << carte->getTitlu() << "' a fost returnata." << endl;
    logEveniment("Returnare: " + utilizator->getNume() + " -> " + carte->getTitlu());
}

void Biblioteca::cautaCarte(int tip, string termen) const
{
    cout << "\n=== Rezultate cautare ===" << endl;
    bool gasit = false;

    for (int i = 0; i < inventarCarti.dimensiune(); i++)
    {
        bool match = false;

        if (tip == 1 && inventarCarti.get(i)->getTitlu().find(termen) != string::npos)
            match = true;
        else if (tip == 2 && inventarCarti.get(i)->getAutor().find(termen) != string::npos)
            match = true;
        else if (tip == 3 && inventarCarti.get(i)->getISBN().find(termen) != string::npos)
            match = true;

        if (match)
        {
            cout << "\n--- Rezultat " << i + 1 << " ---" << endl;
            inventarCarti.get(i)->afisareDetalii();
            gasit = true;
        }
    }

    if (!gasit)
        cout << "Niciun rezultat gasit." << endl;
}

void Biblioteca::logEveniment(string eveniment) const
{
    ofstream logFile("log.txt", ios::app);
    if (logFile.is_open())
    {
        logFile << eveniment << endl;
        logFile.close();
    }
}

void Biblioteca::salveazaDate() const
{
    ofstream fisier("date.txt");
    if (!fisier.is_open())
        return;

    for (int i = 0; i < inventarCarti.dimensiune(); i++)
    {
        Carte *c = inventarCarti.get(i);
        fisier << c->getTipCarte() << "|"
               << c->getTitlu() << "|"
               << c->getAutor() << "|"
               << c->getISBN() << "|"
               << c->getAnAparitie() << "|"
               << c->getStare() << "|"
               << c->getTimpImprumut() << "|"
               << c->getStatus() << "\n";
    }
    fisier.close();
    cout << "Date salvate cu succes!" << endl;
}

void Biblioteca::incarcaDate() {
    ifstream fisier("date.txt");
    if (!fisier.is_open()) return;

    string linie;
    while (getline(fisier, linie)) {
        stringstream ss(linie);
        string tipCarte, titlu, autor, isbn, stare, status, localizare;
        int anAparitie, timpImprumut, nrExemplare;

        getline(ss, tipCarte, '|');
        getline(ss, titlu, '|');
        getline(ss, autor, '|');
        getline(ss, isbn, '|');
        ss >> anAparitie; ss.ignore();
        getline(ss, stare, '|');
        ss >> timpImprumut; ss.ignore();
        ss >> nrExemplare; ss.ignore();
        getline(ss, localizare, '|');
        getline(ss, status, '|');

        Carte* c = nullptr;
        if (tipCarte == "CarteRara") {
            c = new CarteRara(titlu, autor, isbn, anAparitie, stare,
                              0, nrExemplare, localizare, anAparitie, "Necunoscut", false);
        } else {
            c = new CarteFizica(titlu, autor, isbn, anAparitie, stare,
                                timpImprumut, nrExemplare, localizare);
        }
        c->setStatus(status);
        inventarCarti.adauga(c);
    }
    fisier.close();
    cout << "Date incarcate cu succes!" << endl;
}

void Biblioteca::setCladire(Cladire *cladire)
{
    this->cladire = cladire;
}

Cladire *Biblioteca::getCladire() const
{
    return cladire;
}

void Biblioteca::localizazeCarteInCladire(string isbn) const
{
    if (cladire == nullptr)
    {
        cout << "Nu exista o cladire configurata." << endl;
        return;
    }
    cout << "\nLocalizare carte ISBN '" << isbn << "':" << endl;
    cout << cladire->localizarecarte(isbn) << endl;
}

void Biblioteca::cautaUtilizator(string termen) const
{
    cout << "\n=== Rezultate cautare utilizatori ===" << endl;
    bool gasit = false;

    for (int i = 0; i < listaUtilizatori.dimensiune(); i++)
    {
        Utilizator *u = listaUtilizatori.get(i);
        if (u->getNume().find(termen) != string::npos ||
            u->getPrenume().find(termen) != string::npos ||
            u->getEmail().find(termen) != string::npos)
        {
            cout << "\n--- Utilizator ---" << endl;
            u->afisareDetalii();
            gasit = true;
        }
    }

    if (!gasit)
        cout << "Niciun utilizator gasit." << endl;
}

Biblioteca::~Biblioteca()
{
    for (int i = 0; i < inventarCarti.dimensiune(); i++)
    {
        delete inventarCarti.get(i);
    }
    for (int i = 0; i < listaUtilizatori.dimensiune(); i++)
    {
        delete listaUtilizatori.get(i);
    }
}