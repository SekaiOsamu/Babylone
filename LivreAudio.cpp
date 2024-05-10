#include "LivreAudio.h"
#include <iostream>


    LivreAudio::LivreAudio(const string& _titre, const string& _auteur, const string& _ISBN, int _duree, const string& _narrateur)
        : Livre(_titre, _auteur, _ISBN), duree(_duree), narrateur(_narrateur) {}

    void LivreAudio::afficher() const {
        cout << "Livre audio:" << endl;
        cout << "Titre: " << getTitre() << endl;
        cout << "Auteur: " << getAuteur() << endl;
        cout << "ISBN: " << getISBN() << endl;
        cout << "Durée (minutes): " << duree << endl;
        cout << "Narrateur: " << narrateur << endl;
    }

