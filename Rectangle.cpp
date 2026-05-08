//
// Created by amera on 10/16/2025.
//

#include "Rectangle.h"

#include <iostream>
#include <ostream>
#include <stdexcept>


Rectangle::Rectangle() : Parallelogram(4,nullptr) {
};


Rectangle::Rectangle(int s, Point *p) : Parallelogram(s,p) {

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

    if (almostEqual(dotProductAB_BC,0)) {
        x++;
    }

    if (almostEqual(dotProductBC_CD,0)) {
        x++;
    }
    if (almostEqual(dotProductCD_AD,0)) {
        x++;
    }
    if (almostEqual(dotProductAD_AB,0)) {
        x++;
    }

    if (x != 4) {
        std::cout<<x<< std::endl;
        throw std::invalid_argument("This shape is not a Rectangle Type");
    }

};


Rectangle::Rectangle(const Rectangle &other) : Parallelogram(other) {

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

    if (almostEqual(dotProductAB_BC,0)) {
        x++;
    }

    if (almostEqual(dotProductBC_CD,0)) {
        x++;
    }
    if (almostEqual(dotProductCD_AD,0)) {
        x++;
    }
    if (almostEqual(dotProductAD_AB,0)) {
        x++;
    }

    if (x != 4) {
        std::cout<<x<< std::endl;
        throw std::invalid_argument("This shape is not a Rectangle Type");
    }

};

//There is no point of a destructor here, as it is already using the virtual constructor from Polygon.
//Rectangle::~Rectangle() {};



