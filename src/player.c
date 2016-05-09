#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include "SDL.h"
#include "SDL_image.h"
#include "graphics.h"
#include "simple_logger.h"
#include "sprite.h"
#include "vector.h"
#include "entity.h"
#include "player.h"


	extern int mytime;
	extern int oldTime;
	extern int currentTime;
extern SDL_Renderer* renderer;

player newPlayer()
{
Vector2D size; // for the car
size.x = 128; // for the car
size.y = 128;// for the car
player User;

User.p1_car = entityLoad("images/car_sheet1.png",size);
User.speed = 0;    
User.position = 0;// current sposition in world object array
User.rank = 1;
User.minaccel = 0;
User.maxX = 500;
User.minX = -500;
User.playerX = 0;    //increase this number to move the road to the right, thus moving the car left. Decrese this to move the car to the right and the road to the left.
User.accel =0;
User.minspeed = 0;

User.done=0;
User.frame = 0;
User.points = 5;
User.SUP = 0;
User.AUP = 0;
User.HUP =0;
User.maxspeed = 4 + User.SUP;
User.maxaccel = .02 + (User.AUP/100);
return User;
}

void UpdatePlayer(player* user)
{
	
	
	Vector2D carPos;
	carPos.x = 420;// for the car
	carPos.y = 450;// for the car

	user->maxspeed = 4 + ((user->SUP)/4);
	user->maxaccel = .02 + (user->AUP/100);

	if(user->done == 1)
	{
	currentTime = mytime;
	}
	
	if(user->accel > user->maxaccel + user->AUP ) // cant accelerate forever
		{
			user->accel = user->maxaccel-.01;
		}

	if(user->speed < (user->maxspeed + user->SUP) ) //accellerate the car
		{
	user->speed  += user->accel;
		}
	
		if(user->speed > user->maxspeed+user->SUP) //max speed cap
		{
	user->speed  = (user->maxspeed + user->SUP);
		}
	

		if(user->accel < 0 ) //decellerate the car
		{
			user->speed  += (user->accel + user->AUP);
		}

	if(user->speed <= 0.00) //full stop 
		{
		user->speed = 0.00;
		user->accel = 0.00;
		}

	if(user->speed > 0) //update position if they're moving forward
		{
	user->position = (user->position+=user->speed);
		}

	if(user->playerX > user->maxX) //left threshold
	{
	 user->playerX = user->maxX;
	}

if (user->playerX < user->minX) //right threshold
	{
		user->playerX = user->minX;
	}



//slog("player position is %f: speed is %f",user->position ,user->speed );

entityDraw(user->p1_car,renderer,user->frame,carPos);
	//user->position += 1;
}
