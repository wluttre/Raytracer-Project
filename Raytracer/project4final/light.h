/**********************************************************************
* Author: William Luttrell
* File: light.h
* Modified On: December 4, 2015
* Description: class definition for light.cpp
***********************************************************************/
#ifndef LIGHT_H
#define LIGHT_H

#include "vector.h"
#include "rt.h"
#include "crt.h"
#include "scene.h"
#include "object.h"


class Light {
   public:
   Light();
   Light(Vector, COLOR_T);
   Light(double, double, double, COLOR_T);
   COLOR_T illuminate(RAY_T&, Vector&, 
                      Vector&, SCENE_T&, int&, COLOR_T, COLOR_T);

   private:
   Vector location;
   bool testShadow(Vector&, Vector&, SCENE_T&, int&);
   COLOR_T lightColor;
};
#endif
