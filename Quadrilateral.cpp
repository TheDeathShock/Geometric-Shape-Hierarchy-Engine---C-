//
// Created by amera on 10/13/2025.
//

#include "Quadrilateral.h"

#include <iostream>
#include <stdexcept>

using namespace std;

Quadrilateral::Quadrilateral() : Polygon(4,nullptr) {
};
Quadrilateral::Quadrilateral(int s, Point *p) : Polygon(s, p) {

        if (size != 4) {
            throw invalid_argument("ERROR: A quadrilateral must only have only 4 vertices.");
        };
    }


Quadrilateral::Quadrilateral(const Quadrilateral &other) : Polygon(other) {


    if (size != 4) {
        throw invalid_argument("ERROR: A quadrilateral must only have 4 vertices.");
    };
}

//There is no point of a destructor here, as it is already using the virtual constructor from Polygon.
//Quadrilateral::~Quadrilateral() {}






/*
 *  NOTE: There is no need to redefine and reimplement the stuff that are already inherited from the parent class (Polygon).
 */


