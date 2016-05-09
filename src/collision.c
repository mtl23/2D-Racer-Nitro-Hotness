#include "world.h"
#include "player.h"
#include "obstacles.h"
#include "simple_logger.h"
#include "chipmunk/chipmunk.h"
#include "SDL_mixer.h"

//The sound effects that will be used
Mix_Chunk *scratch = NULL;
Mix_Chunk *high = NULL;
Mix_Chunk *med = NULL;
Mix_Chunk *low = NULL;


void CheckCollisions(player *p1, Obstacle Doh)
{
     //Load the sound effects
    high = Mix_LoadWAV( "sfx/Hit_00.wav" );
    med = Mix_LoadWAV( "sfx/slip.wav" );
    low = Mix_LoadWAV( "sfx/Hit_03.wav" );
	
cpSpace* cpSpaceNew	(void )	;

	p1->playerX-340;

	if(Doh.position>=-70 && Doh.position<=30 &&p1->playerX<=100&&p1->playerX>=-150)
	{
		
	
		switch(Doh.obj.sprite.frame) // do collision dectection stuff here
		{
	
			case 4:  //dirt
				p1->speed -=.04;
				p1->accel = -0.001;
				Mix_PlayChannel( -1, low, 0 ); 
			//slog("dirt %f",p1->accel);
			break;

			case 5: //oil appox 25 is the middle
				
				slog("oil %f",p1->playerX);
				if(p1->playerX <=10)
				{
				p1->playerX =250;
				Mix_PlayChannel( -1, med, 0 );
				}
				else
				{
				p1->playerX =-250;
				}
				Mix_PlayChannel( -1, med, 0 );
			break;

			case 6: // booster
			p1->speed += .025;
			Mix_PlayChannel( -1, high, 0 );
			 break;

			default:
			break;
		
		
		}
	}
}