/*
 * =====================================================================================
 *
 *       Filename:  problm14.cpp
 *
 *    Description:  Last assigned problem in the c++ introduction
 *                  to create a triangle class representing triangles
 *
 *        Version:  1.0
 *        Created:  16/10/2014 07:55:52
 *       Revision:  none
 *       Compiler:  gcc
 *
 *         Author:  Lennart Wissel (lw), lennart.wissel@gmx.net
 *   Organization:  UoB
 *
 * =====================================================================================
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

// A simple class to represent triangles
class Triangle {
  public:
    // Constructors - default and explicit
    Triangle();
    Triangle(double x1in, double y1in, double x2in, double y2in, double x3in, double y3in);

    // Access methods
    double getPoint1X();
    double getPoint1Y();
    double getPoint2X();
    double getPoint2X();
    double getPoint3Y();
    double getPoint3Y();

    // More interesting methods
    double perimeter(Triangle& t);
    double area(Triangle& t);

  private:
    // Data
    double pt1x;
    double pt1y;
    double pt2x;
    double pt2y;
    double pt3x;
    double pt3y;
};

// The input and output functions are given for you!
istream& operator>>( istream& in, Triangle& tri );
ostream& operator<<( ostream& out, Triangle tri );

// SEVERAL MEMBER FUNCTION DEFINITIONS
Triangle::Triangle() {
  pt1x = 0.;
  pt1y = 0.;
  pt2x = 0.;
  pt2y = 0.;
  pt3x = 0.;
  pt3y = 0.;
}

Triangle::Triangle(double x1in, double y1in, double x2in, double y2in, double x3in, double y3in) {
  pt1x = x1in;
  pt1y = y1in;
  pt2x = x2in;
  pt2y = y2in;
  pt3x = x3in;
  pt3y = y3in;
}


double Triangle::perimeter(Triangle& t) {
	double ax, ay, bx, by, cx, cy;
	double a, b, c;
	
	ax = t.x1 - t.x2;
	ay	= t.y1 - t.y2;
	a = sqrt(ax*ax + ay*ay);
	
	bx = t.x2 - t.x3;
	by	= t.y2 - t.y3;
	b = sqrt(bx*bx + by*by);
	
	cx = t.x1 - t.x3;
	cy	= t.y1 - t.y3;
	c = sqrt(cx*cx + cy*cy);
	
	return a+b+c;
}

double Triangle::area(Triangle& t) {

}

int main ( ) {
   // Some test code for Triangle class
   // First read in the data;
   ifstream fileData( "data.txt" );
   vector<Triangle> triangleData;

   Triangle temp;
   while ( fileData >> temp )
   {
      triangleData.push_back(temp);
   }
   
   cout << endl;
   cout << "The first triangle is:   " << triangleData[0] << endl;
   cout << "The second triangle is:  " << triangleData[1] << endl;
   cout << "The last triangle is:    " << triangleData.back() << endl;
   cout << endl;

   double biggestPerim = 0;
   for ( int i = 0 ; i < triangleData.size() ; ++i )
   {
      double perim = triangleData[i].perimeter();
      if ( perim > biggestPerim )
      {
         biggestPerim = perim;
      }
   }
   cout << "The largest has a perimeter of: " << biggestPerim << endl;
   cout << endl;
   
   for ( int i = 0 ; i < triangleData.size() ; ++i )
   {
      cout << "The area of triangle: " << triangleData[i] << 
              "   is " << triangleData[i].area() << endl;
   }   
   cout << endl;
}

istream& operator>>( istream& in, Triangle& tri )
{
   double val1, val2, val3, val4, val5, val6 ;
   in >> val1;
   in >> val2;
   in >> val3;
   in >> val4;
   in >> val5;
   in >> val6;
   tri = Triangle( val1, val2, val3, val4, val5, val6 );
   return in;
}

ostream& operator<<( ostream& out, Triangle tri )
{
   out << "(" << tri.getPoint1X() << "," << tri.getPoint1Y() << ") ";
   out << "(" << tri.getPoint2X() << "," << tri.getPoint2Y() << ") ";
   out << "(" << tri.getPoint3X() << "," << tri.getPoint3Y() << ") ";
   return out;
}
