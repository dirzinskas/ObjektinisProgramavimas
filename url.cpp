#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <cctype>

using namespace std;
 
string BeSkyrybos(string netvarkingas) {
    while (!netvarkingas.empty() && ispunct(netvarkingas.front()))
        netvarkingas.erase(netvarkingas.begin());

    while (!netvarkingas.empty() && ispunct(netvarkingas.back()))
        netvarkingas.pop_back();

    return netvarkingas;
}

int main(){
string tekstas, eil, visas;

cout<<"Iveskite failo pavadinima: ";
cin>>tekstas;

ifstream ivestis(tekstas);
if(!ivestis)
{
    cout << "Failo nera" << endl;
    return 1;
}

while (getline(ivestis, eil)) {
    string zodis;
    stringstream ss(eil);

    while (ss >> zodis) {
        zodis = BeSkyrybos(zodis);
        if (zodis.find('.') != string::npos &&
            zodis[0] != '.' &&
            zodis[zodis.length() - 1] != '.') {

            visas += zodis + "\n";
        }
    }
}
ofstream rez("rezultatasurl.txt");

rez << visas;
return 0;
}