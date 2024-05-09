#pragma once

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>
#include<assert.h>

typedef int typedata;

typedef struct Stack
{
	typedata* a;
	int top;
	int capacity;
}ST;

void StackInit(ST* ps);
void StackDestory(ST* ps);
void StackPush(ST* ps, typedata x);
void StackPop(ST* ps);
typedata StackTop(ST* ps);
int StackSize(ST* ps);
bool StackEmpty(ST* ps);