#include <stdlib.h>
#include "data_structs.h"

List *list_append(List *list,void *data) {
	if(list == NULL) { /* creating a new list */
		List *my_list = malloc(sizeof(List));
		my_list->prev = NULL;
		my_list->next = NULL;
		my_list->data = data;
		return my_list;
	} else {
		List *tmp = list;
		while(tmp->next != NULL) {
			tmp = tmp->next;
		}
		List *node = malloc(sizeof(List));
		tmp->next = node;
		node->prev = tmp;
		node->next = NULL;
		node->data = data;
		return list;
	}
}

List *list_get_nth(List *head,int index) {
	if(index == 0) {
		return head;
	} else {
		int i;
		List *node = head;
		for(i = 0;i < index; i++) {
			node = node->next;
			if(node == NULL) {
				return node;
			}
		}
		return node;
	}
}

List *list_remove_at(List *head,int index) {
	if(index == -1) {
		return NULL;
	} else if(index == 0) {
		if(head->data != NULL) {
			free(head->data);
		}
		List *next = head->next;
		if(next != NULL) {
			next->prev = NULL;
		}
		free(head);
		return next;
	} else {
		int i;
		List *node = head;
		for(i = 0;i < index; i++) {
			node = node->next;
			if(node == NULL) {
				return head;
			}
		}
		List *prev = node->prev;
		List *next = node->next;

		free(node->data);
		if(next != NULL) {
			next->prev = prev;
		}
		prev->next = next;
		free(node);
		return head;
	}
}

List *list_remove(List *list,void *data) {
	return list_remove_at(list,list_index_of(data));
}

int list_index_of(List *head,void *data) {
	if(head->data == data) {
		return 0;
	}
	List *node = head;
	int i = 1;
	while(node->next != NULL) {
		node = node->next;
		if(node->data == data) {
			return i;
		}
		i++;
	}
	return -1;
}

List *list_prepend(List *head,void *data) {
	List *tmp = head; /* Finding the real head */
	while(tmp->prev != NULL) {
		tmp = tmp->prev;
	}
	List *new_head = malloc(sizeof(List));
	new_head->prev = NULL;
	new_head->next = tmp;
	new_head->data = data;
	tmp->prev = new_head;
	return new_head;
}

List *list_insert_at(List *head,int index,void *data) {
	if(index == 0) {
		return list_prepend(head,data);
	} else {
		List *node = head;
		int i = 1;
		while((node->next != NULL) && (i < index)) {
			node = node->next;
		}
		List *inserted = malloc(sizeof(List));
		inserted->prev = node;
		inserted->next = node->next;
		if(node->next != NULL) {
			node->next->prev = inserted;
		}
		inserted->data = data;
		node->next = inserted;
		return head;
	}
}
