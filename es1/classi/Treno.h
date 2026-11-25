//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_TRENO_H
#define UNTITLED_TRENO_H
#include "Veicolo.h"


class Treno : public Veicolo {
public:
    void muovi() const override;
    void descrizione() const override;
};


#endif //UNTITLED_TRENO_H
