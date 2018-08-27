/**********************************************************************
* Author: William Luttrell
* File: vector.h
* Modified On: December 4, 2015
* Description: class definition for vector.cpp
***********************************************************************/
#ifndef VECTOR_H
#define VECTOR_H

#include <ostream>

class Vector {
public:
   Vector();
   Vector(double, double, double);
   ~Vector();

   Vector operator+(const Vector&);
   Vector operator-(const Vector&);
   Vector operator*(const Vector&);
   Vector& operator+=(const Vector&);
   Vector& operator-=(const Vector&);
   Vector operator*(double);
   Vector operator/(double);

   double magnitude();
   Vector normalize();
   double dot(const Vector&);

   void set(double, double, double);
   double addAllValues();
   int floorVector();

   double getX();
   double getY();
   double getZ();

   private:
   double x;
   double y;
   double z;
};

#endif
