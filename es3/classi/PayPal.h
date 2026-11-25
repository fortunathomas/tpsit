//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_PAYPAL_H
#define UNTITLED_PAYPAL_H

#include "MetodoPagamento.h"
#include <string>

class PayPal : public MetodoPagamento {
private:
    std::string email;

public:
    PayPal(std::string e);
    void paga(double importo) const override;
};

#endif //UNTITLED_PAYPAL_H
