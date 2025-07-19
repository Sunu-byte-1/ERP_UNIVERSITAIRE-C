#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "dataBase.h"
#include "affichageetudiants.h"
#include "admin.h"

void afficherEtudiants(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	printf("Liste des etudiants \n\n");
	for (int i = 0; i < nbEtudiants; i++)
	{
		printf("\n\tEtudiant  %d", i + 1);
		printf("\n\tPrenom:  %s ", tabEtudiants[i].prenomEtudiant);
		printf("\n\tnom:  %s ", tabEtudiants[i].nomEtudiant);
		printf("\n\tFiliere: %s ", tabEtudiants[i].filiere);
		printf("\n\tMatricule:  %s ", tabEtudiants[i].matricule);
		printf("\n\tDate de Naissance: ");
		afficherDate(tabEtudiants[i].dateNaissance);
		printf("\n\tDate d'inscription: ");
		afficherDate(tabEtudiants[i].dateInscription);
		printf("\n\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
		printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
		printf("\n---------------------------------------------------\n\n");
	}
}

void affichertabEtudiantsAvecNotes(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	printf("Liste des etudiants avec leurs notes\n");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\t\t%s   %s ", tabEtudiants[i].nomEtudiant, tabEtudiants[i].prenomEtudiant);
			printf("\n--------------------------------------------\n");
		}
	}
}

void etudiantsAvecNotesTriees(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	printf("Liste des etudiants avec leurs notes triees par moyenne\n\n");
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			for (int j = i + 1; j < nbEtudiants; j++)
			{
				if (strcmp(tabEtudiants[i].moyenneEtudiant, tabEtudiants[j].moyenneEtudiant) < 0)
				{
					ETUDIANT temp = tabEtudiants[i];
					tabEtudiants[i] = tabEtudiants[j];
					tabEtudiants[j] = temp;
				}
			}
		}
	}
	bool found = false;
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			found = true;
			printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
			printf("\n\t\t%s   %s ", tabEtudiants[i].nomEtudiant, tabEtudiants[i].prenomEtudiant);
			printf("\n--------------------------------------------\n");
		}
	}
	if (!found)
	{
		printf("\n\nAucun etudiant n a une note ");
	}
}

void etudiantsAvecMoyenneSuperieure(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	float moyenneSeuil;
	printf("\n\nVeuillez saisir la moyenne seuil: ");
	scanf("%f", &moyenneSeuil);
	system("cls");
	bool found = false;
	printf("\n\nListe des etudiants avec une moyenne inferieure a %.2f\n", moyenneSeuil);
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			float moyenne = atof(tabEtudiants[i].moyenneEtudiant);
			if (moyenne > moyenneSeuil)
			{
				found = true;
				printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
				printf("\n\t\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
				printf("\n\t\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
				printf("\n\t\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
				printf("\n---------------------------------------------------\n\n");
			}
		}
	}
	if (!found)
	{
		printf("\n\nAucun etudiant trouvé....\n\n");
	}
}

void etudiantsAvecMoyenneInferieure(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	float moyenneSeuil;
	printf("\n\nVeuillez saisir la moyenne seuil: ");
	scanf("%f", &moyenneSeuil);
	system("cls");
	bool found = false;
	printf("\n\nListe des etudiants avec une moyenne inferieure a %.2f\n", moyenneSeuil);
	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].moyenneEtudiant, "vide") != 0)
		{
			float moyenne = atof(tabEtudiants[i].moyenneEtudiant);
			if (moyenne < moyenneSeuil)
			{
				found = true;
				printf("\n\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
				printf("\n\t\tnom:  %s ", tabEtudiants[i].prenomEtudiant);
				printf("\n\t\tPrenom:  %s ", tabEtudiants[i].nomEtudiant);
				printf("\n\t\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
				printf("\n---------------------------------------------------\n\n");
			}
		}
	}
	if (!found)
	{
		printf("\n\nAucun etudiant trouvé....\n\n");
	}
}

void listeEtudiantsTrieParNom(ETUDIANT tabEtudiants[], int nbEtudiants)
{
	printf("Liste des etudiants triee par nom\n");
	for (int i = 0; i < nbEtudiants; i++)
	{
		for (int j = i + 1; j < nbEtudiants; j++)
		{
			if (strcmp(tabEtudiants[i].nomEtudiant, tabEtudiants[j].nomEtudiant) > 0)
			{
				ETUDIANT temp = tabEtudiants[i];
				tabEtudiants[i] = tabEtudiants[j];
				tabEtudiants[j] = temp;
			}
		}
	}
	for (int i = 0; i < nbEtudiants; i++)
	{
		printf("\n\tnom:  %s ", tabEtudiants[i].nomEtudiant);
		printf("\n\t\tPrenom:  %s ", tabEtudiants[i].prenomEtudiant);
		printf("\n\t\tMoyenne:  %s ", tabEtudiants[i].moyenneEtudiant);
		printf("\n\t\tStatut Stage:  %s ", tabEtudiants[i].statutStage);
		printf("\n---------------------------------------------------\n\n");
	}
}
