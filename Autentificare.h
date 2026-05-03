#ifndef AUTENTIFICARE_H
#define AUTENTIFICARE_H

#include <string>
#include <fstream>
#include <iostream>

class Autentificare {
private:
    static const char CHEIE = 'K';  // cheia de criptare XOR

    static std::string cripteaza(std::string text);
    static bool fisierExista(std::string numeFisier);

public:
    static void inregistrare(std::string username, std::string parola, std::string tip);
    static bool login(std::string username, std::string parola, std::string& tipUtilizator);
    static bool usernameExista(std::string username);
};

#endif