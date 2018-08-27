/**********************************************************************
* Author: William Luttrell
* File: light.cpp
* Modified On: December 4, 2015
* Description: implementation of class light
***********************************************************************/

#include "light.h"
#include <math.h>
#include <stdio.h>


Light::Light()
{
   Vector *temp = new Vector();
   location = *temp;
   lightColor.R = 1.0;
   lightColor.G = 1.0;
   lightColor.B = 1.0;
}

Light::Light(Vector v2, COLOR_T lightColor)
{
   location = v2;
   this->lightColor = lightColor;
}

Light::Light(double x, double y, double z, COLOR_T lightColor)
{
   Vector *temp = new Vector(x, y, z);
   location = *temp;
   this->lightColor = lightColor;
}



//tests to see if the current object is in shadow, and therefore does not 
//require diffuse and specular lighting
bool Light::testShadow(Vector& int_pt, Vector& normal, SCENE_T& scene, int& closest_obj)
{
   RAY_T shadow_ray;

   shadow_ray.origin = int_pt;

   shadow_ray.direction = location - int_pt;
   shadow_ray.direction = shadow_ray.direction.normalize();

   Vector dummy_int_pt;
   Vector dummy_normal;
   double dummy_t;

   int obj_index;

   //tests to see if any other objects are in between the current object and the light source
   for(obj_index = 0; obj_index < NUM_OBJS; obj_index++)
   {
      if(closest_obj != obj_index)
      {
         if(scene.objs[obj_index]->intersection(shadow_ray, dummy_int_pt, dummy_normal, dummy_t))
         {
            return true;
         }
      }
   }

   return false;
}

//apply diffuse, ambient and specular lighting to the object, returns the color value of each pixel
COLOR_T Light::illuminate(RAY_T& ray, Vector& int_pt, Vector& normal, SCENE_T& scene,
                          int& closest_obj, COLOR_T color, COLOR_T obj_color)
{
    //vector used to calculate diffuse light values
   Vector L;

   //vector used to calculate specular light values
   Vector R;

   //place holder for dot product values.
   double dot_products;

   double atten;

  
   if(!testShadow(int_pt, normal, scene, closest_obj))
   {
      //diffuse light

      L = location - int_pt;

      double distance_L = L.magnitude();

      L = L.normalize();
      dot_products = normal.dot(L);

      //light attenuation

      atten = 1 / ( distance_L * distance_L * .002 +
                 distance_L * .02 + .2 );

      if(dot_products > 0)
      {
         color.R += dot_products * obj_color.R * atten * lightColor.R;
         color.G += dot_products * obj_color.G * atten * lightColor.G;
         color.B += dot_products * obj_color.B * atten * lightColor.B;

         //specular light

         R = L - (normal * (dot_products* 2));
         R = R.normalize();
         dot_products = R.dot(ray.direction);

         if(dot_products > 0)
         {
            color.R += pow(dot_products, 100) * atten * lightColor.R;
            color.G += pow(dot_products, 100) * atten * lightColor.G;
            color.B += pow(dot_products, 100) * atten * lightColor.B;
         }
      }
   }
   /*else
   {
      color.R = 0.0;
      color.G = 0.0;
      color.B = 0.0;
   }*/
  return color;
}
