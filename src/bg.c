
#include "SDL.h"
#include "SDL_image.h"
#include "simple_logger.h"
#include "bg.h"
#include "sprite.h"
extern    SDL_Renderer* renderer;

void DrawBG(Sprite_M bg1, Sprite_M bg2 )
{
  SDL_Rect gdstRect={0,240,800,360};//for GrassBG
  SDL_Rect dstRect={0,0,800,240};//for BG
  
  SDL_RenderCopy(renderer, bg1.image, NULL,&dstRect);
  SDL_RenderCopy(renderer, bg2.image, NULL,&gdstRect);
}