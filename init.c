/*
** init.c for pong101 in /home/david_h/labo/pong101
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Thu Nov  6 18:02:49 2014 david_h
** Last update Sun Nov  9 13:20:27 2014 david_h
*/

#include <SDL2/SDL.h>

int		create_win_context(SDL_Window **win, char *title, int x, int y)
{
  *win = SDL_CreateWindow(title, 
			  SDL_WINDOWPOS_UNDEFINED,
			  SDL_WINDOWPOS_UNDEFINED,
			  x, y,
			  SDL_WINDOW_SHOWN);
  if (win == NULL)
    {
      printf("Error while creating window context");
      return (0);
    }
}

int		create_renderer(SDL_Renderer **renderer_pp, SDL_Window **win)
{
  *renderer_pp = SDL_CreateRenderer(*win, 0, SDL_RENDERER_ACCELERATED);
  if (*renderer_pp == NULL)
    {
      printf("Renderer Error");
      return (0);
    }
}

void	destroy_SDL(SDL_Renderer *renderer, SDL_Window **win)
{
  SDL_DestroyWindow(*win);
  SDL_DestroyRenderer(renderer);
  SDL_Quit();
}
