#include "Archivo.h"

metodos menu;

int main() {
    int opc=0;
    do{
       cout<<"Que desea hacer?"<<endl
       <<"1.Anadir proyecto"<<endl
       <<"2.Buscar proyecto por folio"<<endl
       <<"3.Buscar proyecto por area"<<endl
       <<"4.Salir"<<endl;
       cin>>opc;
       switch (opc){
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
    }while (opc!=4);
}