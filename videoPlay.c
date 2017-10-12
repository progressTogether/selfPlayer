#include <stdio.h>

#include"SDL.h"

 SDL_Surface *screen = NULL;
 //screen = SDL_SetVideoMode(640,480,8,SDL_SWSURFACE);
 const int SCREEN_BPP = 32;

  char * const title = "Video Player";
  SDL_Window *window = NULL;

 void display_bmp(char* file_name)
 {
     SDL_Surface* image = NULL;

     /* Load the BMP file into a surface */
     image = SDL_LoadBMP(file_name);
     if (image == NULL) {
         fprintf(stderr, "Couldn't load %s: %s\n", file_name, SDL_GetError());
         return;
     }

     /*
      * Palettized screen modes will have a default palette (a standard
      * 8*8*4 colour cube), but if the image is palettized as well we can
      * use that palette for a nicer colour matching
      */
     if (image->format->palette && screen->format->palette) {
         //SDL_SetColors(screen, image->format->palette->colors, 0, image->format->palette->ncolors);
     }

     /* Blit onto the screen surface */
     if (SDL_BlitSurface(image, NULL, screen, NULL) < 0)
         fprintf(stderr, "BlitSurface error: %s\n", SDL_GetError());

     /* Update the modified region of the screen */
     //SDL_UpdateRect(screen, 0, 0, image->w, image->h);
     SDL_Rect rects;
     rects.x = 0;
     rects.y = 0;
	 rects.w = image->w;
	 rects.h = image->h;
     SDL_UpdateWindowSurfaceRects(window,&rects,1);
     /* Free the allocated BMP surface */
     SDL_FreeSurface(image);
 }


 int main(int argc, char **argv)
 {

     SDL_Init(SDL_INIT_EVERYTHING);

     window = SDL_CreateWindow(title,600,300,600,600,SDL_SWSURFACE);

     screen = SDL_GetWindowSurface(window);

     if (screen == NULL)
         return -1;

     display_bmp("./test.bmp");

     getchar();
     return 0;
 }
