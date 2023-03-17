bool compare(Studentas a, Studentas b)
{
    return a.rezultatas < b.rezultatas;
}


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
