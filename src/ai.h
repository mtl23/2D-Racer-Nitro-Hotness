#ifndef __AI_H__
#define __AI_H

#include "world.h"
#include "player.h"
#include "Entity.h"
/**
*@brief The data for world map  
*@param obj this should already be able to hold the size,position,sprite,velocity of each obstacle 
*@param scale factor to scale the sprite as it travels down the road
*@param distance the distance the obstacle is from the player on the map
*@param position  the position in the screen used for collision dectection
*@param rank rank in the race
*@param speed AI speed, calculated like the players with accl and velocity
*/
typedef struct
{
	Entity obj;
	float scale;
	int distance;
	int position;
	int rank; 
	float speed;  
}AI;
/**
*@brief creates a new AI object
*@return a new AI object
*/
AI new_AI();
/**
*@brief updates AI object
*@param AI* pointer to the AI car obj
*@param player* pointer to the player obj
*/
void update_AI(AI* rival,player *p1);
/**
*@brief draws the AI car
*@param AI the AI car obj
*@param player* pointer to the player obj
*/
void draw_AI(AI rival, player *p1);


#endif