//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_CARTACREDITO_H
#define UNTITLED_CARTACREDITO_H
#include <string>

#include "MetodoPagamento.h"


class CartaCredito : public MetodoPagamento {
private:
    std::string circuito;

public:
    CartaCredito(std::string c);
    void paga(double importo) const override;
};


#endif //UNTITLED_CARTACREDITO_H
