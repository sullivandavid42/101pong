/*
** pos_struct.h for pong101 in /home/carle_s/
** 
** Made by Carle Sacha
** Login   <carle_s@epitech.net>
** 
** Started on  Tue Oct 28 17:33:55 2014 Carle Sacha
** Last update Thu Nov 13 10:21:48 2014 carle_s
*/

#ifndef POS_STRUCT_H_
#define POS8STRUCT_H_

typedef struct		s_pos_3d
{
  int			x;
  int			y;
  int			z;
  struct s_pos_3d	*old;
} pos; 

typedef pos *POS;

POS	ball_move_3(POS ball);
POS	newpos(int x, int y, int z);
float	angle(POS ball);

#endif /* POS_STRUCT_H_ */
