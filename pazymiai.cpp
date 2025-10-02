#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>
using namespace std;

struct Studentas
{
    string vardas, pavarde;
    vector<int> nd;
    int egz;
    double vidurkis, mediana;
};

int RandomSk(int max)
{
    return (rand() % (max + 1));
};

bool LyginimasStr(const Studentas &petras, const Studentas &jonas)
{
    return petras.vardas < jonas.vardas;
}

double Mediana(vector<int> pazymiai)
{
    if (pazymiai.empty())
        return 0.0;
    int dydis = pazymiai.size();
    sort(pazymiai.begin(), pazymiai.end());
    if (dydis % 2 == 0)
    {
        return ((pazymiai[(dydis / 2) - 1] + pazymiai[dydis / 2]) / 2.0);
    }
    else
    {
        return pazymiai[dydis / 2];
    }
};

double Vidurkis(vector<int> pazymiai)
{
    if (pazymiai.empty())
        return 0.0;
    double suma = 0;
    double dydis = pazymiai.size();
    for (int i = 0; i < dydis; i++)
    {
        suma += pazymiai[i];
    }
    return (suma / dydis);
};

void GeneruotiDuomenis()
{
    int dydziai[5]={1000,10000,100000,1000000,10000000};
    for(int i=0; i<(sizeof(dydziai)/4);i++)
    {
        string pavadinimas="studentai"+to_string(dydziai[i])+".txt";
        ofstream duom(pavadinimas);
        duom<<"Pavarde Vardas ND1 ND2 ND3 ND4 ND5 Egzaminas"<<endl;
        for(int j=0;j<dydziai[i];j++)
        {
            duom<<"Pavarde"+to_string(j+1)+" Vardas"+to_string(j+1)<<" ";
            for (int i = 0; i <6; i++)
            {
                duom<<RandomSk(10)<<" ";
            }
            
            duom<<endl;
        }
        duom.close();
    }
}
void Skaitymas(vector<Studentas> &s, string failas)
{
    ifstream in(failas);
    if (!in)
    {
        cout << "Nepavyko atidaryti failo." << endl;
        return;
    }

    string eilute;
    getline(in, eilute);

    while (getline(in, eilute))
    {
        if (eilute.empty())
            continue;

        istringstream iss(eilute);
        Studentas petras;
        iss >> petras.vardas >> petras.pavarde;

        string zodis;
        while (iss >> zodis)
        {
            try
            {
                int skaicius = stoi(zodis);
                petras.nd.push_back(skaicius);
            }
            catch (invalid_argument)
            {
                petras.nd.push_back(0);
            }
        }
        if (!petras.nd.empty())
        {
            petras.egz = petras.nd.back();
            petras.nd.pop_back();
        }
        petras.vidurkis = 0.4 * Vidurkis(petras.nd) + 0.6 * petras.egz;
        petras.mediana = 0.4 * Mediana(petras.nd) + 0.6 * petras.egz;

        s.push_back(petras);
    }
    cout << "Duomenys nuskaityti is failo." << endl;
}
void Ivedimas(vector<Studentas> &s, bool generuoti)
{
    string zodis; // ivesciai patikrinti

    while (true)
    {
        Studentas petras;

        cout << "Iveskite varda (spauskite Enter, kad uzbaigti studentu ivedima):" << endl;
        getline(cin, zodis);
        if (zodis.empty())
            break;
        petras.vardas = zodis;

        cout << "Iveskite pavarde: " << endl;
        getline(cin, zodis);
        petras.pavarde = zodis;

        if (generuoti)
        {
            int ndSk = RandomSk(15); // namu darbu skaicius
            for (int i = 0; i < ndSk; i++)
            {
                petras.nd.push_back(RandomSk(10));
            }
            petras.egz = RandomSk(10);
            cout << "Sugeneruota!" << endl;
        }
        else
        {
            while (true)
            {
                cout << "Iveskite namu darbu pazymi (0-10). 'Enter' uzbaigs ivedima: " << endl;
                getline(cin, zodis);
                try
                {
                    if (zodis.empty())
                        break;
                    int skaicius = stoi(zodis);
                    if (skaicius >= 0 && skaicius <= 10)
                    {
                        petras.nd.push_back(skaicius);
                    }
                    else
                    {
                        cout << "Netinkama ivestis. Iveskite skaiciu nuo 0 iki 10" << endl;
                    }
                }
                catch (const invalid_argument &)
                {
                    cout << "Netinkama ivestis. Iveskite skaiciu nuo 0 iki 10" << endl;
                }
            }

            cout << "Iveskite egzamino rezultata:" << endl;
            while (true)
            {
                getline(cin, zodis);
                try
                {
                    int skaicius = stoi(zodis);
                    if (skaicius >= 0 && skaicius <= 10)
                    {
                        petras.egz = skaicius;
                        break;
                    }
                    else
                    {
                        cout << "Netinkama ivestis. Iveskite skaiciu nuo 0 iki 10" << endl;
                    }
                }
                catch (const invalid_argument &)
                {
                    cout << "Netinkama ivestis. Iveskite skaiciu nuo 0 iki 10" << endl;
                }
            }
        }
        petras.vidurkis = 0.4 * Vidurkis(petras.nd) + 0.6 * petras.egz;
        petras.mediana = 0.4 * Mediana(petras.nd) + 0.6 * petras.egz;

        s.push_back(petras);
        cout << "Studento duomenys ivesti!" << endl;
    }
};

void Rusiavimas(vector<Studentas>& s)
{
    int i;
    vector<Studentas> g, v;
    for(i=0;i<s.size();i++)
    {
        if(s[i].vidurkis<5)
        {
            v.push_back(s[i]);
        }
        else
        {
            g.push_back(s[i]);
        }
    }
    

}
void Rezultatai(vector<Studentas> s)
{
    char x; // kokio formato isvedimas
    
    sort(s.begin(), s.end(), LyginimasStr);
    
    if (s.empty())
        cout << "Nera ivestu studentu." << endl;
    else
    {

        while (true)
        {
            cout << "Kaip turetu buti skaiciuojamas vidurkis?" << endl;
            cout << "vidurkis(v), mediana(m) ar abu(a)?" << endl;
            cin >> x;
            if (x == 'a' || x == 'v' || x == 'm')
                break;
            else
            {
                cout << "Netinkama ivestis. Iveskite 'v', 'm' arba 'a'." << endl;
            }
        }
        cout << setw(20) << left << "Pavarde" << setw(20) << "Vardas";
        switch (x)
        {
        case 'v':
            cout << setw(20) << "Galutinis (Vid.)" << endl;
            break;
        case 'm':
            cout << setw(20) << "Galutinis (Med.)" << endl;
            break;
        case 'a':
            cout << setw(20) << left << "Galutinis (Vid.)" << setw(20) << left << "Galutinis (Med.)" << endl;
            break;
        };
        for (size_t i = 0; i < s.size(); i++)
        {
            cout << setw(20) << left << s[i].pavarde << setw(20) << left << s[i].vardas;
            switch (x)
            {
            case 'v':
                cout << setw(20) << left << fixed << setprecision(2) << s[i].vidurkis << endl;
                break;
            case 'm':
                cout << setw(20) << left << fixed << setprecision(2) << s[i].mediana << endl;
                break;
            case 'a':
                cout << setw(20) << left << fixed << setprecision(2) << s[i].vidurkis << setw(20) << left << s[i].mediana << endl;
                break;
            };
        }
    }
};

void Meniu()
{
    cout << "-----------------------------------------" << endl;
    cout << "MENIU" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Pasirinkite veiksma:" << endl;
    cout << "1. Sugeneruoti testinius failus" <<endl;
    cout << "2. Ivesti duomenis ranka" << endl;
    cout << "3. Ivesti duomenis sugeneruojant pazymius" << endl;
    cout << "4. Nuskaityti duomenis is failo" << endl;
    cout << "5. Surusiuoti studentus"<<endl;
    cout << "6. Rodyti rezultatus" << endl;
    cout << "7. Baigti darba" << endl;
    cout << "-----------------------------------------" << endl;
    cout << "Pasirinkite veiksma 1-7" << endl;
}

int main()
{
    vector<Studentas> s;
    int y;         // pasirinkimas
    string failas; // skaitomo failo vardas
    srand(time(0));
    do
    {
        Meniu();

        cin >> y;
        if (cin.fail())
            cin.clear();
        cin.ignore();
        switch (y)
        {
        case 1:
            GeneruotiDuomenis();
            break;
        case 2:
            Ivedimas(s, false);
            break;
        case 3:
            Ivedimas(s, true);
            break;
        case 4:
            cout << "Iveskite failo varda: " << endl;
            cin >> failas;
            Skaitymas(s, failas);
            break;
        case 5:
            Rusiavimas(s);
            break;
        case 6:
            Rezultatai(s);
            break;
        case 7:
            cout << "Programa baigia darba.";
            break;
        default:
            cout << "Netinkama ivestis. Pasirinkite skaiciu 1-5:" << endl;
        }
    } while (y != 7);
    return 0;
}