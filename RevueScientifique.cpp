#include "RevueScientifique.h"
#include <iostream>

    RevueScientifique::RevueScientifique(const string& _titre, const string& _auteur, const string& _ISBN, const string& _domaine, int _facteurImpact, const string& _periodicite)
        : Livre(_titre, _auteur, _ISBN), domaine(_domaine), facteurImpact(_facteurImpact), periodicite(_periodicite) {}

    void RevueScientifique::afficher() const {
        cout << "Revue scientifique:" << endl;
        cout << "Titre: " << getTitre() << endl;
        cout << "Auteur: " << getAuteur() << endl;
        cout << "ISBN: " << getISBN() << endl;
        cout << "Domaine: " << domaine << endl;
        cout << "Facteur d'impact: " << facteurImpact << endl;
        cout << "Périodicité: " << periodicite << endl;
    }

