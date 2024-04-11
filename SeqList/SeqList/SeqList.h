#pragma once
#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
#include<stdlib.h>

typedef int custom;

#define N 4
#define ADD 2

typedef struct seqlist
{
	custom* a;
	int capacity;
	int size;
}Sl;

void SeqlistInfo(Sl* ps);
void Seqlistpushfoint(Sl* ps, custom num);
void Seqlistpopfoint(Sl* ps);
void Seqlistpushback(Sl* ps, custom num);
void Seqlistpushappoint(Sl* ps, custom num, int slot);
void Seqlistpopappoint(Sl* ps, int slot);
void Seqlistsearch(Sl* ps, custom num);
void Seqlistprint(Sl* ps);