#include "Inversores.hpp"
using namespace std;
Inversores::Inversores(){
    tensaoSuportada = " ";
}
void Inversores::setTensaoSuportada(string tensaoSuportada){
    this->tensaoSuportada = tensaoSuportada;
}
string Inversores::getTensaoSuportada(){
    return tensaoSuportada;
}