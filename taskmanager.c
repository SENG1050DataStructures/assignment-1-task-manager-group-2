#include <string.h>
#include <stdio.h>
#include <stdlib.h>


#define MAX_TITLE_SIZE 100
#define MAX_DESCRIPTION_SIZE 100

typedef struct Task {
	int TaskId;
	char Title[MAX_TITLE_SIZE];
	char Description[MAX_DESCRIPTION_SIZE];
	Task* NextTask;
} Task;

Task* createNode(int id, char* title, char* description);



int main(void) {



	return 0;
}

Task* createNode(int id, char* title, char* description) {

	Task* newNode = (Task*)malloc(sizeof(Task));

	if (newNode == NULL) {
		printf("ERROR: Malloc failure when creating node #%d", id);
		exit(1);
	}

	newNode->TaskId = id;
	strcpy(newNode->Title, title);
	strcpy(newNode->Description, description);
	newNode->NextTask = NULL;


	return newNode;
}


Task*