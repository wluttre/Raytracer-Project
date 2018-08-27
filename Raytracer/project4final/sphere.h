/**********************************************************************
* Author: William Luttrell
* File: sphere.h
* Modified On: December 4, 2015
* Description: class definition for sphere.cpp
***********************************************************************/
#ifndef SPHERE_H
#define SPHERE_H

#include "vector.h"
#include "object.h"
class Sphere: public Object {
   public:
   Sphere();
   Sphere(double, Vector);
   Sphere(double, double, double, double);
   bool intersection(RAY_T&, Vector&, Vector&, double&);

   private:
   double radius;
   Vector ctr;
};
#endif
