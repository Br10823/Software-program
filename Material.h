#ifndef Material_h
#define Material_h
#include "Reservation.h"
using namespace std;

class Material
{
  protected:
 int MaterialID;
 string sTitle;

 public:
 Material();
 Material(int, string);
 void setMaterialID(int);
 int getMaterialID();
 void setsTitle(string);
 string getsTitle();
 virtual void toString() = 0;
 virtual int numberOfDaysRented() = 0;
};
Material::Material() {
    MaterialID = -1;
    sTitle = "N/A";
}

Material::Material(int iMID, string sTle) {
    MaterialID = iMID;
    sTitle = sTle;
}

int Material::getMaterialID() {
    return MaterialID;
}

void Material::setMaterialID(int iMID) {
    MaterialID = iMID;
}

string Material::getsTitle() {
    return sTitle;
}

void Material::setsTitle(string sTle) {
    sTitle = sTle;
}


#endif 