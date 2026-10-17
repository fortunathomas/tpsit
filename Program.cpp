#include "Computer.h"
#include "GestionePC.h"
#include <iostream>

int main() {
    Computer a("Dell", "XPS", 3.2, 16, 512, 15, {1, 9, 2024});
    Computer b("HP", "Pavilion", 2.4, 8, 256, 14, {5, 3, 2022});
    GestionePC g;
    
    std::cout << "Codice PC numero 1: " << a.GetCodice() << std::endl;
    std::cout << "Codice PC numero 2: " << b.GetCodice() << std::endl;
    
    g.AggiungiPC(a);
    g.AggiungiPC(b);
    
    
    int x = 0;
    std::cout << "Inserisci codice da cercare: ";
    std::cin >> x;
    std::cout << std::endl;
    
    Computer* trovato = g.RicercaPerCodice(x);
    if (trovato == nullptr) {
        std::cout << "Nessun PC con codice " << x << std::endl;
    } else {
        std::cout << "PC con codice " << x << ": " << trovato->GetNome() << std::endl;
    }
    
    
    double velocitaDesiderata = 0;
    int ramDesiderata = 0;
    int discoDesiderato = 0;
    Computer lista[MAX];
    
    std::cout << "Inserisci velocita processore desiderata: ";
    std::cin >> velocitaDesiderata;
    
    std::cout << "Inserisci dimensioni RAM desiderate: ";
    std::cin >> ramDesiderata;
    
    std::cout << "Inserisci dimensioni disco desiderate: ";
    std::cin >> discoDesiderato;
    
    int pcTrovati = g.RicercaPerCaratteristiche(lista, velocitaDesiderata, ramDesiderata, discoDesiderato);
    std::cout << "PC trovati: " << pcTrovati << std::endl;
    for (int i = 0; i < pcTrovati; i++) {
        std::cout << lista[i].GetNome() << std::endl;
    }
}
