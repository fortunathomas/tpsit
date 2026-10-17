#ifndef TPSIT_GESTIONEPC_H
#define TPSIT_GESTIONEPC_H

#include <fstream>
#include <sstream>
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
    
    bool SalvaPC(const std::string& nomeFile) {
        std::ofstream file(nomeFile);
        if (!file) {
            return false;
        }
        
        for (int i = 0; i < indiceLista; i++) {
            const Computer pc = listaPC[i];
            Data dataAcquisto = pc.GetDataDiAcquisto();
            
            file << pc.GetCodice() << ';'
                 << pc.GetMarca() << ';'
                 << pc.GetModello() << ';'
                 << pc.GetVelocitaProcessore() << ';'
                 << pc.GetDimensioniRAM() << ';'
                 << pc.GetDimensioniDisco() << ';'
                 << pc.GetDimensioniMonitor() << ';'
                 << dataAcquisto.giorno << ';' << dataAcquisto.mese << ';' << dataAcquisto.anno << ";" << '\n';
        }
        
        return true;
    }
    
    bool CaricaPC(const std::string& nomeFile) {
        std::ifstream file(nomeFile);
        if (!file) {
            return false;
        }

        indiceLista = 0;
        std::string riga;

        while (indiceLista < MAX && std::getline(file, riga)) {
            std::stringstream ss(riga);
            std::string campi[10];

            for (int i = 0; i < 10; i++) {
                if (!std::getline(ss, campi[i], ';'))
                    return false;
            }

            try {
                Data d = { std::stoi(campi[7]), std::stoi(campi[8]), std::stoi(campi[9]) };
                listaPC[indiceLista++] = Computer(std::stoi(campi[0]), campi[1], campi[2],std::stod(campi[3]), std::stoi(campi[4]),std::stoi(campi[5]), std::stoi(campi[6]), d);
            }
            
            catch (...) {
                return false;
            }
        }

        return true;
    }
};




#endif //TPSIT_GESTIONEPC_H
