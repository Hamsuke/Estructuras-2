//
// Created by hamsuke on 02/03/20.
//

#ifndef PRACTICA1_ARCHIVO_H
#define PRACTICA1_ARCHIVO_H

#include <stdio.h>
#include <string.h>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class metodos{
private:
    string namearch;
    int folio;
    string name;
    string area;
    string espec:
    float fondos;
    string responsable;

public:
    void abrir();
    void ecribir();
    void lectura();
    void lecturaEsp();
};

void metodos::escritura() {
    int opc=0;
    cout<<"Ingrese un nombre para el archivo (no puede contener espacios ni caracteres especiales, la terminacion sera .txt y la añadira el programa)"<<endl;
    cin>>namearch;
    namearch+=".txt";
    Wdoc.open(namearch , ios::app);
    cout<<"Ingrese nombre del proyecto"<<endl;
    cin.get();
    getline(cin,name);
    cout<<"Seleccione el area de trabajo (ingrese el numero del area correspondiente)"<<endl
    <<"Area 1. Fisico matematicas y ciencias de la tierra"<<endl
    <<"Area 2. Biologia y quimica"<<endl
    <<"Area 3. Ciencias medicas y de la salud"<<endl
    <<"Area 4. Humanidades y ciencias de la conducta"<<endl
    <<"Area 5. Ciencias sociales"<<endl
    <<"Area 6. Biotecnologias y ciencias agropecuarias"<<endl
    <<"Area 7. Ingenierias"<<endl;
    cin>>opc;
    switch (opc){
        case 1:
            area="Fisico matematicas y ciencias de la tierra";
            break;
        case 2:
            area="Biologia y quimica";
            break;
        case 3:
            area="Ciencias medicas y de la salud";
            break;
        case 4:
            area="Humanidades y ciencias de la conducta";
            break;
        case 5:
            area="Ciencias sociales";
            break;
        case 6:
            area="Biotecnologias y ciencias agropecuarias";
            break;
        case 7:
            area="Ingenierias";
            break;
    }
    cout<<"Ingrese el nombre de la especialidad"<<endl;
    getline(cin,espec);
    cout<<"Ingrese el presupuesto del proyecto"<<endl;
    cin >> fondos;
    cout<<"Ingrese el nombre del encargado del proyecto"<<endl;
    cin.get();
    getline(cin,responsable);
    Wdoc << folio << "☘" << name << "☘" << area << "☘" << espec << "☘" << fondos << "☘" << responsable << "☘";
    Wdoc.close();

}

void metodos::lectura() {
    char cadena[255];
    ifstream Rdoc;
    char delimitador[] = "☘";
    Rdoc.open("test.txt" , ios::in);
    int cont=0;

    cout<<left<<setw(25)<<"Folio"<<setw(20)<<"Nombre del proyecto"<<setw(15)<<"Area de trabajo"<<setw(15)<<"Especializacion"<<setw(15)<<"Presupuesto"<<setw(20)<<"Responsable del proyecto"<<endl;
    do{
        Rdoc.getline(cadena, sizeof(cadena));
        char *token = strtok(cadena, delimitador);
        if(token != NULL){
            while(token != NULL){
                if(cont==0){
                    string aux=token;
                    stringstream aux1(aux);
                    aux1>>folio;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==1){
                    name=token;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==2){
                    area=token;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==3){
                    espec=token;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==4){
                    string aux=token;
                    stringstream aux1(aux);
                    aux1 >> fondos;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==5){
                    responsable=token;
                    token = strtok(NULL, delimitador);
                }
                cont=0;
                cout << left <<setw(25)<< folio << setw(20) << name << setw(15) << area << setw(15) << espec << setw(15) << fondos << setw(20) << responsable << endl;
            }
        }
    }while(!Rdoc.eof());
}

void metodos::lecturaEsp() {
    
}

#endif //PRACTICA1_ARCHIVO_H