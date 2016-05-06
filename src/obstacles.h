#ifndef __OBSTACLE_H__
#define __OBSTACLE_H__
#include "entity.h"
#include "world.h"
#include "player.h"

/**
 * @brief a ObstacleList that tells us what position the map has an obstacle
 * if the array entry is greater than 0, it has an obstacle of that type
 * @param ObstList the array of entries
 */

typedef struct
{
 int ObstList[3600]; //the list of road segments, an dwhich one has a obstacle on it
}ObstacleList;

/**
 * @brief an Obstacle Blueprint
 * @param obj the array of entries
 * @param scale, a scale factor
 * @param distance the obstacle lies relative to the player
 * @param position on the map the obstacle lies
  * @param type used for collision detection
 */

typedef struct
{
	Entity obj;
	float scale;
	int distance; 
	int position;
	int type; 

}Obstacle;

/**
 * @brief creats a new ObstacleList
 * @return returns the new ObstacleLIst
 */
ObstacleList newObstacleList();
/**
 * @brief checks if a obstacle needs to be drawns
 * @param type-an int that holds what type of obstacle it is 
 * @param ObstacleList to check for obstacles	
 * @param player to check its position on the map
 */
void checkForObstacles(ObstacleList obList , player* p1, Obstacle Doh);

/**
 * @brief creates a new Obstacle
 * @param type-an int that holds what type of obstacle it is 	
 * @param player to check its position on the map
 * @param position to map where it should go
 *@return the Obstacle that was created
 */

Obstacle newObstacle(int type);

/**
 * @brief draws necessary obstacles every frame
 * @param a list of entites that need to be searched for obstacles 	
 * @param player to check its position on the map
 * @param float the distance in decimal form between the obstacle and the player  
 */
void	 drawObstacle(Obstacle target, player *p1, float distance); 

#endif
