#ifndef _WORLD_
#define _WORLD_
#include"vector.h";

/**
*@brief the game map stored as an array
*@param segments the array that akes the map, currently uses 6 values road A,B,C,D,E,F
*/
typedef struct
{
	char* segments[3600]; //this char array holds data for the entire map each entry is what road type should be drawn

}map;


/**
*@brief creates a new game map stored as an array
*@return the new map object
*/
map setWorld();

#endif