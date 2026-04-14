//
// Created by sauls on 12/04/2026.
//

#include "Circulo.h"

Circulo::Circulo() : Figura(), diametro(0.0) {
}

Circulo::Circulo(string color, double diametro) : Figura(color){
    this->diametro = diametro;
}

Circulo::~Circulo() {

}

double Circulo::area() const {
    double radio = diametro / 2.0;
    return 3.14 * radio * radio;
}
