/*
Bearbeitungsmodul:
Hier geschehen die eigentlichen Funktionen des Programms,
die der Benutzer in Gang gesetzt hat:
-Liste hinzufügen
-ändere CD
-sortiere Sammlung
-initialisiere alte Liste
-einlesen von Datei
-speichere in Datei
-Sammlung ausgeben

Dazu greift das Bearbeitungsmodul häufig auf das Listenmodul zu.
*/


#ifndef BEARBEITUNG
#define BEARBEITUNG
#include "liste.h"

void ausgebenSammlung (CD_Liste ** anker);
//Liste wird nummeriert ausgegeben.

void aendereCD (CD_Info * cd, int CD_nr);
//Liste muss(!) für CD_nr davor nummeriert ausgegeben werden!!!

//Whileschleife für Änderung der Infos mit Endbedingung
//Auswahl wie bei main-Funktion mit Nummern!

void loescheCD_nr (CD_Liste ** anker, int CD_nr);
//Liste muss(!) für CD_nr davor nummeriert ausgegeben werden!!!

//Verwendet Funktion naechsteCD solange bis CD_nr erreicht ist.
//Anschließend wird loescheCD ausgeführt.

void sortiereSammlung (CD_Liste ** anker_alt);
//Elemente der alten Liste werden in eine neu-initialisierte Liste
//solange übergeben, bis der anker_alt = NULL ist. Die Bedingung für die
//Sortierung ist hier falsch herum, aufgrund des Last-In First-Out Stacks.(!)
//anker_alt wird dann auf anker_neu gesetzt.

CD_Liste ** anker einlesenDatei (void);
//initListe wird ausgeführt um neue Liste zu erstellen.
//Aus der Datei werden dann die Elemente hinzugefügt.

void speichereListe (CD_Liste ** anker);
//Die Liste wird in eine Datei geschrieben. Hierbei muss berücksichtigt werden,
//ob es eine bereits gespeicherte Liste gibt und diese korrekt überschrieben
//weden muss.

#endif