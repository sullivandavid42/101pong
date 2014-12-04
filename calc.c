/*
** calc.c for pong101 in /home/carle_s/
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Tue Oct 28 17:33:55 2014 Carle Sacha
** Last update Thu Nov 13 10:27:37 2014 carle_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./include/my.h"
#include "./include/pos_struct.h"

int		pong_calc(int ac, char **av)
{
  POS		ball;
  int		n;
  int		nstart;
  float       	inc;

  if (ac != 8)
    {
      my_putstr("usage : X0 Y0 Z0 X1 Y1 Z1 n\n");
      return (0);
    }
  ball = malloc(sizeof(pos));
  ball->old = malloc(sizeof(pos));
  ball->old->old = NULL;
  ball->old->x = my_getnbr(av[1]);
  ball->old->y = my_getnbr(av[2]);
  ball->old->z = my_getnbr(av[3]);
  ball->x = my_getnbr(av[4]);
  ball->y = my_getnbr(av[5]);
  ball->z = my_getnbr(av[6]);
  n = my_getnbr(av[7]);
  nstart = n;
  while (n > 0)
  {
    ball = ball_move_3(ball);
    n = n - 1;
  }
  printf("\n\nLes coordonnées du vecteur vitesse sont : (%d,%d,%d).\n", ball->x - ball->old->x, ball->y - ball->old->y, ball->z - ball->old->z);
  printf("A l'instant t+%d, les coordonées de la balle seront (%d,%d,%d).\n", nstart, ball->x, ball->y, ball->z);
  printf("L'angle d'incidence est de %2.2f degrés.\n", angle(ball));
  return (0);
}
