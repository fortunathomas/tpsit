//
// Created by tho on 25/11/2026.
//

#include "NotificaSMS.h"
#include <iostream>

NotificaSMS::NotificaSMS(std::string numero) : numeroTelefono(numero) {}

void NotificaSMS::invia(std::string messaggio) {
    std::cout << "[SMS a " << numeroTelefono << "]: " << messaggio << std::endl;
}