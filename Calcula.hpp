#ifndef EMPRESA_SOLAR_H
#define EMPRESA_SOLAR_H

class Empresa_Solar{
		float potencia, gasto;
	public:
		Empresa_Solar();
		Empresa_Solar(float,float);
		void setPotencia(float);
		void setGasto(float);
		int economia_anual();
		int quantidade_de_paineis_necessarios();
		int area_minima();	
};
#endif