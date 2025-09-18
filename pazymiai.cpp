#include <iostream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

struct Studentas{
    string vardas, pavarde;
    vector<int> nd;
    int egz;
    double vidurkis, mediana;
    };

    double Mediana(vector<int> pazymiai, int n){
    sort(pazymiai.begin(),pazymiai.end());
    if(n % 2 == 0){
        return((pazymiai[(n/2)-1]+pazymiai[n/2])/2.0);
    } else {
        return pazymiai[n/2];
    }
    };

int main() {
    int n; //nd skaicius
    char x; //kokio formato isvedimas
    Studentas s[3];

    cout<<"iveskite nd skaiciu:"<<endl;
    cin>>n;

    for(int i=0;i<3;i++){
        s[i].vidurkis=0;
        cout<<"iveskite " <<i+1 <<"-ojo studento varda ir pavarde"<<endl;
        cin>>s[i].vardas>>s[i].pavarde;
        cout<<"iveskite namu darbus:"<<endl;
        for(int y=0;y<n;y++)
        {
            int x;
            cin>>x;
            s[i].nd.push_back(x);
            s[i].vidurkis+=x;
        }
        cout<<"iveskite egzamino rezultata:"<<endl;
        cin>>s[i].egz;
        s[i].vidurkis=0.4*(s[i].vidurkis/double(n))+0.6*s[i].egz;
        s[i].mediana=0.4*Mediana(s[i].nd, n)+0.6*s[i].egz;
    }

    

    cout<<setw(20)<<left<<"pavarde"<<setw(20)<<"vardas"<<setw(20)<<"galutinis(vid.)"<<endl;
    for(int i=0;i<3;i++){
        cout<<setw(20)<<left<<s[i].pavarde<<setw(20)<<left<<s[i].vardas<<setw(20)<<left<<fixed<<setprecision(2)<<s[i].vidurkis<<endl;
    }

    return 0;
}