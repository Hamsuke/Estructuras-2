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
#include <ctime>
#include <algorithm>

using namespace std;

//Clase con todos los metodos utilizados en el programa
class metodos {
public:
    //Metodo de escritura principal dentro de este se llaman las funciones para añadir a los archivos de indice
    void escritura();
    void addindex();
    void addindex2(int &);

    //Los metodos de lectura y lecturaesp son las busquedas por folio y area respectivamente
    bool lectura();
    void lecturaEsp();

    //El metodo trim limpia las cadenas de caracteres como espacios y saltos de linea
    string rtrim(string&);
};

//El struct normal del programa almacena toda la informacion antes de mandarla a los archivos
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
    //objetos archivo
    fstream reg;
    fstream index;
    //variables locales para el funcionamiento de los metodos
    string tmp;
    //Randomizador
    srand(time(NULL));
    //Aqui empeiza el proceso de registro de proyecto, cada funcion cin.get() se usa para evitar que se brinque algun paso
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
    int opc=0;
    cin>>opc;
    if(opc>7 or opc<1){
        cout<<"Opcion no valida, vuelva a intentar"<<endl;
        cin>>opc;
    }
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
    cout << "Ingrese el nombre de la especialidad" << endl;
    getline(cin, proyecto.espec);
    cout << "Ingrese el presupuesto del proyecto" << endl;
    getline(cin, proyecto.fondos);
    cout << "Ingrese el nombre del encargado del proyecto" << endl;
    getline(cin, proyecto.responsable);
    //Aqui conluye la interaccion del usuario

    //Las siguientes lineas pertenecen al proceso de adicion de archivo
    proyecto.folio=proyecto.name.substr(0, 3);
    proyecto.folio += "-" + to_string(rand() % 100);
    reg.open("test.txt",ios::app);
    index.open("Indice.txt",ios::app);

    //Comprueba que el archivo este vacio si es asi añade los registros al inicio del archivo
    index.seekg(0, ios::end);
    if (0 == index.tellg()) {
        reg << proyecto.folio << "♣" << proyecto.name << "♣" << proyecto.area << "♣" << proyecto.espec
            << "♣" << proyecto.fondos << "♣" << proyecto.responsable << endl;
        index << 1 << "♣" << proyecto.folio << endl;
        addindex2(opc);
        index.close();
        reg.close();
    } else {
        //Si el archivo de indices principal no esta vacio pasa a esta seccion donde llama ambos metodos de indexado
        reg << proyecto.folio << "♣" << proyecto.name << "♣" << proyecto.area << "♣" << proyecto.espec
            << "♣" << proyecto.fondos << "♣" << proyecto.responsable << endl;
        addindex();
        addindex2(opc);
    }
    //Muestra el folio para poder buscarlo en la opcion 2 del menu
    cout<<"El proyecto se registro correctamente su folio es "<<proyecto.folio<<endl;
}

//Este metodo añade al indexado de folios
void metodos::addindex() {
    //Variables locales para el funcionamiento del metodo
    string auxs1;
    string auxs2;
    //Archivo objetivo y metodo de apertura
    fstream indexr("Indice.txt", ios::in);
    int indice=0;
    //El bucle revisara todo el archivo hasta llegar al final y en cada iteracion aumentara el valor del indice para que al momento de ingresarlo en el archivo su valor sea secuencial es decir 1,2,3,4....etc
    do {
        getline(indexr, auxs1);
        indice++;
    }while (!indexr.eof());
    //El archivo deber cerrado en este punto porque la apertura inicial se hizo en modo lectura y no permitiria escribir en el
    indexr.close();
    //Se vuelve a abrir el archivo esta vez en modo escritura y situamos el puntero al final del archivo
    indexr.open("Indice.txt",ios::app);
    indexr << indice << "♣" << proyecto.folio << endl;
    indexr.close();
}

//este metodo añade el indexado por areas con 3 referencias y funciona de una manera muy similar al otro metodo
void metodos::addindex2(int &opc) {
    //Variables locales
    string aux1;
    string aux2;
    int aux01;
    //Objeto archivo
    fstream indexsec("Indicesec.txt", ios::app);
    fstream auxF("temp.txt", ios::app);
    //Revisa que el fichero de indexado este vacio y si es asi le añade de forma inmediata las areas
    indexsec.seekg(0, ios::end);
    if (0 == indexsec.tellg()) {
        indexsec
        <<"Fisico matematicas y ciencias de la tierra"<<"♣"<<endl
        <<"Biologia y quimica"<<"♣"<<endl
        <<"Ciencias medicas y de la salud"<<"♣"<<endl
        <<"Humanidades y ciencias de la conducta"<<"♣"<<endl
        <<"Ciencias sociales"<<"♣"<<endl
        <<"Biotecnologias y ciencias agropecuarias"<<"♣"<<endl
        <<"Ingenierias"<<"♣"<<endl;
    }
    indexsec.close();
    //Vuelve a abrir el archivo esta vez en modo de lectura y lo empieza a copiar a un archivo temporal
    indexsec.open("Indicesec.txt", ios::in);
    for(int i=1;i<=7;i++){
        getline(indexsec, aux1);
        //En cada iteracion del for toma una linea del archivo y la subdivide
        aux01 = aux1.find("♣");
        aux2 = aux1.substr(0, aux01);
        //si la subdivision es igual a el area que eligio el usuario cuando guardo su archivo le añade los campos correspondientes a la cadena
        if (aux2 == proyecto.area) {
            aux1 += proyecto.folio + "♣" + proyecto.name + "♣" + proyecto.responsable+"♣";
        }
        auxF << aux1 << endl;
    }
    indexsec.close();
    //borra el archivo viejo
    remove("Indicesec.txt");
    auxF.close();
    //cambia el nombre del archivo temporal por el del archivo que acaba de ser eliminado
    rename("temp.txt", "Indicesec.txt");
    //Esta funcion la deje porque en lugar de cambiar el nombre lo estaba copiando con un nombre nuevo y el archivo temporal viejo no permitia el correcto funcionamiento en futuras añadiduras
    remove("temp.txt");
}

//Metodo de busqueda por folio
bool metodos::lectura() {
    //Objeto archivo en modo de lectura
    fstream indice("Indice.txt", ios::in);
    fstream datos("test.txt",ios::in);
    //variables locales
    string busqueda;
    string aux1;
    string aux2;
    string aux3;
    int cont=0;
    int trebol1;

    cin.get();
    cout<<"Ingrese el folio del proyecto a buscar (debe ser escrito de la misma manera que se le mostro al momento de registrarlo)"<<endl;
    getline(cin, busqueda);
    do{
        //Empieza a leer lineas delarchivo de indices
        getline(indice, aux1);
        trebol1 = aux1.find("♣", 0);
        aux3 = aux1.substr(trebol1+3);
        //Realiza la comparacion entre la cadena introucida por el usuario y la cadena que esta manipulando el programa en esa parte del proceso
        //Los metodos rtrim reciben ambas cadenas y las limpian de cualquier caracter no necesario para que la comparacion sea mas precisa
        //si las cadenas comparadas son iguales asume que la busqueda del usuario es valida y empieza a revisar el archivo principal
        if(rtrim(aux3)==rtrim(busqueda)){
            //El for tiene una cantidad de ciclos limitada que es regulada por el if, cada vez que el if no entra aumenta incrementa el contador que es el que le informa al for en que indice parar
            //la inicializacion en 0 de dicho contador asegura que aunque el registro este en el primer indice este sera encontrado
            for(int i=0; i<=cont; i++){
                getline(datos, aux2);
                //Cuando el for alcanza el final dde su ciclo la cadena que se esta manipulando en ese momento es la que contiene la informacion que se esta buscando y se entra al ciclo if
                if(cont==i){
                    //En el if la cadena empieza a ser descompuesta en multiples partes que son asignadas a variables dichas descomposiciones parten de la posicion 0 de la cadena hasta la posicion del trebol + 3 posiciones
                    //esta manera asegura que el ruido del trebol se elimina porque el compilador lo interpreta como 3 caracteres en lugar de 1
                    trebol1=aux2.find("♣",0);
                    proyecto.folio=aux2.substr(0,trebol1);
                    aux2=aux2.substr(trebol1+3);

                    trebol1=aux2.find("♣",0);
                    proyecto.name=aux2.substr(0,trebol1);
                    aux2=aux2.substr(trebol1+3);

                    trebol1=aux2.find("♣",0);
                    proyecto.area=aux2.substr(0,trebol1);
                    aux2=aux2.substr(trebol1+3);

                    trebol1=aux2.find("♣",0);
                    proyecto.espec=aux2.substr(0,trebol1);
                    aux2=aux2.substr(trebol1+3);

                    trebol1=aux2.find("♣",0);
                    proyecto.fondos=aux2.substr(0,trebol1);
                    aux2=aux2.substr(trebol1+3);

                    trebol1=aux2.find("♣",trebol1+1);
                    proyecto.responsable=aux2.substr(0,trebol1);

                    //Finalmente muestra una fila con los campos del registros y los valores de las variables
                    cout<<left<<setw(10)<<"Folio"<<setw(20)<<"N. Proyecto"<<setw(25)<<"Responsable"<<setw(15)<<"Especialidad"<<setw(15)<<"Fondos"<<setw(30)<<"Area"<<endl;
                    cout<<left<<setw(10)<<proyecto.folio<<setw(20)<<proyecto.name<<setw(25)<<proyecto.responsable<<setw(15)<<proyecto.espec<<setw(15)<<proyecto.fondos+" MXN"<<setw(30)<<proyecto.area<<endl;
                    return true;
                }
            }
        } else{
                //si no entra al if  aumenta el contador avisando que en esa entrada de registro no se encontraba el folio
                cont++;
        }

    }while (!indice.eof());
}

void metodos::lecturaEsp() {
    //Variables locales
    int opc=0;
    int trebol1;
    int verify;
    string aux2;
    //El uso del char resulto mejor que el trebol entre comillas
    char delim[]="♣";
    //Apertura del archivo en modo lectura
    fstream indice("Indicesec.txt",ios::in);
    cout<<"Ingrese el area que desea revisar"<<endl
    <<"1.Fisico matematicas y ciencias de la tierra"<<endl
    <<"2.Biologia y quimica"<<endl
    <<"3.Ciencias medicas y de la salud"<<endl
    <<"4.Humanidades y ciencias de la conducta"<<endl
    <<"5.Ciencias sociales"<<endl
    <<"6.Biotecnologias y ciencias agropecuarias"<<endl
    <<"7.Ingenierias"<<endl;
    cin>>opc;
    cin.get();
    //Se imprimen en pantallo los campos de refrencia del proyecto
    cout<<left<<setw(10)<<"Folio"<<setw(30)<<"N. Proyecto"<<setw(25)<<"Responsable"<<setw(30)<<"Area"<<endl;
    //Los ciclos de for  estan limitados a la cantidad de areas
    for(int i=0; i<opc; i++){
        //Recibe la caena del archivo en la que debe venir el area y sus contenidos
        getline(indice, aux2);
        //Cuando el for alcanza el area necesaria empieza a descomponer la cadena como el otro metodo de busqueda pero esta vez con menos campos
        if(opc==i+1){
            //Ya que el area solo se extrae una vez es lo primero que toma para la descomposicion y esa variable permanecera intacta el resto del proceso
            trebol1 = aux2.find(delim, 0);
            proyecto.area = aux2.substr(0, trebol1);
            aux2 = aux2.substr(trebol1 + 3);
            do {
                trebol1 = aux2.find(delim, 0);
                proyecto.folio = aux2.substr(0, trebol1);
                aux2 = aux2.substr(trebol1 + 3);

                trebol1 = aux2.find(delim, 0);
                proyecto.name = aux2.substr(0, trebol1);
                aux2 = aux2.substr(trebol1 + 3);

                trebol1 = aux2.find(delim, 0);
                proyecto.responsable = aux2.substr(0, trebol1);
                aux2 = aux2.substr(trebol1 + 3);

                cout << left << setw(10) << proyecto.folio << setw(30) << proyecto.name << setw(25) << proyecto.responsable <<setw(30)<<proyecto.area<< endl;
                verify=aux2.length();
            }while (verify>10);
            }
        }
}

//Este metodo tiene como unica funcion limpiar las cadenas para compararlas y evitar cualquier clase de ruido que de un falso negativo
string metodos::rtrim(string& s){
    string WHITESPACE = " \n\r\t\f\v";
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

#endif //PRACTICA1_ARCHIVO_H