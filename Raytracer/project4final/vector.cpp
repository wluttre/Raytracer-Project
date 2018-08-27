/**********************************************************************
* Author: William Luttrell
* File: vector.h
* Modified On: December 4, 2015
* Description: implementation of class vector
***********************************************************************/
#include "vector.h"

#include <cmath>


Vector::Vector()
{
   x = 0.0;
   y = 0.0;
   z = 0.0;
}

Vector::Vector(double newX, double newY, double newZ)
{
   x = newX;
   y = newY;
   z = newZ;
}

Vector::~Vector() 
{}

Vector Vector::operator+(const Vector& rhs)
{
   Vector ret(x + rhs.x, y + rhs.y, z + rhs.z);
   return ret;
}

Vector Vector::operator-(const Vector& rhs)
{
   Vector ret(x - rhs.x, y - rhs.y, z-rhs.z);
   return ret;
}

Vector Vector::operator*(const Vector& rhs)
{
   Vector ret(x * rhs.x, y * rhs.y, z * rhs.z);
   return ret;
}

Vector& Vector::operator+=(const Vector& rhs)
{
   x += rhs.x;
   y += rhs.y;
   z += rhs.z;
   return *this;
}

Vector& Vector::operator-=(const Vector& rhs)
{
   x -= rhs.x;
   y -= rhs.y;
   z -= rhs.z;
   return *this;
}

Vector Vector::operator*(double rhs)
{
   Vector ret(x * rhs, y * rhs, z * rhs);
   return ret;
}

Vector Vector::operator/(double rhs)
{
   Vector ret(x / rhs, y / rhs, z / rhs);
   return ret;
}

double Vector::magnitude()
{
   return sqrt((x * x + y * y + z * z));
}

Vector Vector::normalize()
{
    Vector ret(x/magnitude(), y/magnitude(), z/magnitude());
    x /= magnitude();
    y /= magnitude();
    z /= magnitude();
    return ret;
}

double Vector::dot(const Vector& rhs)
{
   return rhs.x * x + rhs.y * y + rhs.z * z;
}

void Vector::set(double x, double y, double z)
{
   this->x = x;
   this->y = y;
   this->z = z;
}

double Vector::addAllValues()
{
   return x+y+z;
}

int Vector::floorVector()
{
   Vector ret(x, y, z);
   return  ((int)floor(ret.x)) + 
           ((int)floor(ret.y)) + 
           ((int)floor(ret.z));
}

double Vector::getX()
{
   return x;
}

double Vector::getY()
{
   return y;
}

double Vector::getZ()
{
   return z;
}







