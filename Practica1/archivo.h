//
// Created by victo on 28/02/2020.
//

#ifndef PRACTICA1_ARCHIVO_H
#define PRACTICA1_ARCHIVO_H

#include <string>

class datos{
private:
    int folio;
    std::string nombre;
    int area;
    std::string espec;
    float presupuesto;
    std::string responsable;

public:
    void setfolio(int &);
    void setnombre(std::string &);
    void setarea(int &);
    void setespec(std::string &);
    void setpresup(float &);
    void setresp(std::string &);

    int getfolio();
    std::string getnombre();
    int getarea();
    std::string getespec();
    float getpresup();
    std::string getresponsable();
};

void datos::setfolio(int &i){
    folio=i;
}

void datos::setnombre(std::string &i) {
    nombre=i;
}

void datos::setarea(int &i) {
    area=i;
}

void datos::setespec(std::string &i) {
    espec=i;
}

void datos::setpresup(float &i) {
    presupuesto=i;
}

void datos::setresp(std::string &i) {
    responsable=i;
}

int datos::getfolio() {
    return folio;
}

std::string datos::getnombre() {
    return nombre;
}

int datos::getarea() {
    return area;
}

std::string datos::getespec() {
    return espec;
}

float datos::getpresup() {
    return presupuesto;
}

std::string datos::getresponsable() {
    return responsable;
}

#endif //PRACTICA1_ARCHIVO_H
