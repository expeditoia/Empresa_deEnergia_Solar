#include "Baterias.hpp"
using namespace std;
Baterias::Baterias(){
    capacidadeDeArmazenamento = " ";
    voltagemDeSaida = " ";
}

void Baterias::setCapacidadeDeArmazenamento(string capacidadeDeArmazenamento){
    this->capacidadeDeArmazenamento = capacidadeDeArmazenamento;
}

void Baterias::setVoltagemDeSaida(string voltagemDeSaida){
    this->voltagemDeSaida = voltagemDeSaida;
}

string Baterias::getCapacidadeDeArmazenamento(){
    return capacidadeDeArmazenamento;
}

string Baterias::getVoltagemDeSaida(){
    return voltagemDeSaida;
}