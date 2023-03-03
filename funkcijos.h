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
string read_average_type();
void med_vid(int, int, vector<Studentas> &, string &);
bool pagal_varda(Studentas, Studentas);
bool pagal_pavarde(Studentas, Studentas);
void rezultatu_spausdinimas(string, vector<Studentas> &, int);