//
// Created by hamsuke on 02/03/20.
//

#ifndef PRACTICA1_ARCHIVO_H
#define PRACTICA1_ARCHIVO_H

#include <cstring>
#include <fstream>
#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
#include <algorithm>

using namespace std;

class metodos {
public:
    ofstream Indoc;

    void escritura();

    void lectura();

    void lecturaEsp();

    void addindex();
};

struct registro {
    string folio;
    string name;
    string area;
    string espec;
    string fondos;
    string responsable;
};
registro proyecto;

void metodos::escritura() {
    fstream reg;
    fstream index;
    int indice = 00;
    string tmp;
    srand(time(NULL));

    cout << "Ingrese nombre del proyecto" << endl;
    cin.get();
    getline(cin, proyecto.name);
    cout << "Seleccione el area de trabajo (ingrese el numero del area correspondiente)" << endl
         << "Area 1. Fisico matematicas y ciencias de la tierra" << endl
         << "Area 2. Biologia y quimica" << endl
         << "Area 3. Ciencias medicas y de la salud" << endl
         << "Area 4. Humanidades y ciencias de la conducta" << endl
         << "Area 5. Ciencias sociales" << endl
         << "Area 6. Biotecnologias y ciencias agropecuarias" << endl
         << "Area 7. Ingenierias" << endl;
    getline(cin, proyecto.area);
    cout << "Ingrese el nombre de la especialidad" << endl;
    getline(cin, proyecto.espec);
    cout << "Ingrese el presupuesto del proyecto" << endl;
    getline(cin, proyecto.fondos);
    cout << "Ingrese el nombre del encargado del proyecto" << endl;
    getline(cin, proyecto.responsable);

    tmp = proyecto.name.substr(0, 3);
    proyecto.folio = tmp + "-" + to_string(rand() % 100);
    tmp = proyecto.folio + "♣" + proyecto.name + "♣" + proyecto.area + "♣" + proyecto.espec + "♣" + (proyecto.fondos) +
          "♣" + proyecto.responsable + "♣";
    reg.open("test.txt",ios::app);
    index.open("Indice.txt",ios::app);
    index.seekg(0, ios::end);
    if (0 == index.tellg()) {
        reg << proyecto.folio << "♣" << proyecto.name << "♣" << proyecto.area << "♣" << proyecto.espec
            << "♣" << proyecto.fondos << "♣" << proyecto.responsable << endl;
        index << indice << "♣" << proyecto.folio << endl;
        index.close();
        reg.close();
    } else {
        reg << proyecto.folio << "♣" << proyecto.name << "♣" << proyecto.area << "♣" << proyecto.espec
            << "♣" << proyecto.fondos << "♣" << proyecto.responsable << endl;
        addindex();
    }

}

void metodos::addindex() {
    string auxs1;
    string auxs2;
    fstream indexr("Indice.txt", ios::in);
    int indice=0;
    do {
        getline(indexr, auxs1);
        cout << auxs1 << endl;
        indice++;
    }while (!indexr.eof());
    indexr.close();
    indexr.open("Indice.txt",ios::app);
    indexr << indice << "♣" << proyecto.folio << endl;
    indexr.close();
}

void metodos::lectura() {

}

void metodos::lecturaEsp() {

}

/*
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
*/
#endif //PRACTICA1_ARCHIVO_H