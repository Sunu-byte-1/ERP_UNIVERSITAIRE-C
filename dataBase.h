#ifndef TABLES_H
#define TABLES_H
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
	int j, m, a;
} DATEPERSO;

typedef struct
{
	char matricule[11];
	char prenomEtudiant[50];
	char nomEtudiant[50];
	DATEPERSO dateNaissance;
	char statutStage[10];
	char moyenneEtudiant[10];
	char filiere[10];
	DATEPERSO dateInscription;
	char allocation[10];
} ETUDIANT;

typedef struct
{
	char matricule[11];
	char prenomProffesseur[50];
	char nomProfesseur[50];
	char matiereEnseignee[50];
	char filiere[30];
	char statutSalaire[10];
} PROFESSEUR;

typedef struct
{
	char *idFiliere;
	char nomFiliere[100];
	char descriptionFiliere[1000];
	int statutStage;
	char brancheFiliere;
} FILIERE;

typedef struct
{
	char *idBranche;
	char *nomBranche;
	char descriptionBranche;
} BRANCHE;

typedef struct
{
	int id_entreprise;
	char nomEntreprise[100];
	char usernameEntreprise[50];
	char secteurEntreprise[100];
	char adresseentreprises[150];

} ENTREPRISE;

typedef struct
{
	int id_stage;
	char titreStage[100];
	int id_entreprise;
	char descriptionStage[200];
	DATEPERSO dateDebut;
	DATEPERSO dateFin;

} STAGE;

typedef struct
{
	int id_canditature;
	int id_stage;
	char matriculeEtudiant[11];
	char statut[30];
	DATEPERSO dateCanditature;
	char moyenneEtudiant[10];

} CANDIDATURE;

typedef struct
{
	ETUDIANT etudiantSuggere;

} ETUDIANTSUGGERE;

typedef struct

{
	PROFESSEUR professeur;
	float montant;
	char mois[16];
} SALAIRE;


typedef struct
{
	ETUDIANT etudiant;
	float montant;
	char mois[16];
} ALLOCATION;

#endif
