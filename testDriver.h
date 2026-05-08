//
// Created by amera on 10/16/2025.
//

#ifndef TESTDRIVER_H
#define TESTDRIVER_H

#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Trapezoid.h"
#include "Parallelogram.h"
#include "Rhombus.h"
#include "Rectangle.h"
#include "Square.h"


class testDriver {

    static int totalNumberOfTestFunctions;
    static int numberOfPassedTestFunctions;


public:
    static double testPolygon();
    static double testQuadrilateral();
    static double testRhombus();
    static void testNumberOfPassedTestFunctions();





};



#endif //TESTDRIVER_H
