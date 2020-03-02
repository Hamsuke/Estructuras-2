//
// Created by hamsuke on 02/03/20.
//

#ifndef PRACTICA1_ARCHIVO_H
#define PRACTICA1_ARCHIVO_H

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

class metodos{
private:
    string namearch;
    string name;
    

public:
    void abrir();
    void ecribir();
    void lectura();
    void lecturaEsp();
};

void metodos::escritura() {
    cout<<"Ingrese un nombre para el archivo (no puede contener espacios ni caracteres especiales, la terminacion sera .txt y la añadira el programa)"<<endl;
    cin>>namearch;
    namearch+=".txt";
    Wdoc.open(namearch , ios::app);
    cout<<"Ingrese un nombre"<<endl;
    cin.get();
    getline(cin,name);
    cout<<"Ingrese la direccion de empresa"<<endl;
    getline(cin,dir);
    cout<<"Ingrese el nombre de la ciudad"<<endl;
    getline(cin,city);
    cout<<"Ingrese el estado de la empresa"<<endl;
    getline(cin , state);
    cout<<"ingrese el codigo postal"<<endl;
    cin >> postal;
    cout<<"Ingrese el puesto o rol del empleado"<<endl;
    cin.get();
    getline(cin,pos);
    Wdoc<<name<<"|"<<dir<<"|"<<city<<"|"<<state<<"|"<<postal<<"|"<<pos<<"|";
    Wdoc.close();

}

#endif //PRACTICA1_ARCHIVO_H
