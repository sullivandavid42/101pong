##
## Makefile for pong101 in /home/david_h/labo/pong101
## 
## Made by Sullivan David
## Login   <david_h@epitech.net>
## 
## Started on  Thu Nov  6 18:14:36 2014 david_h
## Last update Thu Nov 13 10:29:42 2014 carle_s
##

NAME	= pong

LIB 	= -lSDL2 -lSDL2_image -lm ./lib/libmy.a

SRC	= main.c \
	  event.c \
	  splash_screen.c \
	  init.c \
	  ball.c \
	  calc.c \
	  pong_math.c

OBJ	= $(SRC:.c=.o)

all: $(NAME)

$(NAME):
	gcc -c $(SRC)
	gcc -o $(NAME) $(OBJ) $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all
