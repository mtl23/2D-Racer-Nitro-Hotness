#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "SDL_image.h"
#include "vector.h"
#include "graphics.h"
#include "simple_logger.h"
 extern SDL_Window* mainWindow;
 extern SDL_Surface *temp;
 extern SDL_Renderer* renderer;
 extern SDL_Texture* BG;

Sprite_M *spriteList =NULL;
int numSprites = 0;
int spriteMax = 100;

void InitSpriteSystem()
{
	spriteList = (Sprite_M*)malloc(sizeof(Sprite_M)*(spriteMax));

	if(spriteList == NULL)
	{
		slog("failed to initialize sprite system. STILL NULL");
	}
memset(spriteList, 0, sizeof(Sprite_M)*(spriteMax));
slog("sprite system is go");
}

void CloseSpriteSystem()
{
  int i;
   if(!spriteList)
   {
		return;
   }
  for(i = 0;i < spriteMax;i++)
   {
     if(spriteList[i].image!=0)
	 {
      spriteFree (&spriteList[i]);
	 }
   }
slog("sprite system is closed");
free(spriteList);
spriteList=NULL;
spriteMax = 0;
}


Sprite_M *spriteLoad(char *filename,int sizeX,int sizeY)
{
  int i;
  SDL_Surface *temp;
  SDL_Texture *myTex;
  /*first search to see if the requested sprite image is alreday loaded*/
  for(i = 0; i < numSprites; i++)
  {
    if(!spriteList)
	{
	slog("WARNING! no sprite list to lookup!");
	}
	  
	if(strncmp(filename,spriteList[i].filename,20)==0)
    {
//	slog("already loaded");
      spriteList[i].refcount++;
	  spriteList[i].framesPerLine = 16;
	  spriteList[i].imageW = sizeX;
	  spriteList[i].imageH = sizeY;
	  spriteList[i].color.r = 200;
	  spriteList[i].color.b = 200;
	  spriteList[i].color.g = 200;
	  return &spriteList[i];
    }
  }
  /*makesure we have the room for a new sprite*/
  if(numSprites + 1 >= spriteMax)
  {
      slog("Maximum Sprites Reached.");
        exit(1);
  }
  /*if its not already in memory, then load it.*/
  numSprites++;
  for(i = 0;i <= numSprites;i++)
  {
    if(!spriteList[i].refcount)break;
  }
  temp = IMG_Load(filename);
  if(temp == NULL)
  {
   slog("unable to load a vital sprite: %s",SDL_GetError());
   return NULL;
  }
 // slog("loaded a sprite for the first time");
 myTex= SDL_CreateTextureFromSurface(renderer,temp);
  spriteList[i].image = myTex;
  /*sets a transparent color for blitting.*/
  /*then copy the given information to the sprite*/
  strncpy(spriteList[i].filename,filename,20);
      /*now sprites don't have to be 16 frames per line, but most will be.*/
  spriteList[i].imageW = sizeX;
  spriteList[i].imageH = sizeY;
  spriteList[i].frameW = spriteList[i].imageW;
  spriteList[i].frameH = spriteList[i].imageH;
  spriteList[i].refcount++;
  spriteList[i].framesPerLine = 16;
  return &spriteList[i];
}




Sprite_M *spriteLoadNoEdits(char *filename,int sizeX,int sizeY)
{
  int i;
  SDL_Surface *temp;
  SDL_Texture *myTex;
  /*first search to see if the requested sprite image is alreday loaded*/
  for(i = 0; i < numSprites; i++)
  {
    if(!spriteList)
	{
	slog("WARNING! no sprite list to lookup!");
	}
	  
	if(strncmp(filename,spriteList[i].filename,20)==0)
    {
//	slog("already loaded");
      spriteList[i].refcount++;
	  spriteList[i].framesPerLine = 16;
	  spriteList[i].imageW = sizeX;
	  spriteList[i].imageH = sizeY;
	  return &spriteList[i];
    }
  }
  /*makesure we have the room for a new sprite*/
  if(numSprites + 1 >= spriteMax)
  {
      slog("Maximum Sprites Reached.");
        exit(1);
  }
  /*if its not already in memory, then load it.*/
  numSprites++;
  for(i = 0;i <= numSprites;i++)
  {
    if(!spriteList[i].refcount)break;
  }
  temp = IMG_Load(filename);
  if(temp == NULL)
  {
   slog("unable to load a vital sprite: %s",SDL_GetError());
   return NULL;
  }
 // slog("loaded a sprite for the first time");
 myTex= SDL_CreateTextureFromSurface(renderer,temp);
  spriteList[i].image = myTex;
  /*sets a transparent color for blitting.*/
  /*then copy the given information to the sprite*/
  strncpy(spriteList[i].filename,filename,20);
      /*now sprites don't have to be 16 frames per line, but most will be.*/
  spriteList[i].imageW = sizeX;
  spriteList[i].imageH = sizeY;
  spriteList[i].frameW = spriteList[i].imageW;
  spriteList[i].frameH = spriteList[i].imageH;
  spriteList[i].refcount++;
  spriteList[i].framesPerLine = 16;
  return &spriteList[i];
}

void spriteFree (Sprite_M *sprite)
{
  /*first lets check to see if the sprite is still being used.*/
  sprite->refcount--;
  if(sprite->refcount== 0)
  {
  strcpy(sprite->filename,"\0");
  sprite->image = NULL;
  }
    if(sprite->refcount<= 0)
  {
  strcpy(sprite->filename,"\0");
  SDL_DestroyTexture(sprite->image);
  memset(sprite,0,sizeof(sprite));
  }
 sprite = NULL;
 
}


void spriteDrawNoEdits(Sprite_M *sprite,  SDL_Renderer *renderer, int frame, Vector2D position)

{

	SDL_Rect rect;//where on the sprite sheet? //this has to be changed with varibnles 
	SDL_Rect dest; 

	rect.x = frame%sprite->framesPerLine * sprite->frameW;
	rect.y = frame/sprite->framesPerLine * sprite->frameH;
	rect.w = sprite->frameW;
	rect.h = sprite->frameH;

	dest.x = position.x;
	dest.y = position.y;
	dest.w = sprite->frameW;
	dest.h = sprite->frameH;

	//find sprite to draw in the list
//	slog("looking for sprite to draw");
	int i;
	for( i =0;i <= spriteMax ;i++)
		{
			if(spriteList[i].image==sprite->image)
			{
				//slog("Drawing");
				// send sprite texture to renderer
				//SDL_SetTextureColorMod(spriteList[i].image,spriteList[i].color.r,spriteList[i].color.g,spriteList[i].color.b);
				SDL_RenderCopy(renderer, spriteList[i].image, &rect, &dest); //tell the renderer theres something you want to do 
			}
			//printf("Finished looking for a sprite to draw in the list\n");
		}

	

}


void spriteDraw(Sprite_M *sprite,  SDL_Renderer *renderer, int frame, Vector2D position)
{

	SDL_Rect rect;//where on the sprite sheet? //this has to be changed with varibnles 
	SDL_Rect dest; 

	rect.x = frame%sprite->framesPerLine * sprite->frameW;
	rect.y = frame/sprite->framesPerLine * sprite->frameH;
	rect.w = sprite->frameW;
	rect.h = sprite->frameH;

	dest.x = position.x;
	dest.y = position.y;
	dest.w = sprite->frameW;
	dest.h = sprite->frameH;

	//find sprite to draw in the list
//	slog("looking for sprite to draw");
	int i;
	for( i =0;i <= spriteMax ;i++)
		{
			if(spriteList[i].image==sprite->image)
			{
				//slog("Drawing");
				// send sprite texture to renderer
				SDL_SetTextureColorMod(spriteList[i].image,spriteList[i].color.r,spriteList[i].color.g,spriteList[i].color.b);
				SDL_RenderCopy(renderer, spriteList[i].image, &rect, &dest); //tell the renderer theres something you want to do 
			}
			//printf("Finished looking for a sprite to draw in the list\n");
		}

	

}
