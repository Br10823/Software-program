#ifndef CD_h
#define CD_h
#include "Material.h"
using namespace std;

class CD:public Material {
private:
    int iDuration;
    
public:
    CD();
    CD(int, int, string);
    int getiDuration();
    void setiDuration(int);
    void toString();
    int numberOfDaysRented();
};

CD::CD() {
    iDuration = -1;
    MaterialID = -1;
    sTitle = "N/A";
}

CD::CD(int iDura, int iMatID, string sTitl) {
    iDuration = iDura;
    MaterialID = iMatID;
    sTitle = sTitl;
}

int CD::getiDuration() {
    return iDuration;
}

void CD::setiDuration(int iDura) {
    iDuration = iDura;
}

int CD::numberOfDaysRented() {
    return 3;
}

void CD::toString() {
    cout << "Material ID: " << MaterialID << endl;
    cout << "Material type: CD " << endl;
    cout << "CD title: " << sTitle << endl;
    cout << "Duration: " << iDuration << endl;
}

#endif