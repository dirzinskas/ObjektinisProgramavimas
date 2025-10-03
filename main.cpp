#include "studentas.h"

int main() {
    vector<Studentas> s, g, v;
    int y;
    char x;
    string failas;
    srand(time(0));

    do {
        Meniu();
        cin >> y;
        if (cin.fail()) cin.clear();
        cin.ignore();
        switch (y) {
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
            while (true) {
                cout << "Kokius studentus pateikti? g, v ar a?" << endl;
                cin >> x;
                if (x == 'g' || x == 'v' || x == 'a') break;
                cout << "Netinkama ivestis." << endl;
            }
            Rusiavimas(s, g, v);
            if (x == 'g') Rezultatai(g);
            else if (x == 'v') Rezultatai(v);
            else Rezultatai(s);
            break;
        case 6:
            Rusiavimas(s, g, v);
            if (g.empty() || v.empty()) cout << "Klaida. Nera tinkamu studentu" << endl;
            Rasymas(g, "g");
            Rasymas(v, "v");
            break;
        case 7:
            cout << "Programa baigia darba.";
            break;
        default:
            cout << "Netinkama ivestis. Pasirinkite skaiciu 1-7:" << endl;
        }
    } while (y != 7);
    return 0;
}
