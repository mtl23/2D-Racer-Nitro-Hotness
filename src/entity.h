#ifndef __ENTITY_H__
#define __ENTITY_H__
#include "vector.h"
#include "sprite.h"

/**
*@brief The data  structure for Entities 
*@param inuse  flag decides what is in use
*@param filename The filename of the sprite associated with the entity 
*@param is_obst obstacle flag
*@param is_AI AI flag
*@param sprite sprite associated with the entity
*@param size size of then entity
*@param position onscreen position
*@param velocity inital velocity (usually 0)
*@param segNum the segment number the entity is on the map as an int
*/
typedef struct Entity_S
{
	int inuse; 
	char filename[32]; 
	int is_obst; 
	int is_AI; 
	Sprite_M sprite; 
	Vector2D size;
	Vector2D position;
	Vector2D velocity;
	int segNum;
	int next_think;/**time index for next_think*/
	int think_rate; /**how often to run think*/
	void(*draw) (struct Entity_S *self, SDL_Renderer *renderer); /**logic*<*/
	void(*think) (struct Entity_S *self); /**logic*<*/
	void(*update) (struct Entity_S *self); /**physics*<*/
	void(*touch) (struct Entity_S *self, struct Entity_S *other); /**collsions*<*/
	void(*free) (struct Entity_S *self); /**cleanup function call on free*<*/

}Entity;


/**
*
*@brief creates the entity system should be used once at game start
*/
void InitEntitySystem(int EntityMax);
/**
*
*@brief closes the entity system should be used once at game end
*/
void CloseEntitySystem();

/**
*
*@brief creates a single new Entity object
*@param a filename, and the position on the scrren you want it drawn
*@return an Entity type object
*/
Entity* EntityNew();
/**
*
*@brief Frees up a single Entity
*/
void entityFree(Entity **entity);
/**
*
*@brief Loads an Entity, it takes a filename so that it can be used with spriteLoad to load the sprite
*@param filename: The name of the sprite you wish to load
*@param position: A 2D vector used to state position on the screen
*@return Returns an ENtity type object so it can be saved as a variable. Necessary for entityDraw()
*/
Entity *entityLoad(char *filename, Vector2D position);
/**
*
*@brief Draws an Entity, it takes a render so it can be used with spriteDraw()
*@param Entity: The entity you wish to be drawn
*@param renderer: The renderer to draw the Entity's sprite onto
*@param position: A 2D vector used to state position on the screen
*/
void entityDraw(Entity *entity,SDL_Renderer* renderer, int frame, Vector2D position);

#endif