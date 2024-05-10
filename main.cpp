#include <iostream>
#include <limits>
#include <string>
#include <sstream> // Pour utiliser std::istd::stringstream
#include "Bibliotheque.h"
#include "LivrePapier.h"
#include "LivreNumerique.h"
#include "LivreAudio.h"
#include "BandeDessinee.h"
#include "RevueScientifique.h"

using namespace std;

// ------------------------------------------------------------------------------------------------------------------------------
// ERROR HANDLERS
bool estAlpha(const std::string& str) {
    for (char c : str) {
        if (!isalpha(c) && !isspace(c)) { // Vérifie si le caractère est alphabétique ou un espace
            return false;
        }
    }
    return true;
}
bool estNumerique(const std::string& str) {
    istringstream iss(str); // input std::string stream iss initialized with the input std::string str
    double val;
    iss >> noskipws >> val; // put iss into value through noskipws that prevents skipping of leading whitespace characters
    return iss.eof() && !iss.fail(); // end of std::string AND extraction operation true
}
void afficherSeparateur() {
    cout << std::string(50, '*') << endl;
}
void afficherConfirmation(const std::string& message) {
    cout << "\n[Confirmation] " << message << endl;
}

// ------------------------------------------------------------------------------------------------------------------------------
int main() {
    Bibliotheque bibliotheque;
    int choix;
    do {
        afficherSeparateur();
        cout << "Menu:" << endl;
        cout << "1. Ajouter un livre" << endl;
        cout << "2. Supprimer un livre par ISBN" << endl;
        cout << "3. Afficher tous les livres" << endl;
        cout << "0. Quitter" << endl;
        afficherSeparateur();
        cout << "Votre choix: ";
        cin >> choix;

        switch(choix) {
            case 1: {
                cout << "\nAjout d'un livre:" << endl;
                int typeLivre;
                cout << "Choisissez le type de livre (1. Livre papier, 2. Livre numérique, 3. Livre audio, 4. Bande dessinée, 5. Revue scientifique): ";
                if(!(cin >> typeLivre)){
                     cout << "Erreur : Veuillez saisir un nombre entier pour le type de livre." << endl;
                    cin.clear(); // Clear the error state
                    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignore remaining characters
                    break;
                };
                std::string titre, auteur, ISBN;
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Pour vider le tampon du flux d'entrée

                cout << "Titre: ";
                getline(cin, titre);
                if (!estAlpha(titre) || titre.empty()) {
                    cout << "Erreur : Le titre doit contenir uniquement des lettres et ne peut pas être vide." << endl;
                    break;
                }

                cout << "Auteur: ";
                getline(cin, auteur);
                if (!estAlpha(auteur) || auteur.empty()) {
                    cout << "Erreur : L'auteur doit contenir uniquement des lettres et ne peut pas être vide." << endl;
                    break;
                }

                cout << "ISBN: ";
                getline(cin, ISBN);
                if (ISBN.size() != 13) {
                    cout << "Erreur : ISBN invalide. L'ISBN doit contenir exactement 13 caractères." << endl;
                    break;
                }

                switch (typeLivre) {
                    case 1: {
                        int nombrePages;
                        std::string typeCouverture;
                        cout << "Nombre de pages: ";
                        if (!(cin >> nombrePages)) {
                            cout << "Erreur : Veuillez saisir un nombre pour le nombre de pages." << endl;
                            cin.clear(); // Réinitialiser le drapeau d'erreur
                            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Ignorer le reste de la ligne
                            break;
                        }
                        cout << "Type de couverture: ";
                        cin.ignore();
                        getline(cin, typeCouverture);
                        if (estNumerique(typeCouverture)) {
                            cout << "Erreur : Le type de couverture ne peut pas être numérique." << endl;
                            break;
                        }
                        bibliotheque.ajouterLivre(new LivrePapier(titre, auteur, ISBN, nombrePages, typeCouverture));
                        afficherConfirmation("Livre papier ajouté avec succès !");
                        break;
                    }
                    case 2: {
                        std::string formatFichier;
                        int tailleFichier;
                        cout << "Format du fichier: ";
                        cin.ignore();
                        getline(cin, formatFichier);
                        if (!estAlpha(formatFichier) || formatFichier.empty()) {
                            cout << "Erreur : Le format du Fichier doit contenir uniquement des lettres et ne peut pas être vide." << endl;
                            break;
                        }
                        cout << "Taille du fichier (Mo): ";
                        if (!(cin >> tailleFichier)) {
                            cout << "Erreur : Veuillez saisir un nombre pour la taille du fichier." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        bibliotheque.ajouterLivre(new LivreNumerique(titre, auteur, ISBN, formatFichier, tailleFichier));
                        afficherConfirmation("Livre numérique ajouté avec succès !");
                        break;
                    }
                    case 3: {
                        int duree;
                        std::string narrateur;
                        cout << "Durée (minutes): ";
                        if (!(cin >> duree)) {
                            cout << "Erreur : Veuillez saisir un nombre pour la durée." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        cout << "Narrateur: ";
                        cin.ignore();
                        getline(cin, narrateur);
                        if (!estAlpha(narrateur) || narrateur.empty()) {
                            cout << "Erreur : Le narrateur doit contenir uniquement des lettres et ne peut pas être vide." << endl;
                            break;
                        }
                        bibliotheque.ajouterLivre(new LivreAudio(titre, auteur, ISBN, duree, narrateur));
                        afficherConfirmation("Livre audio ajouté avec succès !");
                        break;
                    }
                    case 4: {
                        std::string serie, illustrateur;
                        int nombreTomes;
                        cout << "Série: ";
                        cin.ignore();
                        getline(cin, serie);
                        if (!estAlpha(serie) || serie.empty()) {
                            cout << "Erreur : La serie doit contenir uniquement des lettres et ne peut pas être vide." << endl;
                            break;
                        }
                        cout << "Nombre de tomes: ";
                        if (!(cin >> nombreTomes)) {
                            cout << "Erreur : Veuillez saisir un nombre pour le nombre de tomes." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        cout << "Illustrateur: ";
                        cin.ignore();
                        getline(cin, illustrateur);
                        if (!estAlpha(illustrateur) || illustrateur.empty()) {
                            cout << "Erreur : L'illustrateur doit contenir uniquement des lettres et ne peut pas être vide." << endl;
                            break;
                        }
                        bibliotheque.ajouterLivre(new BandeDessinee(titre, auteur, ISBN, serie, nombreTomes, illustrateur));
                        afficherConfirmation("Bande dessinée ajoutée avec succès !");
                        break;
                    }
                    case 5: {
                        std::string domaine, periodicite;
                        int facteurImpact;
                        cout << "Domaine: ";
                        cin.ignore();
                        getline(cin, domaine);
                        if (!estAlpha(domaine) || domaine.empty()) {
                            cout << "Erreur : Le domaine doit contenir uniquement des lettres et ne peut pas être vide." << endl;
                            break;
                        }
                        cout << "Facteur d'impact: ";
                        if (!(cin >> facteurImpact)) {
                            cout << "Erreur : Veuillez saisir un nombre pour le facteur d'impact." << endl;
                            cin.clear();
                            cin.ignore(numeric_limits<streamsize>::max(), '\n');
                            break;
                        }
                        cout << "Périodicité: ";
                        cin.ignore();
                        getline(cin, periodicite);
                        bibliotheque.ajouterLivre(new RevueScientifique(titre, auteur, ISBN, domaine, facteurImpact, periodicite));
                        afficherConfirmation("Revue scientifique ajoutée avec succès !");
                        break;
                    }
                    default:
                        cout << "Choix invalide." << endl;
                }
                break;
            }
            case 2: {
                std::string ISBN;
                cout << "\nSuppression d'un livre par ISBN:" << endl;
                cout << "ISBN du livre à supprimer: ";
                cin >> ISBN;
                bibliotheque.supprimerLivre(ISBN);
                afficherConfirmation("Livre supprimé avec succès !");
                break;
            }
            case 3: {
                cout << "\nAffichage de tous les livres:" << endl;
                bibliotheque.afficherLivres();
                break;
            }
            case 0: {
                cout << "\nAu revoir !" << endl;
                break;
            }
            default: {
                cout << "\nChoix invalide. Veuillez choisir à nouveau." << endl;
                break;
            }
        }
    } while (choix != 0);

    return 0;
}
