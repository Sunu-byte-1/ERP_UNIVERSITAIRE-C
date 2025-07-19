#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "dataBase.h"
#include "allocations.h"

bool connexionCaisse(char username[50], char password[50]);
bool connexionCaissePrompt();

extern SALAIRE tabSalaires[1000];
extern int nbSalaires;

void payerProfesseur(PROFESSEUR tabProfesseurs[], int nbProfesseurs);

void afficherListeProfesseursPayes(SALAIRE tabSalaires[], int nbSalaires);

void listeImpayesProfesseurs(PROFESSEUR tabProfesseurs[], int nbProfesseurs);