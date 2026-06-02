#ifndef CARTERARA_H
#define CARTERARA_H

#include "CarteFizica.h"

class CarteRara : public CarteFizica {
private:
    int anEstimat;        // anul estimat al manuscrisului
    std::string origine;  // de unde provine (ex: "Biblioteca Nationala")
    bool esteManuscris;   // manuscris sau carte rara tiparita

public:
    CarteRara(std::string titlu, std::string autor, std::string ISBN,
              int anAparitie, std::string stare, int timpImprumut,
              int nrExemplare, std::string localizare,
              int anEstimat, std::string origine, bool esteManuscris);

    int getAnEstimat() const;
    std::string getOrigine() const;
    bool getEsteManuscris() const;
    std::string getTipCarte() const override { return "CarteRara"; }
    // O carte rara NU poate fi imprumutata
    bool poateFiImprumutata() const { return false; }

    void afisareDetalii() const override;

    virtual ~CarteRara() {}
};

#endif