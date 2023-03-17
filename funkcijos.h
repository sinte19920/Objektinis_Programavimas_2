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
