#include "Mylib.h"
using namespace std::chrono;

struct Studentas
{
    string vardas;
    string pavarde;
    vector<double> pazymiai; // pazymio vektorius
    double egz;
    double rezultatas;
};

// funkcija, skirta vidurkio arba medianos pasirinkimo nuskaitymui
string read_average_type()
{
    string vidurkis_mediana;

    cout << "Norite, kad galutiniame rezultate butu pateiktas rezultatu vidurkis ar mediana?" << endl
         << "(irasykite 'med' - medianai, 'vid' - vidurkiui): ";

    // nuskaitome vartotojo pasirinkimą, kol jis įves tinkamą reikšmę
    while (vidurkis_mediana != "med" && vidurkis_mediana != "vid")
        cin >> vidurkis_mediana;

    return vidurkis_mediana;
}

// funkcija, apskaiciuojanti mediana arba vidurki
void med_vid(int n, int nd, vector<Studentas> &studentai, string &vidurkis_mediana)
{
    vidurkis_mediana = read_average_type();
    double vid = 0;
    if (vidurkis_mediana == "vid")
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < nd; j++)
                vid += studentai[i].pazymiai[j];
            studentai[i].rezultatas = 0.4 * (vid / nd) + 0.6 * studentai[i].egz;
            vid = 0;
        }
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            int pazymiu_skaicius = nd;
            // isrikiuojama nuo maziausio iki didziausio
            sort(studentai[i].pazymiai.begin(), studentai[i].pazymiai.end());

            if (pazymiu_skaicius % 2 == 0)
                vid = (studentai[i].pazymiai[pazymiu_skaicius / 2 - 1] + studentai[i].pazymiai[pazymiu_skaicius / 2]) / 2;
            else
                vid = studentai[i].pazymiai[pazymiu_skaicius / 2];

            studentai[i].rezultatas = 0.4 * (vid / nd) + 0.6 * studentai[i].egz;
            vid = 0;
        }
    }
}

// funkcija, palyginanti vardus
bool pagal_varda(Studentas a, Studentas b)
{
    return a.vardas < b.vardas;
}

// funkcija, palyginanti pavardes
bool pagal_pavarde(Studentas a, Studentas b)
{
    return a.pavarde < b.pavarde;
}

void rezultatu_spausdinimas(string vidurkis_mediana, vector<Studentas> &studentai, int n)
{
    ofstream fr("rezultatai.txt");
    fr << left << setw(20) << "Vardas"
       << left << setw(20) << "Pavarde";
    if (vidurkis_mediana == "vid")
        fr << left << setw(15) << "Galutinis (Vid.)" << endl;
    else
        fr << left << setw(15) << "Galutinis (Med.)" << endl;

    fr << "-----------------------------------------------" << endl;

    for (int i = 0; i < studentai.size(); i++)
    {
        fr << left << setw(20) << studentai[i].vardas
           << left << setw(20) << studentai[i].pavarde
           << left << setw(15) << fixed << setprecision(2) << studentai[i].rezultatas << endl;
    }
    fr.close();
}

int main()
{

    string filename;
    ifstream file;

    cout << "Įveskite failo pavadinimą: ";
    cin >> filename;

    file.open(filename);

    // tikrinama, ar failas sėkmingai atidarytas
    while (!file.is_open())
    {
        cout << "Nepavyko atidaryti failo. Pabandykite įvesti kitą pavadinimą: ";
        cin >> filename;
        file.open(filename);
    }

    ifstream fd(filename);

    Studentas studentas;
    vector<Studentas> studentai;
    string pirmoji_eilute;

    getline(fd, pirmoji_eilute);

    // suzinomas namu darbu pazymiu skaicius
    int nd_sk = 0;
    size_t pozicija = pirmoji_eilute.find("ND");
    while (pozicija != string::npos)
    {
        nd_sk++;
        pozicija = pirmoji_eilute.find("ND", pozicija + 1);
    }

    int studentu_sk = 0;
    string studento_eilute;

    // nuskaitomi studentu vardai, pavardes ir pazymiai
    while (getline(fd, studento_eilute))
    {
        studentas.pazymiai.clear();

        stringstream ss(studento_eilute);
        ss >> studentas.vardas >> studentas.pavarde;

        // pazymiai isrenkami is failo
        int pazymys = 0;
        for (int i = 0; i < nd_sk; i++)
        {
            ss >> pazymys;
            studentas.pazymiai.push_back(pazymys);
        }
        ss >> studentas.egz;

        // issaugomi duomenys i 'studentai' vektoriu
        studentai.push_back(studentas);
        studentu_sk++;
    }

    string vidurkis_mediana;
    med_vid(studentu_sk, nd_sk, studentai, vidurkis_mediana);

    cout << "Surusiuoti studentus pagal varda ar pagal pavarde abeceles didejimo tvarka? ('vard' arba 'pavard'): ";
    string atsakymas;

    // netinkamos ivesties metu vykdomas ciklas
    while (atsakymas != "vard" && atsakymas != "pavard")
        cin >> atsakymas;

    if (atsakymas == "vard")
        sort(studentai.begin(), studentai.end(), pagal_varda);
    else
        sort(studentai.begin(), studentai.end(), pagal_pavarde);

    auto start = high_resolution_clock::now(); // Paleisti

    rezultatu_spausdinimas(vidurkis_mediana, studentai, studentu_sk);

    auto end = high_resolution_clock::now(); // Stabdyti
    duration<double> diff = end - start;     // Skirtumas (s)
    cout << "duomenu isspausdinimas uztruko : " << diff.count() << " s" << endl;
    cout << "duomenu isspausdinimas uztruko : " << duration_cast<milliseconds>(end - start).count() << " msec " << endl;

    fd.close();
    return 0;
}
