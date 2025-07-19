#include "dataBase.h"
#include "admin.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stage.h"

void ListeCandidatures(ETUDIANT tabEtudiants[], int nbEtudiants, CANDIDATURE tabCandidatures[], int nbCandidatures, STAGE tabStages[], int nbStages)
{
	printf("Liste des candidatures des etudiants\n");

	int indexEtudiant = 0;
	int indexStage = 0;

	for (int i = 0; i < nbCandidatures; i++)
	{
	}
}

CANDIDATURE postuluerStage(ETUDIANT tabEtudiants[], int nbEtudiants, STAGE tabStages[], int nbStages, char matriculeEtudiant[11])
{
	CANDIDATURE C;

	static int idCandidature = 1;
	system("cls");
	printf("\n ----- POSTULER A UN STAGE -----\n");

	C.id_canditature = idCandidature++;

	bool stageExiste = false;
	int positionStage = 0;

	printf("Veuillez saisir l'ID du stage:   ");
	do
	{
		scanf("%d", &C.id_stage);
		for (int i = 0; i < nbStages; i++)
		{
			if (tabStages[i].id_stage == C.id_stage)
			{
				stageExiste = true;
				positionStage = i;
				break;
			}
		}
		if (!stageExiste)
		{
			printf("ID de stage invalide\n");
		}
	} while (!stageExiste);

	printf("\n\nStage trouve: ***%s***\n", tabStages[positionStage].titreStage);
	printf("%s \n\n", tabStages[positionStage].descriptionStage);

	strcpy(C.matriculeEtudiant, matriculeEtudiant);
	strcpy(C.statut, "attente");

	C.dateCanditature = saisirDate("Date de candidature (JJ/MM/AAAA)");

	for (int i = 0; i < nbEtudiants; i++)
	{
		if (strcmp(tabEtudiants[i].matricule, matriculeEtudiant) == 0)
		{
			strcpy(tabEtudiants[i].statutStage, "attente");
			strcpy(C.moyenneEtudiant, tabEtudiants[i].moyenneEtudiant);
			printf("\n\n\nCandidature ajoutee avec succes pour l'etudiant %s %s\n\n\n", tabEtudiants[i].prenomEtudiant, tabEtudiants[i].nomEtudiant);
			break;
		}
	}

	return C;
}