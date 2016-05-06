#ifndef _CAMERA_
#define _CAMERA_

#include "SDL.h"
#include "SDL_image.h"
#include "Entity.h"

typedef struct
{
	Entity cam;
	SDL_Rect* game_cam;
	Vector3D position;

}camera;


void newCamera();

SDL_Rect* Project(camera);

#endif