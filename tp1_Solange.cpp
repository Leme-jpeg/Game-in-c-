
/*
Auteur: Solange Desjardins
Date: 25 janvier 2022
Nom du programme:
Description: Replonger dans l'enfer de notre dépendance aux diagrammes d'action aka creer un jeu

*/


#include <iostream>   
#include <conio.h>
#include <iomanip>  
#include <Windows.h>  
#include "C:\\cvm.h"  
#include <cstdlib>  

using namespace std;

char LireToucheDeplacement(void)
{
	unsigned char Rep;
	Rep = _getch();
	while (!(Rep == 0 || Rep == 224))
	{
		cout << "\a";
		Rep = _getch();
	}
	return _getch();
}

void main(void)
{
	//chaque Pierre est compose de 8 caractères sur 2 lignes et 4 colonnes.
	const char PierreBlanche = 178;
	const char PierreGrise = 176;
	const char MurNoir = 32;
	const char Argent = 36;


	int i = 0;
	int j = 0;
	int NbrePoints = 0;
	int Touche = 0;


	char Joueur1 = 201;
	char Joueur2 = 203;
	char Joueur3 = 203;
	char Joueur4 = 187;

	char Joueur5 = 200;
	char Joueur6 = 202;
	char Joueur7 = 202;
	char Joueur8 = 188;

	int x = 0;
	int y = 0;


	const int BAS = 80, HAUT = 72, DROITE = 77, GAUCHE = 75, HD = 73, HG = 71, BG = 79, BD = 81;
	const int NB_COL = 12, NB_LIG = 8;

	int Mat[NB_LIG][NB_COL] = {
		{ 0, 0, 0, 0, 0, 0, 0, 0, 4, 0, 0, 1},
		{ 0, 0, 4, 4, 0, 0, 0, 0, 0, 4, 0, 4},
		{ 0, 0, 4, 1, 4, 0, 0, 0, 0, 0, 4, 1},
		{ 0, 0, 4, 1, 4, 0, 0, 4, 4, 0, 4, 1},
		{ 1, 0, 4, 4, 4, 1, 4, 0, 4, 0, 4, 0},
		{ 1, 0, 1, 1, 0, 1, 4, 1, 4, 0, 4, 0},
		{ 1, 0, 1, 0, 0, 0, 4, 4, 4, 0, 4, 0},
		{ 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
	};






	while (NbrePoints < 15)
	{


		clrscr();

		cout << "Decouvrez et amassez 15 cases $$$$ Points : " << NbrePoints;

		for (i = 0; i < NB_LIG; i++)
		{
			for (j = 0; j < NB_COL; j++)
			{
				if (x == j && i == y)
				{
					gotoxy(j * 5 + 11, i * 3 + 3);
					cout << Joueur1 << Joueur2 << Joueur3 << Joueur4;
					gotoxy(j * 5 + 11, i * 3 + 4);
					cout << Joueur5 << Joueur6 << Joueur7 << Joueur8;

					switch (Mat[i][j])
					{
						//Blanc Devient Gris
					case 0:
						Mat[i][j] = 3;
						break;

						// Argent revele
					case 1:
						Mat[i][j] = 2;
						break;

						//Argent compte points et devient gris
					case 2:
						Mat[i][j] = 3;
						NbrePoints = NbrePoints + 1;

						break;
						//Pierre Grise devient mur noir
					case 3:
						Mat[i][j] = 4;
						break;
					}
				}
				else
				{
					switch (Mat[i][j])
					{
					case 0:
						gotoxy(j * 5 + 11, i * 3 + 3);
						cout << PierreBlanche << PierreBlanche << PierreBlanche << PierreBlanche;
						gotoxy(j * 5 + 11, i * 3 + 4);
						cout << PierreBlanche << PierreBlanche << PierreBlanche << PierreBlanche;
						break;
					case 1:
						gotoxy(j * 5 + 11, i * 3 + 3);
						cout << PierreBlanche << PierreBlanche << PierreBlanche << PierreBlanche;
						gotoxy(j * 5 + 11, i * 3 + 4);
						cout << PierreBlanche << PierreBlanche << PierreBlanche << PierreBlanche;
						break;
					case 2:
						gotoxy(j * 5 + 11, i * 3 + 3);
						cout << Argent << Argent << Argent << Argent;
						gotoxy(j * 5 + 11, i * 3 + 4);
						cout << Argent << Argent << Argent << Argent;
						break;
					case 3:
						gotoxy(j * 5 + 11, i * 3 + 3);
						cout << PierreGrise << PierreGrise << PierreGrise << PierreGrise;
						gotoxy(j * 5 + 11, i * 3 + 4);
						cout << PierreGrise << PierreGrise << PierreGrise << PierreGrise;

						break;

					case 4:
						gotoxy(j * 5 + 11, i * 3 + 3);
						cout << MurNoir << MurNoir << MurNoir << MurNoir;
						gotoxy(j * 5 + 11, i * 3 + 4);
						cout << MurNoir << MurNoir << MurNoir << MurNoir;

						break;
					}
				}





			}

		}

		// verifier que cest une touche valide
		Touche = LireToucheDeplacement();

		//deplacements:	
		switch (Touche)
		{
		case BAS:
			if (y < NB_LIG - 1 && y >= 0 && Mat[y + 1][x] != 4)
			{
				y++;
			}
			break;

		case HAUT:
			if (y <= NB_LIG - 1 && y > 0 && Mat[y - 1][x] != 4)
			{
				y--;
			}
			break;

		case DROITE:
			if (x >= 0 && x < NB_COL - 1 && Mat[y][x + 1] != 4)
			{
				x++;
			}
			break;

		case GAUCHE:
			if (x > 0 && x < NB_COL && Mat[y][x - 1] != 4)
			{
				x--;
			}
			break;

		case HD:
			if ((y <= NB_LIG - 1 && y > 0) && (x >= 0 && x < NB_COL - 1) && Mat[y - 1][x + 1] != 4)

			{
				y--;
				x++;
			}
			break;

		case HG:
			if ((y <= NB_LIG - 1 && y > 0) && (x > 0 && x < NB_COL) && Mat[y - 1][x + 1] != 4)

			{
				y--;
				x--;
			}
			break;

		case BG:
			if ((y < NB_LIG - 1 && y >= 0) && (x > 0 && x < NB_COL) && Mat[y + 1][x - 1] != 4)

			{
				y++;
				x--;
			}
			break;

		case BD:
			if ((y < NB_LIG - 1 && y >= 0) && (x >= 0 && x < NB_COL - 1) && Mat[y + 1][x + 1] != 4)

			{
				y++;
				x++;
			}
			break;


		}
		//0 == PierreBlanche;
		//1 == $$$$ caché  (== PierreBlanche);
		//2 == $$$$ visible,
		//3 == PierreGrise;
		//4 == MurNoir;




	}
}
