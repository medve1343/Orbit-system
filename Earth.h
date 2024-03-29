/***********************************************************************
 * Header File:
 *    Earth
 * Author:
 *    Gergo Medveczky
 * Summary:
 *    Earth class
 ************************************************************************/

#ifndef Earth_h
#define Earth_h
#include "position.h"
#include "constants.h"

class Earth
{
public:
   // Default Constructor for Hubble
   Earth()
   {
   pos = Position(0.0,0.0);
   angle = Angle(0.0, true);
   }
   // Draw Earth
   void draw() const { drawEarth(pos, angle.getRadians());}
   // Radius getter for Hubble
   double getRadius() const{return EARTH_RADIUS;}
   Position getPosition() const{return pos;}
   void rotateEarth(double &elapsedSeconds)
   {
      // rotate the earth
      double rotationAmount = -(2 * PI / SECONDS_PER_DAY) * elapsedSeconds;
      angle.addRadians(rotationAmount);
   }

private:
   Position pos;
   Angle angle;
};

#endif /* Earth_h */
