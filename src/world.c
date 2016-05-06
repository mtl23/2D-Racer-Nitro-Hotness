#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "SDL.h"
#include "SDL_image.h"
#include "simple_logger.h"
#include "sprite.h"
#include "vector.h"
#include "world.h"
#include "SDL_mixer.h"


extern Sprite_M BG1;
extern Sprite_M BG2;
extern Mix_Music *level_music;
extern int lvl;

map setWorld()
{
	map mymap;
	int numSegments =3600;
	if(lvl ==0)*mymap.segments = (char*)malloc(sizeof(char)* numSegments);
	memset(mymap.segments, 0, sizeof(char)* numSegments);
	int i;
	
	switch(lvl)
	{
	case(0):
	// this is level one
	BG1 = *spriteLoad("images/sky_bg.png",0,0);
	BG2 = *spriteLoad("images/grass.png",0,0);
	level_music = Mix_LoadMUS( "sfx/balrog.mid" );
	for (i=0;i<numSegments;i++)
	{
	switch (i%4){
					
				case(0):
				{
				mymap.segments[i] ="line_A";
				break;
				}

				case(1):
				{
				mymap.segments[i] ="line_B";
				break;
				}
				
				case(2):
				{
				mymap.segments[i] ="line_C";
				break;
				}
				
				case(3):
				{
				mymap.segments[i] ="line_D";
				break;
				}
	}//end switch

	if(i>3400)
	{
	if(i%2 ==1)
		{
		mymap.segments[i] ="line_E";
		}
	else 
		{
		mymap.segments[i] ="line_F";
		}
	}
//	slog("mymap.segments[%i] = %s ",i, mymap.segments[i] );
	}//end level 1
	break;	
	case(1):
	// this is level two
	Mix_HaltMusic();
	BG1 = *spriteLoad("images/sky.png",0,0);
	level_music = Mix_LoadMUS( "sfx/surf.mid" );
	for (i=0;i<numSegments;i++)
	{
	switch (i%4){
					
				case(0):
				{
				mymap.segments[i] ="line_A";
				break;
				}

				case(1):
				{
				mymap.segments[i] ="line_B";
				break;
				}
				
				case(2):
				{
				mymap.segments[i] ="line_C";
				break;
				}
				
				case(3):
				{
				mymap.segments[i] ="line_D";
				break;
				}
	}//end switch

	if(i>3400)
	{
	if(i%2 ==1)
		{
		mymap.segments[i] ="line_E";
		}
	else 
		{
		mymap.segments[i] ="line_F";
		}
	}
//	slog("mymap.segments[%i] = %s ",i, mymap.segments[i] );
	}//end level 2
	break;

	case(2):
	// this is level three
	Mix_HaltMusic();
	BG1 = *spriteLoad("images/bgsky2.png",0,0);
	level_music = Mix_LoadMUS( "sfx/BigBlue.mid" );
	for (i=0;i<numSegments;i++)
	{
	switch (i%4){
					
				case(0):
				{
				mymap.segments[i] ="line_A";
				break;
				}

				case(1):
				{
				mymap.segments[i] ="line_B";
				break;
				}
				
				case(2):
				{
				mymap.segments[i] ="line_C";
				break;
				}
				
				case(3):
				{
				mymap.segments[i] ="line_D";
				break;
				}
	}//end switch

	if(i>3400)
	{
	if(i%2 ==1)
		{
		mymap.segments[i] ="line_E";
		}
	else 
		{
		mymap.segments[i] ="line_F";
		}
	}
//	slog("mymap.segments[%i] = %s ",i, mymap.segments[i] );
	}//end level 3
	break;
	}
	return mymap;
}