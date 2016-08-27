#include <iostream>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <cstdio>

using namespace std;

//dichiarazione costanti e tipi
//utilizzo le costanti in modo da poter modificare semplicemente le capacità del programma
const int c=3;
const int dim=500000;
typedef char stringa [dim];

struct Osservazione{
	int mese;
	int anno;
	double temperatura;
};

typedef Osservazione vett_oss [c];

//prototipi funzioni
void input(vett_oss v);
double converti_F(double t);
double converti_K(double t);
void Visualizza(const vett_oss v);
void MaxTemp(const vett_oss v);
void cerca(const vett_oss v);
