//
// Created by nickr on 2022-03-02.
//

#ifndef ROOTFINDER_COMPLEX_H
#define ROOTFINDER_COMPLEX_H

// INFO
//   Implements arithmetic operations for complex number class

class Complex {
public:
    double real = 0;
    double imag = 0;
    int smallStep = 0;
    int badIteration = 0;


    void printz();
};

Complex addition(Complex z1, Complex z2);

Complex sub(Complex z1, Complex z2);

Complex mult(Complex z1, Complex z2);

Complex exp(int n, Complex z);


Complex conj(Complex z);

Complex scalar(double scalar, Complex z);

double mag(Complex z);

Complex div(Complex z1, Complex z2);


bool err(Complex z);


#endif //ROOTFINDER_COMPLEX_H
