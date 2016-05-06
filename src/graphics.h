#ifndef _GRAPHICS_
#define _GRAPHICS_
/*
 *			graphics.h
 *			Originaly written by Donald Kehoe for the NJIT Introduction to game development class
 *			This file contains data structures, constants and function prototypes needed to initialize SDL and
 *			to handle sprites and graphics.
 */


#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
/**
*@brief delay in ms to the next frame
*@param Uint32 the amount of delay in ms 
*/
void FrameDelay(Uint32 delay);
/**
*@brief procedures to move to the next frame
*/
void NextFrame();


#endif
