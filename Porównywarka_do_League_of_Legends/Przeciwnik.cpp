#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <Windows.h>
#include "Uzytkownik.h"
#include <iomanip>
using namespace std;

void Przeciwnik::wybierzPostac()
{
		HANDLE gOut;
		gOut=GetStdHandle(STD_OUTPUT_HANDLE);
		SetConsoleTextAttribute(gOut,FOREGROUND_RED );
		cout<<"Podaj nazwe(nick) postaci Twojego rywala w grze League of Legends: ";	cin>>nazwapostaci;	cout<<endl;
		cout<<"Wybierz klase postaci Twojego rywala wpisujac odpowiadajaca jej liczbe:"<<endl<<endl;
	do
	{
		cout<<"1) Kayle"<<endl;
		cout<<"2) Rek'sai"<<endl;
		cout<<"3) Tristana"<<endl;
		cout<<"4) Trundle"<<endl;
		cout<<"5) Zac"<<endl;
		cin>>wybierz;	 cout<<endl;
		if(wybierz==1) {typ="Kayle";	cout<<"Postac Twojego rywala to "<<typ<<endl;}
		if(wybierz==2) {typ="Rek'sai";	cout<<"Postac Twojego rywala to "<<typ<<endl;}
		if(wybierz==3) {typ="Tristana";	cout<<"Postac Twojego rywala to "<<typ<<endl;}
		if(wybierz==4) {typ="Trundle";	cout<<"Postac Twojego rywala to "<<typ<<endl;}
		if(wybierz==5) {typ="Zac";		cout<<"Postac Twojego rywala to "<<typ<<endl;}
		if(wybierz<1 || wybierz>5) cout<<"Niestety nie ma takiej postaci w bazie, wybierz jeszcze raz."<<endl;
	}while(wybierz<1 || wybierz>5);

	do
	{
		cout<<"Podaj aktualny poziom postaci Twojego rywala od 1 do 18: "; cin>>poziompostaci; cout<<endl; 
		if(poziompostaci<1 || poziompostaci>18) cout<<"BLAD!"<<endl;
	}while(poziompostaci<1 || poziompostaci>18);
	cout<<"Statystyki(bez ekwipunku) dla "<<poziompostaci<<" poziomu:"<<endl;
	if(poziompostaci>=2){ cout<<"Prosze czekac..."<<endl; Sleep(1000); system("cls");}
	poczatkoweStaty(wybierz,poziompostaci);
	ekwipunekPostaci(typ);
}
double Przeciwnik::algorytmObliczeniaProcentu(int p)
{
	double procentWzrostu=0;
	double kolejnyPoziom;
	int Poziom=1;

	for(int i=Poziom; i<p; i++)
	{
		kolejnyPoziom=(i*3.5)+65;
		procentWzrostu+=kolejnyPoziom;
	}
	return procentWzrostu/100;
}

double Przeciwnik::opoznienieAtaku(double predkosc,int poziom, double procent)
{
	srand(time(NULL));
	int a,b;
	double opoznic,wynik,w;

	a=-1+rand()%3; if(a==0) { a=1; }
	b=1+rand()%8;

	opoznic=(a*(1/b))*0.1;
	wynik=predkosc/(1-opoznic);
	procent=((procent*poziom)+100)/100;
	w=wynik*procent;
	if(w>=2.51) { w=2.50; }
	return w;
}

void Przeciwnik::wyswietlStatyPostaci()
{
	cout<<"0) Obrazenia ataku = "<<obrazeniaataku<<"      "<<"1) Predkosc ataku = "<<predkoscataku<<endl;
	cout<<"2) Odpornosc na magie = "<<odpornoscnamagie<<"      "<<"3) Regeneracja zdrowia = "<<regeneracjazdrowia<<endl;
	cout<<"4) Pancerz = "<<pancerz<<"      "<<"5) Zdrowie = "<<zdrowie<<endl;
	cout<<"6) Regeneracja many = "<<regeneracjamany<<"    "<<"7) Mana = "<<mana<<endl;
	cout<<"8) Predkosc ruchu = "<<predkoscruchu<<endl;
}

void Przeciwnik::wyswietlEkwipunek()
{
	if(Miecz==true) { cout<<"Miecz: "<<nazwaMiecza<<endl; }
	if(Luk==true) { cout<<"Luk: "<<nazwaLuku<<endl; }
	if(Zbroja==true) { cout<<"Zbroja: "<<nazwaZbroi<<endl; }
	if(Buty==true) { cout<<"Buty: "<<nazwaButow<<endl; }
	cout<<endl;
}

void Przeciwnik::poczatkoweStaty(int w,int p)
{
	pr=algorytmObliczeniaProcentu(p);

	if(w==1)//dla Kayle
	{
		/* Zwiekszanie */
		zzdrowie=93*pr; rzdrowie=0.75*pr; zmana=40*pr; rmana=0.8*pr; zatak=2.8*pr;
		zpancerz=3.5*pr; znamagie=0*pr;
		/* Statystyki koncowe */
		zdrowie=481.24+zzdrowie; regeneracjazdrowia=7.5+rzdrowie; mana=282.2+zmana;	regeneracjamany=5.2+rmana; obrazeniaataku=48.204+zatak; 
		predkoscataku=opoznienieAtaku(0.638,poziompostaci,2.5);
		pancerz=23.38+zpancerz;	odpornoscnamagie=30+znamagie; predkoscruchu=335;	
		wyswietlStatyPostaci();
	}
	else if(w==2)//dla Rek'sai
	{
		/* Zwiekszanie */
		zzdrowie=90*pr; rzdrowie=0.65*pr; zmana=40*pr; rmana=0*pr; zatak=3.35*pr;
		zpancerz=3.75*pr; znamagie=1.25*pr;
		/* Statystyki koncowe */
		zdrowie=570+zzdrowie; regeneracjazdrowia=7.34+rzdrowie; mana=100+zmana;	regeneracjamany=0+rmana; obrazeniaataku=55.628+zatak; 
		predkoscataku=opoznienieAtaku(0.625,poziompostaci,2);
		pancerz=28.3+zpancerz;	odpornoscnamagie=32.1+znamagie; predkoscruchu=335;	
		wyswietlStatyPostaci();
	}
	else if(w==3)//dla Tristany
	{
		/* Zwiekszanie */
		zzdrowie=82*pr; rzdrowie=0.65*pr; zmana=32*pr; rmana=0.45*pr; zatak=2.41*pr;
		zpancerz=3*pr; znamagie=0*pr;
		/* Statystyki koncowe */
		zdrowie=460+zzdrowie; regeneracjazdrowia=5.54+rzdrowie; mana=214.76+zmana;	regeneracjamany=6.755+rmana; obrazeniaataku=54.65+zatak; 
		predkoscataku=opoznienieAtaku(0.658,poziompostaci,1.5);
		pancerz=19+zpancerz;	odpornoscnamagie=30+znamagie; predkoscruchu=325;	
		wyswietlStatyPostaci();
	}
	else if(w==4)//dla Trundle
	{
		/* Zwiekszanie */
		zzdrowie=96*pr; rzdrowie=0.85*pr; zmana=45*pr; rmana=0.6*pr; zatak=3*pr;
		zpancerz=2.7*pr; znamagie=1.25*pr;
		/* Statystyki koncowe */
		zdrowie=520.28+zzdrowie; regeneracjazdrowia=8.575+rzdrowie; mana=236.6+zmana;	regeneracjamany=6.905+rmana; obrazeniaataku=57.04+zatak; 
		predkoscataku=opoznienieAtaku(0.672,poziompostaci,2.9);
		pancerz=24.838+zpancerz;	odpornoscnamagie=30.85+znamagie; predkoscruchu=350;	
		wyswietlStatyPostaci();
	}
	else if(w==5)//dla Zac'a
	{
		/* Zwiekszanie */
		zzdrowie=95*pr; rzdrowie=0.55*pr; zmana=0*pr; rmana=0*pr; zatak=3.38*pr;
		zpancerz=3.5*pr; znamagie=1.25*pr;
		/* Statystyki koncowe */
		zdrowie=519.6+zzdrowie; regeneracjazdrowia=7.37+rzdrowie; mana=0+zmana;	regeneracjamany=0+rmana; obrazeniaataku=56.295+zatak; 
		predkoscataku=opoznienieAtaku(0.638,poziompostaci,1.6);
		pancerz=20.38+zpancerz;	odpornoscnamagie=30.85+znamagie; predkoscruchu=335;	
		wyswietlStatyPostaci();
	}
	else{cout<<"BLAD!"<<endl;}
}

void Przeciwnik::ekwipunekPostaci(string postac)
{
	int licznik=3;
	int wybor,wyborMiecz,wyborLuk,wyborZbroja,wyborButy;
	Miecz=false,Luk=false,Zbroja=false,Buty=false;
	cout<<endl;
	cout<<"Wybierz ekwipunek dla swojej postaci (postac moze walczyc tylko mieczem lub tylko strzelac z luku): "<<postac<<endl;
	do
	{
		cout<<"1) Miecze"<<"  "<<"2) Luki"<<"  "<<"3) Zbroje"<<"  "<<"4) Buty"<<endl;
		cout<<"Zostaly "<<licznik<<" przedmioty do wybrania."<<endl;
		cin>>wybor; cout<<endl; 
		if(wybor==1 && Miecz!=true && Luk!=true)//miecze
		{
			cout<<"1) Dlugi miecz: +10pkt. obrazen od ataku"<<endl;
			cout<<"2) Ostrze poszukiwacza: +16pkt. obrazen od ataku, +15% do predkosci ataku"<<endl;
			cout<<"3) Sztylet: +15% do predkosci ataku"<<endl;
			cout<<"4) Koniec Rozumu: +25pkt. odpornosc na magie, +50% do predkosci ataku"<<endl;
			cout<<"Wybierz miecz:"; cin>>wyborMiecz; cout<<endl;
			switch(wyborMiecz)
			{
			case 1:
				obrazeniaataku=obrazeniaataku+10;
				nazwaMiecza="Dlugi miecz";
				break;
			case 2:
				obrazeniaataku=obrazeniaataku+16;
				double pp;
				pp=(predkoscataku*15)/100;
				predkoscataku=predkoscataku+pp;
				if(predkoscataku>=2.51) { predkoscataku=2.50; }
				nazwaMiecza="Ostrze poszukiwacza";
				break;
			case 3:
				double pp1;
				pp1=(predkoscataku*15)/100;
				predkoscataku=predkoscataku+pp1;
				if(predkoscataku>=2.51) { predkoscataku=2.50; }
				nazwaMiecza="Sztylet";
				break;
			case 4:
				odpornoscnamagie=odpornoscnamagie+25;
				double pp2;
				pp2=(predkoscataku*50)/100;
				predkoscataku=predkoscataku+pp2;
				if(predkoscataku>=2.51) { predkoscataku=2.50; }
				nazwaMiecza="Koniec Rozumu";
				break;
			}
			cout<<"Wybrales miecz: "<<nazwaMiecza<<endl;
			Miecz=true;
			licznik--;
		}
		else if(wybor==2 && Luk!=true && Miecz!=true)//luki
		{
			cout<<"1) Wygiety luk: +30% do predkosci ataku"<<" "<<"2) Huragan Runaana: +70% do predkosci ataku"<<endl;
			cout<<"Wybierz luk:"; cin>>wyborLuk; cout<<endl;
			switch(wyborLuk)
			{
			case 1:
				double p1;
				p1=(predkoscataku*30)/100;
				predkoscataku=predkoscataku+p1;
				if(predkoscataku>=2.51) { predkoscataku=2.50; }
				nazwaLuku="Wygiety luk";
				break;
			case 2:
				double p2;
				p2=(predkoscataku*70)/100;
				predkoscataku=predkoscataku+p2;
				if(predkoscataku>=2.51) { predkoscataku=2.50; }
				nazwaLuku="Huragan Runaana";
				break;
			}
			cout<<"Wybrales luk: "<<nazwaLuku<<endl;
			Luk=true;
			licznik--;
		}
		else if(wybor==3 && Zbroja!=true)
		{
			cout<<"1) Plaszcz Raptora: +30pkt. do pancerza, +100% do regeneracji zdrowia"<<endl;
			cout<<"2) Lodowcowy Calun: +25pkt. do pancerza, +250pkt. do many"<<endl;
			cout<<"3) Plaszcz Negacji: +45pkt. do odpornosci na magie"<<endl;
			cout<<"Wybierz zbroje:"; cin>>wyborZbroja; cout<<endl;
			switch(wyborZbroja)
			{
			case 1:
				pancerz=pancerz+30;
				zdrowie=zdrowie*2;
				nazwaZbroi="Plaszcz Raptora";
				break;
			case 2:
				pancerz=pancerz+25;
				mana=mana+250;
				nazwaZbroi="Lodowcowy calun";
				break;
			case 3:
				odpornoscnamagie=odpornoscnamagie+45;
				nazwaZbroi="Plaszcz Negacji";
				break;
			}
			cout<<"Wybrales zbroje: "<<nazwaZbroi<<endl;
			Zbroja=true;
			licznik--;
		}
		else if(wybor==4 && Buty!=true)
		{
			cout<<"1) Buty ruchliwosci: +25pkt. do predkosci ruchu"<<endl;
			cout<<"2) Nagolenniki Berserkera: +45pkt. do predkosci ruchu"<<endl;
			cout<<"3) Obuwie Merkurego: +25pkt. do odpornosci na magie"<<endl;
			cout<<"Wybierz buty:"; cin>>wyborButy; cout<<endl;
			switch(wyborButy)
			{
			case 1:
				predkoscruchu=predkoscruchu+25;
				nazwaButow="Buty ruchliwosci";
				break;
			case 2:
				predkoscruchu=predkoscruchu+45;
				nazwaButow="Nagolenniki Berserkera";
				break;
			case 3:
				odpornoscnamagie=odpornoscnamagie+25;
				nazwaButow="Obuwie Merkurego";
				break;
			}
			cout<<"Wybrales buty: "<<nazwaButow<<endl;
			Buty=true;
			licznik--;
		}
	}while(licznik>0);
	system("cls");
	cout<<"Ekwipunek Twojego rywala to:"<<endl;
	if(Miecz==true) { cout<<"Miecz: "<<nazwaMiecza<<endl; }
	if(Luk==true) { cout<<"Luk: "<<nazwaLuku<<endl; }
	if(Zbroja==true) { cout<<"Zbroja: "<<nazwaZbroi<<endl; }
	if(Buty==true) { cout<<"Buty: "<<nazwaButow<<endl; }
	cout<<endl;
	cout<<"Nowe statystyki Twojego rywala: "<<endl;
	wyswietlStatyPostaci();
}