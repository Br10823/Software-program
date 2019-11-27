#ifndef Reservation_h
#define Reservation_h
#include "Date.h"
#include "Material.h"
#include <iostream>
  using namespace std;

  class Reservation:public Date
  {
    private:
    int MaterialID;
    int ClientID;
    Date reservationDate;

    public:
    Reservation();
    Reservation (int, int, Date);
    void setMaterialID(int);
    int getMaterialID();
    void setClientID(int);
    int getClientID();
    void setReservationDate(Date);
    Date getReservationDate();
    Date calculateEndOfReservation(int);
    void toString();
  };
  Reservation::Reservation() {
    Date D1;
    MaterialID = -1;
    ClientID = -1;
    reservationDate = D1;
}

  Reservation::Reservation(int iMiD, int iCiD, Date Rd) {
    MaterialID = iMiD;
    ClientID = iCiD;
    reservationDate = Rd;
}

  int Reservation::getMaterialID() {
    return MaterialID;
}

  void Reservation::setMaterialID(int iMiD) {
    MaterialID = iMiD;
}

  int Reservation::getClientID() {
    return ClientID;
}

  void Reservation::setReservationDate(class Date Rd) {
    reservationDate = Rd;
}

  void Reservation::setClientID(int iCiD) {
    ClientID = iCiD;
}

  void Reservation::toString() {
    cout << endl;
    cout << "Material ID: " << MaterialID << endl;
    cout << "Client ID: " << ClientID << endl;
    cout << "Reservation date: " << reservationDate << endl;
}

  Date Reservation::getReservationDate() {
    return reservationDate;
}

  Date Reservation::calculateEndOfReservation(int iTime) {
    return reservationDate + iTime;
}


#endif