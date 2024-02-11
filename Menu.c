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



//Not sure if I'll need to do input parsing or if people will do their own?
int getNum(void) {
	char buffer[100];
	int num = -1;

	fgets(buffer, 100, stdin);
	if (sscanf(buffer, "%d", &num) == 0) {
		num = -1;
	}
	return num;
}

int replaceChar(char* buffer, char target, char newChar) {
	int replaceCount = 0;
	for (int i = 0; i < strlen(buffer); i++) {
		if (buffer[i] == target) {
			buffer[i] = newChar;
		}
	}
	return replaceCount; 
}


void moveCursor(int x, int y) {
	
	printf("\033[%d;%dH", y, x);

}
void clearScreen(void) {

	printf("\033[2J");
	moveCursor(0, 0);
}

void drawMenu(void) {

	clearScreen();

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
	printf("\tPlease select: ");
		
}
