#ifndef REVUESCIENTIFIQUE_H
#define REVUESCIENTIFIQUE_H

#include "Livre.h"

using namespace std;

    class RevueScientifique : public Livre {
    private:
        string domaine;
        int facteurImpact;
        string periodicite;

    public:
        RevueScientifique(const string& _titre, const string& _auteur, const string& _ISBN, const string& _domaine, int _facteurImpact, const string& _periodicite);
        void afficher() const override;
    };

#endif // REVUESCIENTIFIQUE_H
