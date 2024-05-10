#include "Livre.h"


    Livre::Livre(const string& _titre, const string& _auteur, const string& _ISBN)
        : titre(_titre), auteur(_auteur), ISBN(_ISBN) {}

    string Livre::getISBN() const {
        return ISBN;
    }

    string Livre::getTitre() const {
        return titre;
    }

    string Livre::getAuteur() const {
        return auteur;
    }
