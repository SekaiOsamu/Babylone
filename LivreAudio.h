#ifndef LIVREAUDIO_H
#define LIVREAUDIO_H

#include "Livre.h"

using namespace std;

    class LivreAudio : public Livre {
    private:
        int duree;
        string narrateur;

    public:
        LivreAudio(const string& _titre, const string& _auteur, const string& _ISBN, int _duree, const string& _narrateur);
        void afficher() const override;
    };

#endif // LIVREAUDIO_H
