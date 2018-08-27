/**********************************************************************
* Author: William Luttrell
* File: box.cpp
* Modified On:December 4, 2015
* Description: implementation of class box
***********************************************************************/

#include "vector.h"
#include "rt.h"
#include "crt.h"
#include "box.h"

Box::Box()
{
  Vector *temp = new Vector (0,0,0);
  upperRight = *temp;
  lowerLeft = *temp;
}

Box::Box(Vector ll, Vector ur)
{
   upperRight = ur;
   lowerLeft = ll;
}


bool Box::intersection(RAY_T &ray, Vector &int_pt, Vector &normal, double &t)
{
   const Vector normalArray[6] = {Vector(-1,0,0), Vector(1,0,0), Vector(0,-1,0),
                                  Vector(0,1,0), Vector(0,0,-1), Vector(1,0,0)};
   double temp;
   double tNear = -1000;
   double tFar = 1000;
   double t1, t2;
   bool swapflag;
   int nindex = 0;
   int i;
   for(i = 0; i < 3; i++)
   {
      swapflag = false;

      if(i == 0)
      {
         if(ray.direction.getX() == 0)//ray is parallel
         {
            if(ray.origin.getX() < lowerLeft.getX() || ray.origin.getX() > upperRight.getX())
            {//no hit
               //return false;
            }
         }
         t1 = (lowerLeft.getX() - ray.origin.getX())/ray.direction.getX();
         t2 = (upperRight.getX() - ray.origin.getX())/ray.direction.getX();
      }
      else if(i == 1)
      {
         if(ray.direction.getY() == 0)//ray is parallel
         {
            if(ray.origin.getY() < lowerLeft.getY() || ray.origin.getY() > upperRight.getY())
            {//no hit
               //return false;
            }
         }
         t1 = (lowerLeft.getY() - ray.origin.getY())/ray.direction.getY();
         t2 = (upperRight.getY() - ray.origin.getY())/ray.direction.getY();
      }
      else if(i == 2)
      {
         if(ray.direction.getZ() == 0)//ray is parallel
         {
            if(ray.origin.getZ() < lowerLeft.getZ() || ray.origin.getZ() > upperRight.getZ())
            {//no hit
               //return false;
            }
         }
         t1 = (lowerLeft.getZ() - ray.origin.getZ())/ray.direction.getZ();
         t2 = (upperRight.getZ() - ray.origin.getZ())/ray.direction.getZ();
      }
      if(t1 > t2)
      {
         swapflag = true;
         temp = t1;
         t1 = t2;
         t2 = temp;
      }
      if(t1 > tNear)
      {
         tNear = t1;
         nindex = i*2 + swapflag;
      }
      if(t2 < tFar)
      {
         tFar = t2;
      }
      if(tNear > tFar)
      {
         return false;
      }
      if(tFar < 0)
      {
         return false;
      }
   }
   //where we set int_pt and normal
   t = tNear;
   int_pt = ray.origin+ray.direction * tNear;
   normal = normalArray[nindex];
   return true;

}

