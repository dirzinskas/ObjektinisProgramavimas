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

bool Lyginimas(const Studentas &petras,const Studentas &jonas){
    return petras.vardas<jonas.vardas;
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

void Skaitymas(vector<Studentas> &s, string failas)
{
    ifstream in(failas);
    if(!in)
    {
        cout<<"Nepavyko atidaryti failo."<<endl;
        return;
    }

    string eilute;
    getline(in, eilute);

    while(getline(in,eilute))
    {
        if(eilute.empty()) continue;

        istringstream iss(eilute);
        Studentas petras;
        iss>>petras.vardas>>petras.pavarde;

        string zodis;
        while(iss>>zodis){
            try
            {
                int skaicius=stoi(zodis);
                petras.nd.push_back(skaicius);
            }catch(invalid_argument){
                petras.nd.push_back(0);
            }
            
        }
        if(!petras.nd.empty()){
            petras.egz=petras.nd.back();
            petras.nd.pop_back();
        }
        petras.vidurkis = 0.4 * Vidurkis(petras.nd) + 0.6 * petras.egz;
        petras.mediana = 0.4 * Mediana(petras.nd) + 0.6 * petras.egz;

        s.push_back(petras);
    }
    cout<<"duomenys nuskaityti is failo."<<endl;
}
void Ivedimas(vector<Studentas> &s, bool generuoti)
{
    string zodis; // ivesciai patikrinti

    while (true)
    {
        Studentas petras;

        cout << "iveskite varda (spauskite Enter, kad uzbaigti studentu ivedima):" << endl;
        getline(cin, zodis);
        if (zodis.empty())
            break;
        petras.vardas = zodis;

        cout << "iveskite pavarde: " << endl;
        getline(cin, zodis);
        petras.pavarde = zodis;

        if (generuoti == true)
        {
            int ndSk = RandomSk(15); // namu darbu skaicius
            for (int i = 0; i < ndSk; i++)
            {
                petras.nd.push_back(RandomSk(10));
            }
            petras.egz = RandomSk(10);
            cout << "sugeneruota!" << endl;
        }
        else
        {
            while (true)
            {
                cout << "iveskite namu darbu pazymi (0-10). Enter uzbaigs ivedima: " << endl;
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
                        cout << "netinkama ivestis. iveskite skaiciu nuo 0 iki 10" << endl;
                    }
                }
                catch (const invalid_argument &)
                {
                    cout << "netinkama ivestis. iveskite skaiciu nuo 0 iki 10" << endl;
                }
            }

            cout << "iveskite egzamino rezultata:" << endl;
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
                        cout << "netinkama ivestis. iveskite skaiciu nuo 0 iki 10" << endl;
                    }
                }
                catch (const invalid_argument &)
                {
                    cout << "netinkama ivestis. iveskite skaiciu nuo 0 iki 10" << endl;
                }
            }
        }
        petras.vidurkis = 0.4 * Vidurkis(petras.nd) + 0.6 * petras.egz;
        petras.mediana = 0.4 * Mediana(petras.nd) + 0.6 * petras.egz;

        s.push_back(petras);
        cout << "studento duomenys ivesti." << endl;
    }
};

void Rezultatai(vector<Studentas> s)
{
    char x; // kokio formato isvedimas
    sort(s.begin(),s.end(),Lyginimas);
    if (s.empty())
        cout << "nera ivestu studentu." << endl;
    else
    {

        while (true)
        {
            cout << "kaip turetu buti skaiciuojamas vidurkis?" << endl;
            cout << "vidurkis(v), mediana(m) ar abu(a)?" << endl;
            cin >> x;
            if (x == 'a' || x == 'v' || x == 'm')
                break;
            else
            {
                cout << "netinkama ivestis. iveskite v, m arba a." << endl;
            }
        }
        cout << setw(20) << left << "pavarde" << setw(20) << "vardas";
        switch (x)
        {
        case 'v':
            cout << setw(20) << "galutinis(vid.)" << endl;
            break;
        case 'm':
            cout << setw(20) << "galutinis(med.)" << endl;
            break;
        case 'a':
            cout << setw(20) << left << "galutinis(vid.)" << setw(20) << left << "galutinis(med.)" << endl;
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
    cout << "MENIU" << endl;
    cout << "Pasirinkite veiksma:" << endl;
    cout << "1. Ivesti duomenis ranka" << endl;
    cout << "2. Ivesti duomenis sugeneruojant pazymius" << endl;
    cout <<"3. Nuskaityti duomenis is failo"<<endl;
    cout << "4. Rodyti rezultatus" << endl;
    cout << "5. Baigti darba" << endl;
    cout << "Pasirinkite veiksma 1-5" << endl;
}

int main()
{
    vector<Studentas> s;
    int y; // pasirinkimas
    string failas; //skaitomo failo vardas
    srand(time(0));
    do
    {
        Meniu();
        cin >> y;
        cin.ignore();
        switch (y)
        {
        case 1:
            Ivedimas(s, false);
            break;
        case 2:
            Ivedimas(s, true);
            break;
        case 3:
            cout<<"Iveskite failo varda: "<<endl;
            cin>>failas;
            Skaitymas(s, failas);
            break;
        case 4:
            Rezultatai(s);
            break;
        case 5:
            cout << "programa baigia darba";
            break;
        default:
            cout << "netinkama ivestis. pasirinkite skaiciu 1-5:"<<endl;
        }
    } while (y != 5);
    return 0;
}