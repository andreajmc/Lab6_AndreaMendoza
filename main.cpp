#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include "Product.h"
#include "Box.h"
#include "Books.h"
#include "Clothes.h"
#include "Electronics.h"
#include "Videogames.h"
#include "Computer.h"

#include <vector>
using std::vector;

#include <string>
using std::string;

Box*** addToBox(Product, bool, vector<Box>&, Box***, int);
Box*** createBoxMatrix(int);
void initBoxMatrix(Box***,int);
void printBoxMatrix(Box***,int, int);
void freeBoxMatrix(Box***&,int);

int main() {
    Box *** storage = createBoxMatrix(10);
    initBoxMatrix(storage, 10);
    int choice1 = -1;
    vector <Box> boxes;
    while (choice1 != 4) {
        cout << "¡Bienvenido al sistema de almacenamiento!" << endl
             << endl << "¿Qué desea hacer?" << endl
             << "(1) Crear un producto." << endl
             << "(2) Visualizar el almacén." << endl
             << endl << "(4) Salir." << endl
             << "Ingrese la opción correspondiente a su elección: ";
        cin>>choice1;

        if (choice1 < 1 || choice1 > 4 ) {
            cout<<"Ha ingresado una opción inválida. Por favor, ingrese un número valido: ";
            cin>>choice1;
        }

        if (choice1 == 1) {
            int choice2;

            string name;
            double weight;
            bool fragile;

            cout << "-- Productos --" << endl << endl
            << "Ingrese el nombre de su producto: ";
            cin>>name;
            cout << endl <<"Ingrese el peso (en kilogramos) de su producto: ";
            cin>>weight;
            if (weight > 999) {
                cout<<"El máximo peso que puede tener un productor es de 999kg."<<endl<<
                "Ingrese un nuevo peso: ";
                cin>>weight;
            }
            cout << endl << "¿Qué producto desea crear?" << endl
                 << "(1) Libros." << endl
                 << "(2) Ropa." << endl
                 << "(3) Electrónicos." << endl
                 << "Ingrese la opción correspondiente a su elección: ";
            cin>>choice2;

            if (choice2 < 1 || choice2 > 3 ) {
                cout<<"Ha ingresado una opción inválida. Por favor, ingrese un número valido: ";
                cin>>choice2;
            }

            if (choice2 == 1) {
                int code;
                cout<<"Ingrese el código del libro: ";
                cin>>code;
                Books book (name,weight,false,code);
                storage = addToBox(book, false, boxes, storage, 0);
            } else if (choice2 == 2) {
                string type;
                cout<<"Ingrese el tipo de ropa: ";
                cin>>type;
                Clothes c (name,weight,false,type);
                storage = addToBox(c, false, boxes, storage, 0);
            } else if (choice2 == 3) {
                int choice3;
                cout << endl << "¿Qué producto electrónico desea crear?" << endl
                     << "(1) Videojuegos." << endl
                     << "(2) Computadora." << endl
                     << "Ingrese la opción correspondiente a su elección: ";
                cin>>choice3;

                while (choice3 < 1 || choice3 > 2 ) {
                    cout<<"Ha ingresado una opción inválida. Por favor, ingrese un número valido: ";
                    cin>>choice3;
                }

                if (choice3 == 1) {
                    string dev;
                    cout<<"Ingrese el nombre del desarrollador del videojuego: ";
                    cin>>dev;
                    Videogames vid (name,weight,true,dev);
                    storage = addToBox(vid, true, boxes, storage, 0);
                } else if (choice3 == 2) {
                    string OS;
                    cout<<"Ingrese el nombre del sistema operativo de la computadora: ";
                    cin>>OS;
                    Computer computer (name,weight,true,OS);
                    storage = addToBox(computer, true, boxes, storage, 0);
                }

            }
        } else if (choice1 == 2) {
            int choice4;
            cout << endl << "¿Cómo desea visualizar el almacén?" << endl
                 << "(1) Fragilidad." << endl
                 << "(2) Peso." << endl
                 << "Ingrese la opción correspondiente a su elección: ";
            cin >> choice4;

            while (choice4 < 1 || choice4 > 2) {
                cout << "Ha ingresado una opción inválida. Por favor, ingrese un número valido: ";
                cin >> choice4;
            }

            if (choice4 == 1) {
                printBoxMatrix(storage, 10, 1);
            } else if (choice4 == 2) {
                printBoxMatrix(storage, 10, 2);
            }

            int choice5;
            cout << endl << "¿Qué desea hacer?" << endl
                 << "(1) Mover caja a un espacio libre." << endl
                 << "(2) Intercambiar dos cajas de lugar." << endl
                 << "(3) Mostrar la información de una caja." << endl
                 << "(4) Volver al menú." << endl
                 << endl << "Ingrese el número correspodiente a su opción: ";
            cin >> choice5;

            if (choice5 < 1 || choice5 > 4) {
                cout << "Ha ingresado una opción inválida." << endl << "Ingrese una opción válida: ";
                cin >> choice5;
            }

            if (choice5 == 1) {
                int x;
                cout << "Ingrese la coordenada x de la caja que desea mover: ";
                cin >> x;
                int y;
                cout << "Ingrese la coordenada y de la caja que desea mover: ";
                cin >> y;
                if (x < 0 || x >= 10 || y < 0 || y >= 10) {
                    cout << "Ha ingresado una coordenada inválida." << endl
                         << "Ingrese la coordenada x de la caja que desea mover: ";
                    cin >> x;
                    cout << "Ingrese la coordenada y de la caja que desea mover: ";
                    cin >> y;
                }
                if (storage[x][y] == NULL) {
                    cout << "No hay una caja disponible en esa posición." << endl
                         << "Ingrese la coordenada x de la caja que desea mover: ";
                    cin >> x;
                    cout << "Ingrese la coordenada y de la caja que desea mover: ";
                    cin >> y;
                }

                int x2;
                cout << "Ingrese la coordenada x del espacio al que desea mover: ";
                cin >> x2;
                int y2;
                cout << "Ingrese la coordenada y del espacio al que desea mover: ";
                cin >> y2;
                if (x2 < 0 || x2 >= 10 || y2 < 0 || y2 >= 10) {
                    cout << "Ha ingresado una coordenada inválida." << endl
                         << "Ingrese la coordenada x del espacio al que desea mover: ";
                    cin >> x2;
                    cout << "Ingrese la coordenada y del espacio que desea mover: ";
                    cin >> y2;
                }
                if (storage[x2][y2] != NULL) {
                    cout << "El espacio no está disponible." << endl
                         << "Ingrese la coordenada x del espacio al que desea mover: ";
                    cin >> x2;
                    cout << "Ingrese la coordenada y del espacio al que desea mover: ";
                    cin >> y2;
                }

                storage[x2][y2] = storage[x][y];
                storage[x][y] = NULL;
            } else if (choice5 == 2) {
                int x;
                cout << "Ingrese la coordenada x de la caja que desea mover: ";
                cin >> x;
                int y;
                cout << "Ingrese la coordenada y de la caja que desea mover: ";
                cin >> y;
                if (x < 0 || x >= 10 || y < 0 || y >= 10) {
                    cout << "Ha ingresado una coordenada inválida." << endl
                         << "Ingrese la coordenada x de la caja que desea mover: ";
                    cin >> x;
                    cout << "Ingrese la coordenada y de la caja que desea mover: ";
                    cin >> y;
                }
                if (storage[x][y] == NULL) {
                    cout << "No hay una caja disponible en esa posición." << endl
                         << "Ingrese la coordenada x de la caja que desea mover: ";
                    cin >> x;
                    cout << "Ingrese la coordenada y de la caja que desea mover: ";
                    cin >> y;
                }

                int x2;
                cout << "Ingrese la coordenada x de la segunda caja que desea mover: ";
                cin >> x2;
                int y2;
                cout << "Ingrese la coordenada x de la segunda caja que desea mover: ";
                cin >> y2;
                if (x2 < 0 || x2 >= 10 || y2 < 0 || y2 >= 10) {
                    cout << "Ha ingresado una coordenada inválida." << endl
                         << "Ingrese la coordenada x de la segunda caja que desea mover: ";
                    cin >> x2;
                    cout << "Ingrese la coordenada y de la segunda caja que desea mover: ";
                    cin >> y2;
                }
                if (storage[x2][y2] == NULL) {
                    cout << "No ha seleccionado una caja." << endl
                         << "Ingrese la coordenada x de la segunda caja que desea mover: ";
                    cin >> x2;
                    cout << "IIngrese la coordenada y de la segunda caja que desea mover: ";
                    cin >> y2;
                }

                Box *temp = storage[x2][y2];
                storage[x2][y2] = storage[x][y];
                storage[x][y] = temp;
                delete temp;
            } else if (choice5 == 3) {
                int x;
                cout << "Ingrese la coordenada x de la caja que desea información: ";
                cin >> x;
                int y;
                cout << "Ingrese la coordenada y de la caja que desea  información: ";
                cin >> y;
                if (x < 0 || x >= 10 || y < 0 || y >= 10) {
                    cout << "Ha ingresado una coordenada inválida." << endl
                         << "Ingrese la coordenada x de la caja que desea  información: ";
                    cin >> x;
                    cout << "Ingrese la coordenada y de la caja que desea  información: ";
                    cin >> y;
                }
                if (storage[x][y] == NULL) {
                    cout << "No hay una caja disponible en esa posición." << endl
                         << "Ingrese la coordenada x de la caja que desea  información: ";
                    cin >> x;
                    cout << "Ingrese la coordenada y de la caja que desea  información: ";
                    cin >> y;
                }
                cout << endl << "Peso de la caja: " << storage[x][y]->setWeightT();
                string f;
                if (storage[x][y]->isFragile()) {
                    f = "Sí.";
                } else {
                    f = "No.";
                }
                cout << endl << "¿Frágil? " << f << endl;
                cout << "Objetos dentro de la caja: " << endl;
                for (const auto &item : storage[x][y]->getStuff()) {
                    cout << "     -" << item.getName() << endl;
                }
                cout << "¡Gestión realizada exitósamente!" << endl;
            }
        }
    }
    freeBoxMatrix(storage, 10);
}

Box*** addToBox(Product p, bool fragile, vector<Box> &boxes, Box*** storage, int cont) {
    cout<<"size:"<<boxes.size();
    cout<<"t/f:"<<boxes.empty();
    cout<<"cont: "<<cont;
    bool full = false;

    if (boxes.size() == 0) {
        vector <Product> products;
        Box b (products,fragile,0);
        boxes.push_back(b);
        b.addStuff(p);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (storage[i][j] == NULL) {
                    Box* b2 = new Box(products,fragile,0);
                    storage[i][j] = b2;
                    b2->addStuff(p);
                    i = 10;
                    break;
                }
            }

        }
    } else {
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                Box* box = storage[i][j];
                if (box->getWeight() <= 999) {
                    if (box->getWeight() + p.getWeight() <= 999) {
                        box->addStuff(p);
                        if (!box->isFragile()) {
                            box->setFragile(fragile);
                        }
                    }
                    i = 10;
                    j = 10;
                }
            }
            if (i == 9)
                full = true;
        }
    }
    if (full) {
        vector <Product> products;
        Box b (products,fragile,0);
        boxes.push_back(b);
        b.addStuff(p);
        for (int i = 0; i < 10; ++i) {
            for (int j = 0; j < 10; ++j) {
                if (storage[i][j] == NULL) {
                    Box* b2 = new Box(products,fragile,0);
                    storage[i][j] = b2;
                    b2->addStuff(p);
                    i = 10;
                    break;
                }
            }

        }
    }
    return storage;
}

void freeBoxMatrix(Box ***& matrix,int size){
    for(int i=0;i<size;i++){
        for (int j = 0; j < 10; ++j) {
            delete matrix[i][j];
        }
        delete[] matrix[i];
        matrix[i]=NULL;
    }
    delete[] matrix;
    matrix=NULL;
}

Box*** createBoxMatrix(int size){
    Box*** retVal=NULL;
    retVal=new Box**[size];
    for(int i=0;i<size;i++){
        retVal[i]=new Box* [size];
    }
    return retVal;
}


void initBoxMatrix(Box *** matrix,int size){
    for(int i=0;i<size;i++)
        for(int j=0;j<size;j++)
            matrix[i][j] = NULL;
}

void printBoxMatrix(Box*** matrix,int size, int choice){
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if (choice == 1) {
                if (matrix[i][j] != NULL && matrix[i][j]->isFragile()) {
                    cout<<"[F]";
                } else if (matrix[i][j] != NULL && !matrix[i][j]->isFragile()){
                    cout<< "[X]";
                } else {
                    cout<<"[ ]";
                }
            } else if (choice == 2) {
                if (matrix[i][j] == NULL) {
                    cout<<"[ ]";
                } else {
                    double temp = matrix[i][j]->setWeightT();
                    while (temp >= 10) {
                        temp /= 10;
                    }
                    int x = temp;
                    cout<<"["<<x<<"]";
                }
            }
        }
        cout<<endl;
    }
    cout<<endl;
}







