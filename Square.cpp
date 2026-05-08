//
// Created by amera on 10/16/2025.
//

#include "Square.h"

#include <stdexcept>


Square::Square(): Rectangle(4,nullptr) {
};

Square::Square(int s, Point *p) : Rectangle(s, p) {

    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);

    double dotProductAB_BC = AB[0] * BC[0] + AB[1] * BC[1];
    double dotProductBC_CD = BC[0] * CD[0] + BC[1] * CD[1];
    double dotProductCD_AD = CD[0] * AD[0] + CD[1] * AD[1];
    double dotProductAD_AB = AB[0] * AD[0] + AB[1] * AD[1];

    int x = 0;

    if (getShorterSide() != getLongerSide()) {
        throw std::invalid_argument("This shape is not a square");
    }

};

Square::Square(const Square &other) : Rectangle(other) {

    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);

    double dotProductAB_BC = AB[0] * BC[0] + AB[1] * BC[1];
    double dotProductBC_CD = BC[0] * CD[0] + BC[1] * CD[1];
    double dotProductCD_AD = CD[0] * AD[0] + CD[1] * AD[1];
    double dotProductAD_AB = AB[0] * AD[0] + AB[1] * AD[1];

    int x = 0;

    if (getShorterSide() != getLongerSide()) {
        throw std::invalid_argument("This shape is not a square");
    }
}

//There is no point of a destructor here, as it is already using the virtual constructor from Polygon.

//Square::~Square() {};


double Square::getSide() {
    return getLongerSide(); //Doesn't matter if we return the longer side or shorter side, as both of them must be the same length.
}



