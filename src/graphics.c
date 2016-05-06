#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "graphics.h"


#define MaxSprites    255
  extern SDL_Renderer* renderer;
  extern int lvl;
Uint32 NOW;					/*the current time since program started*/


void NextFrame()
{
  Uint32 Then;
  SDL_RenderPresent(renderer);
  Then = NOW;									/*these next few lines  are used to show how long each frame takes to update.  */
  NOW = SDL_GetTicks();

  //fprintf(stdout,"Ticks passed this frame: %i\n", NOW - Then);
  FrameDelay(30); /*this will make your frame rate about 30 frames per second.  If you want 60 fps then set it to about 15 or 16*/
}

void FrameDelay(Uint32 delay)
{
    static Uint32 pass = 100;
    Uint32 dif;
    dif = SDL_GetTicks() - pass;
    if(dif < delay)SDL_Delay( delay - dif);
    pass = SDL_GetTicks();
}


