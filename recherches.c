
#include "admin.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

void rechercherEtudiantParMatricule(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char matricule[10];
	printf("\n\nVeuillez saisir le matricule de l'etudiant a rechercher: ");
	scanf("%s", matricule);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].matricule, matricule) == 0)
		{
			found = true;
			printf("\n\tEtudiant trouve: ");
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec le matricule %s.\n", matricule);
	}
}

void rechercherEtudiantParNom(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char nom[50];
	printf("\n\nVeuillez saisir le nom de l'etudiant a rechercher: ");
	scanf("%s", nom);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].nomEtudiant, nom) == 0)
		{
			found = true;
			printf("\n\tEtudiant trouve: ");
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec le nom %s.\n", nom);
	}
}

void rechercherEtudiantParPrenom(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char prenom[50];
	printf("\n\nVeuillez saisir le prenom de l'etudiant a rechercher: ");
	scanf("%s", prenom);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].prenomEtudiant, prenom) == 0)
		{
			found = true;
			printf("\n\tEtudiant trouve: ");
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec le prenom %s.\n", prenom);
	}
}

void rechercherEtudiantParDateNaissance(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	DATEPERSO dateNaissance;
	dateNaissance = saisirDate("Veuillez saisir la date de naissance de l'etudiant a rechercher");

	bool found = false;

	system("cls");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (tabEtudiants[i].dateNaissance.j == dateNaissance.j &&
			tabEtudiants[i].dateNaissance.m == dateNaissance.m &&
			tabEtudiants[i].dateNaissance.a == dateNaissance.a)
		{
			found = true;
			printf("\n\tEtudiant trouve: ");
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec la date de naissance %02d/%02d/%04d.\n", dateNaissance.j, dateNaissance.m, dateNaissance.a);
	}
}

void rechercherEtudiantParStatutStage(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char statutStage[20];
	printf("\n\nVeuillez saisir le statut de stage de l'etudiant a rechercher: ");
	scanf("%s", statutStage);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].statutStage, statutStage) == 0)
		{
			found = true;
			printf("\n\tEtudiant trouve: ");
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec le statut de stage %s.\n", statutStage);
	}
}

void rechercherEtudiantParMoyenne(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char moyenne[3];
	printf("\n\nVeuillez saisir la moyenne de l'etudiant a rechercher: ");
	scanf("%s", moyenne);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, moyenne) == 0)
		{
			found = true;
			printf("\n\tEtudiant trouve: ");
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec la moyenne %s.\n", moyenne);
	}
}

void rechercherEtudiantParNomOuPrenom(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char nomOuPrenom[50];
	printf("\n\nVeuillez saisir le nom ou le prenom de l'etudiant a rechercher: ");
	scanf("%s", nomOuPrenom);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].nomEtudiant, nomOuPrenom) == 0 || strcmp(tabEtudiants[i].prenomEtudiant, nomOuPrenom) == 0)
		{
			found = true;
			printf("\n\tEtudiant trouve: ");
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec le nom ou le prenom %s.\n", nomOuPrenom);
	}
}

void rechercherEtudiantParMatriculeOuNomOuPrenom(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	char matriculeOuNomOuPrenom[50];
	printf("\n\nVeuillez saisir le matricule, le nom ou le prenom de l'etudiant a rechercher: ");
	scanf("%s", matriculeOuNomOuPrenom);
	bool found = false;

	system("cls");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].matricule, matriculeOuNomOuPrenom) == 0 ||
			strcmp(tabEtudiants[i].nomEtudiant, matriculeOuNomOuPrenom) == 0 ||
			strcmp(tabEtudiants[i].prenomEtudiant, matriculeOuNomOuPrenom) == 0)
		{
			found = true;
			printf("\n\tEtudiant trouve: ");
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec le matricule, le nom ou le prenom %s.\n", matriculeOuNomOuPrenom);
	}
}
