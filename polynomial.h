//
// Created by nickr on 2022-03-02.
//

#ifndef ROOTFINDER_POLYNOMIAL_H
#define ROOTFINDER_POLYNOMIAL_H

#define SMALLSTEP 0.001
#define CONVERGERAD 0.0001

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
    std::vector<complex> rootList;
    guessMatrix gm;
    guessMatrix roots;

    void initPML() {
        std::cout << "Enter Order: ";
        std::cin >> this->order;
        std::cout << "\n";
        std::cout << "Enter Terms Highest to Lowest Order\n x^2 + 3x + 2 --> 1, 3, 2\n";
        complex term;
        this->gm.initgm(10, 0.05);


        for (int i = 0; i <= order; i++) {
            std::cout << "Real Part of Term: ";
            std::cin >> term.real;
            pml.push_back(term);
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
        double margin = 5;
        if (mag(div(polyVal, polyPrimeVal)) > margin) {
            z1.badIteration = 1;
            return z1;
        }
        z1 = addition(z0, scalar(-1, div(polyVal, polyPrimeVal)));
        if (mag(scalar(-1, div(polyVal, polyPrimeVal))) < SMALLSTEP) {
            z1.smallStep = 1;
        }
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

    void convergenceTest() {
        complex root;
        complex iteration;
        root.real = 0;
        root.imag = 0;
        iteration.real = 0;
        iteration.imag = 0;
        for (int i = 0; i < this->gm.guesslist.size(); i++) {
            if (this->gm.guesslist[i].smallStep == 1) {             //Finds first small iteration in list
                root = this->gm.guesslist[i];                       //Small Number close to root
                this->roots.guesslist.push_back(root);
            }
        }
    }

    void printgm() {
        for (int i = 0; i < this->gm.guesslist.size(); i++) {
            this->gm.guesslist[i].printz();
        }
    }

    complex findARoot(complex z0) {
        double precision = 0.000001;
        double stepSize = 1;
        complex prevGuess;
        complex currentGuess = z0;              // Make a guess of the root, pretend its a circle,
                                        // position it on a point, if the point exits the circle,
                                        // it moves to the new point, if it doesn't consider every point in that circle
                                        // Newtons iterate those points
                                        // Shrink Circle at one point
        while (stepSize > precision) {
            prevGuess = currentGuess;
            currentGuess = newtonsGuess(currentGuess); //Watch for
            if (currentGuess.badIteration == 1) {
                //break?
            }
            stepSize = mag(sub(currentGuess, prevGuess));
        }
        return currentGuess;
    }
    complex pruneListFromRoot(complex z, double radius) {
        int j = 0;
        for (int i = 0; i < this->roots.guesslist.size(); i++) {
            if (mag(sub(z, this->roots.guesslist[i - j])) < radius) {
                this->roots.guesslist.erase(this->roots.guesslist.begin() + i - j);
                j++;
            }
        }
        return z;
    }

    void cleanRoots() {
        complex root;
        for (int i = 0; this->roots.guesslist.size() > order; i++) {
            root = findARoot(this->roots.guesslist[0]);
            this->roots.guesslist.push_back(pruneListFromRoot(root, 0.05));
        }
        this->rootList = this->roots.guesslist;
    }

    void printRoots() {
        for (int i = 0; i < this->rootList.size(); i++) {
            this->rootList[i].printz();
        }
    }
};


#endif //ROOTFINDER_POLYNOMIAL_H
