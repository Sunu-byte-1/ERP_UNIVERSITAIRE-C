#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <windows.h>
#include "allMenu.h"
#include "admin.h"
#include "affichageetudiants.h"
#include "recherches.h"
#include "stage.h"
#include "dataBase.h"
#include "Entreprise.h"
#include "candidature.h"
#include "etudiant.h"
#include "suggestion.h"
#include "couleurs.h"
#include "professeur.h"
#include "gestionProfesseurs.h"
#include "caisse.h"

int main()
{

    int choix, choixAdmin, choixEtudiant, choixEntreprise, choixProf, choixCaisse;

    // tab etudianrs
    ETUDIANT tabEtudiants[1000] = {
        {"ABD-DIO-01", "Abdallah", "DIOUF", {14, 2, 1940}, "non", "17", "GL", {15, 10, 2025}, "non"},
        {"MOH-TIN-02", "Mohammed", "TINE", {2, 7, 1995}, "non", "19", "GL", {14, 10, 2025}, "non"},
        {"LOU-ALV-03", "Louis", "ALVES", {4, 9, 1998}, "non", "12", "IAGE", {16, 12, 2024}, "non"},
        {"MAM-BAR-04", "Mamadou", "BARRY", {2, 8, 2000}, "non", "vide", "RI", {1, 1, 2024}, "non"},
        {"BOU-MBA-05", "Boubacar", "MBAYE", {17, 12, 1990}, "non", "vide", "GL", {14, 10, 2025}, "non"},
        {"FAT-SOW-06", "Fatou", "SOW", {10, 3, 2002}, "non", "vide", "RI", {10, 10, 2024}, "non"},
        {"AMA-NDO-07", "Amadou", "NDOYE", {22, 5, 2001}, "non", "vide", "IAGE", {5, 11, 2024}, "non"},
        {"MAI-DIA-08", "Maimouna", "DIALLO", {8, 6, 2003}, "non", "vide", "GL", {1, 10, 2024}, "non"}};
    int nbEtudiants = 8;
    char matriculeSaisi[11];
    char username[50], password[50];
    char usernameEntreprise[50], passwordEntreprise[50];
    bool listeVue = false;

    // stage
    STAGE tabStages[100];
    int nbStages = 0;

    // candidatures
    CANDIDATURE tabCandidatures[100];
    int nbCandidatures = 0;

    // Sggestions
    ETUDIANTSUGGERE tabSuggestions[100];
    int nbSuggestions = 0;
    bool verifSuggestion = false;

    // profsss
    PROFESSEUR tabProfesseurs[100] = {
        {"P-01-LON", "Masseka", "LONGATE", "PHP", "GL", "non"},
        {"P-02-NDI", "Lamine", "NDIAYE", "BUREAUTIQUE", "GL", "non"},
        {"P-03-DIA", "Moustapha", "DIALLO", "ARCHITECTURE", "GL", "non"},
        {"P-04-SAM", "Monsieur", "SAMB", "JAVASCRIPT", "GL", "non"},
        {"P-05-GUE", "Ndacke", "GUEYE", "ALGORITHMES", "GL", "non"},
        {"P-06-NDI", "Babacar", "NDIAYE", "JAVA", "GL", "non"},
        {"P-07-NDI", "Malle", "NDIAYE", "SGBD", "GL", "non"}};
    int nbProfesseurs = 7;
    char matriculeProf[8];

    // allocation
    ALLOCATION tabAllocations[1000];
    int nbAllocations = 0;

    do
    {
        couleur(9);
        choix = menuPrincipal();

        // switch pour le menu principal
        switch (choix)
        {

        // 1. Admin
        case 1:
            couleur(10);
            if (connexionAdminPrompt(username, password))
            {
                couleur(10);
                system("cls");
                printf("\n\n");
                couleur(10);
                printf("Connexion resussie.....\n");
                couleur(10);
                printf("\n\n");
                system("pause");
                system("cls");
                do
                {
                    choixAdmin = menuAdmin();
                    switch (choixAdmin)
                    {
                    // 1. Ges des etu
                    case 1:
                    {
                        system("cls");
                        int choixAdminEtudiant;
                        do
                        {

                            choixAdminEtudiant = adminGestionEtudiants();
                            switch (choixAdminEtudiant)
                            {
                            case 1:
                                system("cls");
                                tabEtudiants[nbEtudiants] = ajouterEtudiant();
                                nbEtudiants++;
                                break;
                            case 2:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    ajouterNote(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant enregistré pour l instant");
                                }
                                printf("\n\n");
                                system("pause");
                                break;

                            case 3:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    modifierEtudiant(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant enregistré pour l instant");
                                }

                                printf("\n\n");
                                system("pause");
                                break;

                            case 4:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    afficherEtudiants(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant enregistré pour l instant");
                                }

                                printf("\n\n");
                                system("pause");
                                break;

                            case 5:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    etudiantsAvecNotesTriees(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant enregistré pour l instant");
                                }

                                printf("\n\n");
                                system("pause");
                                break;

                            case 6:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    listeEtudiantsTrieParNom(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant enregistré pour l instant");
                                }

                                // afficherEtudiants(tabEtudiants, nbEtudiants);
                                printf("\n\n");
                                system("pause");
                                break;

                            case 7:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    etudiantsAvecMoyenneSuperieure(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant enregistré pour l instant");
                                }
                                printf("\n\n");
                                system("pause");
                                break;

                            case 8:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    etudiantsAvecMoyenneInferieure(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant enregistré pour l instant");
                                }
                                printf("\n\n");
                                system("pause");
                                break;

                            case 9:
                                system("cls");
                                if (nbCandidatures > 0)
                                {
                                    afficherEtudiantsAvecStages(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant postule a cet instant");
                                }

                                printf("\n\n");
                                system("pause");
                                break;

                            case 10:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    afficherEtudiantsSansStage(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\nAucun etudiant enregiste a cet instant");
                                }

                                printf("\n\n");
                                system("pause");
                                break;

                            case 11:
                                system("cls");
                                rechercherEtudiantParNom(tabEtudiants, nbEtudiants);
                                printf("\n\n");
                                system("pause");
                                break;

                            case 12:
                                system("cls");
                                rechercherEtudiantParPrenom(tabEtudiants, nbEtudiants);
                                printf("\n\n");
                                system("pause");
                                break;

                            case 13:
                                system("cls");
                                rechercherEtudiantParMatricule(tabEtudiants, nbEtudiants);
                                printf("\n\n");
                                system("pause");
                                break;

                            case 14:
                                system("cls");
                                rechercherEtudiantParMatriculeOuNomOuPrenom(tabEtudiants, nbEtudiants);
                                printf("\n\n");
                                system("pause");
                                break;

                            case 15:
                                rechercherEtudiantParMoyenne(tabEtudiants, nbEtudiants);
                                printf("\n\n");
                                system("pause");
                                break;

                            default:
                                printf("\n\n");
                                break;
                            }
                        } while (choixAdminEtudiant != 16);
                    }
                    break;

                    // 2. Ges entr
                    case 2:
                        system("cls");
                        int choixAdminEntreprise;
                        do
                        {
                            choixAdminEntreprise = adminGestionEntreprises();
                            switch (choixAdminEntreprise)
                            {
                            case 1:
                                system("cls");
                                if (nbStages > 0)
                                {
                                    voirListeStages(tabStages, nbStages, tabEntreprises, nbEntreprises);
                                }
                                else
                                {
                                    printf("\n\nPas d offre de stage disponible\n");
                                }

                                printf("\n\n");
                                system("pause");
                                break;

                            case 2:
                                system("cls");

                                if (nbCandidatures > 0)
                                {
                                    afficherEtudiantsAvecStages(tabEtudiants, nbEtudiants);
                                }
                                else
                                {
                                    printf("\n\nPas de candidature de stage disponible\n");
                                }

                                printf("\n\n");
                                system("pause");
                                break;

                            case 3:
                                system("cls");
                                listeStageeRefuses(tabEtudiants, nbEtudiants);

                                printf("\n\n");
                                system("pause");
                                break;

                            case 4:
                                system("cls");
                                listeStageeAccepte(tabEtudiants, nbEtudiants);
                                printf("\n\n");
                                system("pause");
                                break;

                            case 5:
                                system("cls");
                                if (nbEtudiants > 0)
                                {
                                    tabEtudiantsSuggerer(tabEtudiants, nbEtudiants);
                                    printf("\n\n");
                                    printf("Veuillez copier le matricule de l'étudiant à suggerer\n\n");

                                    system("pause");
                                    system("cls");

                                    tabSuggestions[nbSuggestions] = suggererEtudiant(tabEtudiants, nbEtudiants);
                                    nbSuggestions++;
                                }
                                else
                                {
                                    printf("Aucun étudiant enregisté....\n\n");
                                }

                                printf("\n\n");
                                system("pause");
                                break;

                            case 6:
                                system("cls");
                                listePartenaires(tabEntreprises, nbEntreprises);
                                printf("\n\n");
                                system("pause");
                                break;

                            default:
                                break;
                            }
                        } while (choixAdminEntreprise != 7);
                        break;

                    // 3. Ges prof
                    case 3:
                        system("cls");
                        int choixAdminProfesseur;
                        do
                        {
                            choixAdminProfesseur = adminGestionProfesseurs();
                            switch (choixAdminProfesseur)
                            {
                            case 1:
                                system("cls");
                                tabProfesseurs[nbProfesseurs] = ajouterProfesseur();
                                nbProfesseurs++;
                                printf("\n\n");
                                system("pause");
                                break;
                            case 2:
                                system("cls");
                                modifierProfesseur(tabProfesseurs, nbProfesseurs);
                                printf("\n\n");
                                system("pause");
                                break;
                            case 3:
                                system("cls");
                                afficherProfesseurs(tabProfesseurs, nbProfesseurs);
                                printf("\n\n");
                                system("pause");
                                break;
                            case 4:
                                system("cls");
                                rechercherProfesseurParNom(tabProfesseurs, nbProfesseurs);
                                printf("\n\n");
                                system("pause");
                                break;
                            case 5:
                                system("cls");
                                rechercherProfesseurParMatricule(tabProfesseurs, nbProfesseurs);
                                printf("\n\n");
                                system("pause");
                                break;
                            case 6:
                                // Retour
                                break;
                            default:
                                printf("Choix invalide, veuillez reessayer.\n");
                                break;
                            }
                        } while (choixAdminProfesseur != 6);
                        break;
                    default:
                        break;
                    }
                } while (choixAdmin != 4);

                break;
            }
            else
            {
                system("cls");
                couleur(12);
                printf("\n\n");
                printf("Nom d'utilisateur ou mot de passe incorrect.\n");
                couleur(9);
                printf("\n\n");
                system("pause");
            }
            break;

        // 2. Etudiant
        case 2:
            couleur(11);
            system("cls");
            printf("\n\n");
            printf("Veuillez saisir votre matricule: ");
            scanf("%s", matriculeSaisi);

            if (connexionEtudiant(matriculeSaisi, tabEtudiants, nbEtudiants))
            {
                couleur(10);
                system("cls");
                printf("\n\n");
                printf("Connexion resussie.....\n");
                couleur(11);
                printf("\n\n");
                system("pause");
                system("cls");
                do
                {
                    choixEtudiant = menuEtudiant();

                    switch (choixEtudiant)
                    {

                    case 1:
                        system("cls");
                        voirInfosEtudiant(matriculeSaisi, tabEtudiants, nbEtudiants);
                        printf("\n\n");
                        system("pause");
                        break;

                    case 2:
                        system("cls");
                        etudiantsAvecNotesTriees(tabEtudiants, nbEtudiants);
                        printf("\n\n");
                        system("pause");
                        break;

                    case 3:
                        system("cls");
                        if (nbStages > 0)
                        {
                            voirListeStages(tabStages, nbStages, tabEntreprises, nbEntreprises);
                            printf("\n\n");
                            system("pause");

                            tabCandidatures[nbCandidatures] = postuluerStage(tabEtudiants, nbEtudiants, tabStages, nbStages, matriculeSaisi);
                            nbCandidatures++;
                        }
                        else
                        {
                            printf("Aucun stage disponible pour le moment.\n");
                        }
                        printf("\n\n");
                        system("pause");
                        break;

                    case 4:
                        system("cls");
                        voirStatutStageEtudiant(matriculeSaisi, tabEtudiants, nbEtudiants);
                        printf("\n\n");
                        system("pause");
                    default:
                        break;
                    }
                } while (choixEtudiant != 5);
                break;
            }
            else
            {
                system("cls");
                couleur(12);
                printf("\n\n");
                printf("Matricule incorrect. Veuillez r��essayer.\n");
                couleur(9);
                printf("\n\n");
                system("pause");
                continue;
            }

        // Entr
        case 3:
            couleur(14);
            system("cls");
            printf("\n\n");
            printf("Veuillez saisir votre nom d'utilisateur: ");
            scanf("%s", usernameEntreprise);

            if (connexionEntreprise(usernameEntreprise, tabEntreprises, nbEntreprises))
            {
                couleur(10);
                system("cls");
                printf("\n\n");
                printf("Connexion resussie.....\n");
                couleur(14);
                printf("\n\n");
                system("pause");
                system("cls");
                do
                {
                    choixEntreprise = menuEntreprise();

                    switch (choixEntreprise)
                    {
                    // Ajouter stage
                    case 1:
                        system("cls");
                        tabStages[nbStages] = creerStage(tabEntreprises, nbEntreprises, usernameEntreprise);
                        nbStages++;
                        printf("\n\n");
                        system("pause");
                        break;

                    // list etu post
                    case 2:
                        system("cls");
                        // listeVue = true;
                        listePostules(tabEtudiants, nbEtudiants);
                        printf("\n\n");
                        system("pause");
                        break;

                    case 3:
                        system("cls");
                        if (nbCandidatures <= 0)
                        {
                            printf("Pas de demande de stage pour l instant");
                            printf("\n\n");
                            system("pause");
                        }
                        else
                        {
                            printf("Liste des postulant veuillez copier le matricule de l etudiant a gerer...\n\n");
                            listePostules(tabEtudiants, nbEtudiants);
                            printf("\n\n");
                            system("pause");
                            validerCandidature(tabEtudiants, nbEtudiants, tabCandidatures, nbCandidatures);
                            printf("\n\n");
                            system("pause");
                        }
                        break;

                    case 4:
                        system("cls");
                        verifSuggestion = true;
                        if (nbSuggestions <= 0)
                        {
                            printf("Aucune suggestion d etudiant pour l instant\n");
                        }
                        else
                        {
                            listeSuggestion(tabSuggestions, nbSuggestions);
                            printf("\n\n");
                        }

                        printf("\n\n");
                        system("pause");
                        break;

                    case 5:
                        system("cls");
                        if (!verifSuggestion)
                        {
                            printf("\n\nVeuillez consulter la liste de suggestion et copier un matricule  ");
                        }
                        else
                        {
                            if (nbSuggestions > 0)
                            {
                                validerSuggestion(tabEtudiants, nbEtudiants, tabSuggestions, nbSuggestions);
                            }
                            else
                            {
                                printf("\n\nAucune suggestion d etudiant pour l instant\n");
                            }
                        }

                        printf("\n\n");
                        system("pause");
                        break;

                    case 6:
                        system("cls");
                        afficherListeStagesParEntreprise(tabEntreprises, nbEntreprises, tabStages, nbStages, usernameEntreprise);
                        printf("\n\n");
                        system("pause");
                        break;

                    default:
                        printf("Choix invalide, veuillez reessayer.\n");
                        printf("\n\n");
                        system("pause");
                        break;
                    }
                } while (choixEntreprise != 7);
            }
            else
            {
                system("cls");
                couleur(12);
                printf("\n\n");
                printf("Nom d'utilisateur incorrect. Veuillez réssayer.\n");
                couleur(9);
                printf("\n\n");
                system("pause");
                continue;
            }

            break;

        case 4:
            couleur(4);
            system("cls");
            printf("\n\n");
            printf("Veuillez saisir votre Matricule de professeur: ");
            scanf("%s", matriculeProf);

            if (connexionProfesseur(matriculeProf, tabProfesseurs, nbProfesseurs))
            {
                couleur(10);
                system("cls");
                printf("\n\n");
                printf("Connexion resussie.....\n");
                couleur(14);
                printf("\n\n");
                system("pause");
                system("cls");

                do
                {
                    choixProf = menuProfesseur();
                    switch (choixProf)
                    {
                    case 1:
                        system("cls");
                        afficherProfesseur(tabProfesseurs, nbProfesseurs, matriculeProf);
                        printf("\n\n");
                        system("pause");
                        break;

                    case 2:
                        system("cls");
                        afficherEtudiantsParFiliere(tabEtudiants, nbEtudiants, tabProfesseurs, nbProfesseurs, matriculeProf);
                        printf("\n\n");
                        system("pause");
                        break;
                    default:
                        break;
                    }
                } while (choixProf != 3);
            }
            else
            {

                system("cls");
                couleur(12);
                printf("\n\n");
                printf("Matricule de prof incorrect. Veuillez réssayer.\n");
                couleur(9);
                printf("\n\n");
                system("pause");
                continue;
            }

            break;

        // 5. CAISSE
        case 5:
            couleur(15);
            system("cls");
            if (connexionCaissePrompt())
            {
                couleur(10);
                system("cls");
                printf("\n\n");
                printf("Connexion resussie.....\n");
                couleur(15);
                printf("\n\n");
                system("pause");
                system("cls");

                do
                {
                    choixCaisse = menuCaisse();
                    switch (choixCaisse)
                    {
                    case 1:
                        system("cls");
                        payerProfesseur(tabProfesseurs, nbProfesseurs);

                        printf("\n\n");
                        system("pause");
                        break;

                    case 2:
                        system("cls");
                        printf("Payement en cours \n\n");
                        payerEtudiant(tabEtudiants, nbEtudiants);
                        printf("Veuillez patienter...\n");
                        Sleep(3000);
                        printf("\n\nPaiement effectué avec succès !\n");
                        printf("\n\n");
                        system("pause");
                        break;

                    case 3:
                        system("cls");
                        afficherListeProfesseursPayes(tabSalaires, nbSalaires);
                        printf("\n\n");
                        system("pause");
                        break;

                    case 4:
                        system("cls");
                        afficherListeEtudiantsPayes();
                        printf("\n\n");
                        system("pause");
                        break;

                    case 5:
                        system("cls");
                        listeImpayesEtudiants(tabEtudiants, nbEtudiants);
                        printf("\n\n");
                        system("pause");
                        break;

                    case 6:
                        system("cls");
                        listeImpayesProfesseurs(tabProfesseurs, nbProfesseurs);
                        printf("\n\n");
                        system("pause");
                        break;

                    default:
                        break;
                    }
                } while (choixCaisse != 7);
            }
            else
            {
                couleur(12);
                printf("\n\nNom d'utilisateur ou mot de passe incorrect.\n\n");
                couleur(9);
                printf("\n\n");
                system("pause");
            }
            break;

        // 6. Quitter
        case 6:
            couleur(7);
            printf("\n\n\n\n");
            printf("MERCI D AVOIR UTILISE L ERP UNIVERSITAIRE MERCI !!!!\n");
            printf("\n\n\n\n");
            break;

        // Choix invalide
        default:
            printf("Choix invalide, veuillez reessayer.\n");
            break;

            // tant que choix menu principal diff de quittt
        }

    } while (choix != 6);
    return 0;
}
