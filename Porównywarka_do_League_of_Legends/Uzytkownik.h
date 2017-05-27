#pragma once
#ifndef AA
#define AA
#include "Postac.h"
#include "Wyswietlanie.h"
#include <iostream>
#include <string>
#include "Ekwipunek.h"
#include "Statystyki.h"
using namespace std;

class Postac_uzytkownika : public Statystyki, Ekwipunek, postac, wyswietlanie
{
private:
	bool Miecz,Luk,Zbroja,Buty;
	int wybierz;
	double pr;
public:
	string typ;
	string nazwapostaci;
	int poziompostaci;
	Postac_uzytkownika(string nazwa="Uzytkownik",int poziom=5): nazwapostaci(nazwa),poziompostaci(poziom){}//jakis tam randomowy
	void wybierzPostac();//uzytkownik wybiera postac, nazwa, typ, poziom
	double algorytmObliczeniaProcentu(int p);
	double opoznienieAtaku(double predkosc,int poziom,double procent);
	void poczatkoweStaty(int w,int p);
	void wyswietlStatyPostaci();
	void ekwipunekPostaci(string postac);
	void wyswietlEkwipunek();
};

class Przeciwnik : public Statystyki, Ekwipunek, postac, wyswietlanie
{
private:
	bool Miecz,Luk,Zbroja,Buty;
	int wybierz;
	double pr;
public:
	string typ;
	string nazwapostaci;
	int poziompostaci;
	Przeciwnik(string nazwa="Przeciwnik",int poziom=5): nazwapostaci(nazwa),poziompostaci(poziom){}//jakis tam randomowy
	void wybierzPostac();//uzytkownik wybiera postac, nazwa, typ, poziom
	double algorytmObliczeniaProcentu(int p);
	double opoznienieAtaku(double predkosc,int poziom,double procent);
	void poczatkoweStaty(int w,int p);
	void wyswietlStatyPostaci();
	void ekwipunekPostaci(string postac);
	void wyswietlEkwipunek();
};
#endif