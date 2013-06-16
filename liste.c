#include "liste.h"
#include <stdlib.h>

void initListe (CD_Liste ** liste)
//Initialisierung einer neuen Liste mit NULL-Pointer
{
	*liste = NULL;
}


void loescheCD (CD_Liste ** liste, CD_Liste * element)
//Loescht die Daten der CD, den Knoten und überbrückt
//den vorherigen und den naechsten Knoten.
{
	CD_Liste * naechstes_element = element->next;
	CD_Liste * voriges_element = * liste;
	int i;
	if (voriges_element != NULL)
	{
		while (voriges_element->next != element);
		{
			voriges_element = voriges_element->next;
		}
		
	}

	voriges_element->next = element->next;
	free(element->info);
	free(element);
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
