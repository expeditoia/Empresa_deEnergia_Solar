#include "Interruptor.hpp"
using namespace std;
InterruptoresDR::InterruptoresDR(){
    amperesSuportado = " ";
}
void InterruptoresDR::setAmperesSuportado(string amperesSuportado){
    this->amperesSuportado = amperesSuportado;
}

string InterruptoresDR::getAmperesSuportado(){
    return amperesSuportado;
}