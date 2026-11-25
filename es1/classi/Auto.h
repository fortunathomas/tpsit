//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_AUTO_H
#define UNTITLED_AUTO_H
#include "Veicolo.h"


class Auto : public Veicolo {
public:
    void muovi() const override;
    void descrizione() const override;
};


#endif //UNTITLED_AUTO_H
