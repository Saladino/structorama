#include "bearbeitung.h"

void aendereMerkmal (CD_Info * cd);
CD_Liste* sortieren (CD_Liste ** anker, int a, int b);

void ausgebenSammlung (CD_Liste ** anker)
{
	int i = 1, j = 0;
	CD_Liste *tmp = *anker;


	while (tmp != NULL)
	{
		printf("\nCD Nummer:         %i", i);
		printf("\nCD Name:           %s", tmp->info->cd_name);
		printf("\nInterpret:         %s", tmp->info->interpret_name);
		printf("\nErscheinungsdatum: %i.%i.%i", tmp->info->erscheinung.Tag, tmp->info->erscheinung.Monat, tmp->info->erscheinung.Jahr);
		printf("\nGenre:             %s", tmp->info->genre);
		printf("\nSongs:             ");
		while (tmp->info->song_anzahl > j)
		{
			if(j==0) printf("%i. %s", j+1, tmp->info->song[j].songname);
			else printf(", %i. %s", j+1, tmp->info->song[j].songname);
			j++;
		}
		j=0;
		i++;
		tmp= tmp->next;
		printf("\n");
	}
	printf("\n");
}

void aendereCD (CD_Liste ** anker, int CD_nr)
{
    int j=1;
    CD_Liste *tmp = *anker;
    while (tmp->next != NULL) 
    {
            tmp = tmp->next;
            j++;


    }


    if(CD_nr<=j)
    {
        int i = 1;
        tmp = *anker;
        for (i=1; i < CD_nr; i++) tmp = tmp->next;
        aendereMerkmal (tmp->info);
    }
    else printf("zu aendernde CD ist nicht vorhanden!\n");
}

int compare (const void * a, const void * b)
{
	return ( *(int*)a - *(int*)b );
}

void aendereMerkmal (CD_Info * cd)
{
	int a, b, c, i = 0, j = 0;
	char speicher[20];
	int s;
	printf("\nGeben Sie die in der Klammer stehenden Nummer an und bestaetigen Sie mit [ENTER]");
	do{
		printf("\nNamen(1) Interpret(2) Erscheinungsdatum(3) Genre(4) Songs(5)\n");
		fflush(stdin);
		scanf("%i", &a);
	} while((a<1)||(5<a));

	switch(a)
	{
	case 1:
		{
			printf("Neuen Namen eingeben: ");
			scanf("%s", cd->cd_name);
		}
		break;
	case 2:
		{
			printf("Neuen Namen eingeben: ");
			scanf("%s", cd->interpret_name);
		}
		break;
	case 3:
		{
			printf("Tag eingeben: ");
			scanf("%i", &(cd->erscheinung.Tag));
			printf("Monat eingeben: ");
			scanf("%i", &(cd->erscheinung.Monat));
			printf("Jahr eingeben: ");
			scanf("%i", &(cd->erscheinung.Jahr));
		}
		break;
	case 4:
		{
			printf("Neues Genre eingeben: ");
			scanf("%s", cd->genre);
		}
		break;
	case 5:
		{
			printf("\nGeben Sie die in der Klammer stehenden Nummer an und bestaetigen Sie mit [ENTER]");
			do{
				printf("\nHinzufuegen(1) Loeschen(2) Veraendern(3) Sortieren(4)\n");
				fflush(stdin);
				scanf("%i", &b);
			} while((b<1)||(4<b));

			switch(b)
			{
			case 1:
				{
					printf("Geben Sie den Songnamen an: ");
					scanf("%s", &(cd->song[cd->song_anzahl].songname));
					cd->song_anzahl++;
				}
				break;
			case 2:
				{
					for(i=0; i < cd->song_anzahl; i++)
					{
						if(i==0) printf("%i. %s", i+1, cd->song[i].songname);
						else printf(", %i. %s", i+1, cd->song[i].songname);
					}
					do{
						printf("\nEingabe der Songnummer um diesen zu loeschen: ");
						fflush(stdin);
						scanf("%i", &c);
					} while((c<1)||(cd->song_anzahl<c));
					for(i=c; i < cd->song_anzahl; i++) strcpy(cd->song[i-1].songname, cd->song[i].songname);
					cd->song_anzahl--;
				}
				break;
			case 3:
				{
					for(i=0; i < cd->song_anzahl; i++)
					{
						if(i==0) printf("%i. %s", i+1, cd->song[i].songname);
						else printf(", %i. %s", i+1, cd->song[i].songname);
					}
					do{
						printf("\nEingabe der Songnummer um diesen zu veraendern: ");
						fflush(stdin);
						scanf("%i", &c);
					} while((c<1)||(cd->song_anzahl<c));
					printf("Geben Sie den neuen Namen fuer %i an: ", c);
					scanf("%s", cd->song[c-1].songname);
				}
				break;
			case 4:
				{
					for(i=0; i<cd->song_anzahl-1; i++)
					{
						s = i;
						for(j=i+1; j<cd->song_anzahl; j++)
						{
							if(cd->song[j].songname[0]<cd->song[s].songname[0])
							{
								strcpy(speicher, cd->song[s].songname);
								strcpy(cd->song[s].songname, cd->song[j].songname);
								strcpy(cd->song[j].songname, speicher);
							}
						}
					}
				}
				break;
			}
		}
		break;
	}

}

void loescheCD_nr (CD_Liste ** anker, int CD_nr)
{
	int i = 1;
	CD_Liste *tmp = *anker;
	for (i=1; i < CD_nr; i++) tmp=tmp->next;
	loescheCD (anker, tmp);
	//free(tmp);
}

CD_Liste* sortiereSammlung (CD_Liste ** anker)
{
	int a, b;
	printf("\nGeben Sie die in der Klammer stehenden Nummer fuer das jeweilige Sortierkriterium an und bestaetigen Sie mit [ENTER]");

	do{
		printf("\nNamen(1) Interpret(2) Erscheinungsdatum(3) Genre(4)\n");
		fflush(stdin);
		scanf("%i", &a);
	} while((a<1)||(4<a));

	do{
		printf("\nVorwaerts(1) oder Rueckwaerts(2): ");
		fflush(stdin);
		scanf("%i", &b);
	} while((b<1)||(2<b));
	return sortieren (anker, a, b);
}

CD_Liste* sortieren (CD_Liste ** anker, int a, int b)
{
	CD_Liste *neu;
	CD_Liste *tmp;
	CD_Liste *tmp2;
	CD_Liste *speicher;
	int i = 0;
	int j = 0;
	int schritt_t = 0;
	int schritt_s = 0;
	neu = (CD_Liste*) malloc(sizeof(CD_Liste));
	tmp = *anker; //Pointer um Liste wiederholt durchzugehn.
	tmp2 = neu;
	speicher = *anker; //Pointer mit dem höchsten jeweiligen Wert.
	while(*anker != NULL)
	{
		speicher = *anker;
		tmp = *anker;
		schritt_t = 0;
		schritt_s = 0;
		while(tmp != NULL)
		{

			if(b==1) switch(a)
			{
			case 1: if(tmp->info->cd_name<speicher->info->cd_name) {speicher = tmp; schritt_s = schritt_t;}
					break;
			case 2: if(tmp->info->interpret_name<speicher->info->interpret_name) {speicher = tmp; schritt_s = schritt_t;}
					break;
			case 3: if((10000*tmp->info->erscheinung.Jahr+100*tmp->info->erscheinung.Monat+tmp->info->erscheinung.Tag)<(10000*speicher->info->erscheinung.Jahr+100*speicher->info->erscheinung.Monat+speicher->info->erscheinung.Tag)) {speicher = tmp; schritt_s = schritt_t;}
					break;
			case 4: if(tmp->info->genre<speicher->info->genre) {speicher = tmp; schritt_s = schritt_t;}
					break;
			}

			if(b==2) switch(a)
			{
			case 1: if(tmp->info->cd_name>speicher->info->cd_name) {speicher = tmp; schritt_s = schritt_t;}
					break;
			case 2: if(tmp->info->interpret_name>speicher->info->interpret_name) {speicher = tmp; schritt_s = schritt_t;}
					break;
			case 3: if((10000*tmp->info->erscheinung.Jahr+100*tmp->info->erscheinung.Monat+tmp->info->erscheinung.Tag)>(10000*speicher->info->erscheinung.Jahr+100*speicher->info->erscheinung.Monat+speicher->info->erscheinung.Tag)) {speicher = tmp; schritt_s = schritt_t;}
					break;
			case 4: if(tmp->info->genre>speicher->info->genre) {speicher = tmp; schritt_s = schritt_t;}
					break;
			}
			tmp = tmp->next;
			schritt_t++;
		}
		if(j == 0)
		{
			neu = speicher;
			tmp2 = speicher;
		}
		else
		{
			tmp2->next = speicher;
			tmp2 = tmp2->next;
		}
		tmp = *anker;
		if (schritt_s==0) *anker = speicher->next;
		else
		{
			for(i=1; i<schritt_s; i++) tmp = tmp->next;
			tmp->next = speicher->next;
		}
		j++;
	}
	tmp2->next = NULL;
	return neu;
}

void einlesenDatei (CD_Liste **anker)
{
	int anzahl, i;
	CD_Info *tmp = (CD_Info*) malloc(sizeof(CD_Info));
	CD_Info *tmp2 = (CD_Info*) malloc(sizeof(CD_Info));
	FILE * bin;
	bin = fopen(DAT_NAME, "r+b");
	fseek(bin, -sizeof(int), SEEK_END);
	fread(&anzahl, sizeof(CD_Info), 1, bin);
	fseek(bin, 0, SEEK_SET);
	for (i=0; i<anzahl;i++)
	{
		fread(tmp, sizeof(CD_Info), 1, bin);
		fseek(bin, 0, SEEK_CUR);
		einfuegenListe(anker, tmp);
		tmp = (CD_Info*) malloc(sizeof(CD_Info));
	}
	fclose(bin);
}

void speichereListe (CD_Liste ** anker)
{
	int i = 0;
	FILE * bin;
	CD_Liste *tmp = *anker;
	bin = fopen(DAT_NAME, "w+b");
	rewind(bin);
	while(tmp != NULL)
	{
		fwrite(tmp->info, sizeof(CD_Info), 1, bin);
		tmp = tmp->next;
		i++;
	}
	fwrite(&i, sizeof(int), 1, bin);
	fclose(bin);
}

