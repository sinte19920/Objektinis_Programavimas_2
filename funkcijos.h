#include "Mylib.h"

struct Studentas
{
    string vardas;
    string pavarde;
    vector<double> pazymiai;
    double egz;
    double rezultatas;
};

void duomenu_nuskaitymas(vector<Studentas> &);
string generate_name(int);
string generate_surname(int);
int generate_grade();
string read_average_type();
void med_vid(int, int, vector<Studentas> &, string &);