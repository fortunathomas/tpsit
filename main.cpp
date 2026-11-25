#include <iostream>
#include <vector>
#include "es1/classi/Veicolo.h"
#include "es1/classi/Auto.h"
#include "es1/classi/Bicicletta.h"
#include "es1/classi/Treno.h"

int main() {
    Auto* a = new Auto();
    Bicicletta* b = new Bicicletta();
    Treno* t = new Treno();

    Veicolo* v[] = { a, b, t};
    
    for (int i = 0; i < 3; i++) {
        v[i]->descrizione();
        v[i]->muovi();
        std::cout << "---" << std::endl;
    }
    
    for (int i = 0; i < 3; i++) {
        v[i]->descrizione();
        v[i]->muovi();
        std::cout << "Eliminato " << v[i] << std::endl;
    }
    
    return 0;
}
