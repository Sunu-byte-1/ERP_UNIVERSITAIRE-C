#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "professeur.h"
#include "dataBase.h"
#include <stdbool.h>

int connexionProfesseur(const char matricule[8], PROFESSEUR tabProfesseurs[], int nbProfesseurs)
{
	for (int i = 0; i < nbProfesseurs; i++)
	{
		if (strcmp(tabProfesseurs[i].matricule, matricule) == 0)
		{
			return true;
		}
	}
	return false;
}

void afficherProfesseur(PROFESSEUR tabProfesseurs[], int nbProfesseurs, const char matricule[8])
{
	int position = 0;

	for (int i = 0; i < nbProfesseurs; i++)
	{
		if (strcmp(tabProfesseurs[i].matricule, matricule) == 0)
		{

			position = i;
			break;
		}
	}

	{
		printf("\n\tMatricule:  %s ", tabProfesseurs[position].matricule);
		printf("\n\tNom:  %s ", tabProfesseurs[position].nomProfesseur);
		printf("\n\tPrenom:  %s ", tabProfesseurs[position].prenomProffesseur);
		printf("\n\tMatiere Enseignee: %s ", tabProfesseurs[position].matiereEnseignee);
		printf("\n\tFiliere: %s ", tabProfesseurs[position].filiere);
		printf("\n\tStatut Salaire: %s ", tabProfesseurs[position].statutSalaire);
		printf("\n---------------------------------------------------\n\n");
	}
}

void afficherEtudiantsParFiliere(ETUDIANT tabEtudiants[], int nbEtudiants, PROFESSEUR tabProfesseurs[], int nbProfesseurs, char matricule[8])
{
	int position = 0;

	for (int i = 0; i < nbProfesseurs; i++)
	{
		if (strcmp(tabProfesseurs[i].matricule, matricule) == 0)
		{
			position = i;
			break;
		}
	}

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].filiere, tabProfesseurs[position].filiere) == 0)
		{

			printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
			printf("\n\tNom:  %s ", tabEtudiants[i].nomEtudiant);
			printf("\n\tPrenom:  %s ", tabEtudiants[i].prenomEtudiant);
			printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
			printf("\n\tDate de Naissance: ");
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
			printf("\n---------------------------------------------------\n\n");
		}
	}
}