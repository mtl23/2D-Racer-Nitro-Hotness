#ifndef __COLLISION_H__
#define __COLLISION_H__

#include "world.h"
#include "player.h"
#include "obstacles.h"
/**
*@brief The function that checks for the collisions on the map
*param player* pointer to the player colliding with something
*param Obstacle the obstacle type that the player is colliding with
*/
void CheckCollisions(player* p1, Obstacle Doh);
#endif