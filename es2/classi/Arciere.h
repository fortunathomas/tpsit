//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_ARCIERE_H
#define UNTITLED_ARCIERE_H
#include "Personaggio.h"


class Arciere : public Personaggio {
public:
    void attacca() const override;
    void presentati() const override;
};


#endif //UNTITLED_ARCIERE_H
