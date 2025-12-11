#ifndef STUDENTAS_LIST_H
#define STUDENTAS_LIST_H

#include <iostream>
#include <string>
#include <iomanip>
#include <list>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <sstream>

using namespace std;

struct Studentas {
    string vardas, pavarde;
    vector<int> nd;
    int egz;
    double vidurkis, mediana;
};

int RandomSk(int max);
bool LyginimasStr(const Studentas &petras, const Studentas &jonas);
double Mediana(vector<int> pazymiai);
double Vidurkis(vector<int> pazymiai);
void GeneruotiDuomenis();
void Skaitymas(list<Studentas> &s, string failas);
void Ivedimas(list<Studentas> &s, bool generuoti);
void Rusiavimas(list<Studentas>& s, list<Studentas>& g, list<Studentas>& v);
void Rasymas(list<Studentas> s, string x);
void Rezultatai(list<Studentas> s);
void Meniu();

#endif
