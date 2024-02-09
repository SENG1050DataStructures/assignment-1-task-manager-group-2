#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.c"

#define MAX_TITLE_SIZE 100
#define MAX_DESCRIPTION_SIZE 100

int GLOBAL_TASKID = -1;


// Prototypes
typedef struct Task Task;
Task* createNode(void);
void addToHead(Task** head);
void addToTail(Task** head);

struct Task {
	int TaskId;
	char Title[MAX_TITLE_SIZE];
	char Description[MAX_DESCRIPTION_SIZE];
	Task* NextTask;
};

//Josh
int main(void) {
	
	int userInput = -1;

    Task* head = NULL;


	while (userInput != EXIT) {

		drawMenu();

		userInput = getNum();
        switch (userInput) {
        case ADD_TASK_HEAD:
            addToHead(&head);
            break;

        case ADD_TASK_TAIL:
            addToTail(&head);
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

	return 0;
}

//Josh
Task* createNode(void) {
    
    Task* newNode = (Task*)malloc(sizeof(Task));

    if (newNode == NULL) {
        printf("ERROR: Malloc failure when creating node");
        exit(1);
    }

    newNode->TaskId = ++GLOBAL_TASKID;
    newNode->NextTask = NULL;

    //By Marcus & Josh
    clearScreen();
    moveCursor(0, 0);
    printf("---------------------------\n");
    printf("|Please enter Task details|\n");
    printf("---------------------------\n");
    printf("Title: \n");
    printf("Description: \n");

    moveCursor(8, 4);
    fgets(newNode->Title, MAX_TITLE_SIZE, stdin);
    replaceChar(newNode->Title, '\n', '\0');

    moveCursor(14, 5);
    fgets(newNode->Description, MAX_DESCRIPTION_SIZE, stdin);
    replaceChar(newNode->Description, '\n', '\0');

	return newNode;
}


//Marcus
void addToHead(Task** head) {

    Task* newTask = createNode();

    if (*head != NULL) {
        newTask->NextTask = *head;
    }
    *head = newTask;
}

//Marcus
void addToTail(Task** head) {

    Task* newTask = createNode();
    
    if (*head == NULL) {
        *head = newTask;
        return;
    }

    Task* current = *head;
    while (current->NextTask != NULL) {
        current = current->NextTask;
    }
    current->NextTask = newTask;
}