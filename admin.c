
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "admin.h"
#include "dataBase.h"

bool connexionAdmin(char *username, char *password)
{

	if (strcmp(username, "admin") == 0 && strcmp(password, "admin123") == 0)
	{
		return true;
	}

	else
	{
		return false;
	}
}

int connexionAdminPrompt(char *username, char *password)
{
	system("cls");
	printf("\n\n");
	printf("\n\nVeuillez entrer votre nom d'utilisateur: ");
	scanf("%s", username);
	printf("\nVeuillez entrer votre mot de passe: ");
	scanf("%s", password);
	return connexionAdmin(username, password);
}

DATEPERSO saisirDate(char message[100])
{
	DATEPERSO D;

	printf("\n %s", message);
	printf("\n  Jour:  ");
	scanf("%d", &D.j);

	printf("  Mois:  ");
	scanf("%d", &D.m);

	printf("  Annee:  ");
	scanf("%d", &D.a);

	return D;
}

void afficherDate(DATEPERSO D)
{
	printf("  %02d/%02d/%04d ", D.j, D.m, D.a);
}

ETUDIANT ajouterEtudiant()
{
	static int compteur = 1;
	ETUDIANT E;

	system("cls");

	printf("\n\nPrenom: ");
	getchar();
	gets(E.prenomEtudiant);

	printf("\n\nNom: ");
	gets(E.nomEtudiant);

	printf("\n\nFiliere: ");
	gets(E.filiere);

	sprintf(E.matricule, "%.3s-%.3s-%02d", E.prenomEtudiant, E.nomEtudiant, compteur);
	compteur++;

	E.dateNaissance = saisirDate("Date de naissance");
	E.dateInscription = saisirDate("Date d'inscription");

	strcpy(E.statutStage, "non");
	strcpy(E.moyenneEtudiant, "vide");
	strcpy(E.allocation, "non");

	return E;
}

void modifierEtudiant(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char matriculeSaisi[11];
	system("cls");
	bool found = false;
	int position = 0;

	printf("\n\nVeuillez saisir le matricule de l'etudiant a modifier: ");
	scanf("%s", matriculeSaisi);

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].matricule, matriculeSaisi) == 0)
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
		gets(tabEtudiants[position].prenomEtudiant);

		printf("\n\nNouveau Nom: ");
		gets(tabEtudiants[position].nomEtudiant);

		printf("\n\nNouvelle Filiere: ");
		gets(tabEtudiants[position].filiere);

		tabEtudiants[position].dateNaissance = saisirDate("Date de naissance");
		tabEtudiants[position].dateInscription = saisirDate("Date d'inscription");

		strcpy(tabEtudiants[position].statutStage, "non");
	}
	else
	{
		printf("\n\nEtudiant avec le matricule %s non trouve.\n", matriculeSaisi);
	}
	printf("\n\nModification terminee.\n");
	system("pause");
}

void ajouterNote(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char matriculeSaisi[11];
	system("cls");
	bool found = false;
	int position = 0;

	printf("\n\nVeuillez saisir le matricule de l'etudiant a modifier: ");
	getchar();
	gets(matriculeSaisi);

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].matricule, matriculeSaisi) == 0)
		{
			found = true;
			position = i;
			break;
		}
	}

	if (found)
	{
		printf("\n\nVeuillez saisir la nouvelle moyenne de l'etudiant: ");
		gets(tabEtudiants[position].moyenneEtudiant);
		printf("\n\nMoyenne de l'etudiant %s %s modifiee avec succes.\n", tabEtudiants[position].prenomEtudiant, tabEtudiants[position].nomEtudiant);
	}
	else
	{
		printf("\n\nEtudiant avec le matricule %s non trouve.\n", matriculeSaisi);
	}
	system("pause");
}
