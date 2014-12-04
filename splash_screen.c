/*
** splash_screen.c for pong101 in /home/david_h/labo/pong101
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Tue Nov 11 13:48:50 2014 david_h
** Last update Tue Nov 11 14:55:53 2014 david_h
*/

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdio.h>
#include <stdlib.h>
#include "./include/defs.h"

int		load_splash(SDL_Renderer *renderer, char *path)
{
  SDL_Texture	*pong;
  int	w, h;
  SDL_Event event;
  bool quit;

  quit = false;
  w = 640;
  h = 480;
  pong = IMG_LoadTexture(renderer, path);
  SDL_QueryTexture(pong, NULL, NULL, &w, &h);
  if (pong == NULL)
    {
      printf("Can't Load %s", path);
      return (0);
    }
  while (!quit)
    {
      SDL_PollEvent(&event);
      switch (event.type)
        {
        case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
            {
            case SDLK_UP:
              {
                quit = true;
                return (1);
              }
	      break;
	    }
	}
      SDL_RenderCopy(renderer, pong, 0, 0);
      SDL_RenderPresent(renderer);
    }
  SDL_DestroyTexture(pong);
  //  SDL_RenderClear(renderer);
}
