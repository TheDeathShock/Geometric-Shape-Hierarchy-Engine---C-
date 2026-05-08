#include <iomanip>
#include <iostream>

#include "Parallelogram.h"
#include "Point.h"
#include "Polygon.h"
#include "Quadrilateral.h"
#include "Rectangle.h"
#include "Rhombus.h"
#include "Square.h"
#include "Trapezoid.h"
#include "testDriver.h"

using namespace std;

int main() {


    testDriver::testPolygon();
    testDriver::testQuadrilateral();
    testDriver::testRhombus();
    testDriver::testNumberOfPassedTestFunctions();



    return 0;
}