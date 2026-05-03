#include <iostream>
#include <cassert>
#include "Biblioteca.h"
#include "CarteFictiune.h"
#include "CarteTehnica.h"
#include "UtilizatorStudent.h"
#include "Exceptii.h"

using namespace std;

void testAdaugareCarte() {
    Biblioteca b("Test");
    CarteFictiune* c = new CarteFictiune(
        "Test Carte", "Test Autor", "123-456", 
        2020, "Noua", 14, 2, "Raft A1", "Fantasy", 12
    );
    b.adaugaCarte(c);
    cout << "[PASS] testAdaugareCarte" << endl;
}

void testStatusCarte() {
    CarteFictiune c(
        "Test", "Autor", "123", 
        2020, "Noua", 14, 2, "Raft A1", "Fantasy", 12
    );
    assert(c.getStatus() == "Disponibila");
    c.setStatus("Imprumutata");
    assert(c.getStatus() == "Imprumutata");
    cout << "[PASS] testStatusCarte" << endl;
}

void testStatusInvalidCarte() {
    CarteFictiune c(
        "Test", "Autor", "123", 
        2020, "Noua", 14, 2, "Raft A1", "Fantasy", 12
    );
    c.setStatus("StatusInvalid");
    assert(c.getStatus() == "Disponibila");
    cout << "[PASS] testStatusInvalidCarte" << endl;
}

void testAdaugareUtilizator() {
    Biblioteca b("Test");
    UtilizatorStudent* u = new UtilizatorStudent(
        "Baltei", "Marian", 1,
        "marian@email.com", "0712345678",
        "Facultatea de Informatica", 2, "12345"
    );
    b.adaugaUtilizator(u);
    cout << "[PASS] testAdaugareUtilizator" << endl;
}

void testImprumutCarte() {
    Biblioteca b("Test");
    CarteFictiune* c = new CarteFictiune(
        "Test", "Autor", "111",
        2020, "Noua", 14, 2, "Raft A1", "Fantasy", 12
    );
    UtilizatorStudent* u = new UtilizatorStudent(
        "Baltei", "Marian", 1,
        "marian@email.com", "0712345678",
        "Informatica", 2, "12345"
    );
    b.adaugaCarte(c);
    b.adaugaUtilizator(u);
    b.imprumutaCarte(1, 111);
    assert(c->getStatus() == "Imprumutata");
    cout << "[PASS] testImprumutCarte" << endl;
}

void testExceptieCarteIndisponibila() {
    Biblioteca b("Test");
    CarteFictiune* c = new CarteFictiune(
        "Test", "Autor", "222",
        2020, "Noua", 14, 2, "Raft A1", "Fantasy", 12
    );
    UtilizatorStudent* u = new UtilizatorStudent(
        "Baltei", "Marian", 2,
        "marian@email.com", "0712345678",
        "Informatica", 2, "12345"
    );
    b.adaugaCarte(c);
    b.adaugaUtilizator(u);
    b.imprumutaCarte(2, 222);
    
    try {
        b.imprumutaCarte(2, 222);
        assert(false); // nu trebuia sa ajunga aici
    } catch (CarteIndisponibila& e) {
        cout << "[PASS] testExceptieCarteIndisponibila" << endl;
    }
}

void testDepozit() {
    Depozit<int> d;
    d.adauga(1);
    d.adauga(2);
    d.adauga(3);
    assert(d.dimensiune() == 3);
    assert(d.get(0) == 1);
    d.elimina(0);
    assert(d.dimensiune() == 2);
    assert(d.get(0) == 2);
    cout << "[PASS] testDepozit" << endl;
}

int main() {
    cout << "\n=== Rulare Teste Unitare ===" << endl;
    testAdaugareCarte();
    testStatusCarte();
    testStatusInvalidCarte();
    testAdaugareUtilizator();
    testImprumutCarte();
    testExceptieCarteIndisponibila();
    testDepozit();
    cout << "\nToate testele au trecut cu succes! ✓" << endl;
    return 0;
}