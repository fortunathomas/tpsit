//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_BICICLETTA_H
#define UNTITLED_BICICLETTA_H
#include "Veicolo.h"


class Bicicletta : public Veicolo {
public:
    void muovi() const override;
    void descrizione() const override;
};


#endif //UNTITLED_BICICLETTA_H
