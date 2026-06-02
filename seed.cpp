#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

struct Carte {
    string tip, tipAf, titlu, autor, isbn;
    int an;
    string stare;
    int timp, ex;
    string raft;
};

int main() {
    vector<Carte> v;
    
    // Carti reale
    v.push_back({"CarteFizica","FICTIUNE","Ion Vol.1","Liviu Rebreanu","9789736899614",1920,"Buna",21,8,"A1"});
    v.push_back({"CarteFizica","FICTIUNE","Ion Vol.2","Liviu Rebreanu","9789736899621",1920,"Buna",21,7,"A2"});
    v.push_back({"CarteFizica","FICTIUNE","Morometii Vol.1","Marin Preda","9789733606123",1955,"Buna",21,12,"A2"});
    v.push_back({"CarteFizica","FICTIUNE","Morometii Vol.2","Marin Preda","9789733606130",1967,"Buna",21,10,"A3"});
    v.push_back({"CarteFizica","FICTIUNE","Enigma Otiliei","George Calinescu","9789736899638",1938,"Buna",21,15,"B1"});
    v.push_back({"CarteFizica","FICTIUNE","Padurea Spanzuratilor","Liviu Rebreanu","9789736899645",1922,"Uzata",21,6,"B1"});
    v.push_back({"CarteFizica","FICTIUNE","Baltagul","Mihail Sadoveanu","9789733606147",1930,"Buna",21,9,"B2"});
    v.push_back({"CarteFizica","FICTIUNE","Maitreyi","Mircea Eliade","9789733606154",1933,"Buna",21,11,"B2"});
    v.push_back({"CarteFizica","FICTIUNE","Ultima Noapte de Dragoste","Camil Petrescu","9789733606161",1930,"Buna",21,10,"B3"});
    v.push_back({"CarteFizica","FICTIUNE","1984","George Orwell","9780451524935",1949,"Buna",21,25,"C1"});
    v.push_back({"CarteFizica","FICTIUNE","Ferma Animalelor","George Orwell","9780451526342",1945,"Buna",21,20,"C1"});
    v.push_back({"CarteFizica","FICTIUNE","Stapanul Inelelor: Fratia Inelului","J.R.R. Tolkien","9780261102354",1954,"Buna",21,30,"C2"});
    v.push_back({"CarteFizica","FICTIUNE","Stapanul Inelelor: Cele Doua Turnuri","J.R.R. Tolkien","9780261102361",1954,"Buna",21,30,"C2"});
    v.push_back({"CarteFizica","FICTIUNE","Stapanul Inelelor: Intoarcerea Regelui","J.R.R. Tolkien","9780261102378",1955,"Buna",21,28,"C3"});
    v.push_back({"CarteFizica","FICTIUNE","Hobbitul","J.R.R. Tolkien","9780261102385",1937,"Buna",21,35,"C3"});
    v.push_back({"CarteFizica","FICTIUNE","Harry Potter si Piatra Filozofala","J.K. Rowling","9789731800370",1997,"Buna",21,40,"D1"});
    v.push_back({"CarteFizica","FICTIUNE","Harry Potter si Camera Secretelor","J.K. Rowling","9789731800387",1998,"Buna",21,38,"D1"});
    v.push_back({"CarteFizica","FICTIUNE","Harry Potter si Prizonierul din Azkaban","J.K. Rowling","9789731800394",1999,"Buna",21,35,"D2"});
    v.push_back({"CarteFizica","FICTIUNE","Harry Potter si Pocalul de Foc","J.K. Rowling","9789731800400",2000,"Buna",21,33,"D2"});
    v.push_back({"CarteFizica","FICTIUNE","Harry Potter si Ordinul Phoenix","J.K. Rowling","9789731800417",2003,"Buna",21,30,"D3"});
    v.push_back({"CarteFizica","FICTIUNE","Harry Potter si Printul Semipur","J.K. Rowling","9789731800424",2005,"Buna",21,28,"D3"});
    v.push_back({"CarteFizica","FICTIUNE","Harry Potter si Talismanele Mortii","J.K. Rowling","9789731800431",2007,"Noua",21,25,"E1"});
    v.push_back({"CarteFizica","FICTIUNE","Crima si Pedeapsa","F. Dostoevsky","9789733606230",1866,"Buna",21,15,"E1"});
    v.push_back({"CarteFizica","FICTIUNE","Fratii Karamazov","F. Dostoevsky","9789733606254",1880,"Buna",21,10,"E2"});
    v.push_back({"CarteFizica","FICTIUNE","Idiotul","F. Dostoevsky","9789733606261",1869,"Buna",21,9,"E2"});
    v.push_back({"CarteFizica","FICTIUNE","Razboi si Pace Vol.1","Leo Tolstoy","9789733606275",1869,"Buna",21,12,"E3"});
    v.push_back({"CarteFizica","FICTIUNE","Razboi si Pace Vol.2","Leo Tolstoy","9789733606282",1869,"Buna",21,10,"E3"});
    v.push_back({"CarteFizica","FICTIUNE","Anna Karenina","Leo Tolstoy","9789733606299",1877,"Buna",21,14,"F1"});
    v.push_back({"CarteFizica","FICTIUNE","Marele Gatsby","F.S. Fitzgerald","9780743273565",1925,"Buna",21,20,"F1"});
    v.push_back({"CarteFizica","FICTIUNE","Sa Ucizi o Pasarica","Harper Lee","9780061935466",1960,"Buna",21,18,"F2"});
    v.push_back({"CarteFizica","FICTIUNE","O Suta de Ani de Singuratate","G.G. Marquez","9789733606312",1967,"Buna",21,15,"F2"});
    v.push_back({"CarteFizica","FICTIUNE","Maestrul si Margareta","M. Bulgakov","9789733606336",1967,"Buna",21,12,"F3"});
    v.push_back({"CarteFizica","FICTIUNE","Procesul","Franz Kafka","9789733606343",1925,"Buna",21,10,"F3"});
    v.push_back({"CarteFizica","FICTIUNE","Metamorfoza","Franz Kafka","9789733606350",1915,"Buna",21,14,"G1"});
    v.push_back({"CarteFizica","FICTIUNE","Minunata Lume Noua","Aldous Huxley","9789733606367",1932,"Buna",21,14,"G1"});
    v.push_back({"CarteFizica","FICTIUNE","Fahrenheit 451","Ray Bradbury","9781451673319",1953,"Buna",21,16,"G2"});
    v.push_back({"CarteFizica","FICTIUNE","It","Stephen King","9781501156700",1986,"Buna",21,22,"G2"});
    v.push_back({"CarteFizica","FICTIUNE","The Shining","Stephen King","9780385121675",1977,"Buna",21,20,"G3"});
    v.push_back({"CarteFizica","FICTIUNE","Carrie","Stephen King","9780385086950",1974,"Buna",21,18,"G3"});
    v.push_back({"CarteFizica","FICTIUNE","Misery","Stephen King","9780450417399",1987,"Buna",21,15,"H1"});
    v.push_back({"CarteFizica","FICTIUNE","The Stand","Stephen King","9780385121682",1978,"Buna",21,12,"H1"});
    v.push_back({"CarteFizica","FICTIUNE","Doctor Sleep","Stephen King","9781476779072",2013,"Noua",21,14,"H2"});
    v.push_back({"CarteFizica","FICTIUNE","A Game of Thrones","George R.R. Martin","9780553103540",1996,"Buna",21,25,"H2"});
    v.push_back({"CarteFizica","FICTIUNE","A Clash of Kings","George R.R. Martin","9780553108033",1998,"Buna",21,22,"H3"});
    v.push_back({"CarteFizica","FICTIUNE","A Storm of Swords","George R.R. Martin","9780553106633",2000,"Buna",21,20,"H3"});
    v.push_back({"CarteFizica","FICTIUNE","Si nu a mai ramas niciunul","Agatha Christie","9780007136834",1939,"Buna",21,20,"A1"});
    v.push_back({"CarteFizica","FICTIUNE","Crima din Orient Express","Agatha Christie","9780007119318",1934,"Buna",21,22,"A2"});
    v.push_back({"CarteFizica","FICTIUNE","Alchimistul","Paulo Coelho","9789736899508",1988,"Buna",21,30,"A3"});
    v.push_back({"CarteFizica","FICTIUNE","Veronika Decide sa Moara","Paulo Coelho","9789736899515",1998,"Buna",21,22,"B1"});
    v.push_back({"CarteFizica","FICTIUNE","Strainul","Albert Camus","9789733606411",1942,"Buna",21,18,"B2"});
    v.push_back({"CarteFizica","FICTIUNE","Ciuma","Albert Camus","9789733606428",1947,"Buna",21,16,"B3"});
    v.push_back({"CarteFizica","FICTIUNE","Mizerabilii Vol.1","Victor Hugo","9789733606466",1862,"Buna",21,12,"C1"});
    v.push_back({"CarteFizica","FICTIUNE","Mizerabilii Vol.2","Victor Hugo","9789733606473",1862,"Buna",21,11,"C2"});
    v.push_back({"CarteFizica","FICTIUNE","Hamlet","William Shakespeare","9789733606527",1603,"Buna",21,20,"C3"});
    v.push_back({"CarteFizica","FICTIUNE","Romeo si Julieta","William Shakespeare","9789733606534",1597,"Buna",21,22,"D1"});
    v.push_back({"CarteFizica","FICTIUNE","Batranul si Marea","Ernest Hemingway","9780684801223",1952,"Buna",21,18,"D2"});
    v.push_back({"CarteFizica","FICTIUNE","Fructele Maniei","John Steinbeck","9780143039433",1939,"Buna",21,15,"D3"});
    v.push_back({"CarteFizica","FICTIUNE","Codul lui Da Vinci","Dan Brown","9780385504201",2003,"Buna",21,28,"E1"});
    v.push_back({"CarteFizica","FICTIUNE","Ingeri si Demoni","Dan Brown","9780671027360",2000,"Buna",21,24,"E2"});
    v.push_back({"CarteFizica","FICTIUNE","Inferno","Dan Brown","9780385537858",2013,"Noua",21,20,"E3"});
    v.push_back({"CarteFizica","FICTIUNE","Numele Trandafirului","Umberto Eco","9789733606664",1980,"Buna",21,15,"F1"});
    v.push_back({"CarteFizica","FICTIUNE","Norwegian Wood","Haruki Murakami","9780375704024",1987,"Buna",21,18,"F2"});
    v.push_back({"CarteFizica","FICTIUNE","Fundatia","Isaac Asimov","9780553293357",1951,"Buna",21,15,"F3"});
    v.push_back({"CarteFizica","FICTIUNE","2001: O Odisee Spatiala","Arthur C. Clarke","9780451457998",1968,"Buna",21,14,"G1"});
    v.push_back({"CarteFizica","FICTIUNE","Ocolul Pamantului in 80 de Zile","Jules Verne","9789733606732",1872,"Buna",21,18,"G2"});
    v.push_back({"CarteFizica","FICTIUNE","20000 de Leghe sub Mari","Jules Verne","9789733606725",1870,"Buna",21,16,"G3"});
    v.push_back({"CarteFizica","FICTIUNE","Barbati care urasc femeile","Stieg Larsson","9789736899706",2005,"Buna",21,20,"H1"});
    v.push_back({"CarteFizica","FICTIUNE","Insupportabila Usurinta a Fiintei","Milan Kundera","9789733606688",1984,"Buna",21,16,"H2"});
    v.push_back({"CarteFizica","FICTIUNE","Contele de Monte Cristo Vol.1","Alexandre Dumas","9789733606602",1844,"Buna",21,15,"H3"});
    v.push_back({"CarteFizica","FICTIUNE","Contele de Monte Cristo Vol.2","Alexandre Dumas","9789733606619",1844,"Buna",21,14,"A1"});
    v.push_back({"CarteFizica","FICTIUNE","Siddhartha","Hermann Hesse","9789733606596",1922,"Buna",21,14,"A2"});
    v.push_back({"CarteFizica","TEHNICA","C++ Primer 5th Ed.","Stanley Lippman","9780321714114",2012,"Buna",30,8,"A1"});
    v.push_back({"CarteFizica","TEHNICA","Clean Code","Robert C. Martin","9780132350884",2008,"Buna",30,10,"A2"});
    v.push_back({"CarteFizica","TEHNICA","Design Patterns","Gang of Four","9780201633610",1994,"Buna",30,6,"A3"});
    v.push_back({"CarteFizica","TEHNICA","The Pragmatic Programmer","David Thomas","9780135957059",2019,"Noua",30,8,"B1"});
    v.push_back({"CarteFizica","TEHNICA","Introduction to Algorithms","T.H. Cormen","9780262033848",2009,"Buna",30,5,"B2"});
    v.push_back({"CarteFizica","TEHNICA","Python Crash Course","Eric Matthes","9781593279288",2019,"Noua",30,12,"B3"});
    v.push_back({"CarteFizica","TEHNICA","Clean Architecture","Robert C. Martin","9780134494166",2017,"Noua",30,7,"C1"});
    v.push_back({"CarteFizica","STIINTA","O Scurta Istorie a Timpului","Stephen Hawking","9780553380163",1988,"Buna",21,10,"C2"});
    v.push_back({"CarteFizica","STIINTA","Sapiens","Yuval Noah Harari","9780062316097",2011,"Noua",21,15,"C3"});
    v.push_back({"CarteFizica","STIINTA","Homo Deus","Yuval Noah Harari","9780062464347",2015,"Noua",21,12,"D1"});
    v.push_back({"CarteFizica","STIINTA","Cosmos","Carl Sagan","9780345331359",1980,"Uzata",21,7,"D2"});
    v.push_back({"Revista","REVISTA","Dilema Veche Nr.1000","Redactia Dilema","9771220304001",2023,"Noua",7,5,"A1"});
    v.push_back({"Revista","REVISTA","Romania Literara Nr.50","Redactia RL","9771015899050",2023,"Noua",7,3,"A2"});
    v.push_back({"Revista","REVISTA","National Geographic Romania","Nat Geo","9770258890001",2024,"Noua",7,6,"A3"});
    v.push_back({"CarteDigitala","DIGITALA","Atomic Habits","James Clear","9780735211292",2018,"Noua",14,999,"DIGITAL"});
    v.push_back({"CarteDigitala","DIGITALA","Deep Work","Cal Newport","9781455586691",2016,"Noua",14,999,"DIGITAL"});
    v.push_back({"CarteRara","RARA","Psaltirea in Versuri","Dosoftei","RON-RARE-001",1673,"Deteriorata",0,1,"SALA-RARA"});
    v.push_back({"CarteRara","RARA","Biblia de la Blaj","Samuil Micu","RON-RARE-002",1795,"Uzata",0,1,"SALA-RARA"});
    v.push_back({"CarteRara","RARA","Letopisetul Tarii Moldovei","Grigore Ureche","RON-RARE-003",1640,"Deteriorata",0,1,"SALA-RARA"});

    // Generam pana la 2010
    string autori[] = {"Victor Hugo","Charles Dickens","Leo Tolstoy","F. Dostoevsky","Franz Kafka","Albert Camus","Ernest Hemingway","F.S. Fitzgerald","John Steinbeck","Aldous Huxley","George Orwell","Ray Bradbury","Kurt Vonnegut","Jack London","Mark Twain","Oscar Wilde","Thomas Hardy","Jane Austen","Emily Bronte","Charlotte Bronte","Thomas Mann","Hermann Hesse","Stefan Zweig","Gunter Grass","Boris Pasternak","Ivan Turgenev","Anton Chekhov","Maxim Gorky","Gustave Flaubert","Emile Zola","Marcel Proust","Honore de Balzac","Stendhal","Alexandre Dumas","Guy de Maupassant","Antoine de Saint-Exupery","Jorge Luis Borges","Mario Vargas Llosa","Isabel Allende","Naguib Mahfouz","Orhan Pamuk","Haruki Murakami","Yasunari Kawabata","Yukio Mishima","Chinua Achebe","J.M. Coetzee","Toni Morrison","Maya Angelou","William Faulkner","Truman Capote","Umberto Eco","Italo Calvino","Primo Levi","Vladimir Nabokov","Alexander Pushkin","Nikolai Gogol","Milan Kundera","Patrick Modiano","Michel Houellebecq","Marguerite Duras","Colette","Romain Rolland","Andre Gide","Simone de Beauvoir","Federico Garcia Lorca","Pablo Neruda","Carlos Fuentes","Julio Cortazar","Roberto Bolano","Khalil Gibran","Amos Oz","Kenzaburo Oe","Kobo Abe","Soseki Natsume","Samuel Beckett","James Joyce","Oscar Wilde","Bernard Shaw","Dylan Thomas","Graham Greene","Evelyn Waugh","George Bernard Shaw","H.G. Wells","Arthur Conan Doyle","Bram Stoker","Mary Shelley","Jonathan Swift","Daniel Defoe","Henry Fielding","Laurence Sterne","Samuel Richardson","William Thackeray","Anthony Trollope","George Meredith","Thomas Hardy","Joseph Conrad","D.H. Lawrence","Virginia Woolf","E.M. Forster","Aldous Huxley","Christopher Isherwood","Angus Wilson"};
    string rafts[] = {"A1","A2","A3","B1","B2","B3","C1","C2","C3","D1","D2","D3","E1","E2","E3","F1","F2","F3","G1","G2","G3","H1","H2","H3"};
    string stariG[] = {"Noua","Buna","Buna","Buna","Uzata"};
    string tipuriG[] = {"FICTIUNE","FICTIUNE","FICTIUNE","FICTIUNE","FICTIUNE","FICTIUNE","TEHNICA","STIINTA","TEHNICA","REVISTA"};

    int isbnC = 300000;
    int idx = 0;
    while ((int)v.size() < 2010) {
        string autor = autori[idx % 100];
        string isbn = "9780" + to_string(isbnC++);
        string raft = rafts[idx % 24];
        string stare = stariG[idx % 5];
        int an = 1850 + (idx % 170);
        int ex = 3 + (idx % 18);
        string tipAf = tipuriG[idx % 10];
        int timp = 21;
        if (tipAf == "TEHNICA") timp = 30;
        if (tipAf == "REVISTA") timp = 7;
        string titlu;
        if (tipAf == "FICTIUNE") titlu = autor + " - Opere Vol." + to_string((idx/100)+1);
        else if (tipAf == "TEHNICA") titlu = "Manual Tehnic " + to_string(idx);
        else if (tipAf == "STIINTA") titlu = "Studii Stiintifice " + to_string(idx);
        else titlu = "Revista Academica Nr." + to_string(idx);
        Carte c;
        c.tip = "CarteFizica"; c.tipAf = tipAf; c.titlu = titlu;
        c.autor = autor; c.isbn = isbn; c.an = an; c.stare = stare;
        c.timp = timp; c.ex = ex; c.raft = raft;
        v.push_back(c);
        idx++;
    }

    ofstream date("date.txt");
    for (auto& c : v) {
        date << c.tip << "|" << c.tipAf << "|" << c.titlu << "|"
             << c.autor << "|" << c.isbn << "|" << c.an << "|" << c.stare << "|"
             << c.timp << "|" << c.ex << "|" << c.ex << "|" << c.raft << "\n";
    }
    date.close();

    ofstream exFile("exemplare.txt");
    int exC = 1;
    for (auto& c : v) {
        if (c.ex >= 999) { exFile << "EX-DIGITAL|" << c.isbn << "|Disponibil|\n"; continue; }
        for (int i = 0; i < c.ex; i++) {
            string num = to_string(exC++);
            while ((int)num.length() < 5) num = "0" + num;
            exFile << "EX-" << num << "|" << c.isbn << "|Disponibil|\n";
        }
    }
    exFile.close();

    ofstream util("utilizatori.dat");
    string p = "parola123"; string pc = p;
    for (size_t i = 0; i < p.size(); i++) pc[i] = p[i] ^ 'K';
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

    cout << "Generat " << v.size() << " titluri!" << endl;
    return 0;
}
