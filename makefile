# makefile for Connect Four game

#
# !!!!! DO NOT MODIFY THIS FILE !!!!!
#

CC = gcc
CFLAGS = -Wall -std=c11
LDFLAGS = -lm
RM = rm -f

connect : connect_cli.o connect_game.o
	$(CC) $(LDFLAGS) -o $@ $^

connect_cli.o : connect_cli.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
connect_game.o : connect_game.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
.PHONY : clean		
clean:
	$(RM) connect connect_cli.o connect_game.o
