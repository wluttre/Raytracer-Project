/**********************************************************************
* Author: William Luttrell
* File: sphere.cpp
* Modified On: December 4, 2015
* Description: implementation of class sphere
***********************************************************************/

#include "vector.h"
#include "rt.h"
#include "crt.h"
#include "sphere.h"
#include <math.h>

Sphere::Sphere()
{
   radius = 0.0;
   Vector *temp = new Vector();
   ctr = *temp;
}

Sphere::Sphere(double r, Vector v2)
{
   radius = r;
   ctr = v2;
}

Sphere::Sphere(double r, double x, double y, double z)
{
   radius = r;
   Vector *temp = new Vector(x,y,z);
   ctr = *temp;
}

//test intersection between the ray and the sphere, saves data values in int_pt and 
//normal for illuminate function, return true if intersection is true, false if false.
bool Sphere::intersection(RAY_T &ray, Vector &int_pt, Vector &normal, double &t)
{
    //used to calculate t through the quadratic formula
    double A, B, C;
    //the discriminant of A, B, and C. Used to test sphere intersection and calculate t
    double discrim;
    //scalar distance to intersections with sphere
    double t0, t1;

    A = 1;

    B = 2 * (ray.direction * (ray.origin - ctr)).addAllValues();

    C = ((ray.origin - ctr) * (ray.origin - ctr)).addAllValues() - pow(radius, 2);

    discrim = pow(B, 2) - (4*A*C);

    //if ray misses sphere
    if(discrim <= 0)
    {
       return false;
    }


    // compute intersection points between ray and sphere
    t0 = (B*-1 - sqrt(discrim)) / (2*A);
    t1 = (B*-1 + sqrt(discrim)) / (2*A);
    // test for intersection that is not in view
    if ( t0 <= 0 && t1 <= 0)
       return false;

    if(t0 <= 0)
       t = t1;

    else if(t1 <= 0)
       t = t0;
    else
       t = fmin(t0,t1);
    //set intersection and normal values for illuminate method
    int_pt = ray.origin + ray.direction * t;

    normal = (int_pt - ctr) / radius;

    return true;
}

