
#include "admin.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>

#ifndef RECHERCHES_H
#define RECHERCHES_H


void rechercherEtudiantParMatricule(ETUDIANT tabEtudiants[], int nbEtudiants);
void rechercherEtudiantParNom(ETUDIANT tabEtudiants[], int nbEtudiants);
void rechercherEtudiantParPrenom(ETUDIANT tabEtudiants[], int nbEtudiants);
void rechercherEtudiantParDateNaissance(ETUDIANT tabEtudiants[], int nbEtudiants);
void rechercherEtudiantParMatriculeOuNomOuPrenom(ETUDIANT tabEtudiants[], int nbEtudiants);
void rechercherEtudiantParNomOuPrenom(ETUDIANT tabEtudiants[], int nbEtudiants);
void rechercherEtudiantParMoyenne(ETUDIANT tabEtudiants[], int nbEtudiants);
void rechercherEtudiantParStatutStage(ETUDIANT tabEtudiants[], int nbEtudiants);

#endif
