//
// Created by amera on 10/16/2025.
//

#include "Rhombus.h"

#include <stdexcept>

Rhombus::Rhombus(): Parallelogram(4, nullptr) {
};
Rhombus::Rhombus(int s, Point *p):Parallelogram(s,p){

    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};


    double lsAB = getMagnitude(AB);
    double lsBC = getMagnitude(BC);
    double lsCD = getMagnitude(CD);
    double lsAD = getMagnitude(AD);

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);


    if (!((almostEqual(lsAB,lsBC)) && (almostEqual(lsAB,lsCD)) && (almostEqual(lsAB,lsAD)))) {
        throw std::invalid_argument("ERROR: The array of points you inputted doesn't represent a Rhombus type shape"); // A rhombus must have equal sides length

    }

};


Rhombus::Rhombus(const Rhombus &other):Parallelogram(other){
    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};


    double lsAB = getMagnitude(AB);
    double lsBC = getMagnitude(BC);
    double lsCD = getMagnitude(CD);
    double lsAD = getMagnitude(AD);

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);


    if (!((almostEqual(lsAB,lsBC)) && (almostEqual(lsAB,lsCD)) && (almostEqual(lsAB,lsAD)))) {
        throw std::invalid_argument("ERROR: The array of points you inputted doesn't represent a Rhombus type shape"); // A rhombus must have equal sides length

    }
};

//There is no point of a destructor here, as it is already using the virtual constructor from Polygon.

//Rhombus::~Rhombus() {}

double Rhombus::getSide() {
    return getLongerSide(); //Doesn't matter if we return longer side or shorter side, as both should be equal.
}



//Everything is inherited from the parent class, this child class has no new unique features associated with it.


