#include <iostream>
#include "Biblioteca.h"
#include "Meniu.h"
#include "Autentificare.h"
#include "Cladire.h"
#include "Camera.h"

using namespace std;

int main() {
    // Cream un cont staff implicit daca nu exista
    if (!Autentificare::usernameExista("admin")) {
        Autentificare::inregistrare("admin", "admin123", "staff");
    }

    Biblioteca biblioteca("Biblioteca Centrala");
    // Cream cladirea cu camere default
    Cladire* cladire = new Cladire("Str. Bibliotecii Nr. 1", 2);
    cladire->adaugaCamera(new Camera("Sala de Lectura", SALA_LECTURA, 50, "08:00 - 20:00"));
    cladire->adaugaCamera(new Camera("Depozit", DEPOZIT, 1000, "08:00 - 16:00"));
    cladire->adaugaCamera(new Camera("Receptie", RECEPTIE, 10, "08:00 - 20:00"));
    cladire->adaugaCamera(new Camera("Sala Calculatoare", SALA_CALCULATOARE, 20, "09:00 - 18:00"));
    cladire->adaugaCamera(new Camera("Sala Copii", SALA_COPII, 30, "09:00 - 17:00"));
    biblioteca.setCladire(cladire);
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