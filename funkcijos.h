/*
VECTOR
*/

#include "Mylib.h"

struct Studentas
{
    string vardas;
    string pavarde;
    vector<double> pazymiai;
    double egz;
    double rezultatas;
};

string generate_name(int);
string generate_surname(int);
int generate_grade();
string read_average_type();
bool compare(Studentas, Studentas);
void med_vid(int, int, vector<Studentas> &, string &);
void duomenu_nuskaitymas(vector<Studentas> &);

/*
DEQUE
*/
#include "Mylib.h"

struct Studentas
{
    string vardas;
    string pavarde;
    deque<double> pazymiai;
    double egz;
    double rezultatas;
};

string generate_name(int);
string generate_surname(int);
int generate_grade();
string read_average_type();
bool compare(Studentas, Studentas);
void med_vid(int, int, deque<Studentas> &, string &);
void duomenu_nuskaitymas(deque<Studentas> &);

/*
LIST
*/

#include "Mylib.h"

struct Studentas
{
    string vardas;
    string pavarde;
    list<double> pazymiai;
    double egz;
    double rezultatas;
};

string generate_name(int);
string generate_surname(int);
int generate_grade();
string read_average_type();
bool compare(Studentas, Studentas);
void med_vid(int, int, list<Studentas> &, string &);
void duomenu_nuskaitymas(list<Studentas> &);