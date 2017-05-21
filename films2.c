#/* films2.c -- using a linked list of structures */
#include <stdio.h>
#include <stdlib.h> /* has the malloc prototype */
#include <string.h> /* has the strcpy prototype */
#define TSIZE 45 /* size of array to hold title */
struct film {
	char title[TSIZE];
	int rating;
    struct film * next; /* points to next struct in list */
};
//char * s_gets(char * st, int n);
int main(void)
{
	struct film * head = NULL;
	struct film * prev, * current;
	char input[TSIZE];
/* Gather and store information */
	puts("Enter first movie title:");
	while (gets(input) != NULL && input[0] != '\0')
	{
		current = (struct film *) malloc(sizeof(struct film));
	if (head == NULL) /* first structure */
		head = current;
	else /* subsequent structures */
		prev->next = current;
		current->next = NULL;
		strcpy(current->title, input);
		puts("Enter your rating <0-10>:");
		scanf("%d", &current->rating);
		while(getchar() != '\n')
			continue;
		puts("Enter next movie title (empty line to stop):");
		prev = current;
	}
/* Show list of movies */
	if (head == NULL)
		printf("No data entered. ");
	else
		printf ("Here is the movie list:\n");
	current = head;
	while (current != NULL)
	{
		printf("Movie: %s Rating: %d\n",current->title, current->rating);
		current = current->next;
	}
	current = head;
	int i=0;
	while (current != NULL)
	{
		++i;
		current = current->next;
	}
	printf("length%d\n",i);
	printf("which to delete");
	int pos;
	scanf("%d", pos);
	current = head;
	if(pos==1){
		head=current->next;
		free(current);
	}else{
		int i=0;
		while(current !=NULL)
		{
			++i;
			if(i == pos-1)
			{
				break;
			}
        current = current->next; //移到下一结点
        }
        struct film *point=current->next->next;
        free(current->next);
        current->next=point;
    }
    printf ("Here is the movie list:\n");
    current = head;
    while (current != NULL)
    {
    	printf("Movie: %s Rating: %d\n",current->title, current->rating);
    	current = current->next;
    }  
/* Program done, so free allocated memory */
    current = head;
while (current != NULL)
{
	free(current);
	current = current->next;
}
printf("Bye!\n");
return 0;
}