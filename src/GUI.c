#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "player.h"
#include "SDL_ttf.h"
#include "GUI.h"
#include "SDL_image.h"
#include "chipmunk/chipmunk.h"
#include "simple_logger.h"

extern SDL_Renderer* renderer;
int mytime;
int oldTime;
int currentTime;
Uint32 mil;
Uint32 mil2;
Uint32 sec;
Uint32 sec2;
Uint32 min;
Uint32 min2;



SDL_Surface* R1 = IMG_Load("images/1.png");
SDL_Surface* R2 = IMG_Load("images/2.png");

GUI InitGUI()
{
	GUI temp;
	//temp.timer = NULL; // an sdl surface
	temp.speed = NULL;
	temp.rank = NULL;
	temp.ranker = NULL;
	temp.mph =NULL;

	temp.speeddst.x= 650;
	temp.speeddst.y= 0;
    temp.speeddst.w= 24;
    temp.speeddst.h= 24;

	temp.speeddst2.x = 740;
	temp.speeddst2.y = 70;
	temp.speeddst2.w = 50;
	temp.speeddst2.h = 50;

	temp.rankdst.x =408;
	temp.rankdst.y =18;
	temp.rankdst.w =65;
	temp.rankdst.h =80;

	mytime = SDL_GetTicks();
	currentTime = SDL_GetTicks();
	oldTime = SDL_GetTicks();

	
	temp.rankdst2.x = 280;
	temp.rankdst2.y = 0;
	temp.rankdst2.w = 120;
	temp.rankdst2.h = 100;

	SDL_Color textColor2 = { 0, 0, 0 ,0 };
	SDL_Color textColor = { 255, 5, 5 ,0 };
	temp.textColor = textColor;
	temp.textColor2 = textColor2;

return temp;
}

void DrawGui(GUI HUD, player p1)
{
	
	

	int timer_digit1;
	int timer_digit2;
	int timer_digit3;
	int timer_digit4;
	int timer_digit5;
	int timer_digit6;
	int timer_digit7;
	int timer_digit8;

	char time[10];
	char speed[10]; 
	Sprite_M digits;
	Sprite_M digits2;
	int s1f;
	int s2f;
	
	digits = *spriteLoadNoEdits("images/num1.png",36,64);
	digits2 = *spriteLoadNoEdits("images/num2.png",24,24);
	
		digits.color.r = 0;
		digits.color.b = 0;
		digits.color.g = 0;
		digits2.color.r = 0;
		digits2.color.b = 0;
		digits2.color.g = 0;

	HUD.mph = IMG_Load("images/mph.png");
	HUD.ranker = IMG_Load("images/rank.png");
	Vector2D s1;
	Vector2D s2;

	Vector2D t1;
	Vector2D t2;
	Vector2D t3;
	Vector2D t4;
	Vector2D t5;
	Vector2D t6;
	Vector2D t7;
	Vector2D t8;
		
	t1.x=730;
	t1.y=10;

	t2.x=710;
	t2.y=10;

	t3.x=690;
	t3.y=10;
	
	t4.x= 670;
	t4.y= 10;

	t5.x= 650;
	t5.y= 10 ;

	t6.x= 630;
	t6.y=  10;

	t7.x= 610;
	t7.y= 10;

	t8.x= 590;
	t8.y= 10;


	s1.x = 710;
	s1.y = 60;

	s2.x = 678;
	s2.y = 60;

		if(p1.rank == 1 )
		{
			HUD.rank = R1 ;
		}
		else if (p1.rank == 2)
		{
			HUD.rank = R2 ;
		}

		s2f = int(p1.speed*15)%100/10;

		spriteDrawNoEdits(&digits,renderer,int(p1.speed*15)%10,s1);
		
		spriteDrawNoEdits(&digits,renderer,s2f,s2);
			
		currentTime = SDL_GetTicks();
		mytime = currentTime- oldTime;
		
		mil2 = mytime%100/10;
		mil = mytime%1000/100;
		
		sec = mytime%60000/1000%10;
		sec2 = mytime%60000/10000;
		
		min = mytime/60000%10;
		min2 = mytime/600000%10;

		//slog("%i", mil2);
		//timers
		spriteDrawNoEdits(&digits2,renderer,mil2,t1);
		spriteDrawNoEdits(&digits2,renderer,mil,t2);
		
		spriteDrawNoEdits(&digits2,renderer,10,t3);
		
		spriteDrawNoEdits(&digits2,renderer,sec,t4);
		spriteDrawNoEdits(&digits2,renderer,sec2,t5);
		
		spriteDrawNoEdits(&digits2,renderer,10,t6);
		
		spriteDrawNoEdits(&digits2,renderer,min,t7);
		spriteDrawNoEdits(&digits2,renderer,min2,t8);


		HUD.GUI3 = SDL_CreateTextureFromSurface(renderer,HUD.rank);
		HUD.GUI4 = SDL_CreateTextureFromSurface(renderer,HUD.ranker);
		HUD.GUI5 = SDL_CreateTextureFromSurface(renderer,HUD.mph);

		SDL_RenderCopy(renderer,HUD.GUI3,NULL,&HUD.rankdst);
		SDL_RenderCopy(renderer,HUD.GUI4,NULL,&HUD.rankdst2);
		SDL_RenderCopy(renderer,HUD.GUI5,NULL,&HUD.speeddst2);

}	