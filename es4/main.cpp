//
// Created by tho on 25/11/2026.
//

#include "classi/GestoreNotifiche.h"
#include "classi/NotificaEmail.h"
#include "classi/NotificaSMS.h"
#include "classi/NotificaPush.h"

int main() {
    NotificaEmail* nE = new NotificaEmail("email");
    NotificaSMS* nSms = new NotificaSMS("numero");
    NotificaPush* nPush = new NotificaPush("device");

    GestoreNotifiche gestore;
    gestore.aggiungi(nE);
    gestore.aggiungi(nSms);
    gestore.aggiungi(nPush);

    gestore.inviaATutti("Ciao");

    return 0;
}