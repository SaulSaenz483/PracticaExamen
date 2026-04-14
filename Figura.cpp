//
// Created by sauls on 12/04/2026.
//

#include "Figura.h"

Figura::Figura() {
    color = "Sin Definir";
}

Figura::Figura(string color) {
    this->color = color;
}

Figura::~Figura() {

}
string Figura::getColor() {
    return color;
}
