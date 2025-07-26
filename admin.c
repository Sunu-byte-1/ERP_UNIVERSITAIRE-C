
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
	printf("\nannee: ");
	do
	{
		scanf("%d", &D.a);
	} while (D.a < 1900 || D.a > 2100);

	printf("\nmois: ");
	do
	{
		scanf("%d", &D.m);
	} while (D.m < 1 || D.m > 12);

	do
	{
		printf("\njour: ");
		scanf("%d", &D.j);
		if (D.m == 2)
		{
			if (D.a % 4 == 0 && D.a % 100 != 0 || D.a % 400 == 0)
			{
				if (D.j < 1 || D.j > 29)
				{
					printf("Jour invalide pour fevrier d'une annee bissextile.\n");
				}
			}
			else
			{
				if (D.j < 1 || D.j > 28)
				{
					printf("Jour invalide pour fevrier d'une annee non bissextile.\n");
				}
			}
		}
		else if (D.m == 4 || D.m == 6 || D.m == 9 || D.m == 11)
		{
			if (D.j < 1 || D.j > 30)
			{
				printf("Jour invalide pour le mois %d.\n", D.m);
			}
		}
		else
		{
			if (D.j < 1 || D.j > 31)
			{
				printf("Jour invalide pour le mois %d.\n", D.m);
			}
		}
	} while ((D.m == 2 && ((D.a % 4 == 0 && D.a % 100 != 0 || D.a % 400 == 0) ? (D.j < 1 || D.j > 29) : (D.j < 1 || D.j > 28))) || (D.m == 4 || D.m == 6 || D.m == 9 || D.m == 11) ? (D.j < 1 || D.j > 30) : (D.j < 1 || D.j > 31));

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

void statistiques(ETUDIANT tabEtudiants[], int nbEtudiants, STAGE tabStages[], int nbStages, PROFESSEUR tabProfesseurs[100], int nbProfesseurs, ENTREPRISE tabEntreprises[], int nbEntreprises)
{

	printf("\n==========================ETUDIANTS======================");
	printf("\n\tNombre total d'etudiants: %d", nbEtudiants);
	printf("\n\tNombre d'etudiants avec une moyenne: ");
	printf("\n\t\t\t\t%d", nbEtudiants);
	printf("\n\tNombre d'etudiants ayant postule a un stage: %d", cptstage(tabEtudiants, nbEtudiants));
	printf("\n\tNombre d'etudiants ayant la moyenne: %d", cptMoyenne(tabEtudiants, nbEtudiants));

	printf("\n\n==========================PROFESSEURS======================");
	printf("\n\tNombre total de professeurs: %d", nbProfesseurs);

	printf("\n\n==========================ENTREPRISES======================");
	printf("\n\tNombre total d'entreprises: %d", nbEntreprises);
	printf("\n\tNombre total de stages: %d", nbStages);
}

int cptstage(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	int count = 0;
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].statutStage, "attente") == 0)
		{
			count++;
		}
	}
	return count;
}
int cptMoyenne(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	int count = 0;
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			if (atof(tabEtudiants[i].moyenneEtudiant) > 10.0)
			{
				count++;
			}
		}
	}
	return count;
}
