//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_NOTIFICA_H
#define UNTITLED_NOTIFICA_H
#include <string>


class Notifica {
public:
    virtual void invia(std::string messaggio) = 0;
    virtual ~Notifica() {}
};


#endif //UNTITLED_NOTIFICA_H
