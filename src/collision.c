#include "world.h"
#include "player.h"
#include "obstacles.h"
#include "simple_logger.h"
#include "chipmunk/chipmunk.h"

void CheckCollisions(player *p1, Obstacle Doh)
{
	
	
	
cpSpace* cpSpaceNew	(void )	;

	p1->playerX-340;

	if(Doh.position>=-70 && Doh.position<=30 &&p1->playerX<=100&&p1->playerX>=-150)
	{
		//slog("obstacle is on y tracking point %d", int(Doh.position));
		//slog("hit the obstacle of type %d", Doh.obj.sprite.frame); // this sets them equal but its not quite right
	
		switch(Doh.obj.sprite.frame) // do collision dectectioon stuff here
		{
	
			case 3:  //rock
				if(p1->playerX >=25)
				{
				p1->playerX =150;
				}
				else
				{
				p1->playerX =-70;
				}
				p1->speed =1.10;
				slog("rock %f %f",p1->speed,p1->playerX);
			break;

			case 4:  //dirt
				p1->speed -=.01;
				p1->accel = -0.0001;
			slog("dirt %f",p1->accel);
			break;

			case 5: //oil appox 25 is the middle
				
				slog("oil %f",p1->playerX);
				if(p1->playerX <=10)
				{
				p1->playerX =200;
				}
				else
				{
				p1->playerX =-200;
				}
				slog("new spot from oil %f",p1->playerX);
			break;

			case 6: // booster
				p1->speed += .055;
			slog("booster %f",p1->speed);
			break;

			default:
			break;
		
		
		}
	}
}