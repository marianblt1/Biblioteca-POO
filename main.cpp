#include <iostream>
#include "Biblioteca.h"
#include "Meniu.h"
#include "Autentificare.h"

using namespace std;

int main() {
    // Cream un cont staff implicit daca nu exista
    if (!Autentificare::usernameExista("admin")) {
        Autentificare::inregistrare("admin", "admin123", "staff");
    }

    Biblioteca biblioteca("Biblioteca Centrala");
    biblioteca.incarcaDate();  // incarcam datele la pornire

    string username, parola, tipUtilizator;
    int optiune;

    cout << "\n==========================" << endl;
    cout << "   BIBLIOTECA CENTRALA    " << endl;
    cout << "==========================" << endl;
    cout << "1. Login" << endl;
    cout << "2. Inregistrare" << endl;
    cout << "0. Iesire" << endl;
    cout << "Optiune: ";
    cin >> optiune;
    cin.ignore();

    if (optiune == 2) {
        string tip;
        cout << "Username: "; getline(cin, username);
        cout << "Parola: "; getline(cin, parola);
        cout << "Tip (normal/staff): "; getline(cin, tip);
        Autentificare::inregistrare(username, parola, tip);
    }

    if (optiune == 1 || optiune == 2) {
        if (optiune == 2) {
            cout << "\nAcum te poti loga!" << endl;
        }
        cout << "Username: "; getline(cin, username);
        cout << "Parola: "; getline(cin, parola);

        if (Autentificare::login(username, parola, tipUtilizator)) {
            cout << "\nBine ai venit, " << username << "! (" << tipUtilizator << ")" << endl;
            Meniu meniu(biblioteca, tipUtilizator);
            meniu.ruleaza();
            biblioteca.salveazaDate();  // salvam datele la iesire
        } else {
            cout << "Username sau parola incorecta!" << endl;
        }
    }

    return 0;
}