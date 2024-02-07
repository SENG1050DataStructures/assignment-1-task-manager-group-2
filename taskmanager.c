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



int main(void)
{
    
}