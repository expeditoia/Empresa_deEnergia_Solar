#include "Placas_Solares.hpp"
using namespace std;
Placas::Placas(){
    capacidadeDeGeracaoWatts = " ";
}
void Placas::setCapacidadeDeGeracaoWatts(string capacidadeDeGeracaoWatts){
    this->capacidadeDeGeracaoWatts = capacidadeDeGeracaoWatts;
}
string Placas::getCapacidadeDeGeracaoWatts(){
    return capacidadeDeGeracaoWatts;
}