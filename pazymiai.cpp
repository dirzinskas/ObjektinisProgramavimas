#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

struct Studentas{
    string vardas, pavarde;
    int nd1, nd2, nd3, egz;
    double galutinis;
    };

int main() {

    Studentas s[3];

    for(int i=0;i<3;i++){
        cout<<"iveskite " <<i+1 <<"-ojo studento varda, pavarde, triju nd ir egzamino rezultatus:"<<endl;
        cin>>s[i].vardas>>s[i].pavarde>>s[i].nd1>>s[i].nd2>>s[i].nd3>>s[i].egz;
        s[i].galutinis=0.4*((s[i].nd1+s[i].nd2+s[i].nd3+s[i].egz)/3) + s[i].egz*0.6;
    }

    

    cout<<setw(20)<<left<<"pavarde"<<setw(20)<<"vardas"<<setw(20)<<"galutinis(vid.)"<<endl;
    for(int i=0;i<3;i++){
        cout<<setw(20)<<left<<s[i].pavarde<<setw(20)<<left<<s[i].vardas<<setw(20)<<left<<fixed<<setprecision(2)<<s[i].galutinis<<endl;
    }

    return 0;
}