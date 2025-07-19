
#ifndef STAGE_H
#define STAGE_H

#include <stdbool.h>
#include "admin.h"
#include "dataBase.h"

void voirListeStages(STAGE tabStages[], int nbStages, ENTREPRISE tabEntreprises[], int nbEntreprises);

void afficherEtudiantsAvecStages(ETUDIANT tabEtudiants[], int nbEtudiants);

void afficherEtudiantsSansStage(ETUDIANT tabEtudiants[], int nbEtudiants);

void afficherEtudiantsAvecStagesTriees(ETUDIANT tabEtudiants[], int nbEtudiants);

void listePostules(ETUDIANT tabEtudiants[], int nbEtudiants);

void listeStageeRefuses(ETUDIANT tabEtudiants[], int nbEtudiants);

void listeStageeAccepte(ETUDIANT tabEtudiants[], int nbEtudiants);

#endif
