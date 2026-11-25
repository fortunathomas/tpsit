//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_GESTORENOTIFICHE_H
#define UNTITLED_GESTORENOTIFICHE_H

#include "Notifica.h"
#include <vector>
#include <string>

class GestoreNotifiche {
private:
    std::vector<Notifica*> canali;
public:
    void aggiungi(Notifica* n);
    void inviaATutti(std::string messaggio);
};


#endif //UNTITLED_GESTORENOTIFICHE_H
