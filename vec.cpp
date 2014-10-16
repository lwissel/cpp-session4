// VEC class selfmade from handout

#include <iostream>
#include <cmath>
#include <string>
using namespace std;

// Vec class represents a vector in 3d space
class Vec {
  private:
    double x, y, z; // internally cartesian

  public:
    Vec(double xin=0., double yin=0., double zin=0.); // Constructor

    // access functions
    double getx();
    double gety();
    double getz();
    double getr();
    double gettheta();
    double getphi();

    // a member function
    double dotp(Vec& v);

    // real operators
    Vec operator+(Vec& v);
    bool operator>(Vec& v);
};


// defie member functions and more
Vec::Vec(double xin, double yin, double zin) {
  x = xin;
  y = yin;
  z = zin;
}

double Vec::getx() { return x; }
double Vec::gety() { return y; }
double Vec::getz() { return z; }

double Vec::getr() {
  return sqrt(x*x + y*y + z*z);
}

double Vec::gettheta() {
  if (z==0) return M_PI/2.;
  else return atan(y/z);
}

double Vec::dotp(Vec& v) {
  return (this->getx()*v.getx(), this->gety()*v.gety(), this->getz()*v.getz());
}

Vec Vec::operator+(Vec& v) {
  return Vec(this->x+v.getx(), this->y+v.gety(), this->z+v.getz());
}

bool Vec::operator>(Vec& v) {
  return ( this->getr() > v.getr() );
}

int main () {
  Vec v1(1,1,1);
  Vec v2;

  v2 = Vec(1,0,0);

  cout << v2.getx();

}
