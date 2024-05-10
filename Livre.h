#ifndef LIVRE_H
#define LIVRE_H

#include <string>

using namespace std;

    class Livre {
    protected:
        string titre;
        string auteur;
        string ISBN;

    public:
        Livre(const string& _titre, const string& _auteur, const string& _ISBN);
        virtual void afficher() const = 0;
        string getISBN() const;
        string getTitre() const;
        string getAuteur() const;
    };

#endif // LIVRE_H
