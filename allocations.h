#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "dataBase.h"

#ifndef ALLOCATIONS_H
#define ALLOCATIONS_H

#include "dataBase.h"

extern ALLOCATION tabAllocations[100];
extern int nbAllocations;

void payerEtudiant(ETUDIANT tabEtudiants[], int nbEtudiants);

void afficherListeEtudiantsPayes();

void listeImpayesEtudiants(ETUDIANT tabEtudiants[], int nbEtudiants);

#endif // ALLOCATIONS_H
