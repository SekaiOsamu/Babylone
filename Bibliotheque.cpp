#include "Bibliotheque.h"
#include <algorithm>
#include <iostream>



    Bibliotheque::Bibliotheque() {}

    Bibliotheque::~Bibliotheque() {
        for (Livre* livre : livres) {
            delete livre;
        }
    }

    void Bibliotheque::ajouterLivre(Livre* livre) {
        livres.push_back(livre);
    }

    void Bibliotheque::supprimerLivre(const string& ISBN) {
        auto it = std::find_if(livres.begin(), livres.end(), [ISBN](Livre* livre) {
            return livre->getISBN() == ISBN;
        });

        if (it != livres.end()) {
            delete *it;
            livres.erase(it);
            cout << "Livre supprimé avec succès." << endl;
        } else {
            cout << "Aucun livre trouvé avec cet ISBN." << endl;
        }
    }

    void Bibliotheque::afficherLivres() const {
        if (livres.empty()) {
            cout << "La bibliothèque est vide." << endl;
        } else {
            cout << "Livres dans la bibliothèque :" << endl;
            for (Livre* livre : livres) {
                livre->afficher();
                cout << endl;
            }
        }
    }

