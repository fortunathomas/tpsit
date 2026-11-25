//
// Created by tho on 25/11/2026.
//

#include <iostream>
#include <vector>
#include <memory>

#include "classi/MetodoPagamento.h"
#include "classi/CartaCredito.h"
#include "classi/PayPal.h"
#include "classi/Contanti.h"

int main() {
    CartaCredito* c = new CartaCredito("visa");
    PayPal* p = new PayPal("email");
    Contanti* cont = new Contanti;
    
    std::vector<MetodoPagamento*> metodi = { c, p, cont};

    double importoBase = 100.00;
    double commissione = 2.5;

    std::cout << "Pagamento standard: " << std::endl;
    for (MetodoPagamento* m : metodi) {
        m->paga(importoBase);
    }

    std::cout << "Pagamento con commissione: " << std::endl;
    for (MetodoPagamento* m : metodi) {
        m->pagaConCommissione(importoBase, commissione);
    }

    return 0;
}