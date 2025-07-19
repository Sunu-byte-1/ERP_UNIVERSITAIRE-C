# ERP_UNIVERSITAIRE-C

![Repo Size](https://img.shields.io/github/repo-size/Sunu-byte-1/ERP_UNIVERSITAIRE-C)
![Last Commit](https://img.shields.io/github/last-commit/Sunu-byte-1/ERP_UNIVERSITAIRE-C)

---

## Description

Ce projet est un **système de gestion intégré (ERP)** développé en **langage C**.  
Il fonctionne en mode console et permet de gérer plusieurs acteurs : **administrateurs, étudiants, professeurs, entreprises partenaires** et **service financier**.  
L’objectif est de simuler un système complet de gestion académique, adapté à une université ou école supérieure.

---

## Guide d’utilisation

Pour comprendre la structure complète du projet, merci de consulter le fichier **PowerPoint** disponible dans le dossier [`/doc`](./doc/ERP_UNIVERSITAIRE.pptx).  
Ce fichier contient :  
- Le contexte et les objectifs du projet  
- Le modèle conceptuel de données (MCD)  
- Les fonctionnalités réalisées  
- Les difficultés rencontrées  
- Les améliorations possibles  

---

## Fonctionnalités principales 🚀

- Gestion des administrateurs, étudiants, professeurs, entreprises partenaires, et service financier  
- Connexion sécurisée pour chaque rôle  
- Gestion complète des étudiants (notes, classements, candidatures)  
- Attribution de cours aux professeurs  
- Gestion des stages et candidatures pour les entreprises partenaires  
- Paiement automatique des allocations et salaires  

---

## Installation et compilation ⚙️

Clonez le dépôt et compilez avec `gcc` :

```bash
git clone https://github.com/Sunu-byte-1/ERP_UNIVERSITAIRE-C.git
cd ERP_UNIVERSITAIRE-C
gcc -o erp main.c autres_fichiers.c -I./include
./erp


