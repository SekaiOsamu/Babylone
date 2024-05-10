#include "LivreNumerique.h"
#include <iostream>


    LivreNumerique::LivreNumerique(const string& _titre, const string& _auteur, const string& _ISBN, const string& _formatFichier, int _tailleFichier)
        : Livre(_titre, _auteur, _ISBN), formatFichier(_formatFichier), tailleFichier(_tailleFichier) {}

    void LivreNumerique::afficher() const {
        cout << "Livre numérique:" << endl;
        cout << "Titre: " << getTitre() << endl;
        cout << "Auteur: " << getAuteur() << endl;
        cout << "ISBN: " << getISBN() << endl;
        cout << "Format du fichier: " << formatFichier << endl;
        cout << "Taille du fichier (Mo): " << tailleFichier << endl;
    }
