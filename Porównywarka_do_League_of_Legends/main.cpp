/*PORÓWNYWARKA DO LEAGUE OF LEGENDS
£UKASZ KOKOSZA*/

#include <iostream>
#include <string>
#include <Windows.h>
#include "Uzytkownik.h"
#include "Generator.h"
#include "Porownywarka.h"
#include <iomanip>
using namespace std;
/** \mainpage Dokumentacja programu "Porownywarka do League of Legends"
*	Projekt koncowy - Inzynieria Oprogramowania
*	
*	@author Lukasz Kokosza
*
*	Inzynieria Obliczeniowa
*
*/
int main()
{
	string odp;
	string odp1;
	HANDLE gOut;
	gOut=GetStdHandle(STD_OUTPUT_HANDLE);
	Postac_uzytkownika user;
	Przeciwnik rywal;
	Generator generator;
	Porownywarka porownywarka;
	user.wybierzPostac();
	cout<<"Prosze czekac..."<<endl; Sleep(1000); system("cls");
	cout<<"Teraz czas na wybor Twojego przeciwnika! Kontynuuj..."<<endl;
	rywal.wybierzPostac();
	cout<<"Czy chcesz wygenerowac obie postacie (tak || nie)?"<<endl;
	cin>>odp;
	if(odp=="tak")
	{
		Sleep(1000); system("cls");
		SetConsoleTextAttribute(gOut,BACKGROUND_BLUE | FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_INTENSITY);
		generator.GenerujPostacie(user,rywal);
		cout<<"Porownaj postacie(tak)."; cin>>odp1; cout<<endl<<endl;
		porownywarka.Porownaj(user,rywal);
	}
	else{ exit(0); }
	system("pause");
	return 0;
}