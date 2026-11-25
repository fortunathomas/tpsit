//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_GUERRIERO_H
#define UNTITLED_GUERRIERO_H
#include "Personaggio.h"


class Guerriero : public Personaggio {
public:
    void attacca() const override;
    void presentati() const override;
};


#endif //UNTITLED_GUERRIERO_H
