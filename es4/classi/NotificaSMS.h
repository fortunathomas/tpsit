//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_NOTIFICASMS_H
#define UNTITLED_NOTIFICASMS_H


#include "Notifica.h"
#include <string>

class NotificaSMS : public Notifica {
private:
    std::string numeroTelefono;
public:
    NotificaSMS(std::string numero);
    void invia(std::string messaggio) override;
};

#endif //UNTITLED_NOTIFICASMS_H
