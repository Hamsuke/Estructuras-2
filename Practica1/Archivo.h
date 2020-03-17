//
// Created by hamsuke on 02/03/20.
//

#ifndef PRACTICA1_ARCHIVO_H
#define PRACTICA1_ARCHIVO_H

#include <cstdio>
#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;

class metodos{
public:
    ofstream Indoc;
    void escritura();
    void lectura();
    void lecturaEsp();
};

struct registro{
    string namearch;
    string folio;
    string name;
    string area;
    string espec;
    float fondos;
    string responsable;
    string llave;
};
registro proyecto;

void metodos::escritura(){
    fstream reg;
    fstream index;
    int opc=0;
    cout<<"Ingrese un nombre para el archivo (no puede contener espacios ni caracteres especiales, la terminacion sera .txt y la añadira el programa)"<<endl;
    cin>>proyecto.namearch;
    proyecto.namearch+=".txt";
    reg.open(proyecto.namearch , ios::app);
    cout<<"Ingrese nombre del proyecto"<<endl;
    cin.get();
    getline(cin,proyecto.name);
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
            proyecto.area="Fisico matematicas y ciencias de la tierra";
            break;
        case 2:
            proyecto.area="Biologia y quimica";
            break;
        case 3:
            proyecto.area="Ciencias medicas y de la salud";
            break;
        case 4:
            proyecto.area="Humanidades y ciencias de la conducta";
            break;
        case 5:
            proyecto.area="Ciencias sociales";
            break;
        case 6:
            proyecto.area="Biotecnologias y ciencias agropecuarias";
            break;
        case 7:
            proyecto.area="Ingenierias";
            break;
    }
    cin.get();
    cout<<"Ingrese el nombre de la especialidad"<<endl;
    getline(cin,proyecto.espec);
    cout<<"Ingrese el presupuesto del proyecto"<<endl;
    cin >> proyecto.fondos;
    cout<<"Ingrese el nombre del encargado del proyecto"<<endl;
    cin.get();
    getline(cin,proyecto.responsable);
    reg << proyecto.folio << "☘" << proyecto.name << "☘" << proyecto.area << "☘" << proyecto.espec << "☘" << proyecto.fondos << "☘" << proyecto.responsable << "☘"<<endl;
    reg.close();

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
                    aux1>>proyecto.folio;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==1){
                    proyecto.name=token;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==2){
                    proyecto.area=token;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==3){
                    proyecto.espec=token;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==4){
                    string aux=token;
                    stringstream aux1(aux);
                    aux1 >> proyecto.fondos;
                    cont++;
                    token = strtok(NULL, delimitador);
                }
                if(cont==5){
                    proyecto.responsable=token;
                    token = strtok(NULL, delimitador);
                }
                cont=0;
                cout << left <<setw(25)<< proyecto.folio << setw(20) << proyecto.name << setw(15) << proyecto.area
                << setw(15) << proyecto.espec << setw(15) << proyecto.fondos << setw(20) << proyecto.responsable << endl;
            }
        }
    }while(!Rdoc.eof());
}

void metodos::lecturaEsp() {
    
}

#endif //PRACTICA1_ARCHIVO_H