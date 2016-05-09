#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "SDL_ttf.h"
#include "SDL.h"
#include "vector.h"
#include "SDL_image.h"
#include "graphics.h"
#include "simple_logger.h"
#include "sprite.h"
#include "MainMenu.h"
#include "player.h"
#include "world.h"
#include "fileWriter.h";
#include "SDL_mixer.h";

extern SDL_Renderer* renderer;
extern int GP;
extern player mew;
extern int lvl;
extern int mytime;
extern int oldTime;
extern int currentTime;


Vector2D pos;
SDL_Rect screen;
SDL_Texture* background;
SDL_Surface* BG;
TTF_Font *font2 =  NULL;
TTF_Font *font =  NULL;
SDL_Color textColor = { 255, 255, 255 };
SDL_Color textColor2 = { 255, 105, 255 };
  Mix_Music *menu_music;

void showTitle()
{
    menu_music = Mix_LoadMUS( "sfx/records3.mid" );
BG = IMG_Load("images/bg.png");
background = SDL_CreateTextureFromSurface( renderer, BG );
screen.x = 0;
screen.y = 0;
screen.w = 800;
screen.h = 600;


const Uint8 *keys;// the player
int done;
font2 =	TTF_OpenFont( "Carre.ttf", 36 );
font  =	TTF_OpenFont( "fzero.ttf", 24 );
SDL_Texture* Title;

SDL_Rect Logo;
  if( font == NULL )
    {
     slog("font not loaded properly");
		return;
    }
	done = 0;
	char title[32];
	strcpy(title ,"NITRO HOTNESS!!!");

		SDL_Surface *message = TTF_RenderText_Solid( font, title, textColor2 );
		Title = SDL_CreateTextureFromSurface( renderer, message );
	
	Logo.x = 200;
	Logo.y = 100;
	Logo.w = 500;
	Logo.h = 25;

	do
  {
	
	  	  if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                    Mix_PlayMusic( menu_music, -1 );
                  
					}

	currentTime = mytime;
	SDL_RenderCopy(renderer,background,NULL,&screen);
	SDL_RenderCopy(renderer,Title,NULL,&Logo);  
	SDL_RenderPresent(renderer);
	//sprintf(time, "%d", int((currentTime - oldTime) / 1000); 
	//sprintf(speed, "%d", int(p1.speed *15));  
	SDL_Event e;
	SDL_PollEvent( &e ); 
		if(&e)
			{
					
					if( e.type == SDL_KEYUP )
					{
							//Select surfaces based on key press
							switch( e.key.keysym.sym )
							{	
							case SDLK_UP:
							slog("up key is up");
							e.type = SDLK_CLEAR;
							break;
						
							case SDLK_DOWN:
							slog("down key is up");
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_RETURN:
							done = 1;
							e.type = SDLK_CLEAR;
							break;
							}
					}
				}
		   keys = SDL_GetKeyboardState(NULL);

	if(keys[SDL_SCANCODE_ESCAPE])
    {
        exit(1);
    }
	
  } while(!done);
  
	
	  return;
  }

void showMain()

{
    menu_music = Mix_LoadMUS( "sfx/records3.mid" );
BG = IMG_Load("images/bg.png");
background = SDL_CreateTextureFromSurface( renderer, BG );
screen.x = 0;
screen.y = 0;
screen.w = 800;
screen.h = 600;

	
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	const Uint8 *keys;// the player
	int done;

int OP ;
SDL_Texture* Prix;
SDL_Texture* Stage;
SDL_Texture* Edit;
SDL_Texture* Quit;

SDL_Rect r1;
SDL_Rect r2;
SDL_Rect r3;
SDL_Rect r4;

char option1[32];
strcpy(option1 ,"Grand Prix");
char option2[32];
strcpy(option2 ,"Single Race");
char option3[32];
strcpy(option3 ,"Editor");
char option4[32];
strcpy(option4 ,"Exit");

  if( font == NULL )
    {
     slog("font not loaded properly");
		return;
    }
		SDL_Surface *Prixx;
		SDL_Surface *Stagee;
		SDL_Surface *Editt;
		SDL_Surface *Quitt;

	r1.x = 200;
	r1.y = 100;
	r1.w = 250;
	r1.h = 25;
	
	r2.x = 200;
	r2.y = 150;
	r2.w = 250;
	r2.h = 25;

	r3.x = 200;
	r3.y = 200;
	r3.w = 150;
	r3.h = 25;

	r4.x = 200;
	r4.y = 250;
	r4.w = 100;
	r4.h = 25;
		

  if( font == NULL )
    {
     slog("font not loaded properly");
		return;
    }
	done = 0;
	OP = 0;
	do
  {
     if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                    Mix_PlayMusic( menu_music, -1 );
                  
					}

	  
	//currentTime = mytime;
	Prixx = TTF_RenderText_Solid( font, option1, textColor );
	Stagee = TTF_RenderText_Solid( font, option2, textColor );
	Editt = TTF_RenderText_Solid( font, option3, textColor );
	Quitt = TTF_RenderText_Solid( font, option4, textColor );

	switch(OP)
		{
		
		case 0:
		Prixx = TTF_RenderText_Solid( font, option1, textColor2 );
		break;
		
		case 1:
		Stagee = TTF_RenderText_Solid( font, option2, textColor2 );
		break;
		
		case 2:
		Editt = TTF_RenderText_Solid( font, option3, textColor2 );
		break;
		
		case 3:
		Quitt = TTF_RenderText_Solid( font, option4, textColor2 );
		break;		
		}

		Prix = SDL_CreateTextureFromSurface( renderer, Prixx );
		Stage = SDL_CreateTextureFromSurface( renderer, Stagee );
		Edit = SDL_CreateTextureFromSurface( renderer, Editt );
		Quit = SDL_CreateTextureFromSurface( renderer, Quitt );

		SDL_RenderCopy(renderer,background,NULL,&screen);
	SDL_RenderCopy(renderer,Prix,NULL,&r1);  
	SDL_RenderCopy(renderer,Stage,NULL,&r2);  
	SDL_RenderCopy(renderer,Edit,NULL,&r3);  
	SDL_RenderCopy(renderer,Quit,NULL,&r4);  
	SDL_RenderPresent(renderer);
  
	SDL_Event e;
	SDL_PollEvent( &e ); 
		if(&e)
			{
					
					if( e.type == SDL_KEYUP )
					{
							//Select surfaces based on key press
							switch( e.key.keysym.sym )
							{	
							case SDLK_UP:	
							if(OP > 0){
							OP--;
									}
							slog("up key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
						
							case SDLK_DOWN:
							if(OP < 3){
							OP++;
									}
							slog("down key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
							

								
							case SDLK_RETURN:
							switch(OP)
							{
							case 0:
							GP = 1;
							done = 1;
							Mix_HaltMusic();
							//oldTime = SDL_GetTicks();
							//currentTime = SDL_GetTicks();
							break;
							
							case 1:
							GP = 0;					
							levelSelect();
							oldTime = 0;
							currentTime = SDL_GetTicks();
							Mix_HaltMusic();
							done = 1;
							break;
							
							case 2:
							GP = 0;
							EditorMAIN(&mew);
							done = 1;
							break;
							
							case 3:
							exit(1);
							break;
							
							}

							break;
							}
					}
				}
		   keys = SDL_GetKeyboardState(NULL);

	if(keys[SDL_SCANCODE_ESCAPE])
    {
        showMain();
    }
	
  } while(!done);

	SDL_FreeSurface(Prixx);
	SDL_DestroyTexture(Prix);
	SDL_FreeSurface(Stagee);
	SDL_DestroyTexture(Stage);
	SDL_FreeSurface(Editt);
	SDL_DestroyTexture(Edit);
	SDL_FreeSurface(Quitt);
	SDL_DestroyTexture(Quit);
	 return;
  }

void levelSelect()
{
	menu_music = Mix_LoadMUS( "sfx/records3.mid" );
	SDL_RenderCopy(renderer,background,NULL,&screen);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	const Uint8 *keys;// the player
	int done;

int OP;
SDL_Texture* LVL1;
SDL_Texture* LVL2;
SDL_Texture* LVL3;

SDL_Texture* Quit;

SDL_Rect r1;
SDL_Rect r2;
SDL_Rect r3;
SDL_Rect r4;

char option1[32];
strcpy(option1 ,"LEVEL 1");
char option2[32];
strcpy(option2 ,"LEVEL 2");
char option3[32];
strcpy(option3 ,"LEVEL 3");
char option4[32];
strcpy(option4 ,"Return to Main");

  if( font == NULL )
    {
     slog("font not loaded properly");
		return;
    }
	done = 0;
	OP = 0;

	SDL_Surface *Prixx;
	SDL_Surface *Stagee;
	SDL_Surface *Editt;
	SDL_Surface *Quitt;
	
	r1.x = 200;
	r1.y = 100;
	r1.w = 150;
	r1.h = 25;
	
	r2.x = 200;
	r2.y = 150;
	r2.w = 150;
	r2.h = 25;

	r3.x = 200;
	r3.y = 200;
	r3.w = 150;
	r3.h = 25;

	r4.x = 270;
	r4.y = 550;
	r4.w = 250;
	r4.h = 25;
		

  if( font == NULL )
    {
     slog("font not loaded properly");
		return;
    }
	done = 0;

	do
  {
    	
	    if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                    Mix_PlayMusic( menu_music, -1 );
                  
					}

	  
	  currentTime = mytime;
	 Prixx = TTF_RenderText_Solid( font, option1, textColor );
	Stagee = TTF_RenderText_Solid( font, option2, textColor );
	Editt = TTF_RenderText_Solid( font, option3, textColor );
	Quitt = TTF_RenderText_Solid( font, option4, textColor );

	switch(OP)
		{
		
		case 0:
		Prixx = TTF_RenderText_Solid( font, option1, textColor2 );
		break;
		
		case 1:
		Stagee = TTF_RenderText_Solid( font, option2, textColor2 );
		break;
		
		case 2:
		Editt = TTF_RenderText_Solid( font, option3, textColor2 );
		break;
		
		case 3:
		Quitt = TTF_RenderText_Solid( font, option4, textColor2 );
		break;
		}

	LVL1 = SDL_CreateTextureFromSurface( renderer, Prixx );
	LVL2 = SDL_CreateTextureFromSurface( renderer, Stagee );
	LVL3 = SDL_CreateTextureFromSurface( renderer, Editt );
	Quit = SDL_CreateTextureFromSurface( renderer, Quitt );

	SDL_RenderCopy(renderer,background,NULL,&screen);
	SDL_RenderCopy(renderer,LVL1,NULL,&r1);  
	SDL_RenderCopy(renderer,LVL2,NULL,&r2);  
	SDL_RenderCopy(renderer,LVL3,NULL,&r3);  
	SDL_RenderCopy(renderer,Quit,NULL,&r4);  
	SDL_RenderPresent(renderer);
 	SDL_Event e;
	SDL_PollEvent( &e ); 
		if(&e)
			{
					
					if( e.type == SDL_KEYUP )
					{
							//Select surfaces based on key press
							switch( e.key.keysym.sym )
							{	
							case SDLK_UP:	
							if(OP > 0){
							OP--;
									}
							slog("up key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
						
							case SDLK_DOWN:
							if(OP < 3){
							OP++;
									}
							slog("down key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
							
															
							case SDLK_RETURN:
							switch(OP)
							{
							case 0:
							lvl = 0;
							setWorld();
							Mix_HaltMusic();
							done = 1;
							break;
							
							case 1:
							lvl = 1;
							setWorld();
							Mix_HaltMusic();
							done = 1;
							break;
							
							case 2:
							lvl = 2;
							setWorld();
							Mix_HaltMusic();
							done = 1;
							break;
							
							case 3:
							showMain();
							break;
							}

							break;
							}
					}
				}
	keys = SDL_GetKeyboardState(NULL);
	if(keys[SDL_SCANCODE_ESCAPE])
    {
        exit(1);
    }
	
  } while(!done);
	SDL_FreeSurface(Prixx);
	SDL_DestroyTexture(LVL1);
	SDL_FreeSurface(Stagee);
	SDL_DestroyTexture(LVL2);
	SDL_FreeSurface(Editt);
	SDL_DestroyTexture(LVL3);
	SDL_FreeSurface(Quitt);
	SDL_DestroyTexture(Quit);
  return;
}


void Results(int rank, int level)
{
	    menu_music = Mix_LoadMUS( "sfx/records3.mid" );	
	currentTime = mytime;
	SDL_Color textColor3 = {255,0,0,0};
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
	const Uint8 *keys;// the player
	int done;
	
int OP;
SDL_Texture* Next;
SDL_Texture* Edit;
SDL_Texture* Main;
SDL_Texture* Head;
SDL_Texture* Quit;

SDL_Rect r1;
SDL_Rect r2;
SDL_Rect r3;

SDL_Rect header;


char option1[32];
strcpy(option1 ,"Next");
char option2[32];
strcpy(option2 ,"Edit");
char option3[32];
strcpy(option3 ,"Main");

char option4[32];
if(rank==1)
strcpy(option4 ,"Congratualtions you placed 1st");
else
strcpy(option4 ,"...you placed 2nd");

OP = 0;

SDL_Surface *Nextt;
SDL_Surface *Editt;
SDL_Surface *Mainn;
SDL_Surface *Headd;

	
		
	r1.x = 350;
	r1.y = 300;
	r1.w = 120;
	r1.h = 25;
	
	r2.x = 350;
	r2.y = 350;
	r2.w = 120;
	r2.h = 25;

	r3.x = 350;
	r3.y = 400;
	r3.w = 120;
	r3.h = 25;

	header.x = 100;
	header.y = 50;
	header.w = 600;
	header.h = 40;
  if( font == NULL )
    {
     slog("font not loaded properly");
		return;
    }
	done = 0;

	do
  {
    
	if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                    Mix_PlayMusic( menu_music, -1 );
                  
					}
	  
	currentTime = mytime;
	Nextt = TTF_RenderText_Solid( font, option1, textColor );
	Editt = TTF_RenderText_Solid( font, option2, textColor );
	Mainn = TTF_RenderText_Solid( font, option3, textColor );
	Headd = TTF_RenderText_Solid( font, option4, textColor );
	
	
	switch(OP)
		{
		
		case 0:
		Nextt = TTF_RenderText_Solid( font, option1, textColor2 );
		break;
		
		case 1:
		Editt = TTF_RenderText_Solid( font, option2, textColor2 );
		break;
		
		case 2:
		Mainn = TTF_RenderText_Solid( font2, option3, textColor3 );
		break;
		
		}

	Next = SDL_CreateTextureFromSurface( renderer, Nextt );
	Edit = SDL_CreateTextureFromSurface( renderer, Editt );
	Main = SDL_CreateTextureFromSurface( renderer, Mainn );
	Head = SDL_CreateTextureFromSurface( renderer, Headd );
		SDL_RenderCopy(renderer,background,NULL,&screen);
	
	SDL_RenderCopy(renderer,Next,NULL,&r1);  
	SDL_RenderCopy(renderer,Edit,NULL,&r2);  
	
			
	
	SDL_RenderCopy(renderer,Head,NULL,&header);
	SDL_RenderCopy(renderer,Main,NULL,&r3);

	SDL_RenderPresent(renderer);

 	SDL_Event e;
	SDL_PollEvent( &e ); 
		if(&e)
			{
					
					if( e.type == SDL_KEYUP )
					{
							//Select surfaces based on key press
							switch( e.key.keysym.sym )
							{	
							case SDLK_UP:	
							if(OP > 0){
							OP--;
									}
							slog("up key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
						
							case SDLK_DOWN:
							if(OP < 2){
							OP++;
									}
							slog("down key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
							
															
							case SDLK_RETURN:
							switch(OP)
							{
							case 0:
							Mix_HaltMusic();
							done = 1;
							if(lvl == 3)
							{
								lvl == 0;
								Mix_HaltMusic();
								showMain();
							}
							//load next race
							break;
							
							case 1:
							done = 1;
							Editor(&mew);
							//open editor
							break;
							
							case 2:
							done = 1;
							lvl = 0;
							showMain();
							break;
							
							
							}

							break;
							}
					}
				}
		   keys = SDL_GetKeyboardState(NULL);

	if(keys[SDL_SCANCODE_ESCAPE])
    {
        exit(1);
    }
	
  } while(!done);

  	SDL_FreeSurface(Nextt);
	SDL_DestroyTexture(Next);
	SDL_FreeSurface(Editt);
	SDL_DestroyTexture(Edit);
	SDL_FreeSurface(Mainn);
	SDL_DestroyTexture(Main);
	SDL_FreeSurface(Headd);
	SDL_DestroyTexture(Head);
  
  return;
}

void EditorMAIN(player* p1)
{

	int selection;
int red = 128 ;
int green = 128 ;
int blue = 128;

menu_music = Mix_LoadMUS( "sfx/records3.mid" );
SDL_Color textColor3 = {255,0,0,0};
SDL_RenderClear(renderer);
SDL_RenderPresent(renderer);
const Uint8 *keys;// the player
int done;
int OP ;
done = 0;
Sprite_M* Car;
Car = spriteLoad("images/car_sheet1.png",128,128);
Vector2D pos;
char welcome[32];
SDL_Surface* Wel;
SDL_Texture* WEL;
SDL_Rect Top;
char rule1[32];
SDL_Rect RE1;
SDL_Surface* RULE1;
SDL_Texture* R1;
SDL_Surface* RULE2;
char rule2[50];
SDL_Texture* R2;
SDL_Rect RE2;
char rule3[32];
SDL_Surface* RULE3;
SDL_Texture* R3;
SDL_Rect RE3;
char rule4[32];
SDL_Surface* RULE4;
SDL_Texture* R4;
SDL_Rect RE4;

char Points[32];
SDL_Surface* POINTS;
SDL_Texture* P;
SDL_Rect PRect;


char Speed[32];
char Accel[32];
char Handling[32];

SDL_Rect SRect;
SDL_Rect ARect;
SDL_Rect HRect;

SDL_Surface* ACCEL;
SDL_Surface* SPEED;
SDL_Surface* HANDLING;

SDL_Texture* S;
SDL_Texture* A;
SDL_Texture* H;

int pts;
int spd;
int acl;
int han;

pts = p1->points;
spd = p1->SUP;
acl = p1->AUP;
han = p1->HUP;

strcpy(Points ,"Player Points: ");
pos.x = 80;
pos.y = 180;

currentTime = mytime;

strcpy(welcome ,"Welcome to the Editor");

Wel = TTF_RenderText_Solid( font, welcome, textColor3 );

WEL = SDL_CreateTextureFromSurface( renderer, Wel );

Top.x = 160;
Top.y = 20;
Top.w = 500;
Top.h = 40;

strcpy(rule1 ,"Use Q & W to cycle car models");

RULE1 = TTF_RenderText_Solid( font, rule1, textColor );

R1 = SDL_CreateTextureFromSurface( renderer, RULE1 );

RE1.x = 380;
RE1.y = 70;
RE1.w = 300;
RE1.h = 24;



strcpy(rule2 ,"Use UP and DOWN to select upgrade");

RULE2 = TTF_RenderText_Solid( font, rule2, textColor );

R2 = SDL_CreateTextureFromSurface( renderer, RULE2 );

RE2.x = 380;
RE2.y = 100;
RE2.w = 300;
RE2.h = 24;


strcpy(rule3 ,"Use SPACEBAR to spend points");

RULE3 = TTF_RenderText_Solid( font, rule3, textColor );


R3 = SDL_CreateTextureFromSurface( renderer, RULE3 );

RE3.x = 380;
RE3.y = 130;
RE3.w = 300;
RE3.h = 24;

strcpy(rule4 ,"Use ENTER to continue");

RULE4 = TTF_RenderText_Solid( font, rule4, textColor );
R4 = SDL_CreateTextureFromSurface( renderer, RULE4 );

RE4.x = 380;
RE4.y = 160;
RE4.w = 300;
RE4.h = 24;

PRect.x = 380;
PRect.y = 190;
PRect.w = 300;
PRect.h = 24;

SRect.x = 250;
SRect.y = 400;
SRect.w = 100;
SRect.h = 24;

ARect.x = 250;
ARect.y = 430;
ARect.w = 100;
ARect.h = 24;

HRect.x = 250;
HRect.y = 460;
HRect.w = 200;
HRect.h = 24;
OP = 0;


selection = 0;
readSave(&mew);
	do{

		if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                    Mix_PlayMusic( menu_music, -1 );
                  
					}
		
		SDL_RenderClear(renderer);
		sprintf(Points,"Player Points: %i", p1->points);
		sprintf(Speed,"Speed: %i", p1->SUP);
		sprintf(Accel,"Accel: %i", p1->AUP);
		sprintf(Handling,"Handling: %i", p1->HUP);


		POINTS  = TTF_RenderText_Solid( font, Points, textColor3 ) ;
		ACCEL = TTF_RenderText_Solid( font, Accel, textColor3 ) ;
		HANDLING = TTF_RenderText_Solid( font, Handling, textColor3 ) ;
		SPEED = TTF_RenderText_Solid( font, Speed, textColor3 ) ;

		
		switch(OP)
		{
		
		case 0:
		SPEED = TTF_RenderText_Solid( font, Speed, textColor );
		break;
		
		case 1:
		ACCEL = TTF_RenderText_Solid( font, Accel, textColor );
		break;
		
		case 2:
		HANDLING = TTF_RenderText_Solid( font, Handling, textColor );
		break;
		
		}// end switch

		A = SDL_CreateTextureFromSurface( renderer, ACCEL );
		H = SDL_CreateTextureFromSurface( renderer, HANDLING );
		S = SDL_CreateTextureFromSurface( renderer, SPEED );
		P = SDL_CreateTextureFromSurface( renderer, POINTS );

 	SDL_Event e;
	SDL_PollEvent( &e ); 
		if(&e)
			{
					
					if( e.type == SDL_KEYUP )
					{
							//Select surfaces based on key press
							switch( e.key.keysym.sym )
							{	
							
							case SDLK_KP_7:
							Car->color.r -= 10;
							if(Car->color.r < 0)
							Car->color.r = 0;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_8:
							Car->color.g -= 10;
							if(Car->color.b < 0)
							Car->color.b = 0;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_9: 
							Car->color.b -=10;
							if(Car->color.g < 0)
							Car->color.g = 0;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_4:
							Car->color.r += 10;
							if(Car->color.r > 250)
							Car->color.r = 250;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_5:
							Car->color.g += 10;
							if(Car->color.g > 250)
							Car->color.g = 250;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_6:
							Car->color.b += 10;
							if(Car->color.b > 250)
							Car->color.b = 250;
							e.type = SDLK_CLEAR;
							break;
							
							
							case SDLK_UP:	
							if(OP > 0){
							OP--;
									}
							slog("up key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
						
							case SDLK_DOWN:
							if(OP < 2){
							OP++;
									}
							slog("down key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_q:
							selection --;
							if(selection < 0)
								selection = 13;
								if(selection >0 && selection < 10)
									selection = 0;
							p1->frame = selection;
							slog("Q key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_w:
							selection++;
							if(selection >0 && selection < 10)
								selection = 10;
							if (selection > 13)
								selection=0;	
							slog("W key is up %i", OP);
							p1->frame = selection;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_SPACE:
							slog("SPACE key is up %i", OP);
							e.type = SDLK_CLEAR;
							if(p1->points>0)
							{
								switch (OP)
								{
								case 0:
									p1->points --;
									p1->SUP+=1;
								break;
								
								case 1:
								p1->points --;
								p1->AUP+=1;
								break;
								
								case 2:
								p1->points --;
								p1->HUP+=1;
								break;
								}
							}
							break;

							case SDLK_RETURN:
							writeToSave(&mew);
							Mix_HaltMusic();
							//oldTime = SDL_GetTicks();
							//currentTime = SDL_GetTicks();
							done = 1;
							break;
							}

					}
				}
		   keys = SDL_GetKeyboardState(NULL);

	if(keys[SDL_SCANCODE_ESCAPE])
    {
	done = 1;
    }
	
	SDL_RenderCopy(renderer,background,NULL,&screen);
	SDL_RenderCopy(renderer,H,NULL,&HRect);
	SDL_RenderCopy(renderer,A,NULL,&ARect);
	SDL_RenderCopy(renderer,S,NULL,&SRect);
	SDL_RenderCopy(renderer,P,NULL,&PRect);
	SDL_RenderCopy(renderer,R4,NULL,&RE4);
	SDL_RenderCopy(renderer,R3,NULL,&RE3);
	SDL_RenderCopy(renderer,R2,NULL,&RE2);
	SDL_RenderCopy(renderer,R1,NULL,&RE1);
	SDL_RenderCopy(renderer,WEL,NULL,&Top);
	
	spriteDraw(Car,renderer,mew.frame,pos);
	
	SDL_RenderPresent(renderer);

  
  } while(!done);
 
  SDL_DestroyTexture(R1);
  SDL_FreeSurface(RULE1);
  SDL_DestroyTexture(R2);
  SDL_FreeSurface(RULE2);
  SDL_DestroyTexture(R3);
  SDL_FreeSurface(RULE3);
  SDL_DestroyTexture(R4);
  SDL_FreeSurface(RULE4);
  SDL_DestroyTexture(WEL);
  SDL_FreeSurface(Wel);
  
  return;
		

}
void Editor(player* p1)
{
int selection;
int red = 128 ;
int green = 128 ;
int blue = 128;

menu_music = Mix_LoadMUS( "sfx/records3.mid" );
SDL_Color textColor3 = {255,0,0,0};
SDL_RenderClear(renderer);
SDL_RenderPresent(renderer);
const Uint8 *keys;// the player
int done;
int OP ;
done = 0;
Sprite_M* Car;
Car = spriteLoad("images/car_sheet1.png",128,128);
Vector2D pos;
char welcome[32];
SDL_Surface* Wel;
SDL_Texture* WEL;
SDL_Rect Top;
char rule1[32];
SDL_Rect RE1;
SDL_Surface* RULE1;
SDL_Texture* R1;
SDL_Surface* RULE2;
char rule2[50];
SDL_Texture* R2;
SDL_Rect RE2;
char rule3[32];
SDL_Surface* RULE3;
SDL_Texture* R3;
SDL_Rect RE3;
char rule4[32];
SDL_Surface* RULE4;
SDL_Texture* R4;
SDL_Rect RE4;

char Points[32];
SDL_Surface* POINTS;
SDL_Texture* P;
SDL_Rect PRect;


char Speed[32];
char Accel[32];
char Handling[32];

SDL_Rect SRect;
SDL_Rect ARect;
SDL_Rect HRect;

SDL_Surface* ACCEL;
SDL_Surface* SPEED;
SDL_Surface* HANDLING;

SDL_Texture* S;
SDL_Texture* A;
SDL_Texture* H;

int pts;
int spd;
int acl;
int han;

pts = p1->points;
spd = p1->SUP;
acl = p1->AUP;
han = p1->HUP;

strcpy(Points ,"Player Points: ");
pos.x = 80;
pos.y = 180;

currentTime = mytime;

strcpy(welcome ,"Welcome to the Editor");

Wel = TTF_RenderText_Solid( font, welcome, textColor3 );

WEL = SDL_CreateTextureFromSurface( renderer, Wel );

Top.x = 160;
Top.y = 20;
Top.w = 500;
Top.h = 40;

strcpy(rule1 ,"Use Q & W to cycle car models");

RULE1 = TTF_RenderText_Solid( font, rule1, textColor );

R1 = SDL_CreateTextureFromSurface( renderer, RULE1 );

RE1.x = 380;
RE1.y = 70;
RE1.w = 300;
RE1.h = 24;



strcpy(rule2 ,"Use UP and DOWN to select upgrade");

RULE2 = TTF_RenderText_Solid( font, rule2, textColor );

R2 = SDL_CreateTextureFromSurface( renderer, RULE2 );

RE2.x = 380;
RE2.y = 100;
RE2.w = 300;
RE2.h = 24;


strcpy(rule3 ,"Use SPACEBAR to spend points");

RULE3 = TTF_RenderText_Solid( font, rule3, textColor );


R3 = SDL_CreateTextureFromSurface( renderer, RULE3 );

RE3.x = 380;
RE3.y = 130;
RE3.w = 300;
RE3.h = 24;

strcpy(rule4 ,"Use ENTER to continue");

RULE4 = TTF_RenderText_Solid( font, rule4, textColor );
R4 = SDL_CreateTextureFromSurface( renderer, RULE4 );

RE4.x = 380;
RE4.y = 160;
RE4.w = 300;
RE4.h = 24;

PRect.x = 380;
PRect.y = 190;
PRect.w = 300;
PRect.h = 24;

SRect.x = 250;
SRect.y = 400;
SRect.w = 100;
SRect.h = 24;

ARect.x = 250;
ARect.y = 430;
ARect.w = 100;
ARect.h = 24;

HRect.x = 250;
HRect.y = 460;
HRect.w = 200;
HRect.h = 24;
OP = 0;


selection = 0;
readSave(&mew);
	do{

		if( Mix_PlayingMusic() == 0 )
                    {
                        //Play the music
                    Mix_PlayMusic( menu_music, -1 );
                  
					}


		SDL_RenderClear(renderer);
		sprintf(Points,"Player Points: %i", p1->points);
		sprintf(Speed,"Speed: %i", p1->SUP);
		sprintf(Accel,"Accel: %i", p1->AUP);
		sprintf(Handling,"Handling: %i", p1->HUP);


		POINTS  = TTF_RenderText_Solid( font, Points, textColor3 ) ;
		ACCEL = TTF_RenderText_Solid( font, Accel, textColor3 ) ;
		HANDLING = TTF_RenderText_Solid( font, Handling, textColor3 ) ;
		SPEED = TTF_RenderText_Solid( font, Speed, textColor3 ) ;

		
		switch(OP)
		{
		
		case 0:
		SPEED = TTF_RenderText_Solid( font, Speed, textColor );
		break;
		
		case 1:
		ACCEL = TTF_RenderText_Solid( font, Accel, textColor );
		break;
		
		case 2:
		HANDLING = TTF_RenderText_Solid( font, Handling, textColor );
		break;
		
		}// end switch

		A = SDL_CreateTextureFromSurface( renderer, ACCEL );
		H = SDL_CreateTextureFromSurface( renderer, HANDLING );
		S = SDL_CreateTextureFromSurface( renderer, SPEED );
		P = SDL_CreateTextureFromSurface( renderer, POINTS );

 	SDL_Event e;
	SDL_PollEvent( &e ); 
		if(&e)
			{
					
					if( e.type == SDL_KEYUP )
					{
							//Select surfaces based on key press
							switch( e.key.keysym.sym )
							{	
							
							case SDLK_KP_7:
							Car->color.r -= 10;
							if(Car->color.r < 0)
							Car->color.r = 0;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_8:
							Car->color.g -= 10;
							if(Car->color.b < 0)
							Car->color.b = 0;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_9: 
							Car->color.b -=10;
							if(Car->color.g < 0)
							Car->color.g = 0;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_4:
							Car->color.r += 10;
							if(Car->color.r > 250)
							Car->color.r = 250;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_5:
							Car->color.g += 10;
							if(Car->color.g > 250)
							Car->color.g = 250;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_KP_6:
							Car->color.b += 10;
							if(Car->color.b > 250)
							Car->color.b = 250;
							e.type = SDLK_CLEAR;
							break;
							
							
							case SDLK_UP:	
							if(OP > 0){
							OP--;
									}
							slog("up key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
						
							case SDLK_DOWN:
							if(OP < 2){
							OP++;
									}
							slog("down key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_q:
							selection --;
							if(selection < 0)
								selection = 13;
								if(selection >0 && selection < 10)
									selection = 0;
							p1->frame = selection;
							slog("Q key is up %i", OP);
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_w:
							selection++;
							if(selection >0 && selection < 10)
								selection = 10;
							if (selection > 13)
								selection=0;	
							slog("W key is up %i", OP);
							p1->frame = selection;
							e.type = SDLK_CLEAR;
							break;
							
							case SDLK_SPACE:
							slog("SPACE key is up %i", OP);
							e.type = SDLK_CLEAR;
							if(p1->points>0)
							{
								switch (OP)
								{
								case 0:
									p1->points --;
									p1->SUP+=1;
								break;
								
								case 1:
								p1->points --;
								p1->AUP+=1;
								break;
								
								case 2:
								p1->points --;
								p1->HUP+=1;
								break;
								}
							}
							break;

							case SDLK_RETURN:
							writeToSave(&mew);
							Mix_HaltMusic();
							//oldTime = SDL_GetTicks();
							//currentTime = SDL_GetTicks();
							done = 1;
							break;
							}

					}
				}
		   keys = SDL_GetKeyboardState(NULL);

	if(keys[SDL_SCANCODE_ESCAPE])
    {
        done = 1;
    }
	
	SDL_RenderCopy(renderer,background,NULL,&screen);
	SDL_RenderCopy(renderer,H,NULL,&HRect);
	SDL_RenderCopy(renderer,A,NULL,&ARect);
	SDL_RenderCopy(renderer,S,NULL,&SRect);
	SDL_RenderCopy(renderer,P,NULL,&PRect);
	SDL_RenderCopy(renderer,R4,NULL,&RE4);
	SDL_RenderCopy(renderer,R3,NULL,&RE3);
	SDL_RenderCopy(renderer,R2,NULL,&RE2);
	SDL_RenderCopy(renderer,R1,NULL,&RE1);
	SDL_RenderCopy(renderer,WEL,NULL,&Top);
	
	spriteDraw(Car,renderer,mew.frame,pos);
	
	SDL_RenderPresent(renderer);

  
  } while(!done);
 
  SDL_DestroyTexture(R1);
  SDL_FreeSurface(RULE1);
  SDL_DestroyTexture(R2);
  SDL_FreeSurface(RULE2);
  SDL_DestroyTexture(R3);
  SDL_FreeSurface(RULE3);
  SDL_DestroyTexture(R4);
  SDL_FreeSurface(RULE4);
  SDL_DestroyTexture(WEL);
  SDL_FreeSurface(Wel);
  
  return;
		
}