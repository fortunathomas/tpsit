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
    Data dataDiAcquisto;
    
public:
    Computer() {
        this->codice = 0;
        this->marca = "";
        this->modello = "";
        this->velocitaProcessore = 0;
        this->dimensioniRAM = 0;
        this->dimensioniDisco = 0;
        this->dimensioniMonitor = 0;
        this->dataDiAcquisto = { 00, 00, 0000};
    }
    //Costruttore per ripristino da file
    Computer(int codice, std::string marca, std::string modello, double velocitaProcessore, int dimensioniRAM, int dimensioniDisco, int dimensioniMonitor, Data dataDiAcquisto)
    {
        this->codice = codice;
        if (codice > pcCreati) pcCreati = codice;
        this->marca = marca;
        this->modello = modello;
        this->velocitaProcessore = velocitaProcessore < 0 ? 0 : velocitaProcessore;
        this->dimensioniRAM = dimensioniRAM < 0 ? 0 : dimensioniRAM;
        this->dimensioniDisco = dimensioniDisco < 0 ? 0 : dimensioniDisco;
        this->dimensioniMonitor = dimensioniMonitor < 0 ? 0 : dimensioniMonitor;
        this->dataDiAcquisto = dataDiAcquisto;
    }
    
    //Costruttore base
    Computer(std::string marca, std::string modello, double velocitaProcessore, int dimensioniRAM, int dimensioniDisco, int dimensioniMonitor, Data dataDiAcquisto)
        : Computer(++pcCreati, marca, modello, velocitaProcessore, dimensioniRAM, dimensioniDisco, dimensioniMonitor, dataDiAcquisto) {}
    
    
    int GetCodice() const { return codice; }
    std::string GetMarca() const { return marca; }
    std::string GetModello() const { return modello; }
    double GetVelocitaProcessore() const { return velocitaProcessore; }
    int GetDimensioniRAM() const { return dimensioniRAM; }
    int GetDimensioniDisco() const { return dimensioniDisco; }
    int GetDimensioniMonitor() const { return dimensioniMonitor; }
    Data GetDataDiAcquisto() const { return dataDiAcquisto; }
    
    std::string GetNome() const { return marca + " " + modello; }
};



#endif //TPSIT_COMPUTER_H
