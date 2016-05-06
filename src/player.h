#ifndef _PLAYER_H_
#define _PLAYER_H_

#include "sprite.h"
#include "entity.h"


/**
 * @brief player object that the game use
 * @param position  current position on the map
 * @param accel		current acceleeration
 * @param speed		current speed
 * @param maxaccel  the fastest the car can accerlerate
 * @param minspeed  0
 * @param maxX		player offset --the farthest left the road can go
 * @param minX     player offset --the farthest right the road can go
 * @param playerX where to draw the x coordinate of the road    
 * @param done flag for finishiing a race, remember to set it to 0 again at the strat of the next race
 */

typedef struct{

Entity* p1_car;
float position;		
float speed;       
float accel;        
float maxaccel;     
float minaccel;		
float minspeed;        
float maxspeed;        
float maxX;         
float minX;         
float playerX;     
int rank;
int done;
int frame;
int SUP;
int AUP;
int HUP;
int points;
					
			} player;
#endif
/**
 * @brief creates player object 
 * @return a new player object
 */
player newPlayer();

/**
 * @brief destroys player object 
 */
void removePlayer();
/**
 * @brief frees player object data
 */
void freePlayer();

/**
 * @brief Update the player's speed, acceleration, position, and PlayerX based on inputs 
 */
void UpdatePlayer(player* user);