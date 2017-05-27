#include <iostream>
#include <string>
#include <Windows.h>
#include "Generator.h"
using namespace std;

void Generator::GenerujPostacie(Postac_uzytkownika &p1,Przeciwnik &p2)
{
	cout<<"Nazwa Twojej postaci: "<<p1.nazwapostaci<<"   Typ: "<<p1.typ<<endl;
	cout<<"Poziom: "<<p1.poziompostaci<<endl;
	cout<<"Ekwipunek Twojej postaci: "<<endl;
	p1.wyswietlEkwipunek();
	cout<<"Statystyki Twojej postaci: "<<endl;
	p1.wyswietlStatyPostaci();
	cout<<endl<<endl;

	cout<<"Nazwa postaci Twojego rywala: "<<p2.nazwapostaci<<"   Typ: "<<p2.typ<<endl;
	cout<<"Poziom: "<<p2.poziompostaci<<endl;
	cout<<"Ekwipunek postaci Twojego rywala: "<<endl;
	p2.wyswietlEkwipunek();
	cout<<"Statystyki postaci Twojego rywala: "<<endl;
	p2.wyswietlStatyPostaci();

}
