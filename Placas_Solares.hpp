#ifndef PLACAS_H
#define PLACAS_H
using namespace std;
class Placas: public Produto {
private:
    string capacidadeDeGeracaoWatts;
public:
    Placas();
    void setCapacidadeDeGeracaoWatts(string);
    string getCapacidadeDeGeracaoWatts();
};
#endif 