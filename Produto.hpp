#ifndef PRODUTO_H
#define PRODUTO_H

using namespace std;

class Produto{
private:
    string nomeDoProduto;
    float precoDoProduto;
    string codigoBarras;
public:
    Produto();
    void setNomeDoProduto(string);
    void setPrecoDoProduto(float);
    void setCodigoBarras(string);

    string getNomeDoProduto();
    float getPrecoDoProduto();
    string getCodigoBarras();
};
#endif 