#ifndef AFFICHAGEETUDIANTS_H
#define AFFICHAGEETUDIANTS_H

#include "dataBase.h"

void afficherEtudiants(ETUDIANT tabEtudiants[], int nbEtudiants);
void affichertabEtudiantsAvecNotes(ETUDIANT tabEtudiants[], int nbEtudiants);
void etudiantsAvecNotesTriees(ETUDIANT tabEtudiants[], int nbEtudiants);
void etudiantsAvecMoyenneSuperieure(ETUDIANT tabEtudiants[], int nbEtudiants);
void etudiantsAvecMoyenneInferieure(ETUDIANT tabEtudiants[], int nbEtudiants);
void listeEtudiantsTrieParNom(ETUDIANT tabEtudiants[], int nbEtudiants);

#endif
