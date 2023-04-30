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
        Studentas() : egz(0), rezultatas(0) {}

        Studentas(string v, string p): vardas(v), pavarde(p), egz(0), rezultatas(0) {}

        void set_vardas(string v) {vardas = v;}
        void set_pavarde(string p) {pavarde = p;}
        void set_egz(int e) {egz = e;}
        void set_pazymiai(const vector<double>& paz) {pazymiai = paz;}
        void set_rezultatas(double rez) {rezultatas = rez;}

        inline string get_vardas() const{return vardas;}
        inline string get_pavarde() const{return pavarde;}
        inline double get_egz() const{return egz;}
        inline vector<double> get_pazymiai() const{return pazymiai;}
        inline double get_rezultatas() const{return rezultatas;}

        friend istream& operator>>(istream& is, Studentas& studentas) {
            is >> studentas.vardas >> studentas.pavarde;

            int pazymys;
            vector<double> pazymiu_v;
            while(is >> pazymys){ 
                pazymiu_v.push_back(pazymys);
            }
            double egzaminas = pazymiu_v.back();
            pazymiu_v.pop_back();
            studentas.set_egz(egzaminas);

            return is;
        }
        ~Studentas() {}

};

string generate_name(int);
string generate_surname(int);
int generate_grade();
bool compare(Studentas, Studentas);
void med_vid(int, int, vector<Studentas> &, int);
void duomenu_nuskaitymas(vector<Studentas> &);