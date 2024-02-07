#include <stdio.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0

enum Menu {
	INVALID = -2,
	MAIN_MENU = -1,
	ADD_TASK_HEAD = 49,
	ADD_TASK_TAIL = 50,
	DELETE_TASK = 51,
	FIND_TASK = 52,
	PRINT_TASKS = 53,
	EXIT = 54

};


void moveCursor(int x, int y);
void clearScreen(void);

void drawMenu(int input);
void menuSwitch(int userInput);

int getMenuInput(void);


//Not sure if I'll need to do input parsing or if people will do their own?
int getNum(char* buffer);
char* getStr(char* buffer);



void moveCursor(int x, int y) {
	
	printf("\033[%d;%dH", y, x);

}
void clearScreen(void) {

	printf("\033[2J");

}

int getMenuInput(void) {
	int input = -1;

	if (_kbhit() != NULL) {
		input = _getch();
		while (_kbhit())_getch();
	}

	return input;
}
void menuSwitch(int userInput) {

	switch (userInput) {
	case ADD_TASK_HEAD:
		//Add to head
		break;

	case ADD_TASK_TAIL:
		//Add to tail
		break;

	case DELETE_TASK:
		//Delete by ID
		break;

	case FIND_TASK:
		//Find by index
		break;

	case PRINT_TASKS:
		//Print tasks
		break;

	case EXIT:
		//Do nothing
		break;

	default:
		printf("\a");
	}

}
void drawMenu(int input) {

	clearScreen();
	moveCursor(0, 0);


	printf("|---------------------------------|\n");
	printf("|            Main Menu            |\n");
	printf("|---------------------------------|\n");
	printf("|                                 |\n");
	printf("| 1. Add Task to Head             |\n");
	printf("| 2. Add Task to Tail             |\n");
	printf("| 3. Delete Task                  |\n");
	printf("| 4. Find Task                    |\n");
	printf("| 5. Print Tasks                  |\n");
	printf("| 6. Exit                         |\n");
	printf("|                                 |\n");
	printf("|---------------------------------|\n");
	printf("\n");
		
}
