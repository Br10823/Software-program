#ifndef Book_h
#define Book_h
#include "Material.h"
using namespace std;

class Book:public Material {
private:
    int iNumOfPages;
    string sAuthor;
    
public:
    Book();
    Book(int, string, int, string);
    int getnumPag();
    void setnumPag(int);
    string getAutor();
    void setAutor(string);
    int numberOfDaysRented();
    void toString();
};

Book::Book() {
    iNumOfPages = -1;
    MaterialID = -1;
    sTitle = "N/A";
    sAuthor = "N/A";
}

Book::Book(int iNumP, string sAu, int idM, string sTitl) {
    iNumOfPages = iNumP;
    sAuthor = sAu;
    MaterialID = idM;
    sTitle = sTitl;
}

int Book::getnumPag() {
    return iNumOfPages;
}

void Book::setnumPag(int iNumP) {
    iNumOfPages = iNumP;
}

string Book::getAutor() {
    return sAuthor;
}

void Book::setAutor(string sAu) {
    sAuthor = sAu;
}

int Book::numberOfDaysRented() {
    return 10;
}

void Book::toString() {
    cout << "MaterialID: " << MaterialID << endl;
    cout << "Material type: Book" << endl;
    cout << "Title of book: " << sTitle << endl;
    cout << "Number of pages: " << iNumOfPages << endl;
    cout << "Author of the book: " << sAuthor << endl;
}

#endif 
