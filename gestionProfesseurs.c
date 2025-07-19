#include <stdio.h>
#include "dataBase.h"
#include "admin.h"
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "gestionProfesseurs.h"
#include "professeur.h"

PROFESSEUR ajouterProfesseur()
{
	PROFESSEUR P;
	static int compteur = 8;

	system("cls");

	printf("\n\nPrenom: ");
	getchar();
	gets(P.prenomProffesseur);

	printf("\n\nNom: ");
	gets(P.nomProfesseur);

	printf("\n\nMatiere enseignee: ");
	getchar();
	gets(P.matiereEnseignee);

	sprintf(P.matricule, "P-%02d-%.3s", compteur, P.nomProfesseur);
	compteur++;

	printf("\n\nFiliere: ");
	gets(P.filiere);

	printf("\n\nProfesseur ajoute avec succes.\n");

	return P;
}

void afficherProfesseurs(PROFESSEUR tabProfesseurs[], int nbProfesseurs)
{
	printf("Liste des professeurs\n\n");
	for (int i = 0; i < nbProfesseurs; i++)
	{
		printf("\n\tProfesseur %d", i + 1);
		printf("\n\tMatricule:  %s ", tabProfesseurs[i].matricule);
		printf("\n\tPrenom:  %s ", tabProfesseurs[i].prenomProffesseur);
		printf("\n\tNom:  %s ", tabProfesseurs[i].nomProfesseur);
		printf("\n\tMatiere Enseignee: %s ", tabProfesseurs[i].matiereEnseignee);
		printf("\n\tFiliere: %s ", tabProfesseurs[i].filiere);
		printf("\n---------------------------------------------------\n\n");
	}
}

void rechercherProfesseurParNom(PROFESSEUR tabProfesseurs[], int nbProfesseurs)
{
	char nom[50];
	printf("\n\nVeuillez saisir le nom du professeur a rechercher: ");
	scanf("%s", nom);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbProfesseurs; i++)
	{
		if (strcmp(tabProfesseurs[i].nomProfesseur, nom) == 0)
		{
			found = true;
			printf("\n\tProfesseur trouve: ");
			printf("\n\tMatricule:  %s ", tabProfesseurs[i].matricule);
			printf("\n\tPrenom:  %s ", tabProfesseurs[i].prenomProffesseur);
			printf("\n\tNom:  %s ", tabProfesseurs[i].nomProfesseur);
			printf("\n\tMatiere Enseignee: %s ", tabProfesseurs[i].matiereEnseignee);
			printf("\n\tFiliere: %s ", tabProfesseurs[i].filiere);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun professeur trouve avec le nom %s.\n", nom);
	}
}

void rechercherProfesseurParMatricule(PROFESSEUR tabProfesseurs[], int nbProfesseurs)
{
	char matricule[11];
	printf("\n\nVeuillez saisir le matricule du professeur a rechercher: ");
	scanf("%s", matricule);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbProfesseurs; i++)
	{
		if (strcmp(tabProfesseurs[i].matricule, matricule) == 0)
		{
			found = true;
			printf("\n\tProfesseur trouve: ");
			printf("\n\tMatricule:  %s ", tabProfesseurs[i].matricule);
			printf("\n\tPrenom:  %s ", tabProfesseurs[i].prenomProffesseur);
			printf("\n\tNom:  %s ", tabProfesseurs[i].nomProfesseur);
			printf("\n\tMatiere Enseignee: %s ", tabProfesseurs[i].matiereEnseignee);
			printf("\n\tFiliere: %s ", tabProfesseurs[i].filiere);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun professeur trouve avec le matricule %s.\n", matricule);
	}
}

void modifierProfesseur(PROFESSEUR tabProfesseurs[], int nbProfesseurs)
{
	char matriculeSaisi[11];
	system("cls");
	bool found = false;
	int position = 0;

	printf("\n\nVeuillez saisir le matricule du professeur a modifier: ");
	scanf("%s", matriculeSaisi);

	for (int i = 0; i < nbProfesseurs; i++)
	{
		if (strcmp(tabProfesseurs[i].matricule, matriculeSaisi) == 0)
		{
			found = true;
			position = i;
			break;
		}
	}

	if (found)
	{
		printf("\n\nNouveau Prenom: ");
		getchar();
		gets(tabProfesseurs[position].prenomProffesseur);

		printf("\n\nNouveau Nom: ");
		gets(tabProfesseurs[position].nomProfesseur);

		printf("\n\nNouvelle Matiere Enseignee: ");
		gets(tabProfesseurs[position].matiereEnseignee);

		strcpy(tabProfesseurs[position].filiere, "GL");
	}
	else
	{
		printf("\n\nProfesseur avec le matricule %s non trouve.\n", matriculeSaisi);
	}

	printf("\n\nModification terminee.\n");
	system("pause");
}