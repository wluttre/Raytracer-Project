/**********************************************************************
* Author: William Luttrell
* File: rt.h
* Modified On: December 4, 2015
* Description: Type definitions for Colors and Rays
***********************************************************************/
#ifndef RT_H
#ifndef CRT_H
#define CRT_H

#include "vector.h"


  #define NUM_OBJS 11
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
