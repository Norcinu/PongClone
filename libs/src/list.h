#pragma once

struct node {
	int id;
	void* data;
};

struct list {
	struct node* head;
	struct node* tail;

	unsigned int size;
};

int list_add(struct node* n);
int list_init();

struct node* list_get_from(const unsigned int index);

int list_remove(struct node* n);
int list_remove_from(const unsigned int index);

//struct node* traverse();