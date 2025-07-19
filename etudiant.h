
#ifndef ETUDIANT_H
#define ETUDIANT_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "allMenu.h"
#include "admin.h"
#include "recherches.h"
#include "stage.h"
#include "dataBase.h"
#include "Entreprise.h"
#include "candidature.h"

bool connexionEtudiant(char matricule[11], ETUDIANT tabEtudiants[], int nbEtudiants);

void voirInfosEtudiant(char matricule[11], ETUDIANT tabEtudiants[], int nbEtudiants);

void voirStatutStageEtudiant(char matricule[11], ETUDIANT tabEtudiants[], int nbEtudiants);

#endif