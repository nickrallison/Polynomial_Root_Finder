//
// Created by nickr on 2022-03-02.
//

#ifndef ROOTFINDER_POLYNOMIAL_H
#define ROOTFINDER_POLYNOMIAL_H

#include <iostream>
#include <vector>
#include <cmath>
#include "complex.h"
#include "guessMatrix.h"

class polynomial {
public:
    int order;
    std::vector<complex> pml;
    std::vector<complex> derivative;
    guessMatrix gm;

    void initPML() {
        std::cout << "Enter Order: ";
        std::cin >> this->order;
        std::cout << "\n";
        std::cout << "Enter Terms Highest to Lowest Order\n x^2 + 3x + 2 --> 1, 3, 2\n";
        complex term1;
        complex term2;
        complex term3;
        this->gm.initgm(1.5, 0.1);
        term1.real = 1;
        term2.real = 0;
        term3.real = 1;
        pml.push_back(term1);
        pml.push_back(term2);
        pml.push_back(term3);


        for (int i = 0; i <= order; i++) {
            //std::cout << "Real Part of Term: ";
            //std::cin >> term.real;
            //std::cout << "Imaginary Part of Term: ";
            //std::cin >> term.imag;
            //pml.push_back(term);
        }

        for (int i = 0; i < this->pml.size() - 1; i++) {
            this->derivative.push_back(scalar(this->pml.size() - 1 - i, pml[i]));
        }
    }

    void printpml() {
        for (int i = 0; i < this->pml.size(); i++) {
            pml[i].printz();
        }
    }

    void printderiv() {
        for (int i = 0; i < this->derivative.size(); i++) {
            derivative[i].printz();
        }
    }

    complex pmlvalue(complex z) {
        complex value;
        value.real = 0;
        value.imag = 0;
        for (int i = 0; i < this->pml.size(); i++) {
            value = addition(mult(exp(this->pml.size() - 1 - i, z), pml[i]), value);
        }
        return value;
    }
    complex derivvalue(complex z) {
        complex value;
        value.real = 0;
        value.imag = 0;
        for (int i = 0; i < this->derivative.size(); i++) {
            value = addition(mult(exp(this->derivative.size() - 1 - i, z), derivative[i]), value);
        }
        return value;
    }

    complex newtonsGuess(complex z0) { // Test if P'(z0) = 0
        complex z1;
        complex polyPrimeVal = derivvalue(z0);
        complex polyVal = pmlvalue(z0);
        double margin = 0.1;
        if (mag(polyPrimeVal) < margin) {
            z1.real = ERRORTERM;
            z1.imag = ERRORTERM;
            return z1;
        }
        z1 = addition(z0, scalar(-1, div(polyVal, polyPrimeVal)));
        return z1;
    }
    void iterateGuessMatrix() {
        int j = 0;
        for (int i = 0; i < this->gm.guesslist.size(); i++) {
            complex z1;
            z1 = newtonsGuess(this->gm.guesslist[i - j]);
            if (err(z1)) {
                this->gm.guesslist.erase(this->gm.guesslist.begin() + i - j);
                j++;
            }
            else {
                this->gm.guesslist[i - j] = z1;
            }
        }

    }

    void printgm() {
        for (int i = 0; i < this->gm.guesslist.size(); i++) {
            this->gm.guesslist[i].printz();
        }
    }
};


#endif //ROOTFINDER_POLYNOMIAL_H
