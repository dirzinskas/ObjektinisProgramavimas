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
    }};

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

    
    cout<<"kaip turetu buti skaiciuojamas vidurkis?"<<endl;
    cout<<"vidurkis(v), mediana(m) ar abu(a)?"<<endl;
    cin>>x;
    cout<<setw(20)<<left<<"pavarde"<<setw(20)<<"vardas";
    switch(x){
        case 'v':
            cout<<setw(20)<<"galutinis(vid.)"<<endl;
            break;
        case 'm':
            cout<<setw(20)<<"galutinis(med.)"<<endl;
            break;
        case 'a':
            cout<<setw(20)<<left<<"galutinis(vid.)"<<setw(20)<<left<<"galutinis(med.)"<<endl;
            break;
    };
    for(int i=0;i<3;i++){
            switch(x){
        case 'v':
            cout<<setw(20)<<left<<s[i].pavarde<<setw(20)<<left<<s[i].vardas;
            cout<<endl<<setw(20)<<left<<fixed<<setprecision(2)<<s[i].vidurkis<<endl;
            break;
        case 'm':
            cout<<setw(20)<<left<<s[i].pavarde<<setw(20)<<left<<s[i].vardas;
            cout<<endl<<setw(20)<<left<<fixed<<setprecision(2)<<s[i].mediana<<endl;
            break;
        case 'a':
            cout<<setw(20)<<left<<s[i].pavarde<<setw(20)<<left<<s[i].vardas;
            cout<<setw(20)<<left<<fixed<<setprecision(2)<<s[i].vidurkis<<setw(20)<<left<<fixed<<setprecision(2)<<s[i].mediana<<endl;
            break;
    };
    }

    return 0;
}