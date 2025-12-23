#include <iostream>
#include <fstream>
#include <string>
using namespace std;
 
int main(){
string tekstas;

ifstream ivestis("zodziai.txt");
while (getline (ivestis, tekstas)) {
  cout<<tekstas<<endl;
}
ivestis.close();
}