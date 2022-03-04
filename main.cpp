#include <iostream>
#include <vector>
#include "polynomial.h"

int main() {
    polynomial pml;
    pml.initPML();

    pml.iterateGuessMatrix();
    pml.iterateGuessMatrix();
    pml.iterateGuessMatrix();
    pml.iterateGuessMatrix();
    pml.iterateGuessMatrix();

    //complex z0, z1, z2;
    //z0.real = 1;
    //z0.imag = 1;
    //z1.real = 1;
    //z1.imag = 1;
    //z2 = pml.newtonsGuess(z0);
    //z2 = pml.newtonsGuess(z2);
    //z2.printz();

    pml.printgm();

    return 0;
}

