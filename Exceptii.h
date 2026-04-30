#ifndef EXCEPTII_H
#define EXCEPTII_H

#include <exception>
#include <string>

class CarteIndisponibila : public std::exception {
private:
    std::string mesaj;
public:
    CarteIndisponibila(std::string titlu) {
        mesaj = "Cartea '" + titlu + "' nu e disponibila, sorry!";
    }
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class CarteNegasita : public std::exception {
private:
    std::string mesaj;
public:
    CarteNegasita(std::string isbn) {
        mesaj = "Cartea cu ISBN '" + isbn + "' nu a fost gasita!";
    }
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class UtilizatorNegasit : public std::exception {
private:
    std::string mesaj;
public:
    UtilizatorNegasit(int id) {
        mesaj = "Utilizatorul cu ID '" + std::to_string(id) + "' nu a fost gasit!";
    }
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

class UtilizatorSuspendat : public std::exception {
private:
    std::string mesaj;
public:
    UtilizatorSuspendat(std::string nume) {
        mesaj = "Utilizatorul '" + nume + "' este suspendat si nu poate imprumuta carti!";
    }
    const char* what() const noexcept override {
        return mesaj.c_str();
    }
};

#endif