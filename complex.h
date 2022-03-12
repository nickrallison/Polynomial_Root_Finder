//
// Created by nickr on 2022-03-02.
//

#ifndef ROOTFINDER_COMPLEX_H
#define ROOTFINDER_COMPLEX_H

// INFO
//   Implements arithmetic operations for complex number class

class complex {
public:
    double real = 0;
    double imag = 0;
    int smallStep = 0;
    int badIteration = 0;


    void printz() {
        std::cout << this->real << " + " << this->imag << 'i' << '\n';
    }
};

complex addition(complex z1, complex z2) {
    complex result;
    result.real = z1.real + z2.real;
    result.imag = z1.imag + z2.imag;
    return result;
}
complex sub(complex z1, complex z2) {
    complex result;
    result.real = z1.real - z2.real;
    result.imag = z1.imag - z2.imag;
    return result;
}

complex mult(complex z1, complex z2) {
    complex result;
    result.real = z1.real * z2.real - z1.imag * z2.imag;
    result.imag = z1.real * z2.imag + z2.real * z1.imag;
    return result;
}

complex exp(int n, complex z) {
    complex result;
    result.real = 1;
    result.imag = 0;
    for (int i = 0; i < n; i++) {
        result = mult(z, result);
    }
    return result;
}


complex conj(complex z) {
    complex result;
    result.real = z.real;
    result.imag = -1 * z.imag;
    return result;
}

complex scalar(double scalar, complex z) {
    complex result;
    result.real = scalar * z.real;
    result.imag = scalar * z.imag;
    return result;
}

double mag(complex z) {
    double result = sqrt(z.real * z.real + z.imag * z.imag);
    return result;
}

complex div(complex z1, complex z2) {
    complex result;
    result = scalar(pow(mag(z2), -2), mult(z1, conj(z2)));
    return result;
}


bool err(complex z) {
    // INFO
    //   Used in newtons iteration, set to one when step size should be infinite
    // REQUIRES
    //
    // PROMISES
    //

    if (z.badIteration == 1) {
        return 1;
    }
    return 0;
}



#endif //ROOTFINDER_COMPLEX_H
