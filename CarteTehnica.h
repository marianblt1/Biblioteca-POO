#ifndef CARTETEHNICA_H
#define CARTETEHNICA_H

#include "CarteFizica.h"

class CarteTehnica : public CarteFizica {
private:
    std::string domeniu;          // Informatica, Matematica, Fizica, etc.
    std::string nivelDificultate; // Incepator / Intermediar / Avansat

public:
    CarteTehnica(std::string titlu, std::string autor, std::string ISBN,
                 int anAparitie, std::string stare, int timpImprumut,
                 int nrExemplare, std::string localizare,
                 std::string domeniu, std::string nivelDificultate);

    std::string getDomeniu() const;
    std::string getNivelDificultate() const;

    void afisareDetalii() const override;

    virtual ~CarteTehnica() {}
};
#endif