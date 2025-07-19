#include <stdio.h>
#include <stdlib.h>
#include "dataBase.h"

ETUDIANTSUGGERE suggererEtudiant(ETUDIANT tabEtudiants[], int nbEtudiants);

void validerSuggestion(ETUDIANT tabEtudiants[], int nbEtudiants, ETUDIANTSUGGERE tabSuggestions[], int nbSuggestions);

void listeSuggestion(ETUDIANTSUGGERE tabSuggestions[], int nbSuggestions);

void tabEtudiantsSuggerer(ETUDIANT tabEtudiants[], int nbEtudiants);