#ifndef DEPOZIT_H
#define DEPOZIT_H

#include <vector>
#include <iostream>

template <typename T>
class Depozit {
private:
    std::vector<T> elemente;

public:
    void adauga(T element) {
        elemente.push_back(element);
    }

    void elimina(int index) {
        if (index >= 0 && index < (int)elemente.size()) {
            elemente.erase(elemente.begin() + index);
        }
    }

    T get(int index) const {
        return elemente[index];
    }

    int dimensiune() const {
        return elemente.size();
    }

    bool esteGol() const {
        return elemente.empty();
    }

    void afisareTot() const {
        for (size_t i = 0; i < elemente.size(); i++) {
            elemente[i]->afisareDetalii();
        }
    }
};

#endif