#ifndef CARTEDIGITALA_H
#define CARTEDIGITALA_H

#include "Carte.h"

class CarteDigitala : public Carte {
private:
    std::string format;      // PDF, EPUB, MOBI
    float marimeFisier;      // in MB

public:
    CarteDigitala(std::string titlu, std::string autor, std::string ISBN,
                  int anAparitie, std::string stare, int timpImprumut,
                  std::string format, float marimeFisier);

    std::string getFormat() const;
    float getMarimeFisier() const;

    void afisareDetalii() const override;

    virtual ~CarteDigitala() {}
};
#endif