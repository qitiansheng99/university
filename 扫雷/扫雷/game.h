#define _CRT_SECURE_NO_WARNINGS 1
#define ROW 9
#define COL 9

#define COLS COL+2
#define ROWS ROW+2

#define count 10
#include<stdio.h>
#include<time.h>
#include<stdlib.h>

void Initboard(char board[ROWS][COLS],int r,int c,char set);
void Setmine(char board[ROWS][COLS], int r, int c);
void Display(char board[ROWS][COLS], int r, int c);
void Findmine(char mine[ROWS][COLS],char show[ROWS][COLS],int r,int c);