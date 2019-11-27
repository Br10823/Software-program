#include <iostream>
#include "Reservation.h"
#include "Material.h"
#include "Date.h"
#include "Book.h"
#include "CD.h"
#include "Software.h"
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> split(string line){
    string element = "";
    vector<string> splitted;

    for(int i = 0; i < line.length(); i++){
        if(line[i] != ' '){
            element += line[i];
        } else if(element != "") {
            splitted.push_back(element);
            element = "";
        }
    }

    splitted.push_back(element);

    return splitted;
}

int main() {
	vector<Material*> materials;
  vector<Reservation*> reservations;
	int x, y, d, m, y1, iMatID, iClID, iClieID, option;
	Date D1, DReservation;
	bool verify;

	for (x = 0; x < 50; x++) {
		reservations.push_back(new Reservation(-1, -1, D1));
	}
  
	ifstream iMaterialID("material.txt");
  ifstream iDReservation("reservation.txt");
  
	x = 0;

    if(iMaterialID.is_open()){
        while (!iMaterialID.eof()) {
            vector<string> splittedLine;
            string line;
            getline(iMaterialID, line);
            splittedLine = split(line);
            cout << "Size: " << splittedLine.size() << endl << flush;
            int iMID = stoi(splittedLine[0]);
            string title = splittedLine[1];
            char TMaterial = splittedLine[2][0];

            switch (TMaterial) {
                case 'B': {
                    int PageNum = stoi(splittedLine[3]);
                    string author = splittedLine[4];
                    materials.push_back(new Book(PageNum, author, iMID, title));
                    cout << TMaterial << endl;
                    cout << flush;
                }
                break;
                case 'C': {
                    int duration = stoi(splittedLine[3]);
                    materials.push_back(new CD(duration, iMID, title)); 
                    cout << TMaterial << endl;
                    cout << flush;
                }
                break;
                case 'S': {
                    string opsis = splittedLine[3];
                    materials.push_back(new Software(opsis, iMID, title));
                    cout << TMaterial << endl;
                    cout << flush;
                }
                break;
            }
            x++;
        }
    } else {
        cout << "File not open" << endl;
    }

	iMaterialID.close();
    
	x = 0;
	while (!iDReservation.eof()) {
    int iMID;
		iDReservation >> d >> m >> y1 >> iMID >> iClieID;
		Date D1(d, m, y1);
		reservations[x] = new Reservation(iMID, iClieID, D1);
		x++;
	}
	iDReservation.close();

	do {
		cout << "**** MENU ****" << endl;
		cout << "a) Display the list of materials" << endl;
		cout << "b) Display the list of Reservations" << endl;
		cout << "c) Display the reservations of a given material" << endl;
		cout << "d) Display the reservations of a given date" << endl;
		cout << "e) Do a reservation" << endl;
		cout << "f) Finish the program" << endl;
		cin >> option;
        
		switch (option) {
		case 1:
			for (x = 0; x < 20; x++) {
				materials[x]->toString();
				cout << endl;
			}
			break;
        
		case 2:
			for (x = 0; (x < 50) && ((reservations[x]->getClientID()) != -1); x++) {
				reservations[x]->toString();
				bool continueLoop = true;
				for (y = 0; y < 20 && continueLoop; y++){ 
					if (reservations[x]->getMaterialID() == materials[y]->getMaterialID()) {
						cout << "Titulo: " << materials[y]->getsTitle() << endl;
						continueLoop = false;
                        
					}
				}
				cout << endl;
			}
			break;
        
		case 3:
            int idDelMaterials;
            cout << "Dame el ID: ";
            cin >> idDelMaterials;

            for (x = 0; x < 50 && (reservations[x]->getClientID()) != -1; x++) {
                if (reservations[x]->getMaterialID() == idDelMaterials) {
                    cout << "ID Encontrado! :)" << endl;
                    reservations[x]->toString();
                     } 
                }
            
			break;
        //muestra la lista de los materiales DADA la Date (cin)
		
        
        case 4: //referencia: http://www.cplusplus.com/doc/tutorial/pointers/
			
			break; //*********************
        
        
        //hacer una reservacion
		case 5:
			cout << "Ingresa tu ID: " << endl;
			cin >> iClID;
			cout << "Ingresa el ID del material: ";
			verify = false;
			do {
				cin >> iMatID;
				for (x = 0; x < 20; x++) {
					if (iMatID == materials[x]->getMaterialID()) {
						verify = true;
					}
				}
				if (!verify) {
					cout << "ID invalido, ingresalo de nuevo: ";
				}
			} while (!verify);
			cout << "Ingresa la Date:" << endl;
			do {
				cin >> DReservation;
                verify = true;
				for (x = 0; x < 50 && (reservations[x]->getMaterialID()) != -1 && verify; x++) {
					for (y = 0; y < 20; y++) {
						if (iMatID == reservations[x]->getMaterialID()) {
								verify = false;
						}
					}
				}
				if (!verify) {
					cout << "El material ya esta apartado" << endl;
				}
				else {
					for (x = 0; reservations[x]->getMaterialID() != -1; x++);
					reservations[x] = new Reservation(iMatID, iClID, DReservation);
					cout << "Tu reservacion se realizo exitosamente" << endl;
				}
			} while (!verify);
			break;

            case 6: 
            cout << "Gracias por usar el programa!" << endl;
		}
	} while (option != 6);


	return 0;
}
