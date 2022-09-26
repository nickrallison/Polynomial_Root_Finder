//
// Created by nickr on 2022-03-02.
//

// INFO
//   Implements arithmetic operations for Complex number class

#include <iostream>
#include <cmath>

#include "../include/ComplexType.h"

void Complex::printz() {
    std::cout << this->real << " + " << this->imag << 'i' << '\n';
}

Complex addition(Complex z1, Complex z2) {
    Complex result;
    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}

Complex sub(Complex z1, Complex z2) {
    Complex result;
    result.real = z1.real - z2.real;
    result.imag = z1.imag - z2.imag;
    return result;
}

Complex mult(Complex z1, Complex z2) {
    Complex result;
    result.real = z1.real * z2.real - z1.imag * z2.imag;
    result.imag = z1.real * z2.imag + z2.real * z1.imag;
    return result;
}

Complex exp(int n, Complex z) {
    Complex result;
    result.real = 1;
    result.imag = 0;
    for (int i = 0; i < n; i++) {
        result = mult(z, result);
    }
    return result;
}


Complex conj(Complex z) {
    Complex result;
    result.real = z.real;
    result.imag = -1 * z.imag;
    return result;
}

Complex scalar(double scalar, Complex z) {
    Complex result;
    result.real = scalar * z.real;
    result.imag = scalar * z.imag;
    return result;
}

double mag(Complex z) {
    double result = sqrt(z.real * z.real + z.imag * z.imag);
    return result;
}

Complex div(Complex z1, Complex z2) {
    Complex result;
    result = scalar(pow(mag(z2), -2), mult(z1, conj(z2)));
    return result;
}


bool err(Complex z) {
    // INFO
    //   Used in newtons iteration, set to one when step size should be infinite

    if (z.badIteration == 1) {
        return 1;
    }
    return 0;
}

