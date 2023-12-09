#include "Produto.hpp"
using namespace std;
Produto::Produto(){
    nomeDoProduto = " ";
    precoDoProduto = 0;
    codigoBarras = " ";
}

void Produto::setNomeDoProduto(string nomeDoProduto){
    this->nomeDoProduto = nomeDoProduto;
}
void Produto::setPrecoDoProduto(float precoDoProduto){
    this->precoDoProduto = precoDoProduto;
}
void Produto::setCodigoBarras(string codigoBarras){
    this->codigoBarras = codigoBarras;
}
string Produto::getNomeDoProduto(){
    return nomeDoProduto;
}
float Produto::getPrecoDoProduto(){
    return precoDoProduto;
}
string Produto::getCodigoBarras(){
    return codigoBarras;
}