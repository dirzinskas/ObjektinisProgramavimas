#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
using namespace std;

struct Studentas{
    string vardas, pavarde;
    vector<int> nd;
    int egz;
    double galutinis;
    };

int main() {
    int n;
    Studentas s[3];

    cout<<"iveskite nd skaiciu:"<<endl;
    cin>>n;

    for(int i=0;i<3;i++){
        s[i].galutinis=0;
        cout<<"iveskite " <<i+1 <<"-ojo studento varda ir pavarde"<<endl;
        cin>>s[i].vardas>>s[i].pavarde;
        cout<<"iveskite namu darbus:"<<endl;
        for(int y=0;y<n;y++)
        {
            int x;
            cin>>x;
            s[i].nd.push_back(x);
            s[i].galutinis+=x;
        }
        cout<<"iveskite egzamino rezultata:"<<endl;
        cin>>s[i].egz;
        s[i].galutinis=0.4*(s[i].galutinis/double(n))+0.6*s[i].egz;
    }

    

    cout<<setw(20)<<left<<"pavarde"<<setw(20)<<"vardas"<<setw(20)<<"galutinis(vid.)"<<endl;
    for(int i=0;i<3;i++){
        cout<<setw(20)<<left<<s[i].pavarde<<setw(20)<<left<<s[i].vardas<<setw(20)<<left<<fixed<<setprecision(2)<<s[i].galutinis<<endl;
    }

    return 0;
}