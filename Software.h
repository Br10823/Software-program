#ifndef Software_h
#define Software_h
#include "Material.h"
using namespace std;

class Software:public Material {
private:
    string sOperatingSystem;
    
public:
    Software();
    Software(string, int, string);
    string getOperatingSystem();
    void setOperatingSystem(string);
    void toString();
    int numberOfDaysRented();
};

Software::Software() {
    sOperatingSystem = "N/A";
    MaterialID = -1;
    sTitle = "N/A";
}

Software::Software(string sOpSy, int iMatID, string sTitl) {
    sOperatingSystem = sOpSy;
    MaterialID = iMatID;
    sTitle = sTitl;
}

string Software::getOperatingSystem() {
    return sOperatingSystem;
}

void Software::setOperatingSystem(string sOpSy) {
    sOperatingSystem = sOpSy;
}

int Software::numberOfDaysRented() {
    return 1;
}

void Software::toString() {
    cout << "Material ID: " << MaterialID << endl;
    cout << "Type of material: Software" << endl;
    cout << "Software title:  " << sTitle << endl;
    cout << "Operating system: " << sOperatingSystem << endl;
}


#endif 
