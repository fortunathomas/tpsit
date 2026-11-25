//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_NOTIFICAPUSH_H
#define UNTITLED_NOTIFICAPUSH_H


#include "Notifica.h"
#include <string>

class NotificaPush : public Notifica {
private:
    std::string device;
public:
    NotificaPush(std::string device);
    void invia(std::string messaggio) override;
};


#endif //UNTITLED_NOTIFICAPUSH_H
