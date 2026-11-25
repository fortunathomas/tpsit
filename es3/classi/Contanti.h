//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_CONTANTI_H
#define UNTITLED_CONTANTI_H

#include "MetodoPagamento.h"

class Contanti : public MetodoPagamento {
public:
    void paga(double importo) const override;
};


#endif //UNTITLED_CONTANTI_H
