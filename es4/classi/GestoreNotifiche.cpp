//
// Created by tho on 25/11/2026.
//

#include "GestoreNotifiche.h"

void GestoreNotifiche::aggiungi(Notifica* n) {
    canali.push_back(n);
}

void GestoreNotifiche::inviaATutti(std::string messaggio) {
    for (Notifica* n : canali) {
        n->invia(messaggio);
    }
}