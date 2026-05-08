//
// Created by amera on 10/16/2025.
//

#include "testDriver.h"

#include <iostream>
using namespace std;

int testDriver::totalNumberOfTestFunctions = 3;
int testDriver::numberOfPassedTestFunctions = 0;

double testDriver::testPolygon() {
cout<<"\n_________________Polygon Test________________\n" << endl;
    int x = 0;

    Polygon poly;

    poly.setPoint(0,Point(7,1));
    poly.setPoint(1,Point(8,5));
    poly.setPoint(2,Point(5,4));
    poly.setPoint(3,Point(2,5));
    poly.setPoint(4,Point(1,1));


    if (Polygon::almostEqual(poly.area(), 21)) {
        cout << "Polygon Test PASSED" << endl;
        cout<< "Polygon Area is: " << poly.area() << endl;

        numberOfPassedTestFunctions++;
        return poly.area();
    }else{
    cout << "Polygon Test FAILED" << endl;
        cout << poly.area() << endl;
        poly.display();
        return -1;
    }


};

double testDriver::testQuadrilateral() {

    cout<<"\n__________________Quadrilateral Test________________\n" << endl;

    Quadrilateral quad;

    quad.setPoint(0,Point(1,1));
    quad.setPoint(1,Point(5,2));
    quad.setPoint(2,Point(4,6));
    quad.setPoint(3,Point(0,4));


    if (Polygon::almostEqual(quad.area(), 15.5)) {
        cout << "Quadrilateral Test: PASSED" << endl;
        cout<< "Quadrilateral Area is: " << quad.area() << endl;

        numberOfPassedTestFunctions++;
        return quad.area();
    }else {
        cout << "Quadrilateral Test: FAILED" << endl;
        return -1;
    }

}

double testDriver::testRhombus() {
    cout<<"\n__________________Rhombus Test________________\n" << endl;


    Parallelogram rhomb;


    rhomb.setPoint(0,Point(6,0));
    rhomb.setPoint(1,Point(0,-8));
    rhomb.setPoint(2,Point(-6,0));
    rhomb.setPoint(3,Point(0,8));




    if ( Polygon::almostEqual(rhomb.area(),96) && Polygon::almostEqual(rhomb.getLongerSide(), 10) && Polygon::almostEqual(rhomb.getShorterSide(),10) && Polygon::almostEqual(rhomb.getAcuteAngleInRadians(),1.2870022175866)) {
        cout << "Rhombus Test: PASSED" << endl;
        cout<< "Rhombus Area is: " << rhomb.area() << endl;
        cout<<"Rhombus Longer side is: " << rhomb.getLongerSide() << endl;
        cout<<"Rhombus Shorter side is: " << rhomb.getShorterSide() << endl;
        cout<<"Rhombus Acute Angle in Radians is: " << rhomb.getAcuteAngleInRadians() << endl;
        numberOfPassedTestFunctions++;
        return rhomb.area();
    }else {

        return -1;
    }

}

void testDriver::testNumberOfPassedTestFunctions() {
    cout <<"\n\nThe number of PASSED test functions is: " << numberOfPassedTestFunctions  << " / " << totalNumberOfTestFunctions  <<endl;
    cout <<"The number of FAILED test functions is: " << totalNumberOfTestFunctions - numberOfPassedTestFunctions  << " / " << totalNumberOfTestFunctions  <<endl;

}





