/**********************************************************************
* Author: William Luttrell
* File: box.h
* Modified On: December 4, 2015
* Description: class definition for box.cpp
***********************************************************************/
#ifndef BOX_H
#define BOX_H

#include "vector.h"
#include "object.h"
class Box: public Object {
   public:
   Box();
   Box(Vector, Vector);
   bool intersection(RAY_T&, Vector&, Vector&, double&);

   private:
   Vector upperRight;
   Vector lowerLeft;
   RAY_T ray;
};
#endif
