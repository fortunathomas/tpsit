//
// Created by tho on 25/11/2026.
//

#include "NotificaPush.h"
#include <iostream>

NotificaPush::NotificaPush(std::string d) : device(d) {}

void NotificaPush::invia(std::string messaggio) {
    std::cout << "[PUSH su device " << device << "]: " << messaggio << std::endl;
}