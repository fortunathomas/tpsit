//
// Created by tho on 25/11/2026.
//

#ifndef UNTITLED_METODOPAGAMENTO_H
#define UNTITLED_METODOPAGAMENTO_H


class MetodoPagamento {
public:
    virtual void paga(double importo) const = 0;
    void pagaConCommissione(double importo, double percCommissione) const;
    virtual ~MetodoPagamento() {}
};


#endif //UNTITLED_METODOPAGAMENTO_H
