#include "Mylib.h"

struct Studentas
{
    Studentas *studentas;
    string vardas, pavarde;
    int *pazymiai;
    int size;
    int egz;
    float rez;
};

// funkcija, skirta taip / ne atsakymo įvedimui
string nuskaityti_atsakyma()
{
    string atsakymas;
    while (true)
    {
        cin >> atsakymas;
        if (atsakymas == "taip")
            return "taip";
        else if (atsakymas == "ne")
            return "ne";
        else
            cout << "Netinkama ivestis, reikia irasyti 'taip' arba 'ne'." << endl;
    }
    cout << endl;
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

    cout << endl;

    return vidurkis_mediana;
}

void resize_int(int *&array, int size)
{
    int *newArray = new int[size];
    for (int i = 0; i < size - 1; i++)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

// funkcija, naudojama siekiant padidinti masyvo dydį.
void resize(Studentas *&array, int size)
{
    Studentas *newArray = new Studentas[size];
    for (int i = 0; i < size - 1; i++)
    {
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
}

void duomenys(Studentas *temp, string vidurkis_mediana)
{
    string atsakymas = "ne";
    cout << "Iveskite studento varda ir pavarde " << endl
         << "(parasius bent viena is reikiamu duomenu spauskite enter):" << endl;
    cin >> temp->vardas >> temp->pavarde;
    cout << endl;

    cout << "Iveskite pazymi/-ius 10-baleje sistemoje (kai noresite baigti, iveskite bet koki kita simboli): ";
    double paz, suma = 0;
    int n = 0;

    // uztikrinama, kad masyvas būtų tuščias prieš nuskaitant bet kokius duomenis
    temp->pazymiai = NULL;

    while (cin >> paz)
    {
        // patikrinama, ar įvestas skaičius yra nuo 0 iki 10
        if (paz >= 0 && paz <= 10)
        {
            if (n == 0)
            {
                temp->pazymiai = new int[1];
                temp->pazymiai[0] = paz;
                suma += paz;
                n++;
            }
            else
            {
                suma += paz;
                n++;
                resize_int(temp->pazymiai, n);
                temp->pazymiai[n - 1] = paz;
            }
        }
        // sustabdome ciklą, jei įvestas netinkamas skaičius
        else
        {
            cin.clear();
            std::cin.ignore(numeric_limits<streamsize>::max(), '\n');
            break;
        }
    }
    cout << endl;
    if (n == 0)
    {
        temp->pazymiai = new int[1];
        temp->pazymiai[0] = 0;
    }

    cout << "Iveskite egzamino rezultata 10-baleje sistemoje: ";
    while (!(cin >> temp->egz) || temp->egz < 0 || temp->egz > 10)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << endl;

    cout << "Gal norite sugeneruoti atsitiktinius pazymius? (taip / ne): ";
    atsakymas = nuskaityti_atsakyma();
    if (atsakymas == "taip")
    {
        srand(time(NULL));
        temp->rez = (float)rand() / RAND_MAX * 10;
    }

    cout << endl;

    if (vidurkis_mediana == "vid")
        temp->rez = 0.4 * (suma / n) + 0.6 * temp->egz;

    else
    {
        // isrikiuojama nuo maziausio iki didziausio burbulų rikiavimo algoritmu
        for (int i = 0; i < n - 1; i++)
        {
            for (int j = 0; j < n - i - 1; j++)
            {
                if (temp->pazymiai[j] > temp->pazymiai[j + 1])
                {
                    swap(temp->pazymiai[j], temp->pazymiai[j + 1]);
                }
            }
        }
        int mediana;
        if (n % 2 == 0)
            mediana = temp->pazymiai[(n / 2) - 1] + temp->pazymiai[n / 2] / 2.0;
        else
            mediana = temp->pazymiai[n / 2];

        temp->rez = 0.4 * (mediana / n) + 0.6 * temp->egz;
    }
}

void rezultatu_spausdinimas(Studentas *temp)
{
    cout << left << setw(15) << temp->vardas
         << left << setw(15) << temp->pavarde
         << left << setw(15) << fixed << setprecision(2) << temp->rez << endl;
}

int main()
{
    int max = 0;
    string atsakymas;
    Studentas student;
    // Studentas_masyvas student;

    string vidurkis_mediana = read_average_type();
    while (atsakymas != "ne")
    {
        // patikrinama, ar yra bent vienas masyvas, jei ne - sukuriamas naujas
        if (max == 0)
        {
            student.studentas = new Studentas[1];
            max++;
            student.size = max;
            duomenys(&student.studentas[0], vidurkis_mediana);
        }
        // jei jau yra bent vienas studentas
        else
        {
            ++max;
            resize(student.studentas, max);
            duomenys(&student.studentas[max - 1], vidurkis_mediana);
        }
        student.size = max;

        cout << "Ar norite ivesti daugiau duomenu? (taip / ne): ";
        atsakymas = nuskaityti_atsakyma();
        cout << endl;
    }

    cout << left << setw(15) << "Vardas"
         << left << setw(15) << "Pavarde";
    if (vidurkis_mediana == "vid")
        cout << left << setw(15) << "Galutinis (Vid.)" << endl;

    else
        cout << left << setw(15) << "Galutinis (Med.)" << endl;

    cout << "-----------------------------------------------" << endl;

    for (int i = 0; i < student.size; i++)
    {
        rezultatu_spausdinimas(&student.studentas[i]);
        // isvaloma atmintis, kurioje laikomi studento pazymiai
        delete[] student.studentas[i].pazymiai;
    }
    // isvaloma atmintis, kurioje laikomi studentu duomenu masyvai
    delete[] student.studentas;

    return 0;
}