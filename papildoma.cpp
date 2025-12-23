#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <set>
#include <cctype>
#include <iomanip>
using namespace std;
 
int main(){
string tekstas, eil;
map<string, int> zodziai;
map<string, set<int>> lentele;
int eilnr=0;

ifstream ivestis("zodziai.txt");
if(!ivestis)
{
    cout << "Failo nera" << endl;
    return 1;
}

while (getline(ivestis, eil)) {
 string tvarkingas;
  for (char c : eil) {
                if (!ispunct(c)&&!isdigit(c))
                    tvarkingas += tolower(c);
            }

    eilnr++;
    string zodis;
    stringstream ss(tvarkingas);
    while (ss >> zodis) { 
        zodziai[zodis]++;
        lentele[zodis].insert(eilnr);
    }
}
ofstream rez("rezultatas.txt");
rez<< "Zodziu skaicius faile: " << zodziai.size() << endl;
for (const auto& pora : zodziai) {
    if(pora.second < 2) continue;
    rez << "Zodis '" << pora.first << "' pasikartoja " << pora.second << " kartus, eilutese: ";
    const auto& eil = lentele[pora.first];
    for (const auto& nr : eil) {
        rez << nr << " ";
    }
    rez << endl;
}
}