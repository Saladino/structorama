#include "liste.h"

void initListe (CD_Liste ** liste)
//Initialisierung einer neuen Liste mit NULL-Pointer
{
	CD_Liste * liste;
	liste = NULL;
}


void einfuegenListe (CD_Liste ** liste, CD_Info * cd)
//Koppelt Daten der CD mit Knoten der Liste
{
	CD_Liste * letztes_element = *liste;
	CD_Liste * neues_element;
	int i;

	for (i=0; (letztes_element->next != NULL); i++)
	{
		letztes_element = letztes_element->next;
	}

	neues_element = (CD_Liste*) malloc(sizeof(CD_Liste));
	letztes_element->next = neues_element;
	neues_element->info = cd;
	neues_element->next = NULL;
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
