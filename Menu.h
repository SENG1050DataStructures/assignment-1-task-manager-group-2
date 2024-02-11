#pragma once

#include <stdio.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0


enum Menu {
	ADD_TASK_HEAD = 1,
	ADD_TASK_TAIL = 2,
	DELETE_TASK = 3,
	FIND_TASK = 4,
	PRINT_TASKS = 5,
	EXIT = 6

};

int getNum(void);
int replaceChar(char* buffer, char target, char newChar);

void moveCursor(int x, int y);
void clearScreen(void);

void drawMenu(void);