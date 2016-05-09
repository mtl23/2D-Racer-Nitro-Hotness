#include "ai.h"
#include "simple_logger.h"
extern SDL_Renderer* renderer;

AI new_AI()
{
	Vector2D size;
	AI temp;
	temp.obj.is_obst = 1;
	temp.obj.sprite = *spriteLoad("images/rival.png",128,128);
	temp.distance = 0;
	temp.position = 0;
	temp.speed = 2.2;
	return temp;

}
void draw_AI(AI rival, player *p1)
{
	Vector2D carPos;
	carPos.x = 240;// for the car
	carPos.y = 400;// for the car
	//entityDraw(&rival.obj,renderer,0,carPos);
	SDL_Rect frame;
	SDL_Rect dest;
	Vector2D size;
	size.x= 128;
	size.y =128;

	dest.x = (270+  .5* rival.distance ) + p1->playerX;
	dest.y = (450 - rival.distance) ;
	dest.w = size.x - (.6*rival.distance);
	dest.h=  size.y - (.6*rival.distance);
	if(dest.x<420)
	{
	dest.x +=.03;
	}
	if(dest.x >420)
	{
	dest.x -=.03;
	}
	SDL_RenderCopy(renderer, rival.obj.sprite.image ,0,&dest);
		//SDL_RenderPresent(renderer);

}
void update_AI(AI *rival,player *p1)
	{

		rival->position += rival->speed;
		rival->distance = rival->position-p1->position;
		if(rival->position >= p1->position &&(rival->position-p1->position)<350)
		{
			
		//	slog("%d ,%i",rival->position,int(rival->speed));
			rival->distance = rival->position-p1->position;
			draw_AI(*rival, p1);
		}
		else if(rival->position <= p1->position &&(rival->position-p1->position)>-5)
		{
			draw_AI(*rival, p1);

		}
	

	if(rival->position>=3500)// if map size was more dynamic, this should be too now the map is continuous
	{
		rival->position = 3600;
	}


}