#include "funkcijos.h"

// Funkcija, kuri sugeneruoja atsitiktinį studento vardą ir pavardę
string generate_name(int i)
{
    return "Vardas" + to_string(i);
}
string generate_surname(int i)
{
    return " Pavarde" + to_string(i);
}

// Funkcija, kuri sugeneruoja atsitiktinį studento pažymį (nuo 0 iki 10)
int generate_grade()
{
    return rand() % 11;
}

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

bool compare(Studentas a, Studentas b)
{
    return(a.rezultatas < b.rezultatas);
}

// funkcija, apskaiciuojanti mediana arba vidurki
void med_vid(int n, int nd, vector<Studentas> &studentai, string &vidurkis_mediana, vector<Studentas> &neislaike, vector<Studentas> &islaike)
{
    double vid = 0;
    if (vidurkis_mediana == "vid")
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < nd; j++)
                vid += studentai[i].pazymiai[j];
            studentai[i].rezultatas = 0.4 * (vid / nd) + 0.6 * studentai[i].egz;

            if (studentai[i].rezultatas < 5)
                neislaike.push_back(studentai[i]);
            else
                islaike.push_back(studentai[i]);

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

            if (studentai[i].rezultatas < 5)
                neislaike.push_back(studentai[i]);
            else
                islaike.push_back(studentai[i]);

            vid = 0;
        }
    }
    // surikiuojami studentai pagal rezultata
    sort(neislaike.begin(), neislaike.end(), compare);
    sort(islaike.begin(), islaike.end(), compare);
}

void duomenu_nuskaitymas(vector<Studentas> &studentai)
{
    srand(time(NULL));
    Studentas studentas;
    vector<Studentas> neislaike;
    vector<Studentas> islaike;
    string failu_pav[5] = {"", "", "", "", ""};

    // studentu skaicius skirtas failams
    int num_students[] = {1000, 10000, 100000, 1000000, 10000000};

    int nd_sk;
    cout << "Iveskite skaiciu, kiek kiekvienas studentas tures pazymiu (nuo 1 iki 15 iskaitytinai): ";
    while (true)
    {
        cin >> nd_sk;

        if (cin.fail() || nd_sk < 1 || nd_sk > 15)
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "klaida, skaicius turi buti nuo 1 iki 15\n";
        }

        else
            break;
    }

    string vidurkis_mediana = read_average_type();

    for (int i = 0; i < 5; i++)
    {
        int n = num_students[i];
        string filename = "studentai" + to_string(n) + ".txt";
        failu_pav[i] = filename;

        auto start = std::chrono::high_resolution_clock::now(); // Paleisti

        ofstream outfile(filename);

        // pirmoji eilute
        outfile << left << setw(19) << "Vardas";
        outfile << left << setw(17) << "Pavarde";
        for (int j = 0; j < nd_sk; j++)
        {
            string nd = "ND" + to_string(j + 1);
            outfile << left << setw(5) << nd;
        }
        outfile << left << setw(5) << "Egz." << endl;

        for (int j = 1; j <= n; j++)
        {
            string vardas = generate_name(j);
            string pavarde = generate_surname(j);
            outfile << left << setw(18) << vardas;
            outfile << left << setw(18) << pavarde;

            // atsitiktiniai pažymiai
            for (int k = 0; k < nd_sk; k++)
            {
                int grade = generate_grade();
                outfile << left << setw(5) << grade;
            }

            // egzamino pažymys
            int exam_grade = generate_grade();
            outfile << left << setw(5) << exam_grade << endl;
        }
        outfile.close();
        auto end = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> skirt = end - start;    // Skirtumas (s)
        cout << "Failo " << filename << " kurimo sparta: " << fixed << setprecision(2) << skirt.count() << "s" << endl;

        auto start1 = std::chrono::high_resolution_clock::now(); // Paleisti
        ifstream fd(failu_pav[i]);

        string pirmoji_eilute;
        // praignoruojama pirmoji eilute
        getline(fd, pirmoji_eilute);

        for (int j = 1; j <= n; j++)
        {
            studentas.pazymiai.clear();

            fd >> studentas.vardas >> studentas.pavarde;

            int pazymys;
            for (int k = 0; k < nd_sk; k++)
            {
                fd >> pazymys;
                studentas.pazymiai.push_back(pazymys);
            }
            fd >> studentas.egz;

            studentai.push_back(studentas);
        }

        auto end1 = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> skirt1 = end1 - start1;  // Skirtumas (s)
        cout << "Duomenu is failo " << failu_pav[i] << " skaitymo sparta: " << fixed << setprecision(2) << skirt1.count() << "s" << endl;

        int studentu_sk = studentai.size();

        auto start2 = std::chrono::high_resolution_clock::now(); // Paleisti

        med_vid(studentu_sk, nd_sk, studentai, vidurkis_mediana, neislaike, islaike);
        studentai.clear();

        auto end2 = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> skirt2 = end2 - start2;  // Skirtumas (s)
        cout << "Studentu rusiavimo i dvi grupes sparta: " << fixed << setprecision(2) << skirt2.count() << "s" << endl;

        string filename1 = "islaike" + to_string(n) + ".txt";
        string filename2 = "neislaike" + to_string(n) + ".txt";

        ofstream fr(filename1);
        ofstream fr1(filename2);

        auto start3 = std::chrono::high_resolution_clock::now(); // Paleisti
        // Rašomi studentų duomenys į failą
        fr << left << setw(18) << "Vardas"
           << left << setw(18) << "Pavarde";
        if (vidurkis_mediana == "vid")
            fr << left << setw(15) << "Galutinis (Vid.)" << endl;
        else
            fr << left << setw(15) << "Galutinis (Med.)" << endl;

        fr << "----------------------------------------------------" << endl;
        for (int j = 0; j < islaike.size(); j++)
        {
            fr << left << setw(18) << islaike[j].vardas;
            fr << left << setw(18) << islaike[j].pavarde;

            // Rašomas galutinis pažymį į failą
            double average_grade = islaike[j].rezultatas;
            fr << left << setw(15) << fixed << setprecision(2) << average_grade << endl;
        }

        auto end3 = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> skirt3 = end3 - start3;  // Skirtumas (s)
        cout << "Islaikiusiu studentu spausdinimo sparta: " << fixed << setprecision(2) << skirt3.count() << "s" << endl;

        auto start4 = std::chrono::high_resolution_clock::now(); // Paleisti
        // Rašomi studentų duomenis į failą
        fr1 << left << setw(18) << "Vardas"
            << left << setw(18) << "Pavarde";
        if (vidurkis_mediana == "vid")
            fr1 << left << setw(15) << "Galutinis (Vid.)" << endl;
        else
            fr1 << left << setw(15) << "Galutinis (Med.)" << endl;

        fr1 << "----------------------------------------------------" << endl;
        for (int j = 0; j < neislaike.size(); j++)
        {
            fr1 << left << setw(18) << neislaike[j].vardas;
            fr1 << left << setw(18) << neislaike[j].pavarde;

            // Rašome galutini pažymį į failą
            double average_grade = neislaike[j].rezultatas;
            fr1 << left << setw(15) << fixed << setprecision(2) << average_grade << endl;
        }
        auto end4 = std::chrono::high_resolution_clock::now(); // Stabdyti
        std::chrono::duration<double> skirt4 = end4 - start4;  // Skirtumas (s)
        cout << "Neislaikiusiu studentu spausdinimo sparta: " << fixed << setprecision(2) << skirt4.count() << "s" << endl;
        cout << endl;
        fd.close();
        fr.close();
        fr1.close();
    }
}
