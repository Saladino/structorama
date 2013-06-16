#include "bearbeitung.h"

void aendereMerkmal (CD_Info * cd);
void sortieren (CD_Liste ** anker, int a, int b);

void ausgebenSammlung (CD_Liste ** anker)
{
	int i = 1, j = 0;
	CD_Liste *tmp = *anker;

	while (tmp != NULL)
	{
		printf("\nCD Nummer:		 %i", i);
		printf("\nCD Name:			 %s", tmp->info->cd_name);
		printf("\nInterpret:		 %s", tmp->info->interpret_name);
		printf("\nErscheinungsdatum: %i.%i.%i", tmp->info->erscheinung.Tag, tmp->info->erscheinung.Monat, tmp->info->erscheinung.Jahr);
		printf("\nGenre:			 %s", tmp->info->genre);
		printf("\nSongs:			 ");
		while (tmp->info->song_anzahl >= j)
		{
		if(j==0) printf("%i. %s", j+1, tmp->info->song[j].songname);
		else printf(", %i. %s", j+1, tmp->info->song[j].songname);
		j++;
		}
		i++;
	}
}

void aendereCD (CD_Liste ** anker, int CD_nr)
{
	int i = 1;
	CD_Liste *tmp = *anker;
	for (i=1; i < CD_nr; i++) tmp = tmp->next;
	aendereMerkmal (tmp->info);
}

int compare (const void * a, const void * b)
{
  return ( *(int*)a - *(int*)b );
}

void aendereMerkmal (CD_Info * cd)
{
	int a, b, c, i = 0;
	printf("\nGeben Sie die in der Klammer stehenden Nummer an und bestaetigen Sie mit [ENTER]");
	do{
	printf("\nNamen(1) Interpret(2) Erscheinungsdatum(3) Genre(4) Songs(5)\n");
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
			scanf("%i", cd->erscheinung.Tag);
			printf("Monat eingeben: ");
			scanf("%i", cd->erscheinung.Monat);
			printf("Jahr eingeben: ");
			scanf("%i", cd->erscheinung.Jahr);
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
			scanf("%i", &b);
			} while((b<1)||(4<b));
			
			switch(b)
			{
			case 1:
				{
					printf("Geben Sie den Songnamen an: ");
					scanf("%s", cd->song[cd->song_anzahl]);
					cd->song_anzahl++;
				}
				break;
			case 2:
				{
					for(i=0; cd->song_anzahl > i; i++)
					{
					if(i==0) printf("%i. %s", i+1, cd->song[i].songname);
					else printf(", %i. %s", i+1, cd->song[i].songname);
					}
					do{
					printf("Eingabe der Songnummer um diesen zu loeschen: ");
					scanf("%i", &c);
					} while((c<1)||(cd->song_anzahl<c));
					for(i=c; i < cd->song_anzahl; i++) strcpy(cd->song[i-1].songname, cd->song[i].songname);
					cd->song_anzahl--;
				}
				break;
			case 3:
				{
					for(i=0; cd->song_anzahl > i; i++)
					{
					if(i==0) printf("%i. %s", i+1, cd->song[i].songname);
					else printf(", %i. %s", i+1, cd->song[i].songname);
					}
					do{
					printf("Eingabe der Songnummer um diesen zu veraendern: ");
					scanf("%i", &c);
					} while((c<1)||(cd->song_anzahl<c));
					scanf("%s", cd->song[c-1].songname);
				}
				break;
			case 4: 
				{
				qsort (cd->song, cd->song_anzahl, sizeof(Songs), compare);
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
	for (i=1; i < CD_nr; i++) naechsteCD (tmp);
	loescheCD (anker, tmp);
}

void sortiereSammlung (CD_Liste ** anker)
{
	int a, b;
	printf("\nGeben Sie die in der Klammer stehenden Nummer fuer das jeweilige Sortierkriterium an und bestaetigen Sie mit [ENTER]");
	
	do{
	printf("\nNamen(1) Interpret(2) Erscheinungsdatum(3) Genre(4)\n");
	scanf("%i", &a);
	} while((a<1)||(4<a));
	
	do{
	printf("\nVorwaerts(1) oder Rueckwaerts(2): ");
	scanf("%i", &b);
	} while((b<1)||(2<b));
	sortieren (anker, a, b);
}

void sortieren (CD_Liste ** anker, int a, int b)
{
	CD_Liste *neu;
	CD_Liste *tmp;
	CD_Liste *tmp2;
	CD_Liste *speicher;
	int i = 0;
	int schritt_t = 0;
	int schritt_s = 0;
	neu = (CD_Liste*) malloc(sizeof(CD_Liste));
	tmp = *anker; //Pointer um Liste wiederholt durchzugehn.
	tmp2 = neu;
	speicher = *anker; //Pointer mit dem höchsten jeweiligen Wert.
	getch();
	while(*anker != NULL)
	{
		speicher = *anker;
		tmp = *anker;
		schritt_t = 0;
		schritt_s = 0;
		while(tmp != NULL)
		{
			naechsteCD (tmp);
			schritt_t++;
			
			if(b==1) switch(a)
			{
			case 1: if(tmp->info->cd_name<speicher->info->cd_name) speicher = tmp; schritt_s = schritt_t;
			break;
			case 2: if(tmp->info->interpret_name<speicher->info->interpret_name) speicher = tmp; schritt_s = schritt_t;
			break;
			case 3: if((10000*tmp->info->erscheinung.Jahr+100*tmp->info->erscheinung.Monat+tmp->info->erscheinung.Tag)<(10000*speicher->info->erscheinung.Jahr+100*speicher->info->erscheinung.Monat+speicher->info->erscheinung.Tag)) speicher = tmp; schritt_s = schritt_t;
			break;
			case 4: if(tmp->info->genre<speicher->info->genre) speicher = tmp; schritt_s = schritt_t;
			break;
			}
			
			if(b==2) switch(a)
			{
			case 1: if(tmp->info->cd_name>speicher->info->cd_name) speicher = tmp; schritt_s = schritt_t;
			break;
			case 2: if(tmp->info->interpret_name>speicher->info->interpret_name) speicher = tmp; schritt_s = schritt_t;
			break;
			case 3: if((10000*tmp->info->erscheinung.Jahr+100*tmp->info->erscheinung.Monat+tmp->info->erscheinung.Tag)>(10000*speicher->info->erscheinung.Jahr+100*speicher->info->erscheinung.Monat+speicher->info->erscheinung.Tag)) speicher = tmp; schritt_s = schritt_t;
			break;
			case 4: if(tmp->info->genre>speicher->info->genre) speicher = tmp; schritt_s = schritt_t;
			break;
			}
		
		}
		if(tmp2 == NULL)
		{
				neu = speicher;
				tmp2 = speicher;
		}
		else
		{
			tmp2->next = speicher;
			naechsteCD (tmp2);
		}
		tmp = *anker;
		if (schritt_s==0) *anker = speicher->next;
		else
		{
			for(i=0; i<schritt_s; i++) tmp = tmp->next;
			tmp->next = speicher->next;
		}

	}
	tmp2->next = NULL;
	*anker = neu;
}

void einlesenDatei (CD_Liste **anker)
{
	CD_Info *tmp = NULL;
	CD_Info *tmp2 = NULL;
	FILE * bin;
	bin = fopen(DAT_NAME, "r+b");
	fseek(bin, 0, SEEK_END);
	fread(tmp2, sizeof(CD_Info), 1, bin);
	fseek(bin, 0, SEEK_SET);
	fread(tmp, sizeof(CD_Info), 1, bin);
	while(tmp != tmp2)
	{
		einfuegenListe(*anker, tmp);
		fseek(bin, sizeof(CD_Info), SEEK_CUR);
		fread(tmp, sizeof(CD_Info), 1, bin);
	}
	fclose(bin);
}

void speichereListe (CD_Liste ** anker)
{
	FILE * bin;
	CD_Liste *tmp = *anker;
	bin = fopen(DAT_NAME, "r+b");
	rewind(bin);
	while(tmp != NULL)
	{
			fwrite(tmp->info, sizeof(CD_Info), 1, bin);
			naechsteCD (tmp);
	}
}
