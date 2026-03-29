#ifndef CARTEFICTIUNE_H
#define CARTEFICTIUNE_H

#include "CarteFizica.h"

class CarteFictiune : public CarteFizica {
private:
    std::string gen;          // Fantasy, Thriller, Romance, etc.
    int varstaminima;         // varsta minima recomandata

public:
    CarteFictiune(std::string titlu, std::string autor, std::string ISBN,
                  int anAparitie, std::string stare, int timpImprumut,
                  int nrExemplare, std::string localizare,
                  std::string gen, int varstaminima);

    std::string getGen() const;
    int getVarstaMinima() const;

    void afisareDetalii() const override;

    virtual ~CarteFictiune() {}
};

#endif