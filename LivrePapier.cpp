#include "LivrePapier.h"
#include <iostream>


    LivrePapier::LivrePapier(const string& _titre, const string& _auteur, const string& _ISBN, int _nombrePages, const string& _typeCouverture)
        : Livre(_titre, _auteur, _ISBN), nombrePages(_nombrePages), typeCouverture(_typeCouverture) {}

    void LivrePapier::afficher() const {
        cout << "Livre papier:" << endl;
        cout << "Titre: " << getTitre() << endl;
        cout << "Auteur: " << getAuteur() << endl;
        cout << "ISBN: " << getISBN() << endl;
        cout << "Nombre de pages: " << nombrePages << endl;
        cout << "Type de couverture: " << typeCouverture << endl;
    }

