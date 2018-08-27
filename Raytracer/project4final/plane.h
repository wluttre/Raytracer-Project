/**********************************************************************
* Author: William Luttrell
* File: plane.h
* Modified On: December 4, 2015
* Description: class definition for plane.cpp
***********************************************************************/
#ifndef PLANE_H
#define PLANE_H

#include "vector.h"
#include "object.h"
class Plane: public Object {
   public:
   Plane();
   Plane(double, Vector);
   Plane(double, double, double, double);
   bool intersection(RAY_T&, Vector&, Vector&, double&);

   private:
   double D;
   Vector normal;
};
#endif
