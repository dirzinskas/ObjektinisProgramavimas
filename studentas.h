#ifndef STUDENTAS_H
#define STUDENTAS_H

#include <iostream>
#include <string>
#include <iomanip>
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
void Skaitymas(vector<Studentas> &s, string failas);
void Ivedimas(vector<Studentas> &s, bool generuoti);
void Rusiavimas(vector<Studentas>& s, vector<Studentas>& g, vector<Studentas>& v);
void Rasymas(vector<Studentas> s, string x);
void Rezultatai(vector<Studentas> s);
void Meniu();

#endif
