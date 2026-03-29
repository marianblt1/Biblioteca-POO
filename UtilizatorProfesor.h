// UtilizatorProfesor.h
#ifndef UTILIZATORPROFESOR_H
#define UTILIZATORPROFESOR_H

#include "Utilizator.h"

class UtilizatorProfesor : public Utilizator {
private:
    std::string materie;
    std::string institutie;

public:
    UtilizatorProfesor(std::string nume, std::string prenume, int id,
                       std::string email, std::string telefon,
                       std::string materie, std::string institutie);

    std::string getMaterie() const;
    std::string getInstitutie() const;

    void afisareDetalii() const override;

    virtual ~UtilizatorProfesor() {}
};
#endif