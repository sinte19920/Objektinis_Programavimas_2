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
    // Rule of Five
    Studentas(string vardas, string pavarde, vector<double> pazymiai, double egz, double rezultatas)
        : vardas(vardas), pavarde(pavarde), pazymiai(pazymiai), egz(egz), rezultatas(rezultatas) {}
    Studentas(const Studentas &other)
        : vardas(other.vardas), pavarde(other.pavarde), pazymiai(other.pazymiai), egz(other.egz), rezultatas(other.rezultatas) {}
    Studentas(Studentas &&other) noexcept
        : vardas(move(other.vardas)), pavarde(move(other.pavarde)), pazymiai(move(other.pazymiai)), egz(move(other.egz)), rezultatas(move(other.rezultatas)) {}

    Studentas &operator=(const Studentas &other)
    {
        if (this != &other)
        {
            vardas = other.vardas;
            pavarde = other.pavarde;
            pazymiai = other.pazymiai;
            egz = other.egz;
            rezultatas = other.rezultatas;
        }
        return *this;
    }
    Studentas &operator=(Studentas &&other) noexcept
    {
        if (this != &other)
        {
            vardas = move(other.vardas);
            pavarde = move(other.pavarde);
            pazymiai = move(other.pazymiai);
            egz = move(other.egz);
            rezultatas = move(other.rezultatas);
        }
        return *this;
    }

    // Setteriai
    void set_vardas(string vardas) { this->vardas = vardas; }
    void set_pavarde(string pavarde) { this->pavarde = pavarde; }
    void set_egz(int egz) { this->egz = egz; }
    void set_pazymiai(const vector<double> &paz) { this->pazymiai = pazymiai; }
    void set_rezultatas(double rezultatas) { this->rezultatas = rezultatas; }

    // Getteriai
    string get_vardas() const { return vardas; }
    string get_pavarde() const { return pavarde; }
    double get_egz() const { return egz; }
    vector<double> get_pazymiai() const { return pazymiai; }
    double get_rezultatas() const { return rezultatas; }

    ~Studentas() {}

    friend std::ostream &operator<<(std::ostream &os, const Studentas &studentas)
    {
        os << "Vardas: " << studentas.vardas << endl;
        os << "Pavarde: " << studentas.pavarde << endl;
        os << "Rezultatas: " << studentas.rezultatas << endl;
    }
};

string generate_name(int);
string generate_surname(int);
int generate_grade();
bool compare(Studentas, Studentas);
void med_vid(int, int, vector<Studentas> &, int);
void duomenu_nuskaitymas(vector<Studentas> &);
