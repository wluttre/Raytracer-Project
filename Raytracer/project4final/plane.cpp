/**********************************************************************
* Author: William Luttrell
* File: plane.cpp
* Modified On:December 4, 2015
* Description: implementation of class plane
***********************************************************************/

#include "vector.h"
#include "rt.h"
#include "crt.h"
#include "plane.h"
#include <math.h>

Plane::Plane()
{
   D = 0.0;
   Vector *temp = new Vector();
   normal = *temp;
}

Plane::Plane(double d, Vector v2)
{
   D = d;
   normal = v2;
}

Plane::Plane(double d, double x, double y, double z)
{
   D = d;
   Vector *temp = new Vector(x, y, z);
   normal = *temp;
}


bool Plane::intersection(RAY_T &ray, Vector &int_pt, Vector &normal, double &t)
{
   double dot;
   dot = this->normal.dot(ray.direction);

   if(dot == 0)
   {
      return false;
   }

   t = -(this->normal.dot(ray.origin) + D) / dot;

   if(t < 0)
   {
      return false;
   }
   int_pt = ray.origin + ray.direction * t;

   normal = this->normal;
   return true;
}

