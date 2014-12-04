/*
** ball.c for 101pong in /home/carle-s/pong
** 
** Made by carle_s
** Login   <carle-s@epitech.net>
** 
** Started on  Tue Nov 11 15:16:48 2014 carle_s
** Last update Tue Nov 11 17:04:16 2014 carle_s
*/

#include <SDL2/SDL.h>
#include "./include/defs.h"

void	ball_copy(SDL_Rect *ball, SDL_Rect *dest)
{
  dest->x = ball->x;
  dest->y = ball->y;
  dest->w = ball->w;
  dest->h = ball->h;
}

void	init_ball(SDL_Rect *ball, SDL_Rect *bold)
{
  ball->x = BALL_X;
  ball->y = BALL_Y;
  ball->w = BALL_WH;
  ball->h = BALL_WH;
  ball_copy(ball, bold);
  bold->x = bold->x - BALL_V_X;
  bold->y = bold->y - BALL_V_Y;
}

int		ball_move(SDL_Rect *ball, SDL_Rect *bold, SDL_Rect *r1, SDL_Rect *r2)
{
  SDL_Rect	swap;

  ball_copy(ball, &swap);
  ball->x = ball->x + (ball->x - bold->x);
  ball->y = ball->y + (ball->y - bold->y);
  if (ball->y >= 480)
    {
      ball->y = ball->y - 2 * (swap.y - bold->y);
    }
  if (ball->y <= 0)
    {
      ball->y = ball->y - 2 * (swap.y - bold->y);
    }
  if (ball->x <= 50)
    {
      if (ball->y >= r1->y && ball->y <= r1->y + 64 && ball->x >= 30)
	{
	  ball->x = ball->x - 2 * (swap.x - bold->x);
	}
    }
  if (ball->x >= 590)
    {
      if (ball->y >= r2->y && ball->y <= r2->y + 64 && ball->x <= 610)
	{
	  ball->x = ball->x - 2 * (swap.x - bold->x);
	}
    }
  if (ball->x >= 640 || ball->x <= 0)
    {
      init_ball(ball, bold);
      return (0);
    }
  ball_copy(&swap, bold);
  printf("\n%d %d, %d %d, %d %d", ball->x, ball->y, bold->x, bold->y, ball->x - bold->x, ball->y - bold->y);
  return (1);
}
