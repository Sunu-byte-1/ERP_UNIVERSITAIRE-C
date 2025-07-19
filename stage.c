#include "admin.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "stage.h"
#include "dataBase.h"

void voirListeStages(STAGE tabStages[], int nbStages, ENTREPRISE tabEntreprises[], int nbEntreprises)
{
	system("cls");
	printf("Liste des stages disponibles\n\n");

	for (int i = 0; i < nbStages; i++)
	{
		printf("\n\tID : %d |   Titre: %s", tabStages[i].id_stage, tabStages[i].titreStage);

		for (int j = 0; j < nbEntreprises; j++)
		{
			if (tabStages[i].id_entreprise == tabEntreprises[j].id_entreprise)
			{

				printf("\n\tNom Entreprise: %s", tabEntreprises[j].nomEntreprise);
				break;
			}
		}

		printf("\n\tDescription: %s", tabStages[i].descriptionStage);

		printf("\n\tDate Debut: ");
		afficherDate(tabStages[i].dateDebut);

		printf("\n\tDate Fin: ");
		afficherDate(tabStages[i].dateFin);

		printf("\n---------------------------------------------------\n\n");
	}
}

void afficherEtudiantsAvecStages(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	printf("Liste des etudiants avec leurs stages\n");

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].statutStage, "attente") == 0 || strcmp(tabEtudiants[i].statutStage, "accepte") == 0 || strcmp(tabEtudiants[i].statutStage, "refuse") == 0)
		{
			printf("\n\tEtudiant  %d", i + 1);
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tNom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tDate d'inscription: ");
			afficherDate(tabEtudiants[i].dateInscription);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}
}

void afficherEtudiantsSansStage(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	printf("Liste des etudiants sans stage\n");

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].statutStage, "non") == 0)
		{
			printf("\n\tEtudiant  %d", i + 1);
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tNom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tDate d'inscription: ");
			afficherDate(tabEtudiants[i].dateInscription);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}
}

void afficherEtudiantsAvecStagesTriees(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	printf("Liste des etudiants avec leurs stages triees par statut\n");

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].statutStage, "attente") == 0 || strcmp(tabEtudiants[i].statutStage, "accepte") == 0 || strcmp(tabEtudiants[i].statutStage, "refuse") == 0)
		{
			for (int j = i + 1; j < nbEtudiants; j++)
			{
				if (strcmp(tabEtudiants[i].statutStage, tabEtudiants[j].statutStage) < 0)
				{
					ETUDIANT temp = tabEtudiants[i];
					tabEtudiants[i] = tabEtudiants[j];
					tabEtudiants[j] = temp;
				}
			}
			printf("\n\tEtudiant  %d", i + 1);
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tNom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tDate d'inscription: ");
			afficherDate(tabEtudiants[i].dateInscription);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}
}

void listePostules(ETUDIANT tabEtudiants[], int nbEtudiants)
{

	printf("Liste des etudiants ayant postule\n\n");

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].statutStage, "attente") == 0)
		{
			printf("\nEtudiant  %d", i + 1);
			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tNom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
			printf("\n\tDate de Naissance: ");
			afficherDate(tabEtudiants[i].dateNaissance);
			printf("\n\tDate d'inscription: ");
			afficherDate(tabEtudiants[i].dateInscription);
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}
}

void listeStageeRefuses(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	system("cls");
	bool found = false;
	printf("Liste des etudiants dont leurs demandes ont ete refuses\n\n");

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].statutStage, "refuse") == 0)
		{
			found = true;
			printf("\n\t%s   %s  %s ", tabEtudiants[i].nomEtudiant, tabEtudiants[i].prenomEtudiant, tabEtudiants[i].moyenneEtudiant);
			printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("\nIl n y a pas de refus de stage a cet instant\n");
	}
}

void listeStageeAccepte(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	system("cls");
	bool found = false;
	printf("Liste des etudiants dont leurs demandes ont ete acceptes\n\n");

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].statutStage, "accepte") == 0)
		{
			found = true;
			printf("\n\t%s   %s  %s ", tabEtudiants[i].nomEtudiant, tabEtudiants[i].prenomEtudiant, tabEtudiants[i].moyenneEtudiant);
			printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
			printf("\n---------------------------------------------------\n\n");
		}
	}

	if (!found)
	{
		printf("\nIl n y a pas d acceptation de stage a cet instant de stage a cet instant\n");
	}
}