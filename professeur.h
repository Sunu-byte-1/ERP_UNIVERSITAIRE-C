#ifndef PROFESSEUR_H
#define PROFESSEUR_H

#include "dataBase.h"

int connexionProfesseur(const char matricule[8], PROFESSEUR tabProfesseurs[], int nbProfesseurs);
void afficherProfesseur(PROFESSEUR tabProfesseurs[], int nbProfesseurs, const char matricule[8]);

void afficherEtudiantsParFiliere(ETUDIANT tabEtudiants[], int nbEtudiants, PROFESSEUR tabProfesseurs[], int nbProfesseurs, char matricule[8]);

#endif
