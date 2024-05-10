#ifndef BANDEDESSINEE_H
#define BANDEDESSINEE_H

#include "Livre.h"

using namespace std;

    class BandeDessinee : public Livre {
    private:
        string serie;
        int nombreTomes;
        string illustrateur;

    public:
        BandeDessinee(const string& _titre, const string& _auteur, const string& _ISBN, const string& _serie, int _nombreTomes, const string& _illustrateur);
        void afficher() const override;
    };


#endif // BANDEDESSINEE_H
