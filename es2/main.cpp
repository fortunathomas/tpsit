#include <iostream>
#include <vector>

#include "classi/Personaggio.h"
#include "classi/Mago.h"
#include "classi/Arciere.h"
#include "classi/Guerriero.h"

void Turno(Personaggio* p) {
    p->attacca();
    p->presentati();
}

int main() {
    Mago* m = new Mago;
    Arciere* a = new Arciere;
    Guerriero* g = new Guerriero;
    
    std::vector<Personaggio*> personaggi = { m, a, g};
    for (Personaggio* p : personaggi) {
        Turno(p);
    }
    
    for (Personaggio* p : personaggi) {
        delete p;
        std::cout << "Eliminato " << p << std::endl;
    }
}
