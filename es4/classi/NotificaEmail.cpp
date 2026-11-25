//
// Created by tho on 25/11/2026.
//

#include "NotificaEmail.h"
#include <iostream>

NotificaEmail::NotificaEmail(std::string email) : indirizzoEmail(email) {}

void NotificaEmail::invia(std::string messaggio) {
    std::cout << "[EMAIL a " << indirizzoEmail << "]: " << messaggio << std::endl;
}