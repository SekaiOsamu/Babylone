#include "BandeDessinee.h"
#include <iostream>


    BandeDessinee::BandeDessinee(const string& _titre, const string& _auteur, const string& _ISBN, const string& _serie, int _nombreTomes, const string& _illustrateur)
        : Livre(_titre, _auteur, _ISBN), serie(_serie), nombreTomes(_nombreTomes), illustrateur(_illustrateur) {}

    void BandeDessinee::afficher() const {
        cout << "Bande dessinée:" << endl;
        cout << "Titre: " << getTitre() << endl;
        cout << "Auteur: " << getAuteur() << endl;
        cout << "ISBN: " << getISBN() << endl;
        cout << "Série: " << serie << endl;
        cout << "Nombre de tomes: " << nombreTomes << endl;
        cout << "Illustrateur: " << illustrateur << endl;
    }

