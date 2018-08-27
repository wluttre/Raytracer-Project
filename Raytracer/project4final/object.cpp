/**********************************************************************
* Author: William Luttrell
* File: object.cpp
* Modified On: December 4, 2015
* Description: base implementation of the object class
***********************************************************************/

#include "object.h"

Object::Object()
{}
void Object::setColorR(int col, double value)
{
   if(col == 1)
      color1.R = value;
  else
      color2.R = value;
}

void Object::setColorG(int col, double value)
{
   if(col == 1)
      color1.G = value;
  else
      color2.G = value;
}

void Object::setColorB(int col, double value)
{
   if(col == 1)
      color1.B = value;
  else
      color2.B = value;
}

void Object::setChecker(bool checkerboard)
{
   this-> checkerboard = checkerboard;
}

void Object::setReflectivity(double reflectivity)
{
   this-> reflectivity = reflectivity;
}

COLOR_T Object::getColor1()
{
   return color1;
}

COLOR_T Object::getColor2()
{
   return color2;
}

bool Object::getChecker()
{
   return checkerboard;
}

double Object::getReflectivity()
{
   return reflectivity;
}

