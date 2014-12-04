/*
** main.c for pong101 in /home/david_h/labo/pong101
** 
** Made by Sullivan David
** Login   <david_h@epitech.net>
** 
** Started on  Thu Nov  6 18:09:36 2014 david_h
** Last update Thu Nov 13 10:27:30 2014 carle_s
*/

#include <stdlib.h>
#include <SDL2/SDL.h>

int		main(int ac, char *av)
{
  SDL_Window	*window;
  SDL_Renderer	*renderer;

  create_win_context(&window, "DAT PoONG", 640, 480);
  create_renderer(&renderer, &window);
  if (load_splash(renderer, "pong.png") == 1)
    {
      SDL_DestroyRenderer(renderer);
      renderer = SDL_CreateRenderer(window, 0, SDL_RENDERER_ACCELERATED);
      wait_event(renderer);
    }
  //wait_event(renderer);
  destroy_SDL(renderer, &window);
  pong_calc(ac, av);
  return (0); 
}
