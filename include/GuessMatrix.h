//
// Created by nickr on 2022-03-02.
//

#ifndef ROOTFINDER_GUESSMATRIX_H
#define ROOTFINDER_GUESSMATRIX_H

#include <cmath>
#include <vector>
#include "../include/ComplexType.h"

// INFO
//   Sets up grid of complex numbers at a given spacing and a max radius
//   Used to iterate newtons method and look for convergence

class GuessMatrix {
public:
    std::vector<Complex> guesslist;
    int nperlen; //Side length of Grid (Number of points)
    double effectiveRad;
    double spacing;

    void initgm(double radius, double spacing0);
};

#endif //ROOTFINDER_GUESSMATRIX_H
