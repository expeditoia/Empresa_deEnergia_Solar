#ifndef DISJUNTOREDIFRESDDR_H
#define DISJUNTOREDIFRESDDR_H
using namespace std;
class DisjuntoreDifResDDR: public InterruptoresDR {
private:
    string idrTrueFalse;
public:
    DisjuntoreDifResDDR();
    void setIdrTrueFalse(string);
    string getIdrTrueFalse();
};
#endif 