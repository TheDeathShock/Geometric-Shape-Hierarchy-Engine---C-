//
// Created by amera on 10/15/2025.
//

#include "Parallelogram.h"

#include <cmath>
#include <iostream>
#include <stdexcept>
#include <bits/stl_algo.h>

using namespace std;

bool Parallelogram::isParallel(const double vec1[], const double vec2[]) { //This function checks if the two given vectors of a parallelogram are parallel or not.

    double crossProduct = vec1[0]*vec2[1] - vec1[1]*vec2[0];

    const double EPS = 0.00000001;

    if (fabs(crossProduct)<EPS) {
        return true;
    }else {
        return false;
    }

    //I created a small error of margin which may be caused during rounding and precision errors.
}


Parallelogram::Parallelogram() : Quadrilateral(4,nullptr) {
};
Parallelogram::Parallelogram(int s, Point *p) : Quadrilateral(s, p) {

    if (size != 4) {
        throw invalid_argument("ERROR: A parallelogram type shape must only have 4 vertices.");
    };

    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};



    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);

    if (!((AB_CD_isParallel && BC_AD_isParallel))) {
        throw invalid_argument("ERROR: The array of points you inputted doesn't represent a parallelogram type");
    }

}


Parallelogram::Parallelogram(const Parallelogram &other) : Quadrilateral(other) {


    if (size != 4) {
        throw invalid_argument("ERROR: A parallelogram type shape must only have 4 vertices.");
    };

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

    if (!(AB_CD_isParallel && BC_AD_isParallel)) {
        throw invalid_argument("ERROR: The array of points you inputted doesn't represent a parallelogram type");
    }

};

//There is no point of a destructor here, as it is already using the virtual constructor from Polygon.

//Parallelogram::~Parallelogram() {}




double Parallelogram::getMagnitude(const double vec[]){
    return sqrt(vec[0]*vec[0] + vec[1]*vec[1]);
};



double Parallelogram::getLongerSide() const {
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



    //There is no need to use 4 variables for the length comparaison, as we already know that mag(AB) = mag(CD) since they are parallel, and the same applies to mag(BC) and mag(AD)
    if (lsAB > lsBC) {
        return lsAB;
    }else if (lsBC > lsAB) {
        return lsBC;
    }else {
        return lsAB;
    }
}



double Parallelogram::getShorterSide() const {
    double AB[2] = {(points[1].getXCoordinate() - points[0].getXCoordinate()), (points[1].getYCoordinate() - points[0].getYCoordinate())};
    double BC[2] = {points[2].getXCoordinate() - points[1].getXCoordinate(), points[2].getYCoordinate() - points[1].getYCoordinate()};
    double CD[2] = {points[3].getXCoordinate() - points[2].getXCoordinate() , points[3].getYCoordinate() - points[2].getYCoordinate()};
    double AD[2] = {points[0].getXCoordinate() - points[3].getXCoordinate() , points[0].getYCoordinate() - points[3].getYCoordinate()};


    double longestLength;
    double lsAB = getMagnitude(AB);
    double lsBC = getMagnitude(BC);
    double lsCD = getMagnitude(CD);
    double lsAD = getMagnitude(AD);

    bool AB_CD_isParallel = isParallel(AB,CD);
    bool BC_AD_isParallel = isParallel(BC,AD);


    //There is no need to use 4 variables for the length comparaison, as we already know that mag(AB) = mag(CD) since they are parallel, and the same applies to mag(BC) and mag(AD)
    if (lsAB < lsBC) {
        return lsAB;
    }else if (lsBC < lsAB) {
        return lsBC;
    }else {
        return lsAB;
        //If they are equal, then it can return any, it won't matter.
    }
}


double Parallelogram::getAcuteAngleInRadians() const {

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


    //I am using MATH 204 Linear Algebra knowledge.
    double dotProduct1 = AB[0]*BC[0] + AB[1]*BC[1];
    double cosineTheta1 = dotProduct1/((lsAB * lsBC));
    cosineTheta1 = std::clamp(cosineTheta1, -1.0, 1.0); // This line is very important, this is to make sure that the value of cosing is always within the range of [-1,1], so we don't get an error and our program crashes.
    double angleInRadians1 = acos(cosineTheta1);

    //We know that a parallelogram can have a maximum of 2 different angles, so if the angle that we get is not acute, then the acute one will be the one not acute subtracted or added by pi.
    if (angleInRadians1 > M_PI/2) {
        return M_PI - angleInRadians1;
    }else {
        return angleInRadians1;
    }

}
