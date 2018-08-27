/**********************************************************************
* Author: William Luttrell
* File: object.h
* Modified On: December 4, 2015
* Description: Object definitions and prototype statements
***********************************************************************/
#ifndef OBJECT_H
#define OBJECT_H

#include <ostream>
#include "rt.h"
#include "crt.h"

class Object {
public:
   Object();

   virtual bool intersection(RAY_T&, Vector&, Vector&, double&){};

   void setColorR(int, double);
   void setColorG(int, double);
   void setColorB(int, double);
   void setChecker(bool);
   void setReflectivity(double);

   COLOR_T getColor1();
   COLOR_T getColor2();
   bool getChecker();
   double getReflectivity();

   private:

   bool checkerboard;
   COLOR_T color1;
   COLOR_T color2;
   double reflectivity;
};

#endif
