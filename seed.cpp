#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Carte {
    string tipCarte, tipAfisat, titlu, autor, isbn;
    int an;
    string stare;
    int timpImprumut, nrExemplare;
    string localizare;
};

int main() {
    vector<Carte> carti = {
        // FICTIUNE ROMANA
        {"CarteFizica","FICTIUNE","Ion Vol.1","Liviu Rebreanu","9789736899614",1920,"Buna",21,8,"A1"},
        {"CarteFizica","FICTIUNE","Ion Vol.2","Liviu Rebreanu","9789736899621",1920,"Buna",21,7,"A1"},
        {"CarteFizica","FICTIUNE","Morometii Vol.1","Marin Preda","9789733606123",1955,"Buna",21,12,"A2"},
        {"CarteFizica","FICTIUNE","Morometii Vol.2","Marin Preda","9789733606130",1967,"Buna",21,10,"A2"},
        {"CarteFizica","FICTIUNE","Enigma Otiliei","George Calinescu","9789736899638",1938,"Buna",21,15,"A2"},
        {"CarteFizica","FICTIUNE","Padurea Spanzuratilor","Liviu Rebreanu","9789736899645",1922,"Uzata",21,6,"A3"},
        {"CarteFizica","FICTIUNE","Baltagul","Mihail Sadoveanu","9789733606147",1930,"Buna",21,9,"A3"},
        {"CarteFizica","FICTIUNE","Maitreyi","Mircea Eliade","9789733606154",1933,"Buna",21,11,"B1"},
        {"CarteFizica","FICTIUNE","Ultima Noapte de Dragoste","Camil Petrescu","9789733606161",1930,"Buna",21,10,"B1"},
        {"CarteFizica","FICTIUNE","Cel Mai Iubit Vol.1","Marin Preda","9789733606178",1980,"Buna",21,8,"B2"},
        {"CarteFizica","FICTIUNE","Cel Mai Iubit Vol.2","Marin Preda","9789733606185",1980,"Buna",21,8,"B2"},
        {"CarteFizica","FICTIUNE","Cel Mai Iubit Vol.3","Marin Preda","9789733606192",1980,"Uzata",21,6,"B2"},
        {"CarteFizica","FICTIUNE","Groapa","Eugen Barbu","9789733606209",1957,"Uzata",21,5,"B3"},
        {"CarteFizica","FICTIUNE","Craii de Curtea-Veche","Mateiu Caragiale","9789733606223",1929,"Buna",21,7,"B3"},
        {"CarteFizica","FICTIUNE","Harap-Alb","Ion Creanga","9789733606216",1877,"Buna",14,20,"C1"},
        // FICTIUNE INTERNATIONALA
        {"CarteFizica","FICTIUNE","1984","George Orwell","9780451524935",1949,"Buna",21,25,"C1"},
        {"CarteFizica","FICTIUNE","Ferma Animalelor","George Orwell","9780451526342",1945,"Buna",21,20,"C2"},
        {"CarteFizica","FICTIUNE","Stapanul Inelelor: Fratia Inelului","J.R.R. Tolkien","9780261102354",1954,"Buna",21,30,"C2"},
        {"CarteFizica","FICTIUNE","Stapanul Inelelor: Cele Doua Turnuri","J.R.R. Tolkien","9780261102361",1954,"Buna",21,30,"C2"},
        {"CarteFizica","FICTIUNE","Stapanul Inelelor: Intoarcerea Regelui","J.R.R. Tolkien","9780261102378",1955,"Buna",21,28,"C3"},
        {"CarteFizica","FICTIUNE","Hobbitul","J.R.R. Tolkien","9780261102385",1937,"Buna",21,35,"C3"},
        {"CarteFizica","FICTIUNE","Dune","Frank Herbert","9780441172719",1965,"Buna",21,18,"D1"},
        {"CarteFizica","FICTIUNE","Dune Messiah","Frank Herbert","9780441172726",1969,"Buna",21,12,"D1"},
        {"CarteFizica","FICTIUNE","Harry Potter si Piatra Filozofala","J.K. Rowling","9789731800370",1997,"Buna",21,40,"D1"},
        {"CarteFizica","FICTIUNE","Harry Potter si Camera Secretelor","J.K. Rowling","9789731800387",1998,"Buna",21,38,"D2"},
        {"CarteFizica","FICTIUNE","Harry Potter si Prizonierul din Azkaban","J.K. Rowling","9789731800394",1999,"Buna",21,35,"D2"},
        {"CarteFizica","FICTIUNE","Harry Potter si Pocalul de Foc","J.K. Rowling","9789731800400",2000,"Buna",21,33,"D2"},
        {"CarteFizica","FICTIUNE","Harry Potter si Ordinul Phoenix","J.K. Rowling","9789731800417",2003,"Buna",21,30,"D3"},
        {"CarteFizica","FICTIUNE","Harry Potter si Printul Semipur","J.K. Rowling","9789731800424",2005,"Buna",21,28,"D3"},
        {"CarteFizica","FICTIUNE","Harry Potter si Talismanele Mortii","J.K. Rowling","9789731800431",2007,"Noua",21,25,"D3"},
        {"CarteFizica","FICTIUNE","Crima si Pedeapsa","F. Dostoevsky","9789733606230",1866,"Buna",21,15,"E1"},
        {"CarteFizica","FICTIUNE","Fratii Karamazov","F. Dostoevsky","9789733606254",1880,"Buna",21,10,"E1"},
        {"CarteFizica","FICTIUNE","Razboi si Pace Vol.1","Leo Tolstoy","9789733606261",1869,"Buna",21,12,"E2"},
        {"CarteFizica","FICTIUNE","Razboi si Pace Vol.2","Leo Tolstoy","9789733606278",1869,"Buna",21,10,"E2"},
        {"CarteFizica","FICTIUNE","Anna Karenina","Leo Tolstoy","9789733606285",1877,"Buna",21,14,"E2"},
        {"CarteFizica","FICTIUNE","Marele Gatsby","F.S. Fitzgerald","9780743273565",1925,"Buna",21,20,"E3"},
        {"CarteFizica","FICTIUNE","Sa Ucizi o Pasarica","Harper Lee","9780061935466",1960,"Buna",21,18,"E3"},
        {"CarteFizica","FICTIUNE","O Suta de Ani de Singuratate","G.G. Marquez","9789733606292",1967,"Buna",21,15,"F1"},
        {"CarteFizica","FICTIUNE","Maestrul si Margareta","M. Bulgakov","9789733606308",1967,"Buna",21,12,"F1"},
        {"CarteFizica","FICTIUNE","Procesul","Franz Kafka","9789733606315",1925,"Buna",21,10,"F1"},
        {"CarteFizica","FICTIUNE","Minunata Lume Noua","Aldous Huxley","9789733606329",1932,"Buna",21,14,"F2"},
        // TEHNICA
        {"CarteFizica","TEHNICA","C++ Primer (5th Ed.)","Stanley Lippman","9780321714114",2012,"Buna",30,8,"G1"},
        {"CarteFizica","TEHNICA","Clean Code","Robert C. Martin","9780132350884",2008,"Buna",30,10,"G1"},
        {"CarteFizica","TEHNICA","Design Patterns","Gang of Four","9780201633610",1994,"Buna",30,6,"G2"},
        {"CarteFizica","TEHNICA","The Pragmatic Programmer","David Thomas","9780135957059",2019,"Noua",30,8,"G2"},
        {"CarteFizica","TEHNICA","Introduction to Algorithms","T.H. Cormen","9780262033848",2009,"Buna",30,5,"G2"},
        {"CarteFizica","TEHNICA","Computer Networks","A. Tanenbaum","9780132126953",2010,"Buna",30,7,"G3"},
        {"CarteFizica","TEHNICA","Operating System Concepts","A. Silberschatz","9781119800361",2018,"Buna",30,6,"G3"},
        {"CarteFizica","TEHNICA","Database System Concepts","A. Silberschatz","9780078022159",2019,"Noua",30,5,"H1"},
        {"CarteFizica","TEHNICA","AI: A Modern Approach","Stuart Russell","9780136042594",2020,"Noua",30,4,"H1"},
        {"CarteFizica","TEHNICA","Python Crash Course","Eric Matthes","9781593279288",2019,"Noua",30,12,"H1"},
        {"CarteFizica","TEHNICA","Algebra Liniara","Gh. Morosanu","9789731234578",2005,"Buna",30,10,"H2"},
        {"CarteFizica","TEHNICA","Matematica Discreta","Ioan Tomescu","9789731234585",2008,"Buna",30,9,"H2"},
        {"CarteFizica","TEHNICA","Retele de Calculatoare","Vlad Muntean","9789731234592",2015,"Noua",30,7,"H3"},
        // STIINTA
        {"CarteFizica","STIINTA","O Scurta Istorie a Timpului","Stephen Hawking","9780553380163",1988,"Buna",21,10,"F3"},
        {"CarteFizica","STIINTA","Cosmos","Carl Sagan","9780345331359",1980,"Uzata",21,7,"F3"},
        {"CarteFizica","STIINTA","Sapiens","Yuval Noah Harari","9780062316097",2011,"Noua",21,15,"F3"},
        {"CarteFizica","STIINTA","Homo Deus","Yuval Noah Harari","9780062464347",2015,"Noua",21,12,"G1"},
        {"CarteFizica","STIINTA","Gena Egoista","Richard Dawkins","9780198788607",1976,"Buna",21,8,"G2"},
        // REVISTE
        {"Revista","REVISTA","Dilema Veche Nr.1000","Redactia Dilema","9771220304001",2023,"Noua",7,5,"A1"},
        {"Revista","REVISTA","Romania Literara Nr.50","Redactia RL","9771015899050",2023,"Noua",7,3,"A2"},
        {"Revista","REVISTA","Scientific American - Ed.Speciala","Redactia SA","9781948933094",2023,"Noua",7,4,"F3"},
        {"Revista","REVISTA","Nature Vol.600","Nature Publishing","9780028661056",2022,"Buna",7,3,"H3"},
        // DIGITALE
        {"CarteDigitala","DIGITALA","Clean Architecture","Robert C. Martin","9780134494166",2017,"Noua",14,999,"DIGITAL"},
        {"CarteDigitala","DIGITALA","Atomic Habits","James Clear","9780735211292",2018,"Noua",14,999,"DIGITAL"},
        {"CarteDigitala","DIGITALA","The Phoenix Project","Gene Kim","9781942788294",2013,"Noua",14,999,"DIGITAL"},
        // RARE
        {"CarteRara","RARA","Psaltirea in Versuri","Dosoftei","RON-RARE-001",1673,"Deteriorata",0,1,"SALA-RARA"},
        {"CarteRara","RARA","Biblia de la Blaj","Samuil Micu","RON-RARE-002",1795,"Uzata",0,1,"SALA-RARA"},
        {"CarteRara","RARA","Letopisetul Tarii Moldovei","Grigore Ureche","RON-RARE-003",1640,"Deteriorata",0,1,"SALA-RARA"},
    };

    ofstream date("date.txt");
    for (auto& c : carti) {
        date << c.tipCarte << "|" << c.tipAfisat << "|" << c.titlu << "|"
             << c.autor << "|" << c.isbn << "|" << c.an << "|" << c.stare << "|"
             << c.timpImprumut << "|" << c.nrExemplare << "|" << c.nrExemplare << "|"
             << c.localizare << "\n";
    }
    date.close();

    ofstream exFile("exemplare.txt");
    int exCounter = 1;
    for (auto& c : carti) {
        if (c.nrExemplare >= 999) {
            exFile << "EX-DIGITAL|" << c.isbn << "|Disponibil|\n";
            continue;
        }
        for (int i = 0; i < c.nrExemplare; i++) {
            string num = to_string(exCounter++);
            while ((int)num.length() < 5) num = "0" + num;
            exFile << "EX-" << num << "|" << c.isbn << "|Disponibil|\n";
        }
    }
    exFile.close();

    ofstream util("utilizatori.dat");
    string parola = "parola123";
    string pc = parola;
    for (size_t i = 0; i < parola.size(); i++) pc[i] = parola[i] ^ 'K';
    util << "admin," << pc << ",staff\n";
    util << "ionescu," << pc << ",staff\n";
    util << "bogdan," << pc << ",staff\n";
    util << "popescu," << pc << ",normal\n";
    util << "marian," << pc << ",normal\n";
    util << "andreea," << pc << ",normal\n";
    util << "george," << pc << ",normal\n";
    util << "elena," << pc << ",normal\n";
    util << "stefan," << pc << ",normal\n";
    util << "ana," << pc << ",normal\n";
    util.close();

    cout << "Generat " << carti.size() << " titluri in date.txt" << endl;
    cout << "Generat exemplare in exemplare.txt" << endl;
    cout << "Generat 10 utilizatori in utilizatori.dat" << endl;
    cout << "Parola pentru toti: parola123" << endl;
    return 0;
}