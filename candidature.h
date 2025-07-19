#include "dataBase.h"
#include "admin.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "stage.h"
#ifndef CANDIDATURE_H
#define CANDIDATURE_H	

void ListeCandidatures(ETUDIANT tabEtudiants[], int nbEtudiants, CANDIDATURE tabCandidatures[], int nbCandidatures, STAGE tabStages[], int nbStages);





CANDIDATURE postuluerStage(ETUDIANT tabEtudiants[], int nbEtudiants, STAGE tabStages[], int nbStages, char matriculeEtudiant[11]);

#endif
