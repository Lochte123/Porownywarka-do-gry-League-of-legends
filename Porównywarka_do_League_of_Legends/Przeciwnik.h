/*#pragma once
#ifndef AAA
#define AAA
#include "Postac.h"
#include "Wyswietlanie.h"
#include <iostream>
#include <string>
#include "Ekwipunek.h"
#include "Statystyki.h"
using namespace std;

class Przeciwnik : public Statystyki, Ekwipunek, postac, wyswietlanie
{
public:
	string typ;
	int wybierz;
	double pr;
	string nazwapostaci;
	int poziompostaci;
	Przeciwnik(string nazwa="Przeciwnik",int poziom=5): nazwapostaci(nazwa),poziompostaci(poziom){}//jakis tam randomowy
	void wybierzPostac();//uzytkownik wybiera postac, nazwa, typ, poziom
	double algorytmObliczeniaProcentu(int p);
	void poczatkoweStaty(int w,int p);
	void wyswietlStatyPostaci(double a,double b,double c,double d,double e,double f,double g,double h,double i);
	void ekwipunekPostaci(string postac);
};
#endif*/