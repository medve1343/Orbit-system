/***********************************************************************
 * Header File:
 *    Launched Object : Represents an expelled SpaceCollider in the orbiter simulation
 * Author:
 *    Gergo Medveczky
 * Summary:
 *    Provides a way to easily launch this piece of space debris.
 ************************************************************************/

#pragma once
#include "SpaceCollider.h"
#include <random>

class LaunchedObject : public SpaceCollider
{
public:
    // Default Constructor for Launched Object
   LaunchedObject() : SpaceCollider() {}
    // Non-default Constructor for Launched Object
   LaunchedObject(Angle launchDirection) : SpaceCollider() { direction = launchDirection; }
    // Launch after collision with random velocity
   virtual void launch(const Position& p, const Velocity& v)
   {
      // Pieces add anywhere between 5K and 9K m/s in that direction
      Velocity launchVel = Velocity(direction, random(5000.0, 9000.0));
      launchVel.addVel(v);

      // They are created 4 pixels from point of origin in the direction of travel
      Angle directionOfTravel = Angle(launchVel.getDX(), launchVel.getDY());
      pos = rotate(p, 0.0, 4.0, directionOfTravel.getRadians());
      vel = launchVel;
   }
};
