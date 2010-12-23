#include "data_structs.h"
#include <stdio.h>
#include <string.h>

int main(int argc,char **argv) {
	char *zero, *one, *two, *three, *minusone;
	zero = strdup("Zero");
	one  = strdup("One");
	two  = strdup("Two");
	three = strdup("Three");
	minusone = strdup("-1");
	List *list = list_append(NULL,zero);
	list_append(list,one);
	list_append(list,two);
	list_append(list,three);
	list_remove_at(list,1);
	one = strdup("One");
	list_insert_at(list,1,one);
	list = list_prepend(list,minusone);
	int i;
	for(i = 0;i <= 2; i++) {
		printf("%s\n",(char *)list_get_nth(list,i)->data);
	}
	printf("\n%d\n",list_index_of(list,two));
	return 0;
}
