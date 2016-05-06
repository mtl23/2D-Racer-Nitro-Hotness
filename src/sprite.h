#ifndef __SPRITE_H__
#define __SPRITE_H__
#include <SDL.h>
#include "vector.h"


/**
*
*@brief The blueprint for a sprite object
*@param int the reference count of the specific sprite
*@param char the filename in the sprite, which is actually the adress
*@param SDL_Texture the texture used to save the image and send it to the renderer
*@param int the width of the image
*@param int the height of the image
*@param int frame this is the current frame of the sprite
*@param int the width of the frame on the sprite sheet
*@param int the height of the fram on the sprite sheet
*@param Used for calculating position on a spritesheet by default set to 16 in spriteLoad()
*/
typedef struct

{
	int refcount;       
	char filename[32];  
	SDL_Texture *image;
	int imageW; 
	int imageH; 
	int frame; 
	int frameW;
	int frameH; 
	int framesPerLine; 
	Vector3D color;

}Sprite_M;
/**
*
*@brief creates the sptite system, should be used once at game start
*/
void InitSpriteSystem();

/**
*
*@brief closes the sptite system, should be used once at game end
*/
void CloseSpriteSystem();

/**
*
*@brief allocates a space in the master Sprite-List for a sprite of a given filename (PNG)
*@param filename: the filename of the srpite associated with the entity
*@param sizeX: the final width of the sprite when its drawn
*@param sizeX: the final height of the sprite when its drawn
*@return Sprite_M: returns a Sprite_M object so that it can be saved for later. This is necessary to use spriteDraw()
*/
Sprite_M *spriteLoad(char *filename,int sizeX,int sizeY);

/**
*
*@brief frees a single sptite back to memory
 @param *sprite: pointer to the sprite that you wish to free
*/
void spriteFree(Sprite_M *sprite);

/**
*
*@brief draws the sprite
*@param *sprite: the sprite object we wish to draw
*@param frame: the frame of the spritesheet to be drawn
*@param *renderer: The SDL renderer to drawn the sprite onto
@param position:The position on the screen to draw the sprite onto, the Sprite size was already configured during load
*/
void spriteDraw(Sprite_M *sprite,  SDL_Renderer *renderer, int frame, Vector2D position);

#endif