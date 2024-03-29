/***********************************************************************
 * Header File:
 *    Fragment : A tiny piece from a piece of space junk
 * Author:
 *    Gergo Medveczky
 * Summary:
 *    Is a Timed Object, and is launched from some satellite or satellite piece.
 ************************************************************************/

#pragma once
#include "timedObject.h"

class Fragment :public TimedObject
{
public:
    // Non-default constructor with given angle
   Fragment(const Angle& launchDirection) : TimedObject(launchDirection)
   {
      secondsLeft = random(2.0, 3.0) * TIME_DILATION;
      rotationRate = random(-PI, PI);
   }
    // Getter for fragment radius
   virtual double getRadius() const { return 1.0; };
    // Draw Fargment
   virtual void draw() const { drawFragment(pos, direction.getRadians()); };
};
