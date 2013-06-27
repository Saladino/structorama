#include "cd_info.h"

CD_Info * einlesenCD (void)
{
	int i = 0;
	CD_Info *cd = NULL;
	cd = (CD_Info*) malloc (sizeof(CD_Info));
	printf("\nGeben Sie den CD-Namen an: ");
	scanf("%s", cd->cd_name);
	fflush(stdin);
	printf("\nGeben Sie den Interpreten an: ");
	scanf("%s", cd->interpret_name);
	fflush(stdin);
	printf("\nGeben Sie das Erscheinungsdatum an:\n");
	do{
		printf("Tag: ");
		scanf("%i", &(cd->erscheinung.Tag));
		fflush(stdin);
	} while( (cd->erscheinung.Tag<1)||(31<cd->erscheinung.Tag));
	do{
		printf("Monat: ");
		scanf("%i", &(cd->erscheinung.Monat));
		fflush(stdin);
	} while( (cd->erscheinung.Monat<1)||(12<cd->erscheinung.Monat));
	do{
		printf("Jahr: ");
		scanf("%i", &(cd->erscheinung.Jahr));
		fflush(stdin);
	} while( (cd->erscheinung.Jahr<1)||(9999<cd->erscheinung.Jahr));
	printf("\nGeben Sie das Genre an: ");
	scanf("%s", cd->genre);
	fflush(stdin);
	do{
		printf("\nWieviele Songs wollen Sie eingeben: ");
		scanf("%i", &(cd->song_anzahl));
		fflush(stdin);
	} while((cd->song_anzahl<0)||(21<cd->song_anzahl));
	for (i=0; i < cd->song_anzahl; i++)
	{
		printf("\nSong %i: ", i+1);
		scanf("%s", &(cd->song[i].songname));
		fflush(stdin);
	}
	return cd;
}
