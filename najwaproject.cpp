#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure d�crivant une voiture
typedef struct Voiture {
    char marque[50];                // Marque de la voiture
    char modele[50];                // Mod�le de la voiture
    int annee;                      // Ann�e de fabrication de la voiture
    float prixLocationParJour;      // Prix de location par jour
    char carburant[20];             // Type de carburant
    int nombrePlaces;               // Nombre de places dans la voiture
    char disponibilite[20];         // Disponibilit� de la voiture
    int identifiant;                // Identifiant de la voiture
    char proprietaire[50];          // Propri�taire de la voiture
    char typeTransmission[20];      // Type de transmission de la voiture
} Voiture;

// Fonction pour afficher le menu du programme
void afficherMenu(void) {
    printf("************************************************************\n");
    printf("*                   GESTION DES VOITURES                    *\n");
    printf("************************************************************\n");
    printf("************************* MENU *******************************\n");
    printf("* Veuillez choisir une option :                            *\n");
    printf("* 1- Ajouter une voiture                                   *\n");
    printf("* 2- Supprimer une voiture                                 *\n");
    printf("* 3- Modifier une voiture                                  *\n");
    printf("* 4- Afficher la liste des voitures                        *\n");
    printf("* 5- Rechercher une voiture par son num�ro                 *\n");
    printf("* 6- Trier les voitures                                    *\n");
    printf("* 7- Quitter le programme                                  *\n");
    printf("************************************************************\n");
}
void dessinerCoeur() {
    printf("    ***   ***\n");
    printf("  **   **   **\n");
    printf(" **     **    **\n");
    printf("**             **\n");
    printf("**   au revoir **\n");
    printf(" **           **\n");
    printf("  **         **\n");
    printf("    **     **\n");
    printf("      ** **\n");
    printf("        *\n");
}
void saisirNomUtilisateur(char *nomUtilisateur) {
    printf("Bienvenue dans l'application de gestion des voitures.\n");
    printf("Veuillez saisir votre nom : ");
    scanf("%s", nomUtilisateur);
}
// Fonction pour ajouter une voiture
void ajouter(Voiture *listeVoitures, int *nombreVoitures) {
    FILE *fichier = fopen("najwa.csv", "a"); // Ouvrir le fichier en mode ajout

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier.\n");
        return;
    }

    // Demander le nombre de voitures � ajouter
    printf("Entrez le nombre de voitures � ajouter : ");
    scanf("%d", nombreVoitures);

    for (int i = 0; i < *nombreVoitures; i++) {
        // Demander et enregistrer les informations de la voiture
        printf("Entrez la marque de la voiture : ");
        scanf("%s", listeVoitures[i].marque);
        fprintf(fichier, "%s\n", listeVoitures[i].marque);
        
        printf("Entrez le mod�le de la voiture : ");
        scanf("%s", listeVoitures[i].modele);
        fprintf(fichier, "%s\n", listeVoitures[i].modele);

        printf("Entrez l'ann�e de la voiture : ");
        scanf("%d", &listeVoitures[i].annee);
        fprintf(fichier, "%d\n", listeVoitures[i].annee);

        printf("Entrez le prix de location par jour : ");
        scanf("%f", &listeVoitures[i].prixLocationParJour);
        fprintf(fichier, "%.2f\n", listeVoitures[i].prixLocationParJour);

        printf("Entrez le type de carburant : ");
        scanf("%s", listeVoitures[i].carburant);
        fprintf(fichier, "%s\n", listeVoitures[i].carburant);

        printf("Entrez le nombre de places : ");
        scanf("%d", &listeVoitures[i].nombrePlaces);
        fprintf(fichier, "%d\n", listeVoitures[i].nombrePlaces);

        printf("Entrez la disponibilit� : ");
        scanf("%s", listeVoitures[i].disponibilite);
        fprintf(fichier, "%s\n", listeVoitures[i].disponibilite);

        printf("Entrez l'identifiant : ");
        scanf("%d", &listeVoitures[i].identifiant);
        fprintf(fichier, "%d\n", listeVoitures[i].identifiant);

        printf("Entrez le propri�taire : ");
        scanf("%s", listeVoitures[i].proprietaire);
        fprintf(fichier, "%s\n", listeVoitures[i].proprietaire);

        printf("Entrez le type de transmission : ");
        scanf("%s", listeVoitures[i].typeTransmission);
        fprintf(fichier, "%s\n", listeVoitures[i].typeTransmission);
    }

    fclose(fichier); // Fermer le fichier
}

// Fonction pour afficher la liste des voitures
void afficherListeVoitures(Voiture *listeVoitures, int nombreVoitures) {
    printf("Liste des voitures :\n");
    for (int i = 0; i < nombreVoitures; i++) {
        // Afficher les informations de chaque voiture
        printf("Voiture %d :\n", i+1);
        printf("Marque : %s\n", listeVoitures[i].marque);
        printf("Mod�le : %s\n", listeVoitures[i].modele);
        printf("Ann�e : %d\n", listeVoitures[i].annee);
        printf("Prix de location par jour : %.2f\n", listeVoitures[i].prixLocationParJour);
        printf("Carburant : %s\n", listeVoitures[i].carburant);
        printf("Nombre de places : %d\n", listeVoitures[i].nombrePlaces);
        printf("Disponibilit� : %s\n", listeVoitures[i].disponibilite);
        printf("Identifiant : %d\n", listeVoitures[i].identifiant);
        printf("Propri�taire : %s\n", listeVoitures[i].proprietaire);
        printf("Type de transmission : %s\n", listeVoitures[i].typeTransmission);
        printf("\n");
    }
}

// Fonction pour supprimer une voiture
void supprimer(Voiture *listeVoitures, int *nombreVoitures, int indice) {
    if (indice < 0 || indice >= *nombreVoitures) {
        printf("Indice invalide.\n");
        return;
    }

    // D�placer les voitures apr�s l'indice vers la gauche pour remplir l'espace de la voiture supprim�e
    for (int i = indice; i < *nombreVoitures - 1; i++) {
        listeVoitures[i] = listeVoitures[i + 1];
    }

    // Diminuer le nombre total de voitures
    (*nombreVoitures)--;
}

// Fonction pour modifier les informations d'une voiture
void modifier(Voiture *listeVoitures, int nombreVoitures, int indice) {
    if (indice < 0 || indice >= nombreVoitures) {
        printf("Indice invalide.\n");
        return;
    }

    // Demander et enregistrer les nouvelles informations de la voiture
    printf("Entrez la nouvelle marque de la voiture : ");
    scanf("%s", listeVoitures[indice].marque);

    printf("Entrez le nouveau mod�le de la voiture : ");
    scanf("%s", listeVoitures[indice].modele);

    printf("Entrez la nouvelle ann�e de la voiture : ");
    scanf("%d", &listeVoitures[indice].annee);

    printf("Entrez le nouveau prix de location par jour : ");
    scanf("%f", &listeVoitures[indice].prixLocationParJour);

    printf("Entrez le nouveau type de carburant : ");
    scanf("%s", listeVoitures[indice].carburant);

    printf("Entrez le nouveau nombre de places : ");
    scanf("%d", &listeVoitures[indice].nombrePlaces);

    printf("Entrez la nouvelle disponibilit� : ");
    scanf("%s", listeVoitures[indice].disponibilite);

    printf("Entrez le nouvel ID : ");
    scanf("%d", &listeVoitures[indice].identifiant);

    printf("Entrez le nouveau propri�taire : ");
    scanf("%s", listeVoitures[indice].proprietaire);

    printf("Entrez le nouveau type de transmission : ");
    scanf("%s", listeVoitures[indice].typeTransmission);
}

void rechercherVoitureParnum(Voiture *listeVoitures, int nombreVoitures) {
    int indice;
    printf("Entrez l'indice de la voiture � rechercher : ");
    scanf("%d", &indice);

    if (indice < 0 || indice >= nombreVoitures) {
        printf("Indice invalide.\n");
        return;
    }

    // Afficher les informations de la voiture � l'indice donn�
    printf("Voiture %d :\n", indice + 1);
    printf("Marque : %s\n", listeVoitures[indice].marque);
    printf("Mod�le : %s\n", listeVoitures[indice].modele);
    printf("Ann�e : %d\n", listeVoitures[indice].annee);
    printf("Prix de location par jour : %.2f\n", listeVoitures[indice].prixLocationParJour);
    printf("Carburant : %s\n", listeVoitures[indice].carburant);
    printf("Nombre de places : %d\n", listeVoitures[indice].nombrePlaces);
    printf("Disponibilit� : %s\n", listeVoitures[indice].disponibilite);
    printf("Identifiant : %d\n", listeVoitures[indice].identifiant);
    printf("Propri�taire : %s\n", listeVoitures[indice].proprietaire);
    printf("Type de transmission : %s\n", listeVoitures[indice].typeTransmission);
}

// Fonction pour trier les voitures par marque et prix de location par jour
void trier(Voiture *listeVoitures, int nombreVoitures) {
    for (int i = 0; i < nombreVoitures - 1; i++) {
        for (int j = 0; j < nombreVoitures - i - 1; j++) {
            // Trie d'abord par marque
            if (strcmp(listeVoitures[j].marque, listeVoitures[j + 1].marque) > 0) {
                // �change des �l�ments
                Voiture temp = listeVoitures[j];
                listeVoitures[j] = listeVoitures[j + 1];
                listeVoitures[j + 1] = temp;
            }
            // Si les marques sont les m�mes, trie par prix de location par jour
            else if (strcmp(listeVoitures[j].marque, listeVoitures[j + 1].marque) == 0 &&
                     listeVoitures[j].prixLocationParJour > listeVoitures[j + 1].prixLocationParJour) {
                // �change des �l�ments
                Voiture temp = listeVoitures[j];
                listeVoitures[j] = listeVoitures[j + 1];
                listeVoitures[j + 1] = temp;
            }
        }
    }
}

// Fonction principale
int main() {
    char nomUtilisateur[50];
    int choix, nombreVoitures = 0;
    Voiture *listeVoitures = malloc(sizeof(Voiture) * 100); // Allouer de la m�moire pour le tableau de voitures
    printf("************************************************************\n");
    printf("*                   GESTION DES VOITURES                    *\n");
    printf("************************************************************\n");
                   printf("          ______\n");
                   printf("       //  ||  \\\\ \n");
                   printf(" _____//___||___\\\\_\n");
                   printf(" )  _          _   |\n");
                   printf(" |_/ \\________/ \\__|\n");
                   printf("___\\_/________\\_/______\n");

    saisirNomUtilisateur(nomUtilisateur);
    afficherMenu(); // Afficher le menu du programme
    printf("Entrez votre choix : ");
    scanf("%d", &choix);

    // Boucle principale du programme
    while (choix != 7) {
        switch (choix) {
            case 1:
                ajouter(listeVoitures, &nombreVoitures); // Appeler la fonction pour ajouter des voitures
                break;
            case 2:
                int indice_suppr;
                printf("Entrez l'indice de la voiture � supprimer : ");
                scanf("%d", &indice_suppr);
                supprimer(listeVoitures, &nombreVoitures, indice_suppr);
                break;
            case 3:
                int indice_modif;
                printf("Entrez l'indice de la voiture � modifier : ");
                scanf("%d", &indice_modif);
                modifier(listeVoitures, nombreVoitures, indice_modif);
                break;
            case 4:
                afficherListeVoitures(listeVoitures, nombreVoitures); // Appeler la fonction pour afficher la liste des voitures
                break;
            case 5:
                rechercherVoitureParnum(listeVoitures, nombreVoitures);
                break;
            case 6:
                trier(listeVoitures, nombreVoitures); // Appeler la fonction pour trier les voitures
                break;
            case 7:
                printf("Merci d'avoir utilis� le programme. Au revoir!\n");
                dessinerCoeur();
                break;
            default:
                printf("Choix invalide.\n");
        }

        afficherMenu(); // Afficher � nouveau le menu
        printf("Entrez votre choix : ");
        scanf("%d", &choix);
    }
  switch (choix) {
           case 7:
                printf("Merci d'avoir utilis� le programme. Au revoir!\n");
                dessinerCoeur();
                break;}
    free(listeVoitures); // Lib�rer la m�moire allou�e pour le tableau de voitures

    return 0;
}

