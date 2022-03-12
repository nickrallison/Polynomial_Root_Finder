//
// Created by nickr on 2022-03-02.
//

#ifndef ROOTFINDER_GUESSMATRIX_H
#define ROOTFINDER_GUESSMATRIX_H

#include <cmath>
#include <vector>
#include "complex.h"

// INFO
//   Sets up grid of complex numbers at a given spacing and a max radius
//   Used to iterate newtons method and look for convergence

class guessMatrix {
public:
    std::vector<complex> guesslist;
    int nperlen; //Side length of Grid (Number of points)
    double effectiveRad;
    double spacing;

    void initgm(double radius, double spacing0) {
        this->spacing = spacing0;
        this->nperlen = floor(2 * radius / spacing + 1); // Finds number of points along one side of grid
        this->effectiveRad = ((double) this->nperlen - 1) / 2 * this->spacing;
        for (double i = -1 * this->effectiveRad; i <= this->effectiveRad; i += this->spacing) {       // Vert
            for (double j = -1 * this->effectiveRad; j <= this->effectiveRad; j += this->spacing) {   // Horiz
                complex value;
                value.real = j;
                value.imag = i;
                guesslist.push_back(value);
            }
        }
    }
};

#endif //ROOTFINDER_GUESSMATRIX_H
