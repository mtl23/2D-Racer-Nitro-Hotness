#include <stdio.h>;
#include"player.h";
#include "simple_logger.h";

void writeToSave(player* p1)
{
 
 FILE *f = fopen("player.txt", "w+");

 fprintf(f,"%i\n",p1->points);
 
 fprintf(f,"%i\n",p1->SUP);

 fprintf(f,"%i\n",p1->AUP);
 
 fprintf(f,"%i\n",p1->HUP);
 
 fprintf(f,"%i\n",p1->frame);
   
fclose(f);
}

void readSave(player* p1)
{
FILE *f = fopen("player.txt", "r+");

  int i = 0;
  int set [5];
  int p;
  p=0;
  fscanf (f, "%d", &i);    
  while (!feof (f))
    {  
    //  printf ("%d ", i);
      set[p] = i;
	  fscanf (f, "%d", &i);      
	  p++;
  }
//slog("%i,%i,%i,%i,%i",set[0],set[1],set[2],set[3],set[4]);

p1->points = set[0];
p1->SUP =  set[1];
p1->AUP =  set[2];
p1->HUP = set[3];
p1->frame = set[4];

slog("%i,%i,%i,%i,%i",p1->points,p1->SUP,p1->AUP,p1->HUP,p1->frame);
fclose(f);
}