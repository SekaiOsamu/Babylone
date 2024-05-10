#ifndef BIBLIOTHEQUE_H
#define BIBLIOTHEQUE_H

#include <vector>
#include "Livre.h"

using namespace std;

    class Bibliotheque {
    private:
        vector<Livre*> livres;

    public:
        Bibliotheque();
        ~Bibliotheque();
        void ajouterLivre(Livre* livre);
        void supprimerLivre(const string& ISBN);
        void afficherLivres() const;
    };

#endif // BIBLIOTHEQUE_H
