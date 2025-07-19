#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "etudiant.h"
#include "dataBase.h"

bool connexionEtudiant(char matricule[11], ETUDIANT tabEtudiants[], int nbEtudiants)
{
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].matricule, matricule) == 0)
		{
			return true;
		}
	}
	return false;
}

void voirInfosEtudiant(char matricule[11], ETUDIANT tabEtudiants[], int nbEtudiants)
{
	int position = 0;
	bool found = false;

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].matricule, matricule) == 0)
		{
			found = true;
			position = i;
			break;
		}
	}

	if (!found)
	{
		printf("Aucun etudiant trouve avec le matricule %s.\n", matricule);
	}
	else
	{
		printf("\nEtudiant trouve: \n");
		printf("\n\tMatricule:  %s ", tabEtudiants[position].matricule);
		printf("\n\tNom:  %s ", tabEtudiants[position].nomEtudiant);
		printf("\n\tPrenom:  %s ", tabEtudiants[position].prenomEtudiant);
		printf("\n\tFiliere: %s ", tabEtudiants[position].filiere);
		printf("\n\tDate de Naissance: ");
		afficherDate(tabEtudiants[position].dateNaissance);
		printf("\n\tDate d'inscription: ");
		afficherDate(tabEtudiants[position].dateInscription);
		printf("\n\tMoyenne:  %s ", tabEtudiants[position].moyenneEtudiant);
		printf("\n\tStatut Stage:  %s ", tabEtudiants[position].statutStage);
		printf("\n\tAllocation:  %s ", tabEtudiants[position].allocation);
		printf("\n---------------------------------------------------\n\n");
	}
}

void voirStatutStageEtudiant(char matricule[11], ETUDIANT tabEtudiants[], int nbEtudiants)
{
	int position = 0;

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].matricule, matricule) == 0)
		{
			position = i;
			break;
		}
	}

	printf("\nStatut de stage de l'etudiant: ");
	printf("\n\tMatricule:  %s ", tabEtudiants[position].matricule);
	printf("\n\tNom:  %s ", tabEtudiants[position].nomEtudiant);
	printf("\n\tPrenom:  %s ", tabEtudiants[position].prenomEtudiant);
	printf("\n\tStatut Stage:  %s ", tabEtudiants[position].statutStage);
	printf("\n---------------------------------------------------\n\n");
	printf("\n\n");

	if (strcmp(tabEtudiants[position].statutStage, "non") == 0)
	{
		printf("Vous n avez postule a aucun stage");
	}
	else if (strcmp(tabEtudiants[position].statutStage, "accepte") == 0)
	{
		printf("Felicitation! Votre demande de stage a ete bien accepte");
	}
	else if (strcmp(tabEtudiants[position].statutStage, "refuse") == 0)
	{
		printf("Votre demande de stage a ete refuse, du courage");
	}
	else
	{
		printf("Le dema,de de stage est toujours en attente...");
	}
}