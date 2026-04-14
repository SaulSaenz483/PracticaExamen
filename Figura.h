//
// Created by sauls on 12/04/2026.
//

#ifndef PRACTICAEXAMEN_FIGURA_H
#define PRACTICAEXAMEN_FIGURA_H
using namespace std;
#include "iostream"

class Figura {

protected:
    string color;

public:

    Figura(string color);
    Figura();

    virtual ~Figura();
    virtual double area() const =0;

    string getColor();


};


#endif //PRACTICAEXAMEN_FIGURA_H