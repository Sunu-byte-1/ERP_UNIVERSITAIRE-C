

#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>
#include "dataBase.h"

bool connexionAdmin(char *username, char *password);
int connexionAdminPrompt(char *username, char *password);
DATEPERSO saisirDate(char message[100]);
void afficherDate(DATEPERSO D);
ETUDIANT ajouterEtudiant();
void modifierEtudiant(ETUDIANT tabEtudiants[], int nbEtudiants);
void afficherEtudiants(ETUDIANT tabEtudiants[], int nbEtudiants);
void ajouterNote(ETUDIANT tabEtudiants[], int nbEtudiants);
void affichertabEtudiantsAvecNotes(ETUDIANT tabEtudiants[], int nbEtudiants);
void etudiantsAvecNotesTriees(ETUDIANT tabEtudiants[], int nbEtudiants);
void afficherEtudiantsAvecStagesTriees(ETUDIANT tabEtudiants[], int nbEtudiants);
void etudiantsAvecMoyenneSuperieure(ETUDIANT tabEtudiants[], int nbEtudiants);
void etudiantsAvecMoyenneInferieure(ETUDIANT tabEtudiants[], int nbEtudiants);
void listeEtudiantsTrieParNom(ETUDIANT tabEtudiants[], int nbEtudiants);
