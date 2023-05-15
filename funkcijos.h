#include "Mylib.h"

class Studentas
{
private:
    string vardas;
    string pavarde;
    vector<double> pazymiai;
    double egz;
    double rezultatas;

public:
    // Konstruktrius
    Studentas(string vardas, string pavarde, vector<double> pazymiai, double egz, double rezultatas)
        : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egz(egz), rezultatas(rezultatas) {}

    // Setteriai
    void set_vardas(string v) { this->vardas = vardas; }
    void set_pavarde(string p) { this->pavarde = pavarde; }
    void set_egz(int e) { this->egz = egz; }
    void set_pazymiai(const vector<double> &paz) { this->pazymiai = pazymiai; }
    void set_rezultatas(double rez) { this->rezultatas = rezultatas; }

    // Getteriai
    string get_vardas() const { return vardas; }
    string get_pavarde() const { return pavarde; }
    double get_egz() const { return egz; }
    vector<double> get_pazymiai() const { return pazymiai; }
    double get_rezultatas() const { return rezultatas; }
};

string generate_name(int);
string generate_surname(int);
int generate_grade();
bool compare(Studentas, Studentas);
void med_vid(int, int, vector<Studentas> &, int);
void duomenu_nuskaitymas(vector<Studentas> &);