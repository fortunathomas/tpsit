#include "computer.h"
#include <iostream>
#include <string>

struct Data {
    int giorno;
    int mese;
    int anno;
};

class Computer {
private:
    static int codice;
    std::string marca;
    std::string modello;
    double velocitaProcessore;
    int dimensioniRAM;
    int dimensioniDisco;
    int dimensioniMonitor;
    Data annoDiAcquisto;
    
public:
    Computer(std::string marca, std::string modello, double velocitaProcessore, int dimensioniRAM, int dimensioniDisco, int dimensioniMonitor, Data annoDiAcquisto)
{
    codice = ++codice;
    this->marca = marca;
    this->modello = modello;
    this->velocitaProcessore = velocitaProcessore;
    this->dimensioniRAM = dimensioniRAM;
    this->dimensioniDisco = dimensioniDisco;
    this->dimensioniMonitor = dimensioniMonitor;
    this->annoDiAcquisto = annoDiAcquisto;
};
    
    int GetCodice() {
        return codice;
    }
    
    double GetVelocitaProcessore() {
        return velocitaProcessore;
    }
    
    int GetDimensioniRAM() {
        return dimensioniRAM;
    }
    
    int GetDimensioniDisco() {
        return dimensioniDisco;
    }
    
};
