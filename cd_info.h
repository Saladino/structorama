/*
CD Strukturmodul:
Der eigentliche Informationsträger im Programm. In diesem Modul
sind die Daten der CD gespeichert.
*/

#ifndef CD_INFO
#define CD_INFO

//Deklarationen

typedef struct songliste
  {
		int nummer;
		char songname[20];
	}
Songs;

typedef struct erscheinungsdatum
	{
		int Tag;
		int Monat;
		int Jahr;
	}
Datum;

typedef struct cd_info
	{ 
		char cd_name [21];
		char interpret_name [21];
		Songs song[21];
		char genre [21];
		Datum erscheinung;
	}
CD_Info;

//Funktionen

CD_Info * einlesenCD (void);
void aendernCD (CD_Info * cd);

#endif
