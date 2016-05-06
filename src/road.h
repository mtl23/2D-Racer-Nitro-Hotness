#ifndef _ROAD_
#define _ROAD_
#include "vector.h"
#include "sprite.h"
#include "entity.h"
#include "simple_logger.h"
#include "world.h"
#include "player.h"
/**
 * @brief a Road object that a list of entites that make up the
 * scanlines of the road currently on the screen
 * @param pathlist,  an array of entites
 */

typedef struct

{
	Entity* *pathList;/**the entities that make up the road on the screen**/

}Road_M;
 

/*
* @brief allocates memory for the road at the start
*/

Road_M initRoad();

/**
* @brief a function that updates the Road_M array based on position 
* on the player position
* @param Road_M,  an array of entites that make up the screen
* @param map,  the gamemap object
* @param player,  the player used for position
**/
void roadUpdate(Road_M myRoad,map mymap , player p1); //**get the road sprite for every segemnt in the list currently**//

/**
* @brief draws a road based off the Road_M entity list
* @param Road_M,  an array of entites that make up the screen
* @param map,  the gamemap object
* @param player,  the player used for position
**/
void roadDraw(Road_M myRoad, map mymap, player* p1); // **draws the segments of road data**//
/*
* @brief gets the next position of the world ,map needed to draw
* @param Road_M,  an array of entites that make up the screen
* @param map,  the gamemap object
* @param player,  the player used for position
*/
void roadFetch(Road_M myRoad, map mymap, player *p1); 

#endif