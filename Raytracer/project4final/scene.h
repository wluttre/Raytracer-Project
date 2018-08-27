/**********************************************************************
* Author: William Luttrell
* File: scene.h
* Modified On: December 4, 2015
* Description: Definition of Scene
***********************************************************************/
#ifndef SCENE_H
#define SCENE_H

#include "object.h"
#include "light.h"

class Light;

typedef struct {

  Object **objs;
  Light **light;

  //pixel variables for arbitrary aspect ratio
  double xpixel, ypixel;

} SCENE_T;

#endif
