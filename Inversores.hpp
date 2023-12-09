#ifndef INVERSORES_H
#define INVERSORES_H
using namespace std;
class Inversores: public Produto {
private:
    string tensaoSuportada;
public:
    Inversores();
    void setTensaoSuportada(string);
    string getTensaoSuportada();
};
#endif 