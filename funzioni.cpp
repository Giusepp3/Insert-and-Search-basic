#include "libreria.h"

//la funzione di input, un po intricata, ma dovuta alle numerose scelte richieste dal docente
void input(vett_oss v){
	for(int i=0;i<c;i++){
		cout << "Inserisci i valori per l'osservazione numero " << i+1 << endl;
		do{
			cout << "Mese"<<endl;
			cin >> v[i].mese;
			if(!(v[i].mese>=1 && v[i].mese <=12)){
				cout << "Il mese deve essere compreso tra 1 e 12!!! \n\n";
			}
		}while(!(v[i].mese>=1 && v[i].mese <=12));
		cout << "\nInserisci ora l'anno "<< endl;
		do{
			cin >> v[i].anno;
			if(!(v[i].anno>=1900 && v[i].anno<=2015)){
				cout << "Il valore dell'anno deve essere compreso tra 1900 e 2015\n\n";
			}
		}while(!(v[i].anno>=1900 && v[i].anno<=2015));
		double t;
		char u;
		do{
		cout << "Inserisci il valore della temperatura:\n";
		cin >> t;
		cout << "Qual'e l'unita di misura per la temperatura inserita?\n";
		cin >> u;
		//voglio dare la possibilità di indicare l'unità di misura in maiuscolo, ma anche in minuscolo
		if(!(u=='K'|| u=='F'|| u=='C'||u=='k'||u=='f'||u=='c')||(t<0&&(u=='k'||u=='K'))){
			cout << "devi inserire i valori corretti!\n";
		}
		}while(!(u=='K'|| u=='F'|| u=='C'||u=='k'||u=='f'||u=='c')||(t<0&&(u=='k'||u=='K')));
		if(u=='k'||u=='K'){
			v[i].temperatura=converti_K(t);
		}else if(u=='F'||u=='f'){
			v[i].temperatura=converti_F(t);
		}else if(u=='c'||u=='C'){
			v[i].temperatura=t;
		}
	}
}
//realizzo le funzioni di conversione solo per rendere il codice piu leggibile e curato
double converti_F(double t){
	double c;
	c=t-32;
	c=c/1.8;
	return c;
}

double converti_K(double t){
	double c;
	c=t-272.15;
	return c;
}

void Visualizza(const vett_oss v){
	cout << "Elenco osservazioni:\n\n";
	for(int i=0;i<c;i++){
		cout << v[i].mese<<"/"<<v[i].anno<<" : "<<v[i].temperatura << 'C'<<endl;
	}
}

void MaxTemp(const vett_oss v){
	Osservazione D;
	D.temperatura=0;
	for(int i=0;i<c;i++){
		if(v[i].temperatura>=D.temperatura){
			D=v[i];
			}
	}
	cout << "La temperatura massima rilevata e di " << D.temperatura << " Gradi Celsius, misurata in " << D.mese <<"/"<<D.anno<<endl;
}

void cerca(const vett_oss v){
	double t;
	cout << "Inserisci la temperatura da cercare: \n";
	cin >> t;
	//preferisco dichiarare queste variabili per poter regolare semplicemente la precisione di ricerca
	int a;
	a=int(t)-1;
	int b;
	b=int(t)+1;
	cout << "controllo risultati per temperature vicine a " << t << " C"<< endl;
	for(int i=0;i<c;i++){
		if(v[i].temperatura>=a && v[i].temperatura<=b){
			cout << "La temperatura " << v[i].temperatura<<" si avvicina molto a " << t << " ed e stata rilevata in data " << v[i].mese<<"/"<<v[i].anno<<endl;
		}
	}
}
