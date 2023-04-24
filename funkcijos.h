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
bool compare(Studentas, Studentas);
void med_vid(int, int, vector<Studentas> &);
void duomenu_nuskaitymas(vector<Studentas> &);

// List
void med_vid_list(int n, int nd, list<Studentas> &studentai, list<Studentas> &neislaike, list<Studentas> &islaike);
void duomenu_nuskaitymas_list(list<Studentas> &);

// Deque
void med_vid_deq(int n, int nd, deque<Studentas> &studentai, deque<Studentas> &neislaike, deque<Studentas> &islaike);
void duomenu_nuskaitymas_deq(deque<Studentas> &);