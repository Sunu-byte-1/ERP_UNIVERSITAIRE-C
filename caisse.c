#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dataBase.h"
#include "allocations.h"
#include "caisse.h"
#define usernameCaisse "caisse"
#define passwordCaisse "caisse@123"

bool connexionCaisse(char username[50], char password[50])
{

	if (strcmp(username, usernameCaisse) == 0 && strcmp(password, passwordCaisse) == 0)
	{
		return true;
	}
	else
	{
		return false;
	}
}

bool connexionCaissePrompt()
{
	char username[50];
	char password[50];
	printf("\nVeuillez saisir votre nom d'utilisateur: ");
	scanf("%s", username);
	printf("\n\nVeuillez saisir votre mot de passe: ");
	scanf("%s", password);

	if (connexionCaisse(username, password))
	{
		return true;
	}
	else
	{
		return false;
	}
}

SALAIRE tabSalaires[1000];
int nbSalaires = 0;

void payerProfesseur(PROFESSEUR tabProfesseurs[], int nbProfesseurs)
{
	SALAIRE S;
	bool found = false;
	int position = 0;
	printf("\n\nVeuillez saisir le matricule du professeur: ");
	fflush(stdin);
	scanf("%s", S.professeur.matricule);

	for (int i = 0; i < nbProfesseurs; i++)
	{
		if (strcmp(tabProfesseurs[i].matricule, S.professeur.matricule) == 0)
		{
			S.professeur = tabProfesseurs[i];
			strcpy(tabProfesseurs[i].statutSalaire, "oui");
			found = true;
			break;
		}
	}

	if (!found)
	{
		printf("\n\nProfesseur non trouvé.\n");
	}
	else
	{
		printf("\n\nVeuillez saisir le mois de paiement: ");
		char mois[16];
		fflush(stdin);
		scanf("%s", mois);
		bool salaireExists = false;

		for (int i = 0; i < nbSalaires; i++)
		{
			if (strcmp(tabSalaires[i].mois, mois) == 0)
			{
				printf("\n\nLe salaire du professeur %s pour le mois %s est de %.2f.\n", tabSalaires[i].professeur.matricule, tabSalaires[i].mois, tabSalaires[i].montant);
				salaireExists = true;
				break;
			}
		}

		if (salaireExists)
		{
			printf("\n\nLe salaire a déjà été payé pour ce mois.\n");
		}
		else
		{
			printf("\n\nVeuillez saisir le montant du salaire: ");
			do
			{
				scanf("%f", &S.montant);
			} while (S.montant <= 0);

			tabSalaires[nbSalaires] = S;
			nbSalaires++;

			printf("\n\nPayement effectué avec succès.\n");
		}
	}
}

void listeImpayesProfesseurs(PROFESSEUR tabProfesseurs[], int nbProfesseurs)
{
	printf("\n\nListe des professeurs à payer:\n\n");
	bool found = false;

	for (int i = 0; i < nbProfesseurs; i++)
	{
		if (strcmp(tabProfesseurs[i].statutSalaire, "non") == 0)
		{
			found = true;
			printf("\n\tMatricule: %s", tabProfesseurs[i].matricule);
			printf("\n\tNom: %s", tabProfesseurs[i].nomProfesseur);
			printf("\n\tPrenom: %s", tabProfesseurs[i].prenomProffesseur);
			printf("\n\tMatiere Enseignee: %s", tabProfesseurs[i].matiereEnseignee);
			printf("\n\tFiliere: %s", tabProfesseurs[i].filiere);
			printf("\n\tStatut Salaire: %s", tabProfesseurs[i].statutSalaire);
			printf("\n---------------------------------------------------\n");
		}
	}

	if (!found)
	{
		printf("\n\nTous les professeurs ont été payés.\n");
	}
}

void afficherListeProfesseursPayes(SALAIRE tabSalaires[], int nbSalaires)
{
	if (nbSalaires == 0)
	{
		printf("\n\nAucun professeur n'a été payé.\n");
		return;
	}

	printf("\n\nListe des professeurs payés:\n\n");
	for (int i = 0; i < nbSalaires; i++)
	{
		printf("\n\n\tMatricule: %s", tabSalaires[i].professeur.matricule);
		printf("\n\tNom: %s", tabSalaires[i].professeur.nomProfesseur);
		printf("\n\tPrenom: %s", tabSalaires[i].professeur.prenomProffesseur);
		printf("\n\tMois: %s", tabSalaires[i].mois);
		printf("\n\tMontant: %.2f", tabSalaires[i].montant);
		printf("\n---------------------------------------------------\n");
	}
}