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

cout<<"Iveskite failo pavadinima: ";
cin>>tekstas;

ifstream ivestis(tekstas);
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

rez << "Zodziu daznis:\n";
for (const auto& pora : zodziai) {  
    if(pora.second>1)
        rez << pora.first << ": " << pora.second << "\n";   
}
rez << "\nZodziu lentele:\n";
for (const auto& pora : lentele) {
    rez << pora.first << ": ";
    for (const auto& nr : pora.second) {
        rez << nr << " ";
    }
    rez << "\n";
}}