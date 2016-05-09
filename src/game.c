#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"
#include "graphics.h"
#include "simple_logger.h"
#include "sprite.h"
#include "vector.h"
#include "entity.h"
#include "road.h"
#include "player.h"
#include "world.h"
#include "bg.h"
#include "GUI.h"
#include "obstacles.h"
#include "ai.h"
#include "collision.h"
#include "SDL_mixer.h"
#include "MainMenu.h"
#include "fileWriter.h"
	
	extern int mytime;
	extern int oldTime;
	extern int currentTime;
   SDL_Window* mainWindow;
   SDL_Renderer* renderer;
   extern int entityMax;
   Mix_Music *level_music;
   int lvl = 0; // current level
   Sprite_M BG1;
   Sprite_M BG2;
   player mew;
   int GP;
/*this program must be run from the directory directly below images and src, not from within src*/
/*notice the default arguments for main.  SDL expects main to look like that, so don't change it*/
int main(int argc, char *argv[])
{

 // SDL_Surface *temp = NULL;

  
  int done;// the player
  const Uint8 *keys;// the player

  /* This section starts by loading the BG as a surface and converting it to a texture This will have to change 
  if I can manage to scroll the trexture arond the player*/
 
SDL_CreateWindowAndRenderer(800, 600, SDL_WINDOW_RESIZABLE, &mainWindow, &renderer);
SDL_SetWindowTitle(mainWindow, "Nitro Hotness");
 if( TTF_Init() == -1 )
    {
        return false;    
    }

  if( Mix_OpenAudio( 22050, MIX_DEFAULT_FORMAT, 2, 4096 ) == -1 )
    {
        return false;    
    }

InitSpriteSystem();
InitEntitySystem(entityMax);


map mymap = setWorld();
ObstacleList ol = newObstacleList();
mew = newPlayer();
Obstacle Doh = newObstacle(0);
Road_M Path = initRoad();
AI rival = new_AI();
GUI HUD = InitGUI();
mew.position=0;
done = 0;

//The music that will be played
   Mix_Music *music = NULL;


   Mix_Chunk *buzz = NULL;
    buzz = Mix_LoadWAV( "sfx/buzz.wav" );
	readSave(&mew);
	showTitle();
	showMain();
  oldTime = 0;
  currentTime = 0;
  mytime = 0;

do
 	{
		
  oldTime = 0;
  currentTime = 0;
  mytime = 0;
	  if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                        if( Mix_PlayMusic( level_music, -1 ) == -1 )
                        {
                            return 1;
                        } 
					}
	 SDL_Event e;
	 SDL_PollEvent( &e ); 
		if(&e)
					{
					//User requests quit
					if( e.type == SDL_QUIT )
					{
						done = 1;
					}
					//user presses enter to go to next menu
					
					//User presses a key
					else if( e.type == SDL_KEYDOWN )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{
						
						case SDLK_LEFT:
				//		slog("left is down");	
						mew.playerX += 3;
						mew.accel = (mew.accel - .000001);
						break;

						case SDLK_RIGHT:
					//	slog("right is down");
						mew.playerX -= 3;
						mew.accel = (mew.accel - .000001);
						break;

						case SDLK_UP:
					//	slog("up is down");
						 mew.accel = (mew.accel + .00008);
						 Mix_PlayChannel( 1, buzz, 0 );
						 break;
						
						case SDLK_DOWN:
					//	slog("down is down");
						mew.accel = (mew.accel - .00008);
						break;
						}
					}

					else if( e.type == SDL_KEYUP )
					{
						//Select surfaces based on key press
						switch( e.key.keysym.sym )
						{	
						
						case SDLK_RETURN :
						if(mew.done ==1)
						{
							Mix_HaltMusic();
							if(GP == 1)
							{
							mew.done=0;
							lvl++;
							//slog("new level is %i",lvl);
							mew.position = 0;
							rival.position =0;
							setWorld();
							Results(mew.rank,lvl);
							}
						else if (GP == 0)
							{
							mew.done=0;
							mew.position = 0;
							rival.position =0;
							levelSelect();
							}
						
						}
						else
						{
						slog("too soon");
						}
						
						case SDLK_LEFT:
					//	slog("left is up");	
						e.type = SDLK_CLEAR;
						break;

						case SDLK_RIGHT:
					//	slog("right is up");
						e.type = SDLK_CLEAR;
						break;

						case SDLK_UP:
					//	slog("up is up");
						mew.accel = (mew.accel - .001);
						Mix_HaltChannel(1);
						e.type = SDLK_CLEAR;
						break;

						case SDLK_DOWN:
					//	slog("down is up");
						mew.accel = 0;
						e.type = SDLK_CLEAR;
						break;

						default:
					//slog("simple decel");	
						mew.accel = (mew.accel-0.00001);
						break;

						}
					}

		if(mew.position > rival.position)
		{
			mew.rank = 1 ;
		}
		else if( rival.position > mew.position )
		{
			mew.rank = 2 ;
		}
		SDL_RenderClear(renderer);
		DrawBG(BG1,BG2);
		roadUpdate(Path,mymap,mew);
		roadDraw(Path,mymap,&mew);
		roadFetch(Path,mymap,&mew);
		checkForObstacles(ol , &mew, Doh);
		update_AI(&rival, &mew);
		UpdatePlayer(&mew);
		DrawGui(HUD,mew);
		NextFrame();
		keys = SDL_GetKeyboardState(NULL);

	if(keys[SDL_SCANCODE_ESCAPE])
    {
        done = 1;
    }
	
}
  }while(!done);
      //Free the sound effects
   //Free the music
  Mix_FreeMusic( music );
  CloseEntitySystem();
  CloseSpriteSystem();
  exit(0);		/*technically this will end the program, but the compiler likes all functions that can return a value TO return a value*/ 
 return 0;
}

