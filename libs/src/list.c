#include "list.h"
#include <stdio.h>

static struct list* theList;

int list_add(struct node* n)
{
	return 0; //0 for success
}

int list_init()
{
	theList = (struct list*)malloc(sizeof(struct list));
	theList->head = (struct node*)malloc(sizeof(struct node));
	theList->head->id = 0;
	return 0;
}

struct node* list_get_from(const unsigned int index)
{
	unsigned int start = 0;
	
	return NULL;
}

int list_remove(struct node* n)
{
	return 0;
}

int list_remove_from(const unsigned int index)
{

}

