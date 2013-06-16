#include "liste.h"
#include <stdlib.h>

void initListe (CD_Liste ** liste)
//Initialisierung einer neuen Liste mit NULL-Pointer
{
	*liste = NULL;
}


void einfuegenListe (CD_Liste ** liste, CD_Info * cd)
//Koppelt Daten der CD mit Knoten der Liste
{
	CD_Liste * letztes_element = NULL;
	CD_Liste * neues_element = NULL;
	int i = 0;
	if (*liste!=NULL)
	{
		letztes_element = *liste;

		for (i=0; ((letztes_element->next)!=NULL); i++)
		{
			letztes_element = letztes_element->next;
		}
	
		neues_element = (CD_Liste*) malloc(8);
		letztes_element->next = neues_element;
		neues_element->info = cd;
		neues_element->next = NULL;
	}
	else
	{
		neues_element = (CD_Liste*) malloc(8);
		neues_element->info = cd;
		neues_element->next = NULL;
		*liste = neues_element;
	}
}


void naechsteCD (CD_Liste * element)
//Springt ein next weiter in der Liste.
{
	element = element->next;
}


void loescheCD (CD_Liste ** liste, CD_Liste * element)
//Loescht die Daten der CD, den Knoten und überbrückt
//den vorherigen und den naechsten Knoten.
{
	CD_Liste * naechstes_element = element->next;
	CD_Liste * voriges_element = * liste;
	int i;

	do
	{
		voriges_element = voriges_element->next;
	}
	while (voriges_element->next != element);

	voriges_element->next = element->next;
	free(element->info);
	free(element);
}

int dateivorhanden (void)
//Prüft, ob eine Datei mit dit einer Gespeicherten Liste vorhanden ist.
//Gibt -1 zurück, falls keine datei vorhanden ist, sonst 1.
{
	FILE *tmp = fopen(DAT_NAME,"r");
	if (tmp==NULL)
		return -1;
	else
	{
		fclose(tmp);
		return 1;
	}
}
