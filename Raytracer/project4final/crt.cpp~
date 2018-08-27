/**********************************************************************
* Author: William Luttrell
* File: rt.cpp
* Modified On: December 4, 2015
* Description: implementation of the main file
***********************************************************************/

#include "crt.h"
#include "sphere.h"
#include "light.h"
#include "plane.h"
#include "box.h"

#include<iostream>
#include<fstream>

using namespace std;


COLOR_T doLighting(RAY_T& ray, Vector& int_pt, Vector& normal, SCENE_T& scene,
                   int& closest_obj)
{
   COLOR_T light_color;
   COLOR_T color;
   COLOR_T obj_color;
   COLOR_T paramColor;

   //texturing plane
   if(scene.objs[closest_obj]->getChecker())
   {
      if(int_pt.floorVector() & 1)
      {
         obj_color = scene.objs[closest_obj]->getColor1();
      }
      else
      {
         obj_color = scene.objs[closest_obj]->getColor2();
      }
   }

   else
   {
      obj_color = scene.objs[closest_obj]->getColor1();
   }
   //ambient light

   color.R = 0.1 * obj_color.R;
   color.G = 0.1 * obj_color.G;
   color.B = 0.1 * obj_color.B;

   paramColor.R = 0;
   paramColor.G = 0;
   paramColor.B = 0;


   for(int i = 0; i < NUM_LIGHTS; i++)
   {
      light_color = scene.light[i]->illuminate(ray, int_pt, normal, scene,
                                               closest_obj, paramColor, obj_color);
      color.R += light_color.R;
      color.G += light_color.G;
      color.B += light_color.B;
   }
   return color;
}



//returns the color of the current pixel, testing for object intersection and calling illuminate
COLOR_T trace(SCENE_T scene, RAY_T ray, int depth, int curr_obj)
{
   if(depth >= 5)
   {
      COLOR_T endrec;
      endrec.R = 0.0;
      endrec.G = 0.0;
      endrec.B = 0.0;
      return endrec;
   }
   //vector indicating sphere intersection at a pixel location
   Vector int_pt;
   //the normal vector of the sphere at a pixel location
   Vector normal;

   int i;
   int closest_obj = -1;

   double closest_t = 1000;
   double t = 0;

   Vector closest_int_pt;
   Vector closest_normal;

   COLOR_T trace_color;
   trace_color.R = 0.1;
   trace_color.G = 0.1;
   trace_color.B = 0.1;

   COLOR_T local_color;

   COLOR_T refl_color;
   RAY_T reflected_ray;


   for(i = 0; i < NUM_OBJS; i++)
   {

      if(scene.objs[i]->intersection(ray, int_pt, normal, t) == 1 && curr_obj != i)
         {
            if(t<closest_t)
            {
               closest_t = t;
               closest_int_pt = int_pt;
               closest_normal = normal;
               closest_obj = i;
            }
         }
   }
   if(closest_obj >= 0)
   {
      double reflectivity = scene.objs[closest_obj]->getReflectivity();
      //check for reflectivity
      if(reflectivity > 0)
      {
         reflected_ray.origin = closest_int_pt;
         reflected_ray.direction = ray.direction - closest_normal *
                                  (2 * (closest_normal.dot(ray.direction)));
         reflected_ray.direction = reflected_ray.direction.normalize();

         refl_color = trace(scene, reflected_ray, depth+1, closest_obj);
      }
      if(reflectivity < 1)
      {
         //call illuminate
         local_color = doLighting(ray, closest_int_pt, closest_normal,
                                  scene, closest_obj);
      }
      trace_color.R = refl_color.R*(reflectivity) +
                      local_color.R*(1 - reflectivity);
      trace_color.G = refl_color.G*(reflectivity) +
                      local_color.G*(1 - reflectivity);
      trace_color.B = refl_color.B*(reflectivity) +
                      local_color.B*(1 - reflectivity);
   }
   return trace_color;
}

//initializes the scene
void init(SCENE_T *scene)
{
   scene -> objs = new Object*[NUM_OBJS];
   scene -> light = new Light*[NUM_LIGHTS];
   Sphere *sphere;
   Plane *plane;
   Box *box;
   Vector *temp, *temp2;

   COLOR_T lightColor;

   //1: sphere values
   temp = new Vector(0.0, 0.25, 3.15);
   sphere = new Sphere(0.7,*temp);
   scene -> objs[0] = sphere;

   scene -> objs[0]->setColorR(1, 0.8);
   scene -> objs[0]->setColorG(1, 0.8);
   scene -> objs[0]->setColorB(1, 0.8);


   scene -> objs[0]->setColorR(2, 0.0);
   scene -> objs[0]->setColorG(2, 0.0);
   scene -> objs[0]->setColorB(2, 0.0);

   scene -> objs[0]->setChecker(false);

   scene -> objs[0]->setReflectivity(1.0);
   

   //2: sphere values
   temp = new Vector(0.0, -1.0, 3.15);
   sphere = new Sphere(0.6,*temp);
   scene -> objs[1] = sphere;

   scene -> objs[1]->setColorR(1, 0.0);
   scene -> objs[1]->setColorG(1, 0.3);
   scene -> objs[1]->setColorB(1, 0.0);


   scene -> objs[1]->setColorR(2, 0.0);
   scene -> objs[1]->setColorG(2, 0.0);
   scene -> objs[1]->setColorB(2, 0.0);

   scene -> objs[1]->setChecker(false);

   scene -> objs[1]->setReflectivity(0.0);

   //3: plane values
   temp = new Vector(0.0, 1.0, 0.0);
   plane = new Plane(0.9, *temp);
   scene -> objs[2] = plane;

   scene -> objs[2]->setColorR(1, 0.7);
   scene -> objs[2]->setColorG(1, 0.7);
   scene -> objs[2]->setColorB(1, 0.7);

   scene -> objs[2]->setColorR(2, 0.3);
   scene -> objs[2]->setColorG(2, 0.3);
   scene -> objs[2]->setColorB(2, 0.3);

   scene -> objs[2]->setChecker(true);

   scene -> objs[2]->setReflectivity(0.9);

   //4: box values
   temp = new Vector(0.5, -0.9, 2.3);
   temp2 = new Vector(0.9, -0.5, 3.0);
   box = new Box(*temp, *temp2);
   scene -> objs[3] = box;

   scene -> objs[3]->setColorR(1, 0.3);
   scene -> objs[3]->setColorG(1, 0.3);
   scene -> objs[3]->setColorB(1, 0.3);

   scene -> objs[3]->setColorR(2, 0.0);
   scene -> objs[3]->setColorG(2, 0.0);
   scene -> objs[3]->setColorB(2, 0.0);

   scene -> objs[3]->setChecker(false);

   scene -> objs[3]->setReflectivity(0.5);


   //5: box values
   temp = new Vector(-0.9, -0.9, 2.3);
   temp2 = new Vector(-0.5, -0.5, 3.0);
   box = new Box(*temp, *temp2);
   scene -> objs[4] = box;

   scene -> objs[4]->setColorR(1, 0.3);
   scene -> objs[4]->setColorG(1, 0.3);
   scene -> objs[4]->setColorB(1, 0.3);

   scene -> objs[4]->setColorR(2, 0.0);
   scene -> objs[4]->setColorG(2, 0.0);
   scene -> objs[4]->setColorB(2, 0.0);

   scene -> objs[4]->setChecker(false);

   scene -> objs[4]->setReflectivity(0.5);

   //6: box values
   temp = new Vector(0.5, -0.9, 3.3);
   temp2 = new Vector(0.9, -0.5, 4.0);
   box = new Box(*temp, *temp2);
   scene -> objs[5] = box;

   scene -> objs[5]->setColorR(1, 0.3);
   scene -> objs[5]->setColorG(1, 0.3);
   scene -> objs[5]->setColorB(1, 0.3);

   scene -> objs[5]->setColorR(2, 0.0);
   scene -> objs[5]->setColorG(2, 0.0);
   scene -> objs[5]->setColorB(2, 0.0);

   scene -> objs[5]->setChecker(false);

   scene -> objs[5]->setReflectivity(0.5);


   //7: box values
   temp = new Vector(-0.9, -0.9, 3.3);
   temp2 = new Vector(-0.5, -0.5, 4.0);
   box = new Box(*temp, *temp2);
   scene -> objs[6] = box;

   scene -> objs[6]->setColorR(1, 0.3);
   scene -> objs[6]->setColorG(1, 0.3);
   scene -> objs[6]->setColorB(1, 0.3);

   scene -> objs[6]->setColorR(2, 0.0);
   scene -> objs[6]->setColorG(2, 0.0);
   scene -> objs[6]->setColorB(2, 0.0);

   scene -> objs[6]->setChecker(false);

   scene -> objs[6]->setReflectivity(0.5);

   //8: sphere values
   temp = new Vector(0.7, -0.5, 2.65);
   sphere = new Sphere(0.2,*temp);
   scene -> objs[7] = sphere;

   scene -> objs[7]->setColorR(1, 0.8);
   scene -> objs[7]->setColorG(1, 0.8);
   scene -> objs[7]->setColorB(1, 0.8);


   scene -> objs[7]->setColorR(2, 0.0);
   scene -> objs[7]->setColorG(2, 0.0);
   scene -> objs[7]->setColorB(2, 0.0);

   scene -> objs[7]->setChecker(false);

   scene -> objs[7]->setReflectivity(1.0);
   

   //9: sphere values
   temp = new Vector(-0.7, -0.5, 2.65);
   sphere = new Sphere(0.2,*temp);
   scene -> objs[8] = sphere;

   scene -> objs[8]->setColorR(1, 0.8);
   scene -> objs[8]->setColorG(1, 0.8);
   scene -> objs[8]->setColorB(1, 0.8);


   scene -> objs[8]->setColorR(2, 0.0);
   scene -> objs[8]->setColorG(2, 0.0);
   scene -> objs[8]->setColorB(2, 0.0);

   scene -> objs[8]->setChecker(false);

   scene -> objs[8]->setReflectivity(1.0);

   //10: sphere values
   temp = new Vector(0.7, -0.5, 3.65);
   sphere = new Sphere(0.2,*temp);
   scene -> objs[9] = sphere;

   scene -> objs[9]->setColorR(1, 0.8);
   scene -> objs[9]->setColorG(1, 0.8);
   scene -> objs[9]->setColorB(1, 0.8);


   scene -> objs[9]->setColorR(2, 0.0);
   scene -> objs[9]->setColorG(2, 0.0);
   scene -> objs[9]->setColorB(2, 0.0);

   scene -> objs[9]->setChecker(false);

   scene -> objs[9]->setReflectivity(1.0);
   

   //11: sphere values
   temp = new Vector(-0.7, -0.5, 3.65);
   sphere = new Sphere(0.2,*temp);
   scene -> objs[10] = sphere;

   scene -> objs[10]->setColorR(1, 0.8);
   scene -> objs[10]->setColorG(1, 0.8);
   scene -> objs[10]->setColorB(1, 0.8);


   scene -> objs[10]->setColorR(2, 0.0);
   scene -> objs[10]->setColorG(2, 0.0);
   scene -> objs[10]->setColorB(2, 0.0);

   scene -> objs[10]->setChecker(false);

   scene -> objs[10]->setReflectivity(1.0);

   //LIGHTS

   //Light 1
   lightColor.R = 0.7;
   lightColor.G = 0.7;
   lightColor.B = 0.7;
   scene -> light[0] = new Light(-10.0, 10.0, -5.0, lightColor);

   //Light 2
   lightColor.R = 0.7;
   lightColor.G = 0.7;
   lightColor.B = 0.7;
   scene -> light[1] = new Light(0.0, 10.0, -10.0, lightColor);

  //arbitrary aspect ratio calculations
  
   if(X_RES > Y_RES)
   {
      scene -> xpixel = (double)X_RES/Y_RES;
      scene -> ypixel = 1;
   }
   else if(Y_RES > X_RES)
   {
      scene -> xpixel = 1;
      scene -> ypixel = (double)Y_RES/X_RES;
   }
   else
   {
      scene -> xpixel = 1;
      scene -> ypixel = 1;
   }
}

int main()
{
   //setting up file output
   ofstream outfile("creative.ppm", ofstream::out);
   if(!outfile)
   {
     cout<<"ERROR: File not read"<<endl;
      return 0;
   }

   //declare the ray of the "eye point"
   RAY_T ray;


   //Objects that are being drawn
   SCENE_T scene;

   init(&scene);

   //individual pixel color
   COLOR_T color;

   //pixel loop counters
   int x,y;

   double xPixSize = scene.xpixel/X_RES;
   double yPixSize = scene.ypixel/Y_RES;

   //ppm header


   outfile <<"P6"<<endl<<X_RES<<" "<<Y_RES<<endl<<"255"<<endl;

   for(y = 0; y < Y_RES; y++) {
      for(x = 0; x < X_RES; x++){

         ray.origin.set(0.0, 0.0, 0.0);

         ray.direction.set(-scene.xpixel/2 + x*xPixSize,
                            scene.ypixel/2 - y*yPixSize, 1);

         ray.direction = ray.direction.normalize();

         // call the trace function
         color = trace(scene, ray, 0, -1);

         if(color.R > 1.0)
            color.R = 1.0;
         if(color.G > 1.0)
            color.G = 1.0;
         if(color.B > 1.0)
            color.B = 1.0;


        //print pixel data into ppm file

        outfile<<(unsigned char)(color.R*255)<<
                 (unsigned char)(color.G*255)<<
                 (unsigned char)(color.B*255);
      }
   }
   //end file creation
   outfile.close();

   return 0;
}
