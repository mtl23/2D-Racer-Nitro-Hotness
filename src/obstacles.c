#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "SDL_image.h"
#include "vector.h"
#include "obstacles.h"
#include "simple_logger.h"
#include "road.h"
#include "entity.h"
#include "world.h"
#include "player.h"
#include "collision.h"

extern SDL_Renderer* renderer;


ObstacleList newObstacleList()
{
	int i;
	ObstacleList my_obst;
		for(i=0;i<2700;i++)
		{
			switch(i)
			{
			case(700):
		
			my_obst.ObstList[i] = 1; //rock
				break;

			case(1200):
		
			my_obst.ObstList[i] = 2; //dirt
				break;

			case(1800):
		
			my_obst.ObstList[i] = 3;//oil
				break;

			case(2400):
		
			my_obst.ObstList[i] = 4;//booster
				break;

			default:

			my_obst.ObstList[i] = 0;// nada
				break;
			
			}
		//if(my_obst.ObstList[i]>0)
		//slog("position %i has an obstacle of type: %i", i,my_obst.ObstList[i]);

		}
	return my_obst;	
}
Obstacle newObstacle(int type)
{
	Vector2D size;
	Obstacle temp;
	int frame;
	size.x = 64;
	size.y = 64;
	temp.obj.is_obst = 1;
	temp.obj.sprite = *spriteLoad("images/car_sheet1.png",64,64);
	temp.distance = 0;
	return temp;

}

void checkForObstacles(ObstacleList obList , player *p1, Obstacle Doh)
	{
	int i;
	//Obstacle Doh = newObstacle(1);

	for (i=0;i<500;i++)
		{
			if(obList.ObstList[int(p1->position+i)]>0) // if somewhere on the screen correllates with a spot on the list that isin't a zero
			{
			//	slog("we need to draw an obstacle at position %i of type %i its distance is %d ", int(p1.position+i) , obList.ObstList[int(p1.position+i)],distance );
				
				Doh.position=i-300;
				Doh.distance = i;
				Doh.obj.sprite.frame = obList.ObstList[int(p1->position+i)]+2 ;
				drawObstacle(Doh,p1,Doh.distance);
			}
		}//end for loop
	
	}

void drawObstacle(Obstacle target, player *p1, float distance)
{
	SDL_Rect frame;
	SDL_Rect dest;
	Vector2D size;
	size.x= 0;
	size.y =0;
	if(p1->position <2400)
	{
	switch(target.obj.sprite.frame)
	{
		// this is where is size all the possible obstacles accordingly
		case(3):  //rock
		
			size.x=  100 ;
			size.y=  170;
			break;
		case(4):  //dirt
			size.x=  250 ;
			size.y=  150;
		break;

		case(5): //oil
			size.x=  300 ;
			size.y=  150;
			break;
		
		case(6): //booster
			size.x=  150 ;
			size.y=  150;
			break;
		
		default:
	//		size.x=  300 ;
		//	size.y=  150;
		break;
	}

	frame.x = target.obj.sprite.frame%target.obj.sprite.framesPerLine * target.obj.sprite.frameW;
	frame.y = target.obj.sprite.frame/target.obj.sprite.framesPerLine * target.obj.sprite.frameH;
	frame.w =  128;
	frame.h =  128;

	dest.x = 340 + p1->playerX;
	dest.y = 360 + (360-distance);
	dest.w = size.x - (.15*distance);
	dest.h= size.y - (.28*distance);
	target.obj.position.x = dest.x;
	target.obj.position.y = dest.y;
	CheckCollisions(p1,target);
	//slog("obstacle drawn at %i", int(p1->position));
	SDL_RenderCopy(renderer, target.obj.sprite.image ,&frame,&dest);

	}
}
