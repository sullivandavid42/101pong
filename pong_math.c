/*
** pong_math.c for pong101 in /home/carle_s/
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Tue Oct 28 17:33:55 2014 Carle Sacha
** Last update Thu Nov 13 10:21:16 2014 carle_s
*/

#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include "./include/my.h"
#include "./include/pos_struct.h"

POS	ball_move_3(POS ball)
{
  POS	new;

  new = malloc(sizeof(pos));
  new->x = ball->x + (ball->x - ball->old->x);
  new->y = ball->y + (ball->y - ball->old->y);
  new->z = ball->z + (ball->z - ball->old->z);
  new->old = ball;
  return (new);
}

int	pos_long(POS a, POS b)
{
  return (sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2)));
}

float		angle(POS ball)
{
  float		x;
  float		y;
  float		z;
  float 	angle;

  x = (float) ball->x - ball->old->x;
  y = (float) ball->y - ball->old->y;
  z = (float) ball->z - ball->old->z;
  angle = z / (sqrt(pow(x, 2) + pow(y, 2) + pow(z, 2)));
  angle = ((180 * acos(angle)) / M_PI) - 90; 
  return (angle);
}
