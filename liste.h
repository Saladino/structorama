/*
Listenmodul:
Verwaltet die Liste und beinhaltet die Pointer auf die CD Daten im CD Strukturmodul.
*/

#ifndef LISTE
#define LISTE

#include "cd_info.h"

typedef 
  struct cdliste {
		CD_Info * info;
		struct cdliste * next;
	} 
CD_Liste;
   
    void initListe (CD_Liste ** liste);
	//Initialisierung mit NULL-Pointer
	void einfuegenListe (CD_Liste ** liste, CD_Info * cd);
	//Koppelt Daten der CD mit Knoten der Liste
    void naechsteCD (CD_Liste ** liste);
	//Springt ein next weiter in der Liste.
	


#endif
