#ifndef BATERIAS_H
#define BATERIAS_H

using namespace std;

class Baterias: public Produto {
private:
    string capacidadeDeArmazenamento;
    string voltagemDeSaida;
public:
    Baterias();

    void setCapacidadeDeArmazenamento(string);
    void setVoltagemDeSaida(string);

    string getCapacidadeDeArmazenamento();
    string getVoltagemDeSaida();
};

#endif 
