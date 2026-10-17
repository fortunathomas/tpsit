#ifndef TPSIT_COMPUTER_H
#define TPSIT_COMPUTER_H


#include <string>

struct Data {
    int giorno;
    int mese;
    int anno;
};

class Computer {
private:
    inline static int pcCreati = 0;
    int codice;
    std::string marca;
    std::string modello;
    double velocitaProcessore;
    int dimensioniRAM;
    int dimensioniDisco;
    int dimensioniMonitor;
    Data annoDiAcquisto;
    
public:
    Computer() {
        this->codice = 0;
        this->marca = "";
        this->modello = "";
        this->velocitaProcessore = 0;
        this->dimensioniRAM = 0;
        this->dimensioniDisco = 0;
        this->dimensioniMonitor = 0;
        this->annoDiAcquisto = { 0, 00, 0000};
    }
    
    Computer(std::string marca, std::string modello, double velocitaProcessore, int dimensioniRAM, int dimensioniDisco, int dimensioniMonitor, Data annoDiAcquisto)
    {
        codice = ++pcCreati;
        this->marca = marca;
        this->modello = modello;
        this->velocitaProcessore = velocitaProcessore < 0 ? 0 : velocitaProcessore;
        this->dimensioniRAM = dimensioniRAM < 0 ? 0 : dimensioniRAM;
        this->dimensioniDisco = dimensioniDisco < 0 ? 0 : dimensioniDisco;
        this->dimensioniMonitor = dimensioniMonitor < 0 ? 0 : dimensioniMonitor;
        this->annoDiAcquisto = annoDiAcquisto;
    };
    
    int GetCodice() const { return codice; }
    
    double GetVelocitaProcessore() const { return velocitaProcessore; }
    
    int GetDimensioniRAM() const { return dimensioniRAM; }
    
    int GetDimensioniDisco() const { return dimensioniDisco; }
    
};



#endif //TPSIT_COMPUTER_H
