//
// Created by tho on 25/11/2026.
//

#include "MetodoPagamento.h"
#include <iostream>
#include <iomanip>

void MetodoPagamento::pagaConCommissione(double importo, double percCommissione) const {
    double commissione = importo * (percCommissione / 100.0);
    double totale = importo + commissione;

    std::cout << "Commissione del " << percCommissione << "% applicata: +" << commissione << "€ -> ";

    this->paga(totale);
}