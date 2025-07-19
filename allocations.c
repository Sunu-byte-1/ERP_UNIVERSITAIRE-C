#include "dataBase.h"
#include "allocations.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <stdbool.h>

ALLOCATION tabAllocations[100];
int nbAllocations = 0;

void payerEtudiant(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	ALLOCATION A;
	char mois[16];

	printf("\n\nVeuillez saisir le mois d'allocation  ");
	scanf(" %s", mois);

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			if (strcmp(tabEtudiants[i].allocation, "non") == 0)
			{
				float moy = atof(tabEtudiants[i].moyenneEtudiant);
				if (moy >= 10.0 && moy < 12.0)
				{
					A.etudiant = tabEtudiants[i];
					A.montant = 20000;
					strcpy(A.mois, mois);
					strcpy(tabEtudiants[i].allocation, "oui");
					tabAllocations[nbAllocations] = A;
					nbAllocations++;
				}
				else if (moy >= 12.0 && moy < 14.0)
				{
					A.etudiant = tabEtudiants[i];
					A.montant = 40000;
					strcpy(A.mois, mois);
					strcpy(tabEtudiants[i].allocation, "oui");
					tabAllocations[nbAllocations] = A;
					nbAllocations++;
				}
				else if (moy >= 14.0 && moy < 16.0)
				{
					A.etudiant = tabEtudiants[i];
					A.montant = 60000;
					strcpy(A.mois, mois);
					strcpy(tabEtudiants[i].allocation, "oui");
					tabAllocations[nbAllocations] = A;
					nbAllocations++;
				}
				else if (moy >= 16.0)
				{
					A.etudiant = tabEtudiants[i];
					A.montant = 80000;
					strcpy(A.mois, mois);
					strcpy(tabEtudiants[i].allocation, "oui");
					tabAllocations[nbAllocations] = A;
					nbAllocations++;
				}
			}
		}
	}
	printf("\n\n Payement des allocations effectue avec succes.\n\n\n");
}

void afficherListeEtudiantsPayes()

{
	if (nbAllocations == 0)
	{
		printf("\n\nAucun etudiant n'a ete paye.\n");
		return;
	}

	printf("\n\nListe des etudiants payes:\n\n");
	for (int i = 0; i < nbAllocations; i++)
	{
		printf("\n\tEtudiant: %s %s", tabAllocations[i].etudiant.prenomEtudiant, tabAllocations[i].etudiant.nomEtudiant);
		printf("\n\tMontant: %.2f", tabAllocations[i].montant);
		printf("\n\tMois: %s", tabAllocations[i].mois);
		printf("\n---------------------------------------------------\n");
	}
}

void listeImpayesEtudiants(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	system("cls");
	bool found = false;
	printf("Liste des etudiants n'ayant pas recu d'allocation\n\n");

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].allocation, "non") == 0)
		{
			found = true;
			printf("\n\t%s   %s  %s ", tabEtudiants[i].nomEtudiant, tabEtudiants[i].prenomEtudiant, tabEtudiants[i].moyenneEtudiant);
			printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Tous les etudiants ont recu une allocation.\n");
	}
}