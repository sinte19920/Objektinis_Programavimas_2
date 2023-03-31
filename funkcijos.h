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

// List
void med_vid_list(int n, int nd, list<Studentas> &studentai, string &vidurkis_mediana, list<Studentas> &neislaike, list<Studentas> &islaike);
void duomenu_nuskaitymas_list(list<Studentas> &);

// Deque
void med_vid_deq(int n, int nd, deque<Studentas> &studentai, string &vidurkis_mediana, deque<Studentas> &neislaike, deque<Studentas> &islaike);
void duomenu_nuskaitymas_deq(deque<Studentas> &);