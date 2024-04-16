#define _CRT_SECURE_NO_WARNINGS 1
#define row 10
#define col 10
#include<stdlib.h>
#include<stdio.h>
#include<time.h>
void Initbroad(char arr[row][col], int r, int c);
void Display(char arr[row][col], int r, int c);
void Player1(char arr[row][col], int r, int c);
void Player2(char arr[row][col], int r, int c);
void Computer(char arr[row][col], int r, int c);
char Iswin(char arr[row][col], int r, int c);