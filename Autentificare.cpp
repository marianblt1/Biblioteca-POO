#include "Autentificare.h"
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

string Autentificare::cripteaza(string text) {
    string rezultat = text;
    for (size_t i = 0; i < text.size(); i++) {
        rezultat[i] = text[i] ^ CHEIE;
    }
    return rezultat;
}

bool Autentificare::fisierExista(string numeFisier) {
    ifstream f(numeFisier);
    return f.good();
}

bool Autentificare::usernameExista(string username) {
    ifstream fisier("utilizatori.dat");
    if (!fisier.is_open()) return false;

    string linie;
    while (getline(fisier, linie)) {
        stringstream ss(linie);
        string user, parola, tip;
        getline(ss, user, ',');
        if (user == username) {
            fisier.close();
            return true;
        }
    }
    fisier.close();
    return false;
}

void Autentificare::inregistrare(string username, string parola, string tip) {
    if (usernameExista(username)) {
        cout << "Username-ul exista deja!" << endl;
        return;
    }

    ofstream fisier("utilizatori.dat", ios::app);
    if (fisier.is_open()) {
        string parolaCriptata = cripteaza(parola);
        fisier << username << "," << parolaCriptata << "," << tip << endl;
        fisier.close();
        cout << "Cont creat cu succes!" << endl;
    }
}

bool Autentificare::login(string username, string parola, string& tipUtilizator) {
    ifstream fisier("utilizatori.dat");
    if (!fisier.is_open()) return false;

    string linie;
    while (getline(fisier, linie)) {
        stringstream ss(linie);
        string user, parolaCriptata, tip;
        getline(ss, user, ',');
        getline(ss, parolaCriptata, ',');
        getline(ss, tip, ',');

        if (user == username && parolaCriptata == cripteaza(parola)) {
            tipUtilizator = tip;
            fisier.close();
            return true;
        }
    }
    fisier.close();
    return false;
}