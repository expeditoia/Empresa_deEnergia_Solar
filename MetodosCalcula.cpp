#include "Calcula.hpp"
#include <cmath>

Empresa_Solar::Empresa_Solar()
{
	this->potencia = 0;
	this->gasto = 0;
}
Empresa_Solar::Empresa_Solar(float potencia, float gasto)
{
	this->potencia = potencia;
	this->gasto = gasto;
}
void Empresa_Solar::setPotencia(float potencia){
    this->potencia = potencia;
}
void Empresa_Solar::setGasto(float gasto){
    this->gasto = gasto;
}
int Empresa_Solar::quantidade_de_paineis_necessarios(){
	float resultado;
	resultado=potencia/32;
	return ceil(resultado);
}
int Empresa_Solar::area_minima(){
	return (ceil(potencia/32))*2.5;
}
int Empresa_Solar::economia_anual(){
	return (gasto*12)-((gasto*0.9)*12);
}