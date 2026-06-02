#include <iostream>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ofstream date("date.txt");
    
    string titluriF[] = {"Morometii", "Ion", "Enigma Otiliei", "Baltagul", "Maitreyi", 
                         "Padurea Spanzuratilor", "Ultima noapte", "Cel mai iubit", 
                         "Groapa", "Cronos"};
    string autoriF[] = {"Marin Preda", "Liviu Rebreanu", "G. Calinescu", "Mihail Sadoveanu",
                        "Mircea Eliade", "Liviu Rebreanu", "Camil Petrescu", "Marin Preda",
                        "Eugen Barbu", "Ion Pop"};
    string titluriT[] = {"C++ Modern", "Algoritmi", "Structuri de Date", "Python Pro",
                         "Java Advanced", "Machine Learning", "Linux Administration",
                         "Database Design", "Network Security", "Cloud Computing"};
    string autoriT[] = {"Stroustrup", "Cormen", "Knuth", "Lutz", "Bloch",
                        "Mitchell", "Nemeth", "Date", "Stallings", "Armbrust"};
    string domenii[] = {"Informatica", "Matematica", "Fizica", "Chimie", "Biologie",
                        "Electronica", "Robotica", "Inteligenta Artificiala", "Retele", "Securitate"};
    string stari[] = {"Noua", "Buna", "Uzata"};
    string rafturi[] = {"A1", "A2", "A3", "B1", "B2", "B3", "C1", "C2", "C3", 
                        "D1", "D2", "D3", "E1", "E2", "E3", "F1", "F2", "F3",
                        "G1", "G2", "G3", "H1", "H2", "H3"};

    int idx = 0;

    // 150 carti fictiune
    for (int i = 0; i < 150; i++) {
        string isbn = "97897300" + to_string(10000 + i);
        string titlu = titluriF[i % 10] + " Vol." + to_string(i/10 + 1);
        string autor = autoriF[i % 10];
        string stare = stari[i % 3];
        string raft = rafturi[i % 24];
        int an = 1950 + (i % 70);
        int timp = 14 + (i % 3) * 7;
        int nrEx = 1 + (i % 5);
        date << "CarteFizica|" << titlu << "|" << autor << "|" << isbn << "|"
             << an << "|" << stare << "|" << timp << "|" << nrEx << "|" << raft << "|Disponibila\n";
        idx++;
    }

    // 150 carti tehnice
    for (int i = 0; i < 150; i++) {
        string isbn = "97897301" + to_string(10000 + i);
        string titlu = titluriT[i % 10] + " Ed." + to_string(i/10 + 1);
        string autor = autoriT[i % 10];
        string stare = stari[i % 3];
        string raft = rafturi[i % 24];
        int an = 1990 + (i % 30);
        int timp = 30;
        int nrEx = 1 + (i % 3);
        date << "CarteFizica|" << titlu << "|" << autor << "|" << isbn << "|"
             << an << "|" << stare << "|" << timp << "|" << nrEx << "|" << raft << "|Disponibila\n";
        idx++;
    }

    // 100 carti digitale
    for (int i = 0; i < 100; i++) {
        string isbn = "97897302" + to_string(10000 + i);
        string titlu = "eBook " + titluriT[i % 10] + " " + to_string(i + 1);
        string autor = autoriT[i % 10];
        string raft = rafturi[i % 24];
        int an = 2000 + (i % 20);
        int timp = 14;
        int nrEx = 1 + (i % 10);
        date << "CarteFizica|" << titlu << "|" << autor << "|" << isbn << "|"
             << an << "|Noua|" << timp << "|" << nrEx << "|" << raft << "|Disponibila\n";
        idx++;
    }

    // 80 reviste
    for (int i = 0; i < 80; i++) {
        string isbn = "97897303" + to_string(10000 + i);
        string titlu = "Revista " + domenii[i % 10] + " Nr." + to_string(i + 1);
        string stare = stari[i % 3];
        string raft = rafturi[i % 24];
        int an = 2010 + (i % 14);
        int nrEx = 1 + (i % 8);
        date << "CarteFizica|" << titlu << "|Redactia|" << isbn << "|"
             << an << "|" << stare << "|7|" << nrEx << "|" << raft << "|Disponibila\n";
        idx++;
    }

    // 20 carti rare
    for (int i = 0; i < 20; i++) {
        string isbn = "97897304" + to_string(10000 + i);
        string titlu = "Manuscris Vechi " + to_string(i + 1);
        string autor = "Autor Necunoscut " + to_string(i + 1);
        string raft = rafturi[i % 24];
        int an = 1800 + (i * 5);
        date << "CarteRara|" << titlu << "|" << autor << "|" << isbn << "|"
             << an << "|Uzata|0|1|" << raft << "|Doar in sala\n";
        idx++;
    }

    date.close();
    cout << "Generat " << idx << " carti in date.txt" << endl;

    // Generam utilizatori
    ofstream util("utilizatori.dat");
    string parola = "parola123";
    string parolaCriptata = parola;
    for (size_t i = 0; i < parola.size(); i++) {
        parolaCriptata[i] = parola[i] ^ 'K';
    }

    util << "admin," << parolaCriptata << ",staff\n";
    util << "ionescu," << parolaCriptata << ",staff\n";
    util << "popescu," << parolaCriptata << ",normal\n";
    util << "marian," << parolaCriptata << ",normal\n";
    util << "andreea," << parolaCriptata << ",normal\n";
    util << "george," << parolaCriptata << ",normal\n";
    util << "elena," << parolaCriptata << ",normal\n";
    util << "stefan," << parolaCriptata << ",normal\n";
    util << "ana," << parolaCriptata << ",normal\n";
    util << "bogdan," << parolaCriptata << ",staff\n";
    util.close();

    cout << "Generat 10 utilizatori in utilizatori.dat" << endl;
    cout << "Parola pentru toti: parola123" << endl;

    return 0;
}