#include <iostream>
using namespace std;

class Statystyki
{

public:
	/* ATAK FIZYCZNY */
	double obrazeniaataku;//zadawane obrazenia STATY waga=2
	double predkoscataku;//waga=1
	/* DEFENSYWA */
	double odpornoscnamagie;//zmniejsza obrazenia magiczne STATY waga=1
	double pancerz;//zmniejsza obrazenia fizyczne STATY waga=2
	double regeneracjazdrowia;//wartosc z gory ustalona STATY waga=1
	double zdrowie;//zdrowie postaci STATY waga=2
	/* ATAK MAGIA */
	double mana;//mana postaci STATY waga=2
	double regeneracjamany;//zwiekszenie szybkosci przywracania many STATY waga=1
	/* RUCH */
	double predkoscruchu;//wiadomo STATY waga=1
	/* ZWIEKSZANIE STATOW CO POZIOM */
	double zzdrowie;
	double rzdrowie;
	double zmana;
	double rmana;
	double zatak;
	double zpancerz;
	double znamagie;
};