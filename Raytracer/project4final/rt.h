/**********************************************************************
* Author: William Luttrell
* File: rt.h
* Modified On: December 4, 2015
* Description: Type definitions for Colors and Rays
***********************************************************************/
#ifndef CRT_H
#ifndef RT_H
#define RT_H

#include "vector.h"


  #define NUM_OBJS 4
  #define NUM_LIGHTS 2

  #define X_RES 1024
  #define Y_RES 768

typedef struct {
  double R;
  double G;
  double B;

} COLOR_T;



typedef struct {
  Vector origin;
  Vector direction;

} RAY_T;

#endif
#endif
