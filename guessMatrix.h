//
// Created by nickr on 2022-03-02.
//

#ifndef ROOTFINDER_GUESSMATRIX_H
#define ROOTFINDER_GUESSMATRIX_H

#include <cmath>
#include <vector>
#include "complex.h"

class guessMatrix {
public:
    std::vector<complex> guesslist;
    int nperlen;
    double effecRad;
    double spacing;

    void initgm(double radius, double spacing0) {
        this->spacing = spacing0;
        this->nperlen = floor(2 * radius / spacing + 1);// max radius
        this->effecRad = ((double) this->nperlen - 1) / 2 * this->spacing;
        for (double i = -1 * this->effecRad; i <= this->effecRad; i += this->spacing) {       // Vert
            for (double j = -1 * this->effecRad; j <= this->effecRad; j += this->spacing) {   // Horiz
                complex value;
                value.real = j;
                value.imag = i;
                guesslist.push_back(value);
            }
        }
    }
};

#endif //ROOTFINDER_GUESSMATRIX_H
