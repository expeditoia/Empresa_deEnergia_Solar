#include "DisjuntorDDR.hpp"
using namespace std;
DisjuntoreDifResDDR::DisjuntoreDifResDDR(){
    idrTrueFalse = " ";
}
void DisjuntoreDifResDDR::setIdrTrueFalse(string idrTrueFalse){
    this->idrTrueFalse = idrTrueFalse;
}
string DisjuntoreDifResDDR::getIdrTrueFalse(){
    return idrTrueFalse;
}