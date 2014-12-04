/*
** event.c for pong101 in /home/david_h/labo/pong101
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Thu Nov  6 18:23:47 2014 david_h
** Last update Tue Nov 11 17:07:49 2014 carle_s
*/

#include <SDL2/SDL.h>
#include "./include/defs.h"

void    pos_raq_p1(SDL_Rect *raq_p1, int *y_p1)
{
  raq_p1->x = 30;
  raq_p1->y = *y_p1;
  raq_p1->w = 20;
  raq_p1->h = 64;
}

void    pos_raq_p2(SDL_Rect *raq_p2, int *y_p2)
{
  raq_p2->x = 590;
  raq_p2->y = *y_p2;
  raq_p2->w = 20;
  raq_p2->h = 64;
}

void    up_renderer(SDL_Renderer *renderer)
{
  SDL_RenderPresent(renderer);
  SDL_RenderClear(renderer);
}

void    print_game(SDL_Renderer *renderer, SDL_Rect *raq_p1, SDL_Rect *raq_p2, SDL_Rect *ball)
{
  SDL_RenderDrawLine(renderer, 320, 0, 320, 480);
  SDL_RenderDrawRect(renderer, &(*raq_p1));
  SDL_RenderDrawRect(renderer, &(*raq_p2));
  SDL_RenderDrawRect(renderer, &(*ball));
  up_renderer(renderer);
}

int             wait_event(SDL_Renderer *renderer)
{
  bool          quit;
  int           y_p1;
  int           y_p2;
  SDL_Event     event;
  SDL_Rect      raq_p1;
  SDL_Rect      raq_p2;
  SDL_Rect      ball;
  SDL_Rect      bold;

  quit = false;
  init_ball(&ball, &bold);
  y_p1 = 240;
  y_p2 = 240;
  while (!quit)
    {
      printf("x");
      SDL_Delay(2);
      SDL_PollEvent(&event);
      switch (event.type)
        {
        case SDL_KEYDOWN:
          switch(event.key.keysym.sym)
            {
            case SDLK_ESCAPE: 
              {
                quit = true; 
                return (0); 
              }
            case SDLK_UP: 
              {
                if (y_p1 > 0)
                  y_p1--; 
                else 
                  break; 
                break;
              }
            case SDLK_DOWN:
              {
                if (y_p1 < 480 - 64) 
                  y_p1++; 
                else 
                  break; 
                break;
              }
            case SDLK_LEFT:
              {
                if (y_p2 < 480 - 64) 
                  y_p2++; 
                else 
                  break; 
                break;
              }
            case SDLK_RIGHT:
              {
                if (y_p2 > 0) 
                  y_p2--; else 
                  break; 
                break;
              }
            }
          break;
        }
      pos_raq_p1(&raq_p1, &y_p1);
      pos_raq_p2(&raq_p2, &y_p2);
      ball_move(&ball, &bold, &raq_p1, &raq_p2);
      print_game(renderer, &raq_p1, &raq_p2, &ball);
    }
}
