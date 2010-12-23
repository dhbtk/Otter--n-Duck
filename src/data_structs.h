#include <stdlib.h>

typedef struct node {
	struct node *prev;
	struct node *next;
	void *data;
} List;

List *list_append(List *list,void *data);

List *list_get_nth(List *head,int index);

List *list_remove_at(List *head,int index);

List *list_remove(List *list,void *data);

int list_index_of(List *head,void *data);

List *list_prepend(List *head,void *data);

List *list_insert_at(List *head,int index,void *data);
