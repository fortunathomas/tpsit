//
// Created by tho on 25/11/2026.
//

#include "PayPal.h"
#include <iostream>

PayPal::PayPal(std::string e) : email(std::move(e)) {}

void PayPal::paga(double importo) const {
    std::cout << "Pagato " << importo << "€ tramite account PayPal (" << email << ")" << std::endl;
}