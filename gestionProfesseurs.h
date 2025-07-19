#ifndef GESTIONPROFESSEURS_H
#define GESTIONPROFESSEURS_H

#include "dataBase.h"
#include "admin.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#include "professeur.h"
#include "gestionProfesseurs.h"

PROFESSEUR ajouterProfesseur();
void afficherProfesseurs(PROFESSEUR tabProfesseurs[], int nbProfesseurs);
void rechercherProfesseurParNom(PROFESSEUR tabProfesseurs[], int nbProfesseurs);
void rechercherProfesseurParMatricule(PROFESSEUR tabProfesseurs[], int nbProfesseurs);
void modifierProfesseur(PROFESSEUR tabProfesseurs[], int nbProfesseurs);
#endif // GESTIONPROFESSEURS_H
