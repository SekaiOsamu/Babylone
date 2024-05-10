#ifndef LIVRENUMERIQUE_H
#define LIVRENUMERIQUE_H

#include "Livre.h"

using namespace std;

    class LivreNumerique : public Livre {
    private:
        string formatFichier;
        int tailleFichier;

    public:
        LivreNumerique(const string& _titre, const string& _auteur, const string& _ISBN, const string& _formatFichier, int _tailleFichier);
        void afficher() const override;
    };


#endif // LIVRENUMERIQUE_H
