//
// Created by nickr on 2022-03-02.
//

#ifndef ROOTFINDER_POLYNOMIAL_H
#define ROOTFINDER_POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <cmath>
#include "./ComplexType.h"
#include "./GuessMatrix.h"

// INFO
//   Implements polynomial class alongside related methods and
//   to use newtons method in its internal guessMatrix obj to find roots of the above polynomial

class Polynomial {
public:
    int order;
    int badpdiv = 0;
    std::vector<Complex> pml;
    std::vector<Complex> derivative;
    std::vector<Complex> rootList;
    std::vector<Complex> officialRootList;
    GuessMatrix gm;
    GuessMatrix roots;

    void initPML();

    void printpml();

    void printderiv();

    Complex pmlvalue(Complex z);

    Complex derivvalue(Complex z);

    Complex newtonsGuess(Complex z0);

    void iterateGuessMatrix();

    void convergenceTest();

    void printgm();

    Complex findARoot(Complex z0);

    Complex pruneListFromRoot(Complex z, double radius);

    void cleanRoots();

    void printRoots();
};


#endif //ROOTFINDER_POLYNOMIAL_H
