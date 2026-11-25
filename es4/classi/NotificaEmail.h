//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_NOTIFICAEMAIL_H
#define UNTITLED_NOTIFICAEMAIL_H

#include "Notifica.h"
#include <string>

class NotificaEmail : public Notifica {
private:
    std::string indirizzoEmail;
public:
    NotificaEmail(std::string email);
    void invia(std::string messaggio) override;
};


#endif //UNTITLED_NOTIFICAEMAIL_H
