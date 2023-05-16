#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "Mylib.h"

class Zmogus
{
protected:
    string vardas;
    string pavarde;

public:
    Zmogus(const string &vardas, const string &pavarde)
        : vardas(vardas), pavarde(pavarde) {}

    // Getteriai
    string get_vardas() const { return vardas; }
    string get_pavarde() const { return pavarde; }

    virtual void raso(std::ofstream &raso) const = 0;

    virtual ~Zmogus() {}
};
class Studentas : public Zmogus
{
private:
    vector<double> pazymiai;
    double egz;
    double rezultatas;

public:
    // Rule of Five
    Studentas(const string &vardas, const string &pavarde, vector<double> pazymiai, double egz, double rezultatas)
        : Zmogus(vardas, pavarde), pazymiai(pazymiai), egz(egz), rezultatas(rezultatas) {}
    Studentas(const Studentas &other)
        : Zmogus(other), pazymiai(other.pazymiai), egz(other.egz), rezultatas(other.rezultatas) {}
    Studentas(Studentas &&other) noexcept
        : Zmogus(move(other)), pazymiai(move(other.pazymiai)), egz(move(other.egz)), rezultatas(move(other.rezultatas)) {}

    Studentas &operator=(const Studentas &other)
    {
        if (this != &other)
        {
            Zmogus::operator=(other);
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
            Zmogus::operator=(move(other));
            pazymiai = move(other.pazymiai);
            egz = other.egz;
            rezultatas = other.rezultatas;
        }
        return *this;
    }

    // Setteriai
    void set_egz(int e) { this->egz = egz; }
    void set_pazymiai(const vector<double> &paz) { this->pazymiai = pazymiai; }
    void set_rezultatas(double rez) { this->rezultatas = rezultatas; }

    // Getteriai
    double get_egz() const { return egz; }
    vector<double> get_pazymiai() const { return pazymiai; }
    double get_rezultatas() const { return rezultatas; }

    ~Studentas() {}

    void raso(std::ofstream &raso) const override
    {
        raso << "Vardas: " << vardas << endl;
        raso << "Pavarde: " << pavarde << endl;
    }
};

TEST_CASE("Kodo testavimas :")
{
    Studentas test("VardasX", "PavardeX", {4, 6, 2, 9}, 9, 0);
    Studentas test2("VardasY", "PavardeY", {8, 2, 4, 4}, 5, 0);

    REQUIRE(test.get_pazymiai().size() != 0);
}