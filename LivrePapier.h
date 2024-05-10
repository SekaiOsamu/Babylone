#ifndef LIVREPAPIER_H
#define LIVREPAPIER_H

#include "Livre.h"

using namespace std;

    class LivrePapier : public Livre {
    private:
        int nombrePages;
        string typeCouverture;

    public:
        LivrePapier(const string& _titre, const string& _auteur, const string& _ISBN, int _nombrePages, const string& _typeCouverture);
        void afficher() const override;
    };


#endif // LIVREPAPIER_H
