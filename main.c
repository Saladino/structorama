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


void help(void)
{
	printf("(1) = Hilfe\n(2) = Aendern eines Elements\n(3) = Neues Element Einfuegen\n(4) = Sortieren der Liste\n(5) = Anzeigen der Aktuellen Liste\n(6) = Speichern der Liste\n(7) = Loeschen einer CD\n(8) = Beenden des Programms\n");
}

void hilfe(void)
{
    printf("Guten Tag, sehr geehrter User\nDie Zahlen vor den einzelnen Menuefunktionen, dienen zum Steuern des Programms.\nEin druecken der jeweiligen Zahlentaste mit anschliessendem \nBestaetigen der Entertaste started die jeweilige Funktion.\nFuer weitere Infos werfen Sie bitte einen Blick ins Benutzerhandbuch!\nWeiterhin noch viel Spass mit dem Programm.\n");
}


int main(void)
{

	//Variablendeklaration

	int ende = 0;
	int datei_vorhanden;
	CD_Liste *anker = NULL;
	char eingabe1;
	char eingabe2;
	int cd_nummer;


	//Überprüfung: Datei bereits vorhanden?
	initListe(&anker);
	datei_vorhanden = dateivorhanden();
	if (datei_vorhanden==1)
	{
		do
		{
			printf("Es wurde eine gespeicherte CD-Sammlung gefunden, soll diese Geladen werden?(y/n)\n");
			scanf("%c", &eingabe2);
			fflush(stdin);
			if ('y' == eingabe2)
			{
				einlesenDatei(&anker);
			}
			else if (eingabe2 != 'n')
			{
				printf("Ungueltige Eingabe!\n");

			}
		}
		while (eingabe2 != 'y' && eingabe2 != 'n');
	}
	else if (datei_vorhanden!=-1 && datei_vorhanden!=1)
	{
		printf("Fehler beim erstellen der Liste");
		return -1;
	}



	//Benutzeroberfläche

	while(ende==0)
	{
		printf("Bitte befehl eingeben\n");
		help();
		eingabe1 = getchar();
		fflush(stdin);
		switch (eingabe1)
		{
		case '1':    //1 = Hilfe
            		hilfe();
            		break;
		case '2':    //2 = Ändern eines Elements
			printf("Bitte die Nummer der zu aendernden CD eingeben.\n");
			scanf("%i", &cd_nummer);
			fflush(stdin);
			aendereCD (&anker, cd_nummer);
			break;
		case '3':    //3 = Neues Element hinzufügen
			einfuegenListe (&anker, einlesenCD ());
			break;
		case '4':     //4 = Sortieren der Liste
			anker = sortiereSammlung (&anker);
			break;
		case '5':     //5 = Anzeigen der Liste
			ausgebenSammlung (&anker);
			break;
		case '6':     //6 = Speichern der Liste in der Datei
			if (anker!=NULL)
				speichereListe(&anker);
			else
				printf("Liste ist leer und kann nicht in Datei gespeichert werden\n");
			break;
		case '8':     //8 = Beenden
			ende = 1;
			break;
		case '7':		//7 = Element Löschen
			printf("Bitte geben sie die Nummer der zu loeschenden CD an\n");
			scanf("%i", &cd_nummer);
			fflush(stdin);
			loescheCD_nr (&anker, cd_nummer);
			break;
		default:
			printf("Fehlerhafte eingabe, bitte versuchen sie es erneut.\n");
		}
		printf("\n");
	}

	//Herunterfahren des Programms
	return 0;
}
