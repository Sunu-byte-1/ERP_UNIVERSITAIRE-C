#include <stdio.h>
#include <stdlib.h>
#include "allMenu.h"
#include "admin.h"

int menuProfesseur()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================MENU PROFESSEUR==============================\n\n");
		printf("1. VOIR MES INFORMATIONS\n");
		printf("2. VOIR MES ETUDIANTS\n");
		printf("3. SE DECONNECTER\n");
		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);
	} while (choix < 1 || choix > 3);
	return choix;
}

#include <stdio.h>
#include <stdlib.h>
#include "allMenu.h"

int menuPrincipal()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================BIENVENUE A L UNIVERSITE ******==============================\n\n");
		printf("1. SE CONNECTER EN TANT QU ADMINISTRATEUR\n");
		printf("2. SE CONNECTER EN TANT QU ETUDIANT \n");
		printf("3. SE CONNECTER EN TANT QU ENTREPRISE\n");
		printf("4. SE CONNECTER EN TANT QUE PROFESSEUR\n");
		printf("5. SE CONNECTER EN TANT QUE SERVICE FINANCIER\n");
		printf("6. QUITTER LE PROGRAMME\n");

		fflush(stdin);
		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);
	} while (choix < 1 || choix > 6);

	return choix;
}

int menuEntreprise()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================MENU ENTREPRISE==============================\n\n");
		printf("1. AJOUTER STAGE\n");
		printf("2. VOIR LISTE ETUDIANT(S) POSTULE(S) \n");
		printf("3. VALIDER UN STAGE\n");
		printf("4. AFFICHER LISTE SUGGESTIONS\n");
		printf("5. VALIDER UNE SUGGESTION\n");
		printf("6. AFFICHER MA LISTE DE STAGE(S)\n");
		printf("7. SE DECONNECTER\n");

		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);

	} while (choix < 1 || choix > 7);

	return choix;
}

int menuEtudiant()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================MENU ETUDIANT==============================\n\n");
		printf("1. VOIR SES INFORMATIONS\n");
		printf("2. VOIR SON CLASSEMENT \n");
		printf("3. DEMANDER UN STAGE\n");
		printf("4. VOIR STATUT DE STAGE\n");
		printf("5. SE DECONNECTER\n");

		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);
	} while (choix < 1 || choix > 5);

	return choix;
}

int menuAdmin()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================MENU ADMINISTRATEUR==============================\n\n");
		printf("1. GESTION DES ETUDIANTS\n");
		printf("2. GESTION DES ENTREPRISES \n");
		printf("3. GESTION DES PROFESSEURS\n");
		printf("4. SE DECONNECTER\n");

		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);
	} while (choix < 1 || choix > 4);

	return choix;
}

int menuCaisse()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================MENU CAISSE==============================\n\n");
		printf("1. PAYER UN PROFESSEUR\n");
		printf("2. PAYER UN ETUDIANT \n");
		printf("3. AFFICHER LISTE DES PROFESSEURS PAYES\n");
		printf("4. AFFICHER LISTE DES ETUDIANTS PAYES\n");
		printf("5. LISTE IMPAYES ETUDIANTS\n");
		printf("6. LISTE IMPAYES PROFESSEURS\n");
		printf("7. SE DECONNECTER\n");

		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);
	} while (choix < 1 || choix > 7);

	return choix;
}

int adminGestionEntreprises()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================GESTION ENTREPRISES==============================\n\n");
		printf("1. AFFICHER LISTE STAGES DISPONIBLES\n");
		printf("2. AFFICHER LISTE ETUDIANTS POSTULES \n");
		printf("3. AFFICHER LISTE STAGES REFUSES \n");
		printf("4. AFFICHER LISTE STAGES ACCEPTES\n");
		printf("5. SUGGERER UN ETUDIANT \n");
		printf("6. LISTE DES ENTREPRISES PARTENAIRES \n");

		printf("7. RETOUR\n");

		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);
	} while (choix < 1 || choix > 7);

	return choix;
}

int adminGestionEtudiants()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================GESTION ETUDIANTS==============================\n\n");

		printf("\n\n=============MODIFICATION CREATION DONNEES ETUDIANT=============\n");
		printf("\t1.  AJOUTER UN ETUDIANT\n");
		printf("\t2.  AJOUTER MOYENNE ETUDIANT \n");
		printf("\t3.  MODIFIER DONNEES ETUDIANT\n");

		printf("\n\n=============AFFICHAGE DONNEES DES ETUDIANTS=============\n");
		printf("\t4.  AFFICHER LISTE ETUDIANTS\n");
		printf("\t5.  AFFICHER LISTE ETUDIANTS CLASSES PAR NOTES\n");
		printf("\t6.  AFFICHER LISTE ETUDIANTS CLASSES PAR NOM\n");
		printf("\t7.  AFFICHER LISTE ETUDIANTS AVEC MOYENNE SUPERIEUR A N\n");
		printf("\t8.  AFFICHER LISTE ETUDIANTS AVEC MOYENNE INFERIEUR A N\n");
		printf("\t9.  AFFICHER LISTE ETUDIANTS AYANT POSTULE A UN STAGE\n");
		printf("\t10. AFFICHER LISTE ETUDIANTS AYANT PAS POSTULE A UN STAGE\n");

		printf("\n\n=============RECHERCHER ETUDIANTS PAR CRITERE=============\n");
		printf("\t11. RECHERCHER UN ETUDIANT PAR NOM\n");
		printf("\t12. RECHERCHER UN ETUDIANT PAR PRENOM\n");
		printf("\t13. RECHERCHER UN ETUDIANT PAR MATRICULE\n");
		printf("\t14. RECHERCHER UN ETUDIANT PAR MATRICULE, PRENOM OU NOM\n");
		printf("\t15. RECHERCHER UN ETUDIANT PAR MOYENNE\n");

		printf("\n\n16. RETOUR\n");

		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);

	} while (choix < 1 || choix > 16);

	return choix;
}

int adminGestionProfesseurs()
{
	int choix;
	system("cls");
	do
	{
		printf("=========================GESTION PROFESSEURS==============================\n\n");
		printf("1. AJOUTER UN PROFESSEUR\n");
		printf("2. MODIFIER UN PROFESSEUR \n");
		printf("3. AFFICHER LISTE PROFESSEURS\n");
		printf("4. RECHERCHER UN PROFESSEUR PAR NOM\n");
		printf("5. RECHERCHER UN PROFESSEUR PAR MATRICULE\n");
		printf("6. RETOUR\n");

		printf("\n\nVotre choix:  ");
		scanf("%d", &choix);
	} while (choix < 1 || choix > 6);

	return choix;
}