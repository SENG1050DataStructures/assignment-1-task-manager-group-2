#pragma once
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "Menu.c"

#define MAX_TITLE_SIZE 100
#define MAX_DESCRIPTION_SIZE 100
#define MAX_ARRAY_SIZE 100

int GLOBAL_TASKID = -1;


// Prototypes
typedef struct Task Task;
Task* createNode(void);
void addToHead(Task** head);
void addToTail(Task** head);
void DeleteTaskByTaskId(Task** head);

void FindTaskByIndex(Task* head);
void FreeList(Task* head);
void PrintTasks(Task* head);


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

        switch (userInput = getNum()) {

        case ADD_TASK_HEAD:
            addToHead(&head);
            break;

        case ADD_TASK_TAIL:
            addToTail(&head);
            break;

        case DELETE_TASK:
            DeleteTaskByTaskId(&head);
            break;

        case FIND_TASK:        
            FindTaskByIndex(head);         
            break;

        case PRINT_TASKS:
            PrintTasks(head);
            break;

        case EXIT:
            //Do nothing
            break;

        default:
            printf("\n\n\tInvalid Input.\a");
        }

        if (userInput != EXIT) {
            printf("\n\n\tPress any key to continue.");
            _getch();
        }
	}

    FreeList(head);

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

//Abdullah
void FindTaskByIndex(Task* head) {

    clearScreen();
    if (head == NULL) {
        printf("No Tasks found.\a");
        return;
    }
    printf("Enter index: ");
    int index = getNum();

    if (index == -1) {
        printf("\n\nInvalid input.\a");
        return;
    }

    clearScreen();
    Task* current = head;
    int count = 0;
    while (current != NULL) {
        if (count == index) {
            printf("Task at index %d: \nID: %d\nTitle: %s\nDescription: %s",
                index, current->TaskId, current->Title, current->Description);
            return;
        }
        count++;
        current = current->NextTask;
    }
    printf("Index not available in existing list.");
}

//Abdullah
void FreeList(Task* head) {

    Task* current = head;
    Task* newNode;

    while (current != NULL) {
        newNode = current->NextTask;
        free(current);
        current = newNode;
    }

}

// Joseph
void DeleteTaskByTaskId(Task** head)
{
    clearScreen();
    if (*head == NULL) {
        printf("No Tasks found.\a");
        return;
    }
    printf("Enter Task Id to delete: ");
    int inputTaskId = -1;
    if ((inputTaskId = getNum()) == -1) {
        printf("\n\nInvalid input.\a");
        return;
    }

    Task** trav = head;
    for (; *trav != NULL && (*trav)->TaskId != inputTaskId; trav = &(*trav)->NextTask) {

    }

    if (*trav == NULL) {
        clearScreen();
        printf("Task with ID %d not found\n", inputTaskId);
        return;
    }

    Task* temp = *trav;
    *trav = temp->NextTask;
    free(temp);
}

//Joseph
void PrintTasks(Task* head)
{
    clearScreen();
    if (head == NULL)
    {
        printf("No Tasks found.\a");
        return;
    }

    for (Task* trav = head; trav != NULL; trav = trav->NextTask)
    {
        printf("Task ID : % d\n", trav->TaskId);
        printf("Task Title: %s\n", trav->Title);
        printf("Task Description: %s\n\n", trav->Description);
    }
}