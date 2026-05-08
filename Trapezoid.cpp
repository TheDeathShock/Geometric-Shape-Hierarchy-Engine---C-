//
// Created by amera on 10/15/2025.
//

#include "Trapezoid.h"
#include <vector>
#include <cmath>
#include <stdexcept>


bool Trapezoid::isParallel(const double vec1[], const double vec2[]) { //This function checks if the two given vectors of a trapezoid are parallel or not.

    double crossProduct = vec1[0]*vec2[1] - vec1[1]*vec2[0]; //CrossProduct is basically the cross product of 2 vectors, from MATH 204(Linear Algebra), we know that the cross product of 2 vectors must be zero for the 2 vectors to be parallel.

    const double EOM = 0.00000001; //Basically, we need the cross product to be almost 0, not exactly zero, as exactly zero may give us problems due to double rounding and precision.

    if (fabs(crossProduct)<EOM) {
        return true;
    }else {
        return false;
    }

    //I created a small error of margin which may be caused during rounding and precision errors.

}

Trapezoid::Trapezoid() : Quadrilateral(4,nullptr)
{};

Trapezoid::Trapezoid(int s, Point *p) : Quadrilateral(4,p) {

    //These are basically the vectors of each line segment of the shape.
    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);

    if((!(AB_CD_isParallel || BC_AD_isParallel)) || (AB_CD_isParallel && BC_AD_isParallel)) { //A shape can be trapezoid if and only if there exists only 2 sides that are parallel. In other words, if all sides are parallel, then it is not a trapezoid, or if noo sides are parallel, then its also not a trapezoid.
        throw std::invalid_argument("The array of points you entered does not belong to a trapezoid, please try again.");
    }

    if (size != 4) {
        throw std::invalid_argument("ERROR: A Trapezoid must only have 4 vertices.");
    };
};

Trapezoid::Trapezoid(const Trapezoid &other) : Quadrilateral(other) , shorterSide(other.shorterSide), longerSide(other.longerSide) {

    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);

    if(!(AB_CD_isParallel || BC_AD_isParallel)) {
        throw std::invalid_argument("The array of points you entered does not belong to a trapezoid, please try again.");
    }
    if (size != 4) {
        throw std::invalid_argument("ERROR: A Trapezoid must only have 4 vertices.");
    };


};

//There is no point of a destructor here, as it is already using the virtual constructor from Polygon.

//Trapezoid::~Trapezoid() {}


double Trapezoid::getMagnitude(const double vec[]){
    return sqrt(vec[0]*vec[0] + vec[1]*vec[1]);
};



double Trapezoid::getLongerSide() const {

    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};


    double lsAB;
    double lsBC;
    double lsCD;
    double lsAD;

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);

    if(!(AB_CD_isParallel || BC_AD_isParallel)) {
        throw std::invalid_argument("The array of points you entered does not belong to a trapezoid, please try again.");
    }
    if (AB_CD_isParallel && BC_AD_isParallel) {
        throw std::invalid_argument("ERROR: The shape is not a trapezoid");
    }


    if (AB_CD_isParallel) {
        lsAB = getMagnitude(AB);
        lsCD = getMagnitude(CD);

        if (lsAB > lsCD) {
            return lsAB;
        }
        else if (lsCD > lsAB) {
            return lsCD;
        }else {
            return lsAB; //This should never be the case
        }
    }
    if (BC_AD_isParallel) {
        lsBC = getMagnitude(BC);
        lsAD = getMagnitude(AD);
        if (lsBC > lsAD) {
            return lsBC;
        }else if (lsAD > lsBC) {
            return lsAD;
        }else {
            return lsBC;
        }
    }

throw std::logic_error("Unknown Error"); //This part should never be reached due to contructor limitations, but I have to put it so the program compiles.
}


double Trapezoid::getShorterSide() const {

    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};


    double ls;
    double lsAB;
    double lsBC;
    double lsCD;
    double lsAD;

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);

    if (AB_CD_isParallel) {
        lsAB = getMagnitude(AB);
        lsCD = getMagnitude(CD);

        if (lsAB < lsCD) {
            return lsAB;
        }
        else if (lsCD < lsAB) {
            return lsCD;
        }else {
            return lsAB;
        }
    }
    if (BC_AD_isParallel) {
        lsBC = getMagnitude(BC);
        lsAD = getMagnitude(AD);
        if (lsBC < lsAD) {
            return lsBC;
        }else if (lsAD < lsBC) {
            return lsAD;
        }else {
            return lsBC;
        }
    }

    if(!(AB_CD_isParallel || BC_AD_isParallel)) {
        throw std::invalid_argument("The array of points you entered does not belong to a trapezoid, please try again.");
    }

    throw std::logic_error("Unknown Error"); //This part should never be reached due to contructor limitations, but I have to put it so the program compiles.

};

