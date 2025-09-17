#include <iostream>
using namespace std;

int main() {
    struct Studentas{
    string vardas, pavarde;
    int nd, egz;
    };
    Studentas s1;
    s1.egz=5;
    cout<<s1.egz;
    return 0;
}