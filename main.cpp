#include <iostream>
#include "Biblioteca.h"
#include "CarteFictiune.h"
#include "CarteTehnica.h"
#include "CarteDigitala.h"
#include "Revista.h"
#include "UtilizatorStudent.h"
#include "UtilizatorElev.h"
#include "UtilizatorProfesor.h"

using namespace std;

int main() {
    // Cream biblioteca
    Biblioteca biblioteca("Biblioteca Centrala");

    // Cream cateva carti
    CarteFictiune* c1 = new CarteFictiune(
        "Morometii", "Marin Preda", "978-973-46-0001",
        1955, "Buna", 14, 3, "Raft A1", "Roman", 14
    );

    CarteTehnica* c2 = new CarteTehnica(
        "Programare in C++", "aladin Aladin", "978-973-46-0002",
        2000, "Noua", 30, 2, "Raft B2", "informatica", "avansat"
    );

    CarteDigitala* c3 = new CarteDigitala(
        "Design Patterns", "Gang of Four", "978-973-46-0003",
        1994, "Noua", 14, "PDF", 15.5
    );

    Revista* c4 = new Revista(
        "National Geographic", "Nu stiu", "978-973-46-0004",
        2024, "Noua", 7, 101, "Lunara"
    );

    // Adaugam cartile in biblioteca
    biblioteca.adaugaCarte(c1);
    biblioteca.adaugaCarte(c2);
    biblioteca.adaugaCarte(c3);
    biblioteca.adaugaCarte(c4);

    // Cream cateva utilizatori
    UtilizatorStudent* u1 = new UtilizatorStudent(
        "Baltei", "Marian", 1,
        "marian@email.com", "0748595870",
        "Facultatea de Informatica", 2, "12345"
    );

    UtilizatorProfesor* u2 = new UtilizatorProfesor(
        "Ionescu", "Alexandru", 2,
        "ionescu@email.com", "0723456789",
        "Informatica", "Universitatea de Vest"
    );

    // Adaugam utilizatorii
    biblioteca.adaugaUtilizator(u1);
    biblioteca.adaugaUtilizator(u2);

    // Afisam inventarul
    biblioteca.afisareCarti();
    biblioteca.afisareUtilizatori();

    return 0;
}