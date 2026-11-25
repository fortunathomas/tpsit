//
// Created by tho on 25/11/2026.
//

#include "CartaCredito.h"
#include <iostream>
#include <iomanip>
#include <utility>

CartaCredito::CartaCredito(std::string c) : circuito(std::move(c)) {}

void CartaCredito::paga(double importo) const {
    std::cout << "Pagato " << importo << "€ con Carta di Credito (" << circuito << ")" << std::endl;
}