#include "SDL.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sprite.h"
#include "SDL_image.h"
#include "vector.h"
#include "graphics.h"
#include "simple_logger.h"
#include "road.h"
#include "entity.h"
#include "world.h"
#include "player.h"

  #define YMAX 7
extern SDL_Renderer* renderer;
extern int lvl;
Road_M initRoad()
{


	Road_M myRoad;
	myRoad.pathList = NULL;
	int i;
	myRoad.pathList = (Entity**)malloc(sizeof(Entity)*(YMAX));
	memset(myRoad.pathList, 0, sizeof(Entity)*(YMAX));

	for(i=0;i<YMAX;i++)
	{

	if(myRoad.pathList[i] = EntityNew())
			{
		//	slog("made a road entity");
				myRoad.pathList[i]->inuse = 1;
				myRoad.pathList[i]->segNum = i;
			}
	else if (myRoad.pathList[i] == NULL)
			{
				slog("failed to create road entity");
			}
	}
return myRoad;

}



void roadDraw(Road_M myRoad, map mymap, player* p1) //this is reponsible for scrolling the road.
{

	int i;
	int y;
	SDL_Rect dst;
		
		for(i=0;i<YMAX;i++)
		{		
			dst.x =((p1->playerX-900)+int(2000*(.149*i))/2); //the road segments x position on the screen //(1.05*p1->playerX*i)+??
			dst.w = int(2000*(1.3-.149*i));   // the width of the road segment
			dst.y =560-(60-i)*i;		  //the road segments y position on the screen
			dst.h=60-i;					  // the height of the road segment

			switch(i)
			{
			case 0:
			dst.x -= 60;
			dst.w += 120;
			break;

			case 2:
			dst.x += 4;
			dst.w -= 10;
			break;

			case 3:
			dst.x += 4;
			dst.w -= 10;
			break;

			
			case 5:
			dst.x -= 40;
			dst.w += 80;
			break;

			case 6:
			dst.x -= 85;
			dst.w += 170;
			break;
			

			}


//slog(" car is at point %i ,%s next up is", int(p1->position) ,mymap.segments[i] );
for(y=1;y<YMAX+1;y++)
		{
			//slog("%i:%s", int(p1->position+y) ,mymap.segments[int(p1->position)+y] );
			if(int(p1->position)+y>300 && int(p1->position)+y<700 && lvl ==0 ) //can be mad elevel specific
			{
			dst.x =((1.05*p1->playerX*i)+(p1->playerX-500)+int(2000*(.149*i))/2); //the road segments x position on the screen //(1.05*p1->playerX*i)+??
			dst.w = int(2000*(1.3-.149*i));   // the width of the road segment
			//myRoad.pathList[i]->sprite = *spriteLoad("images/road7.png",dst.x,dst.y);
			}


			if(int(p1->position)+y>1300 && int(p1->position)+y<1700 && lvl ==2 ) //can be mad elevel specific
			{
			dst.x =((1.05*p1->playerX*i)+(p1->playerX-500)+int(2000*(.149*i))/2); //the road segments x position on the screen //(1.05*p1->playerX*i)+??
			dst.w = int(2000*(1.3-.149*i));   // the width of the road segment
			//myRoad.pathList[i]->sprite = *spriteLoad("images/road7.png",dst.x,dst.y);
			}

			if(int(p1->position)+y>2300 && int(p1->position)+y<2700 && lvl ==3 ) //can be mad elevel specific
			{
			dst.x =((1.05*p1->playerX*i)+(p1->playerX-500)+int(2000*(.149*i))/2); //the road segments x position on the screen //(1.05*p1->playerX*i)+??
			dst.w = int(2000*(1.3-.149*i));   // the width of the road segment
			//myRoad.pathList[i]->sprite = *spriteLoad("images/road7.png",dst.x,dst.y);
			}


		}
			SDL_RenderCopy(renderer,myRoad.pathList[i]->sprite.image,NULL,&dst);
			
			//SDL_RenderPresent(renderer);
//	slog("drew the road");
		}
		
}




void roadFetch(Road_M myRoad, map mymap, player* p1) 
{

	int i; 
	int p;
	char* nextline;
	p = int(p1->position+YMAX);
	int screenpos = (int(p1->position)%YMAX);// where amoung the scanlines are we saving the data?
	nextline = mymap.segments[int(p1->position)+YMAX]; //get the datat form inside this file
	//slog("the next road piece is %i , it reads %s",p,mymap.segments[p]);
	myRoad.pathList[screenpos]->segNum = p;
	if(strcmp(nextline,"line_A")==0)
			{
			myRoad.pathList[screenpos]->sprite = *spriteLoad("images/road1.png",0,0);
			
			}
			else if(strcmp (nextline,"line_B")==0)
			{
			myRoad.pathList[screenpos]->sprite = *spriteLoad("images/road2.png",myRoad.pathList[screenpos]->sprite.frameW,myRoad.pathList[screenpos]->sprite.frameH);
			
			}
			else if(strcmp (nextline,"line_C")==0)
			{
			myRoad.pathList[screenpos]->sprite = *spriteLoad("images/road3.png",myRoad.pathList[screenpos]->sprite.frameW,myRoad.pathList[screenpos]->sprite.frameH);
			}

			else if(strcmp (nextline,"line_D")==0)
			{
			myRoad.pathList[screenpos]->sprite = *spriteLoad("images/road4.png",myRoad.pathList[screenpos]->sprite.frameW,myRoad.pathList[screenpos]->sprite.frameH);
			}
				else if(strcmp (nextline,"line_E")==0)
			{
			myRoad.pathList[screenpos]->sprite = *spriteLoad("images/road5.png",myRoad.pathList[screenpos]->sprite.frameW,myRoad.pathList[screenpos]->sprite.frameH);
			}
				else if(strcmp (nextline,"line_F")==0)
			{
			myRoad.pathList[screenpos]->sprite = *spriteLoad("images/road6.png",myRoad.pathList[screenpos]->sprite.frameW,myRoad.pathList[screenpos]->sprite.frameH);
			}
	//		slog("loaded %s ",myRoad.pathList[screenpos]->sprite.filename);
	//		slog("put new piece into position %i with sprite %s", p1->position, myRoad.pathList[screenpos]->sprite.filename )
	
	

	if(p1->position>=3500)// if map size was more dynamic, this should be too now the map is continuous
	{
		p1->accel -= .0411;
	}
	if(p1->position>=3700)// if map size was more dynamic, this should be too now the map is continuous
	{
		p1->speed = 0;
	}

	if(p1->position>3600)// if map size was more dynamic, this should be too now the map is continuous
	{
		p1->position = 3600;
	}
	//slog("New position is %f", p1->position );
	if(p1->position>=3300 && p1->speed == 0)
	{
		p1->done = 1;
	}
}//end fetchroad


void roadUpdate(Road_M myRoad,map mymap , player p1)
{
	int i;
	int position = p1.position;
	//read from the map based on position of the car this loop also sets these
	for(i = 0;i<YMAX;i++)
	{
	 
			if(strcmp(mymap.segments[(position+i)],"line_A")==0)
			{
			myRoad.pathList[(position+i)%YMAX]->sprite = *spriteLoad("images/road1.png",0,0);
			}
			else if(strcmp(mymap.segments[(position+i)],"line_B")==0)
			{
			myRoad.pathList[(position+i)%YMAX]->sprite = *spriteLoad("images/road2.png",0,0);
			}

			else if(strcmp(mymap.segments[(position+i)],"line_C")==0)
			{
			myRoad.pathList[(position+i)%YMAX]->sprite = *spriteLoad("images/road3.png",0,0);
			}

			else if(strcmp(mymap.segments[(position+i)],"line_D")==0)
			{
			myRoad.pathList[(position+i)%YMAX]->sprite = *spriteLoad("images/road4.png",0,0);
			}

					else if(strcmp(mymap.segments[(position+i)],"line_E")==0)
			{
			myRoad.pathList[(position+i)%YMAX]->sprite = *spriteLoad("images/road5.png",0,0);
			}

			else if(strcmp(mymap.segments[(position+i)],"line_F")==0)
			{
			myRoad.pathList[(position+i)%YMAX]->sprite = *spriteLoad("images/road6.png",0,0);
			}
	//		slog("loaded %d : at screen position %d: with sprite %s", i ,myRoad.pathList[i]->segNum, myRoad.pathList[i]->sprite.filename);
	
	}// end (i = position;i<position+ymax;i++)
}

