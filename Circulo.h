//
// Created by sauls on 12/04/2026.
//

#ifndef PRACTICAEXAMEN_CIRCULO_H
#define PRACTICAEXAMEN_CIRCULO_H
#include "Figura.h"

class Circulo : public Figura{
private:
    double diametro;

public:

    Circulo();
    Circulo(string color, double diametro);
    ~Circulo();

    double area() const override;



};


#endif //PRACTICAEXAMEN_CIRCULO_H