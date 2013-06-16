/*
main.c:
Beinhaltet das Menü, in dem der User durch drücken verschiedener
die verschiedenen Funktionen des Programms starten
kann. Hier findet der Aufruf der Funktionen statt.
*/

#include <stdio.h>
#include "bearbeitung.h"
#include "liste.h"
#include "cd_info.h"

CD_Liste ** lade_datei (void)
{
	int datei_vorhanden;
	char eingabe;
	
		printf("Es wurde eine gespeicherte CD-Sammlung gefunden, soll diese Geladen werden?\n");
		scanf("%c", &eingabe);
		if ('y' == eingabe)
		{
			return einlesenDatei();
		}
		else if (eingabe != 'y' && eingabe != 'n')
		{
			printf("Ungueltige Eingabe!\n");
			lade_datei();
		}
}

void help(void)
{
		printf("(0) = Hilfe\n(1) = Speichern\n(2) = Aendern eines Elements\n(3) = Neues Element Einfügen\n(4) = Sotrieren der Liste\n(5) = Anzeigen der Aktuellen Liste\n(6) = Speichern der Liste\n(7) = Beenden des Programms\n");
}

int main(void)
{

//Variablendeklaration
  
	int ende = 0;
	int datei_vorhanden;
	CD_Liste **anker = NULL;
	int eingabe;
	int cd_nummer;


//Überprüfung: Datei bereits vorhanden?

	datei_vorhanden = dateivorhanden();
	if (datei_vorhanden==1)
		anker = lade_datei();
	else if (datei_vorhanden==-1)
		initListe(anker);
	else
	{
		printf("Fehler beim erstellen der Liste");
		return -1;
	}



//Benutzeroberfläche
	help();
	while(ende==0)
	{
		scanf("%i", &eingabe);
		switch (eingabe)
		{
		case 0:    //0 = Hilfe
			help();
			break;
		case 1:    //1 = Speichern der Liste in Datei
			speichereListe (anker);
			break;
		case 2:    //2 = Ändern eines Elements
			printf("Bitte die Nummer der zu aendernden CD eingeben.\n");
			scanf("%i", &cd_nummer);
			aendereCD (anker, cd_nummer);
			break;
		case 3:    //3 = Neues Element hinzufügen
			einfuegenListe (anker, einlesenCD ());
			break;
		case 4:     //4 = Sortieren der Liste
			sortiereSammlung (anker);
			break;
		case 5:     //5 = Anzeigen der Liste
			ausgebenSammlung (anker);
			break;
		case 6:     //6 = Speichern der Liste in der Datei
			if (anker!=NULL)
				speichereListe(anker);
			else
				printf("Liste ist leer und kann nicht in Datei gespeichert werden\n");
			break;
		case 7:     //7 = Beenden
			ende = 1;
			break;
		default:
			printf("Fehlerhafte eingabe, bitte versuchen sie es erneut.\n");
			help();
		}
		
	}

//Herunterfahren des Programms
	return 0;
}
