#include "dataBase.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "database.h"
#include "admin.h"

#include "Entreprise.h"

ENTREPRISE tabEntreprises[100] = {
    {1, "SONATEL", "SONATELSN", "TELECOM", "SENEGAL"},
    {2, "ORANGE", "ORANGESN", "TELECOM", "SENEGAL"},
    {3, "TIGO", "TIGOSN", "TELECOM", "SENEGAL"},
    {4, "EXPRESSO", "EXPRESSOSN", "TELECOM", "SENEGAL"},
    {5, "SENELEC", "SENELECSN", "ENERGIE", "SENEGAL"},
    {6, "SONACOS", "SONACOSSN", "AGROALIMENTAIRE", "SENEGAL"},
    {7, "CFAO MOTORS", "CFAOMOTORSSN", "AUTOMOBILE", "SENEGAL"},
    {8, "TOTAL SENEGAL", "TOTALSN", "ENERGIE", "SENEGAL"},
    {9, "PETROSEN", "PETROSENSN", "ENERGIE", "SENEGAL"},
    {10, "BICIS", "BICISSN", "BANQUE", "SENEGAL"}};
int nbEntreprises = 11;

bool connexionEntreprise(char *username, ENTREPRISE tabEntreprises[], int nbEntreprises)
{
    for (int i = 0; i < nbEntreprises; i++)
    {
        if (strcmp(tabEntreprises[i].usernameEntreprise, username) == 0)
        {
            return true;
        }
    }
    return false;
}

ENTREPRISE ajouterEntreprise()
{
    ENTREPRISE E;
    static int idEntreprise = 10;

    printf("\n ----- Ajouter une Entreprise -----\n");

    E.id_entreprise = idEntreprise++;

    printf("\nVeuillez saisir le nom de l'entreprise: ");
    scanf("%s", E.nomEntreprise);

    printf("\nVeuillez saisir le nom d'utilisateur de l'entreprise: ");
    scanf("%s", E.usernameEntreprise);

    printf("\nVeuillez saisir le secteur d'activite de l'entreprise: ");
    scanf("%s", E.secteurEntreprise);

    printf("\nVeuillez saisir l'adresse de l'entreprise: ");
    scanf("%s", E.adresseentreprises);

    return E;
}

STAGE creerStage(ENTREPRISE tabEntreprises[], int nbEntreprises, char usernameEntreprise[50])
{
    STAGE S;
    static int idStage = 1;
    printf("\n ----- Creer un Stage -----\n\n");

    printf("\n\nVeuillez saisir le titre stage:  ");
    getchar();
    gets(S.titreStage);

    int position = 0;

    for (int i = 0; i < nbEntreprises; i++)
    {
        if (strcmp(tabEntreprises[i].usernameEntreprise, usernameEntreprise) == 0)
        {
            position = i;
            break;
        }
    }

    printf("\n\nVous etes bien  %s\n", tabEntreprises[position].nomEntreprise);

    printf("\nVeuillez saisir la Description du stage:   \n");
    getchar();
    gets(S.descriptionStage);

    S.dateDebut = saisirDate("date de debut du stage (JJ/MM/AAAA):   ");

    S.dateFin = saisirDate("date de fin du stage (JJ/MM/AAAA):    ");

    S.id_stage = idStage++;
    printf("\n\n");
    system("pause");
    system("cls");
    printf("\nStage cree avec succes !\n\n");
    printf("\tID du stage: %d\n", S.id_stage);
    printf("\tTitre du stage: %s\n", S.titreStage);
    printf("\tnom de l'entreprise: %s\n", tabEntreprises[position].nomEntreprise);
    fflush(stdin);
    printf("\tDescription du stage:  %s ", S.descriptionStage);
    printf("\n\tDate de debut du stage:  ");
    afficherDate(S.dateDebut);
    printf("\n\tDate de fin du stage:  ");
    afficherDate(S.dateFin);

    return S;
}

// c est une fonction securisee qui affiche la liste des stages disponibles de l entreprise connectee l empechant a voir les stages des autres entreprises
void afficherListeStagesParEntreprise(ENTREPRISE tabEntreprises[], int nbEntreprises, STAGE tabStages[], int nbStages, char usernameEntreprise[50])
{
    int trouve = 0;
    for (int i = 0; i < nbEntreprises; i++)
    {
        if (strcmp(tabEntreprises[i].usernameEntreprise, usernameEntreprise) == 0)
        {
            printf("\n ----- Liste des Stages pour l'Entreprise: %s -----\n", tabEntreprises[i].nomEntreprise);
            for (int j = 0; j < nbStages; j++)
            {
                if (tabStages[j].id_entreprise == tabEntreprises[i].id_entreprise)
                {
                    trouve = 1;
                    printf("\nID Stage: %d\nTitre: %s\nDescription: %s\nDate debut: ",
                           tabStages[j].id_stage, tabStages[j].titreStage, tabStages[j].descriptionStage);
                    afficherDate(tabStages[j].dateDebut);
                    printf("\nDate fin: ");
                    afficherDate(tabStages[j].dateFin);
                    printf("\n--------------------------------------------------------------------------\n");
                }
            }
            if (!trouve)
            {
                printf("\nAucun stage trouvé pour cette entreprise.\n");
            }
            break;
        }
    }
}

int choixValidationStage()
{
    int choix;
    printf("\n\n\n ----- Choix de Validation de Stage -----\n");
    printf("1. Valider le stage\n");
    printf("2. Refuser le stage\n");
    printf("3. Mettre en attente");

    printf("Votre choix : ");
    scanf("%d", &choix);
    return choix - 1;
}

void validerCandidature(ETUDIANT tabEtudiants[], int nbEtudiants, CANDIDATURE tabCandidature[], int nbCandidatures)
{
    char mat[11];
    int found = false;
    int posEtu = 0;
    int posCand = 0;
    system("cls");
    printf("Veuillez saisir le matricule de l etudiant a gerer:   ");

    do
    {
        scanf("%s", mat);

        for (int i = 0; i < nbEtudiants; i++)
        {
            if (strcmp(tabEtudiants[i].matricule, mat) == 0)
            {
                posEtu = i;
                for (int j = 0; j < nbCandidatures; j++)
                {
                    if (strcmp(tabCandidature[j].matriculeEtudiant, tabEtudiants[i].matricule) == 0)
                    {
                        posCand = j;
                        found = true;
                        break;
                    }
                }
                break;
            }
        }

        if (!found)
        {
            printf("Etudiant non trouve ressayez:  ");
        }
    } while (!found);

    char *choice[] = {"accepte", "refuse", "attente"};
    int n = choixValidationStage();

    if (n >= 0 && n < 3)
    {
        strcpy(tabCandidature[posCand].statut, choice[n]);
        strcpy(tabEtudiants[posEtu].statutStage, choice[n]);

        printf("Candidature de %s %s gere avec success", tabEtudiants[posEtu].prenomEtudiant, tabEtudiants[posEtu].nomEtudiant);
    }
    else
    {
        printf("Choix invalide");
    }
}

void ListePostulants(CANDIDATURE tabCandidatures[], int nbCandidatures, ETUDIANT tabEtudiants[], int nbEtudiants, STAGE tabStages[], int nbStages, ENTREPRISE tabEntreprises[], int nbEntreprises, char usernameEntreprise[50])
{
    printf("\n ----- Liste des Etudiants postulants pour les Stages de %s -----\n", usernameEntreprise);
    for (int i = 0; i < nbCandidatures; i++)
    {
        for (int j = 0; j < nbStages; j++)
        {
            if (tabCandidatures[i].id_stage == tabStages[j].id_stage)
            {
                for (int k = 0; k < nbEntreprises; k++)
                {
                    if (tabStages[j].id_entreprise == tabEntreprises[k].id_entreprise)
                    {
                        if (strcmp(tabEntreprises[k].usernameEntreprise, usernameEntreprise) == 0)
                        {
                            printf("\nID Candidature: %d", tabCandidatures[i].id_canditature);
                            printf("\nMatricule Etudiant: %s", tabCandidatures[i].matriculeEtudiant);
                            printf("\nStatut: %s", tabCandidatures[i].statut);
                            printf("\nDate de Candidature: ");
                            afficherDate(tabCandidatures[i].dateCanditature);
                            printf("\nMoyenne Etudiant: %s\n", tabCandidatures[i].moyenneEtudiant);

                            for (int l = 0; l < nbEtudiants; l++)
                            {
                                if (strcmp(tabCandidatures[i].matriculeEtudiant, tabEtudiants[l].matricule) == 0)
                                {
                                    printf("Nom Etudiant: %s %s\n", tabEtudiants[l].prenomEtudiant, tabEtudiants[l].nomEtudiant);
                                    printf("\nmatricule:  %s", tabEtudiants[l].matricule);
                                    printf("--------------------------------------------------------------------------");
                                    break;
                                }
                            }
                        }
                    }
                }
            }
        }
    }
}

void listePartenaires(ENTREPRISE tabEntreprises[], int nbEntreprise)
{
    printf("Liste des entreprises partenaires\n\n");

    for (int i = 0; i < nbEntreprise; i++)
    {
        printf("%s\n", tabEntreprises[i].nomEntreprise);
        printf("%s\n", tabEntreprises[i].secteurEntreprise);
        printf("--------------------------------------------------------\n");
    }
}

void afficherProfilEtudiant()
{
    ETUDIANT e;

    printf("\n ----- Profil Etudiant -----\n");
    printf("Matricule : %d\n", e.matricule);
    printf("ID Filiere : %s\n", e.filiere);

    printf("Date d'Inscription : %s\n", e.dateInscription);
}
