#include <iostream>
#include "Biblioteca.h"
#include "Meniu.h"

using namespace std;

int main() {
    Biblioteca biblioteca("Biblioteca Centrala");
    Meniu meniu(biblioteca);
    meniu.ruleaza();
    return 0;
}