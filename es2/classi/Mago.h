//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_MAGO_H
#define UNTITLED_MAGO_H
#include <iostream>

#include "Personaggio.h"


class Mago : public Personaggio {
public:
    void attacca() const override;
    void presentati() const override;
};


#endif //UNTITLED_MAGO_H
