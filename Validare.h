#ifndef VALIDARE_H
#define VALIDARE_H

#include <string>
#include <iostream>

class Validare {
public:
    static bool localizare(const std::string& loc) {
        if (loc.size() != 2) return false;
        char litera = loc[0];
        char numar = loc[1];
        return (litera >= 'A' && litera <= 'H') && (numar >= '1' && numar <= '3');
    }

    static bool ISBN(const std::string& isbn) {
        if (isbn.size() != 10 && isbn.size() != 13) return false;
        for (char c : isbn) {
            if (!isdigit(c)) return false;
        }
        return true;
    }

    static bool timpImprumut(int timp) {
        return timp >= 1 && timp <= 90;
    }

    static int citesteInt(const std::string& mesaj) {
    int valoare;
    while (true) {
        std::cout << mesaj;
        if (std::cin >> valoare) {
            std::cin.ignore();
            return valoare;
        } else {
            std::cout << "Input invalid! Introduceti un numar!" << std::endl;
            std::cin.clear();
            std::cin.ignore(1000, '\n');
        }
    }
}

};

#endif