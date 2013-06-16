/*
Listenmodul:
Verwaltet die Liste und beinhaltet die Pointer auf die CD Daten im CD Strukturmodul.
*/

#ifndef LISTE
#define LISTE

#include "cd_info.h"

#define DAT_NAME "Datei.dat"

typedef 
	struct cdliste {
		CD_Info * info;
		struct cdliste * next;
	} 
CD_Liste;
   
    void initListe (CD_Liste ** liste);
	//Initialisierung einer neuen Liste mit NULL-Pointer
	void einfuegenListe (CD_Liste ** liste, CD_Info * cd);
	//Koppelt Daten der CD mit Knoten der Liste
    void naechsteCD (CD_Liste * element);
	//Springt ein next weiter in der Liste.
	void loescheCD (CD_Liste ** liste, CD_Liste * element);
	//Loescht die Daten der CD, den Knoten und überbrückt
	//den vorherigen und den naechsten Knoten.
	int dateivorhanden (void);
	//Prüft, ob eine Datei mit einer Gespeicherten Liste vorhanden ist.
	//Gibt -1 zurück, falls keine datei vorhanden ist, sonst 1.

#endif
