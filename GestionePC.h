#ifndef TPSIT_GESTIONEPC_H
#define TPSIT_GESTIONEPC_H

#include <iostream>

#include "Computer.h"


const int MAX = 100;

class GestionePC {
private:    
    Computer listaPC[MAX];
    int indiceLista = 0;
    
public:
    bool AggiungiPC(Computer pc) {
        if (indiceLista >= MAX) {
            return false;
        }
        
        listaPC[indiceLista] = pc;
        indiceLista++;
        return true;
    }
    
    bool RimuoviPC(Computer pc) {
        int posizionePC = -1;
        
        //Cerco la posizione del PC nella lista
        for (int i = 0; i < indiceLista; i++) {
            if (listaPC[i].GetCodice() == pc.GetCodice()) {
                posizionePC = i;
            }
        }
        
        if (posizionePC == -1) {
            return false;
        }
        
        //Elimino la posizione trovata e sposto tutti gli altri elementi
        for (int i = posizionePC; i < indiceLista-1; ++i) {
            listaPC[i] = listaPC[i + 1];
        }
        
        indiceLista--;
        return true;
    }
    
    Computer* RicercaPerCodice(int codice) {
        for (int i = 0; i < indiceLista; i++) {
            if (listaPC[i].GetCodice() == codice) {
                return &listaPC[i];
            }
        }
        
        return nullptr;
    }
    
    int RicercaPerCaratteristiche(Computer risultati[], double velocitaProcessoreDesiderata, int dimensioniRAMDesiderate, int dimensioniDiscoDesiderate) {
        int pcTrovati = 0;
        
        for (int i = 0; i < indiceLista; i++) {
            Computer pc = listaPC[i];
            
            if (velocitaProcessoreDesiderata <= pc.GetVelocitaProcessore() && dimensioniRAMDesiderate <= pc.GetDimensioniRAM() && dimensioniDiscoDesiderate <= pc.GetDimensioniDisco()) {
                risultati[pcTrovati] = pc;
                pcTrovati++;
            }
        }
        
        return pcTrovati;
    }
};




#endif //TPSIT_GESTIONEPC_H
