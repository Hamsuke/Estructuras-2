//
// Created by victo on 28/02/2020.
//

#include "Archivo.h"

class menuprin{
public:
    void menus();
};

metodos menu;

void menuprin::menus(){
    int opc = 0;
    std::cout << "Que desea hacer?" << endl
              << "1.Insertar proyecto" << endl
              << "2.Buscar proyecto por folio" << endl
              << "3.Buscar proyecto por areas" << endl
              << "4.Salir" << endl;
    cin >> opc;
    if(opc!= 1 or 2 or 3 or 4){
        cin>>opc;
    }
    switch (opc) {
        case 1:
            menu.escritura();
            break;
        case 2:
            menu.lectura();
            break;
        case 3:
            menu.lecturaEsp();
            break;
    }
    while (opc != 4);
}