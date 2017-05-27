#include <iostream>
#include <string>
#include <array>
#include <cmath>
#include <Windows.h>
#include "Porownywarka.h"
using namespace std;

void Porownywarka::Porownaj(Postac_uzytkownika &p1,Przeciwnik &p2)
{
	HANDLE gOut;
	gOut=GetStdHandle(STD_OUTPUT_HANDLE);
	int suma1=0; int suma2=0;
	int waga=1;
	array <char,9> punkty;
	//Porownywarka<char, 9> punkty;

	cout<<"Dokonano porownania Twojej postaci: "<<p1.nazwapostaci<<" "<<p1.typ<<" z postacia rywala: "<<p2.nazwapostaci<<" "<<p2.typ<<endl;
	for(int i=0; i< 9; i++)
	{
		if(i==0)
		{
			waga=2;
			if(p1.obrazeniaataku>p2.obrazeniaataku)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.obrazeniaataku<p2.obrazeniaataku)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twoj przeciwnik ma silny atak, zwieksz obrazenia swojego ataku!"<<endl;
			}
		}
		else if(i==1)
		{
			waga=1;
			if(p1.predkoscataku>p2.predkoscataku)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.obrazeniaataku<p2.obrazeniaataku)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twoj przeciwnik jest szybszy od Ciebie!"<<endl;
			}
		}
		else if(i==2)
		{
			waga=1;
			if(p1.odpornoscnamagie>p2.odpornoscnamagie)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.odpornoscnamagie<p2.odpornoscnamagie)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twojemu rywalowi nie straszne obrazenia magiczne!"<<endl;
			}
		}
		else if(i==3)
		{
			waga=1;
			if(p1.regeneracjazdrowia>p2.regeneracjazdrowia)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.regeneracjazdrowia<p2.regeneracjazdrowia)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twoj rywal szybciej regeneruje zdrowie!"<<endl;
			}
		}
		else if(i==4)
		{
			waga=2;
			if(p1.pancerz>p2.pancerz)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.pancerz<p2.pancerz)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twoj przeciwnik ma lepszy pancerz! Ulepsz swoj!"<<endl;
			}
		}
		else if(i==5)
		{
			waga=2;
			if(p1.zdrowie>p2.zdrowie)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.zdrowie<p2.zdrowie)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twoj przeciwnik ma wiecej zdrowia!"<<endl;
			}
		}
		else if(i==6)
		{
			waga=1;
			if(p1.regeneracjamany>p2.regeneracjamany)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.regeneracjamany<p2.regeneracjamany)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twoj rywal szybciej regeneruje mane!"<<endl;
			}
		}
		else if(i==7)
		{
			waga=2;
			if(p1.mana>p2.mana)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.mana<p2.mana)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twoj rywal ma wieksza ilosc many!"<<endl;
			}
		}
		else if(i==8)
		{
			waga=1;
			if(p1.predkoscruchu>p2.predkoscruchu)
			{
				suma1+=waga;
				punkty[i]='+';
			}
			else if(p1.predkoscruchu<p2.predkoscruchu)
			{
				suma2+=waga;
				punkty[i]='-';
				cout<<"Twoj rywal szybciej sie porusza!"<<endl;
			}
		}
	}
	cout<<"Wygrane kategorie: ";
	for(int i=0; i<9; i++)
	{
		if(punkty[i]=='+')
		{
			cout<<i<<")";
			cout<<punkty[i]<<" ";
		}
	}
	cout<<endl<<endl;
	if(suma1>suma2)
	{
		SetConsoleTextAttribute(gOut,FOREGROUND_GREEN | FOREGROUND_INTENSITY);
		if(suma1-suma2>=4) cout<<"Twoja postac jest zdecydowanie lepsza od przeciwnika. Twoje szanse na wygrana sa bardzo duze. GRATULACJE!"<<endl;
		else cout<<"Twoja postac jest lepsza od przeciwnika, lecz nie jest to miazdzaca przewaga. Przy dobrze rozplanowanej rozgrywce wygrasz. Powodzenia!"<<endl;
	}
	else if(suma2>suma1)
	{
		SetConsoleTextAttribute(gOut,FOREGROUND_RED | FOREGROUND_INTENSITY);
		if(suma2-suma1>=4) cout<<"Twoja postac jest duzo slabsza od przeciwnika. Na ten moment Porownywarka odradza atak!"<<endl;
		else cout<<"Twoja postac jest nie wiele slabsza od przeciwnika. Postaraj sie dobrze rozplanowac rozgrywke, a mozliwe ze wygrasz. Powodzenia!"<<endl;
	}
	else if(suma1==suma2)
	{
		SetConsoleTextAttribute(gOut,FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		cout<<"Obie postacie sa godnymi siebie rywalami. Szansa na zwyciestwo to 50%. Powodzenia!"<<endl;
	}
	//
}