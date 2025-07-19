#ifndef ENTREPRISE_H
#define ENTREPRISE_H
#include "dataBase.h"

#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "database.h"
#include "admin.h"

extern ENTREPRISE tabEntreprises[100];
extern int nbEntreprises;

bool connexionEntreprise(char *username, ENTREPRISE tabEntreprises[], int nbEntreprises);

ENTREPRISE ajouterEntreprise();

STAGE creerStage(ENTREPRISE tabEntreprises[], int nbEntreprises, char usernameEntreprise[50]);

void afficherListeStagesParEntreprise(ENTREPRISE tabEntreprises[], int nbEntreprises, STAGE tabStages[], int nbStages, char usernameEntreprise[50]);

int choixValidationStage();

void validerCandidature(ETUDIANT tabEtudiants[], int nbEtudiants, CANDIDATURE tabCandidature[], int nbCandidatures);

void ListePostulants(CANDIDATURE tabCandidatures[], int nbCandidatures, ETUDIANT tabEtudiants[], int nbEtudiants, STAGE tabStages[], int nbStages, ENTREPRISE tabEntreprises[], int nbEntreprises, char usernameEntreprise[50]);

void afficherProfilEtudiant();

int choixValidationStage();

void ValiderStage();

void afficherListeStages(ETUDIANT tabEtudiants[], int nbEtudiants, ENTREPRISE tabEntreprises[], int nbEntreprises);

void listePartenaires(ENTREPRISE tabEntreprises[], int nbEntreprise);

#endif // ENTREPRISE_H
