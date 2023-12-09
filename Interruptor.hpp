#ifndef INTERRUPTORESDR_H
#define INTERRUPTORESDR_H
using namespace std;
class InterruptoresDR: public  Inversores{
private:
    string amperesSuportado;
public:
    InterruptoresDR();
    void setAmperesSuportado(string);
    string getAmperesSuportado();
};
#endif 