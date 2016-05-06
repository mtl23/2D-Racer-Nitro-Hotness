#ifndef _GUI_H_
#define _GUI_H_
#include "player.h"
#include "SDL_ttf.h"

/**
*@brief define the Gui object for HUB purposes
*@param TTF_Font* font the font to be used ofr the GUI
*@param SDL_Surface *timer the surface to store the game time
*@param SDL_Surface *speed the surface to store the player speed
*@param SDL_Rect speeddst the rectangle to output the player speed
*@param SDL_Rect timedst the rectangle to output the game time
*@param SDL_Texture* GUI1 The texture used to output the player speed
*@param SDL_Texture* GUI2 The texture used to output the game time
*@param SDL_Color textColor The color of the font
*/
typedef struct
{

TTF_Font* font; 
SDL_Surface *timer;
SDL_Surface *speed;
SDL_Surface *rank;
SDL_Surface *mph;
SDL_Surface *ranker;

SDL_Rect speeddst;
SDL_Rect timedst;
SDL_Rect rankdst;
SDL_Texture* GUI1; //speed digit 1
SDL_Texture* GUI2; // speed digit 10
SDL_Texture* GUI3;
SDL_Color textColor;
SDL_Color textColor2;

SDL_Rect speeddst2; //the mph word
SDL_Rect rankdst2; //the rank word
SDL_Texture* GUI4;
SDL_Texture* GUI5;

}GUI;
/**
*@brief draws the time and speed of the car
*@return a GUI type object to be used for DrawGui
*/
GUI InitGUI();

/**
*@brief draws the time and speed of the car
*@param GUI the specific GUI object used for rendering
*@param *player used to output player speed
*@param font display font
*/
void DrawGui(GUI HUD, player p1);


#endif