#include "GrafMacierz.h"
#include "BellFord.h"
#define nieskonczonosc 10000000
#define BRAK -1

void Algorytm_Bellmana_Forda(Graf_Macierz_Sasiedztwa graf, unsigned int* Koszt, signed int* Wierzcholek_Poprzedzajacy) 
	{
	Koszt[0]=0;
	Wierzcholek_Poprzedzajacy[0]=-1;

	for (unsigned int i = 1; i < graf.liczba_wierzcholkow; i++) 
		{

			Koszt[i] = nieskonczonosc;
			Wierzcholek_Poprzedzajacy[i] = BRAK;
		}
	for (unsigned int k = 0; k < graf.liczba_wierzcholkow - 1; k++)
		for (unsigned int i = 1; i < graf.liczba_wierzcholkow; i++)
			for (unsigned int j = 0; j < graf.liczba_wierzcholkow; j++)
				if ((Koszt[i] > Koszt[j] + graf.Macierz_Sasiedztwa[i][j]) && graf.Macierz_Sasiedztwa[i][j]) 
					{
					Koszt[i] = Koszt[j] + graf.Macierz_Sasiedztwa[i][j];
					Wierzcholek_Poprzedzajacy[i] = j;
					}
	}
