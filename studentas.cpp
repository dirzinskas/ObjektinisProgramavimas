#include "studentas.h"

int RandomSk(int max) {
    return (rand() % (max + 1));
}

bool LyginimasStr(const Studentas &petras, const Studentas &jonas) {
    return petras.vardas < jonas.vardas;
}

double Mediana(vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0;
    int dydis = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());
    if (dydis % 2 == 0)
        return ((pazymiai[(dydis / 2) - 1] + pazymiai[dydis / 2]) / 2.0);
    else
        return pazymiai[dydis / 2];
}

double Vidurkis(vector<int> pazymiai) {
    if (pazymiai.empty()) return 0.0;
    double suma = 0;
    for (int val : pazymiai) suma += val;
    return (suma / pazymiai.size());
}

void GeneruotiDuomenis() {
    int dydziai[5] = {1000, 10000, 100000, 1000000, 10000000};
    for (int i = 0; i < (sizeof(dydziai) / sizeof(dydziai[0])); i++) {
        string pavadinimas = "studentai" + to_string(dydziai[i]) + ".txt";
        ofstream duom(pavadinimas);
        duom << "Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas" << endl;
        for (int j = 0; j < dydziai[i]; j++) {
            duom << "Pavarde" + to_string(j + 1) << " Vardas" + to_string(j + 1) << " ";
            for (int k = 0; k < 6; k++) duom << RandomSk(10) << " ";
            duom << endl;
        }
    }
}

void Skaitymas(vector<Studentas> &s, string failas) {
    ifstream in(failas);
    if (!in) {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string eilute;
    getline(in, eilute);

    while (getline(in, eilute)) {
        if (eilute.empty()) continue;

        istringstream iss(eilute);
        Studentas petras;
        iss >> petras.vardas >> petras.pavarde;

        string zodis;
        while (iss >> zodis) {
            try {
                int skaicius = stoi(zodis);
                petras.nd.push_back(skaicius);
            } catch (invalid_argument &) {
                petras.nd.push_back(0);
            }
        }
        if (!petras.nd.empty()) {
            petras.egz = petras.nd.back();
            petras.nd.pop_back();
        }
        petras.vidurkis = 0.4 * Vidurkis(petras.nd) + 0.6 * petras.egz;
        petras.mediana = 0.4 * Mediana(petras.nd) + 0.6 * petras.egz;

        s.push_back(petras);
    }
    cout << "Duomenys nuskaityti is failo." << endl;
}

void Ivedimas(vector<Studentas> &s, bool generuoti) {
    string zodis;
    while (true) {
        Studentas petras;
        cout << "Iveskite varda (Enter uzbaigs):" << endl;
        getline(cin, zodis);
        if (zodis.empty()) break;
        petras.vardas = zodis;

        cout << "Iveskite pavarde: " << endl;
        getline(cin, zodis);
        petras.pavarde = zodis;

        if (generuoti) {
            int ndSk = RandomSk(15);
            for (int i = 0; i < ndSk; i++) petras.nd.push_back(RandomSk(10));
            petras.egz = RandomSk(10);
            cout << "Sugeneruota!" << endl;
        } else {
            while (true) {
                cout << "Iveskite ND pazymi (0-10). 'Enter' uzbaigs:" << endl;
                getline(cin, zodis);
                if (zodis.empty()) break;
                try {
                    int skaicius = stoi(zodis);
                    if (skaicius >= 0 && skaicius <= 10)
                        petras.nd.push_back(skaicius);
                    else
                        cout << "Netinkama ivestis." << endl;
                } catch (...) {
                    cout << "Netinkama ivestis." << endl;
                }
            }
            cout << "Iveskite egzamino rezultata:" << endl;
            while (true) {
                getline(cin, zodis);
                try {
                    int skaicius = stoi(zodis);
                    if (skaicius >= 0 && skaicius <= 10) {
                        petras.egz = skaicius;
                        break;
                    } else cout << "Netinkama ivestis." << endl;
                } catch (...) {
                    cout << "Netinkama ivestis." << endl;
                }
            }
        }
        petras.vidurkis = 0.4 * Vidurkis(petras.nd) + 0.6 * petras.egz;
        petras.mediana = 0.4 * Mediana(petras.nd) + 0.6 * petras.egz;
        s.push_back(petras);
        cout << "Studento duomenys ivesti!" << endl;
    }
}

void Rusiavimas(vector<Studentas>& s, vector<Studentas>& g, vector<Studentas>& v) {
    for (auto &st : s) {
        if (st.vidurkis < 5 && st.mediana < 5) v.push_back(st);
        else g.push_back(st);
    }
}

void Rasymas(vector<Studentas> s, string x) {
    string pavadinimas = "rezultatai_" + x + ".txt";
    ofstream rez(pavadinimas);
    rez << "Pavarde Vardas Galutinis(Vid.) Galutinis(Med.)" << endl;
    for (auto &st : s)
        rez << st.pavarde << " " << st.vardas << " " << st.vidurkis << " " << st.mediana << endl;
}

void Rezultatai(vector<Studentas> s) {
    char x;
    sort(s.begin(), s.end(), LyginimasStr);

    if (s.empty()) {
        cout << "Nera ivestu studentu." << endl;
        return;
    }

    while (true) {
        cout << "Kaip skaiciuoti vidurki? v, m ar a?" << endl;
        cin >> x;
        if (x == 'a' || x == 'v' || x == 'm') break;
        cout << "Netinkama ivestis." << endl;
    }

    cout << setw(20) << left << "Pavarde" << setw(20) << "Vardas";
    if (x == 'v') cout << setw(20) << "Galutinis (Vid.)" << endl;
    else if (x == 'm') cout << setw(20) << "Galutinis (Med.)" << endl;
    else cout << setw(20) << "Galutinis (Vid.)" << setw(20) << "Galutinis (Med.)" << endl;

    for (auto &st : s) {
        cout << setw(20) << st.pavarde << setw(20) << st.vardas;
        if (x == 'v') cout << setw(20) << fixed << setprecision(2) << st.vidurkis << endl;
        else if (x == 'm') cout << setw(20) << fixed << setprecision(2) << st.mediana << endl;
        else cout << setw(20) << st.vidurkis << setw(20) << st.mediana << endl;
    }
}

void Meniu() {
    cout << "-----------------------------------------" << endl;
    cout << "MENIU" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "1. Sugeneruoti testinius failus" << endl;
    cout << "2. Ivesti duomenis ranka" << endl;
    cout << "3. Ivesti duomenis sugeneruojant pazymius" << endl;
    cout << "4. Nuskaityti duomenis is failo" << endl;
    cout << "5. Rodyti rezultatus" << endl;
    cout << "6. Isvesti studentus i faila" << endl;
    cout << "7. Baigti darba" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Pasirinkite veiksma 1-7" << endl;
}
