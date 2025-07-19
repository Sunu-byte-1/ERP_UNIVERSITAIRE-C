#include <stdio.h>
#include <stdlib.h>
#include "suggestion.h"
#include "dataBase.h"
#include "couleurs.h"

ETUDIANTSUGGERE suggererEtudiant(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	system("cls");

	ETUDIANTSUGGERE ES;
	char mat[11];

	couleur(9);
	printf("Veuillez saisir la matricule de l'étudiant a suggerer:   ");
	couleur(7);
	getchar();
	gets(mat);
	bool trouve = false;
	bool found = false;
	int pos = 0;

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			trouve = true;
			if (strcmp(mat, tabEtudiants[i].matricule) == 0)
			{
				found = true;
				ES.etudiantSuggere = tabEtudiants[i];
				pos = i;
				break;
			}
		}
	}

	if (!trouve)
	{
		couleur(12);
		printf("\n\nSeuls les etudiants ayant une note peuvent etre suggerés   ");
		couleur(7);
	}
	else
	{
		couleur(10);
		printf("\n\n\nSuggestion de %s %s reussie.....\n\n", tabEtudiants[pos].nomEtudiant, tabEtudiants[pos].prenomEtudiant);
		couleur(7);
	}

	return ES;
}

void listeSuggestion(ETUDIANTSUGGERE tabSuggestions[], int nbSuggestions)
{
	system("cls");
	printf("Liste de suggessions\n\n");
	for (int i = 0; i < nbSuggestions; i++)
	{
		couleur(14);
		fflush(stdin);
		printf("\n\t%s |  %s %s ", tabSuggestions[i].etudiantSuggere.matricule, tabSuggestions[i].etudiantSuggere.nomEtudiant, tabSuggestions[i].etudiantSuggere.prenomEtudiant);
		couleur(11);
		fflush(stdin);
		printf("\n\tFilière:  %s", tabSuggestions[i].etudiantSuggere.filiere);
		couleur(10);
		fflush(stdin);
		printf("\n\tMoyenne:  %s", tabSuggestions[i].etudiantSuggere.moyenneEtudiant);
		couleur(7);
		printf("\n--------------------------------------------------------");
	}
}

void tabEtudiantsSuggerer(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	system("cls");
	bool found = false;
	couleur(9);
	printf("Liste de Des etudiants à suggerer\n\n");
	couleur(7);
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			found = true;
			couleur(14);
			printf("\n\t%s |  %s %s ", tabEtudiants[i].matricule, tabEtudiants[i].nomEtudiant, tabEtudiants[i].prenomEtudiant);
			couleur(11);
			printf("\n\tFilière:  %s", tabEtudiants[i].filiere);
			couleur(10);
			printf("\n\tMoyenne:  %s", tabEtudiants[i].moyenneEtudiant);
			couleur(7);
			printf("\n--------------------------------------------------------");
		}
	}

	if (!found)
	{
		couleur(12);
		printf("Pas d etudiant avec note disponible\n\n");
		couleur(7);
	}
}

void validerSuggestion(ETUDIANT tabEtudiants[], int nbEtudiants, ETUDIANTSUGGERE tabSuggestions[], int nbSuggestions)
{

	system("cls");
	char mat[11];
	bool found = false;
	printf("\n\nVeuillez saisir le matricule:  ");

	do
	{
		getchar();
		gets(mat);

		for (int i = 0; i < nbSuggestions; i++)
		{
			if (strcmp(mat, tabSuggestions[i].etudiantSuggere.matricule) == 0)
			{
				found = true;
				for (int j = 0; j < nbEtudiants; j++)
				{
					if (strcmp(mat, tabEtudiants[j].matricule) == 0)
					{
						couleur(10);
						strcpy(tabEtudiants[j].statutStage, "accepte");
						printf("\n\n%s %s a été accepté....\n\n", tabEtudiants[j].nomEtudiant, tabEtudiants[j].prenomEtudiant);
						couleur(7);
					}
				}
			}
		}
		if (!found)
		{
			couleur(12);
			printf("\n\nVeuillez saisir un matricule d un etudiant suggeré:  ");
			couleur(7);
		}
	} while (!found);
}