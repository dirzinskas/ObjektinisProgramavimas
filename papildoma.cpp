#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <sstream>
#include <set>
#include <cctype>
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
    eilnr++;
    string zodis;
    stringstream ss(eil);
    while (ss >> zodis) {
        zodziai[zodis]++;
        lentele[zodis].insert(eilnr);
    }
}
cout<< "Zodziu skaicius faile: " << zodziai.size() << endl;
}