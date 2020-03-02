//
// Created by victo on 28/02/2020.
//

#include "Archivo.h"

metodos menu;
do{
    int opc=0;
    std::cout<<"Que desea hacer?"<<endl
    <<"1.Insertar proyecto"<<endl
    <<"2.Buscar proyecto por folio"<<endl
    <<"3.Buscar proyecto por areas"<<endl
    <<"4.Salir"<<endl;
    cin>>opc;
    switch(opc){
        case 1:
            menu.escritura();
            break;
        case 2:
            menu.lectura();
            break;
        case 3:
            menu.escrituraesp();
            break;
    }while(opc!=4);
}