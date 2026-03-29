#ifndef UTILIZATOR_H
#define UTILIZATOR_H

#include <string>
#include <vector>
#include <iostream>

class Utilizator {
private:
    std::string nume;
    std::string prenume;
    int id;
    std::string email;
    std::string telefon;
    std::string status;      // Activ / Penalizat / Suspendat
    int cartiActive;         // numarul de carti imprumutate in prezent
    std::vector<int> listaImprumuturi;  // ID-urile cartilor imprumutate

public:
    Utilizator(std::string nume, std::string prenume, int id,
               std::string email, std::string telefon);

    // Getteri
    std::string getNume() const;
    std::string getPrenume() const;
    int getId() const;
    std::string getEmail() const;
    std::string getTelefon() const;
    std::string getStatus() const;
    int getCartiActive() const;
    std::vector<int> getListaImprumuturi() const;

    // Setteri
    void setStatus(std::string status);
    void adaugaImprumut(int idCarte);
    void eliminaImprumut(int idCarte);

    // Metoda virtuala
    virtual void afisareDetalii() const;

    virtual ~Utilizator() {}
};
#endif