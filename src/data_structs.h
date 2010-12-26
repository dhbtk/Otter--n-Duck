#include <stdlib.h>

typedef struct node {
	struct node *prev;
	struct node *next;
	void *data;
} List;

#define HASH_MAP_BUCKETS 101

typedef int (*HashFunc)(void *);
typedef int (*CompareFunc)(void *,void *);

typedef struct bucket {
	struct bucket *next;
	void *name;
	void *data;
} BitBucket;

typedef struct {
	BitBucket *buckets;
	int buckets_size;
	HashFunc hash_func;
	CompareFunc comp_func;
} HashMap;

List *list_append(List *list,void *data);

List *list_get_nth(List *head,int index);

List *list_remove_at(List *head,int index);

List *list_remove(List *list,void *data, CompareFunc func);

int list_index_of(List *head,void *data, CompareFunc func);

List *list_prepend(List *head,void *data);

List *list_insert_at(List *head,int index,void *data);

int hash_map_string_hash(char *string) {
	/* this is taken straight from K&R */
	int hash;
	for(hash = 0; *string != '\0'; string++) {
		hash = *s + 15 * hash;
	}
	return hash;
}

HashMap *hash_map_new(HashFunc hash_func,CompareFunc compare_func) {
	HashMap *map = malloc(sizeof(HashMap));
	map->buckets_size = HASH_MAP_BUCKETS;
	map->buckets = malloc(map->buckets_size * map->buckets_size);
	if(hash_func == NULL) {
		map->hash_func = (HashFunc)hash_map_string_hash;
	} else {
		map->hash_func = hash_func;
	}
	if(compare_func == NULL) {
		map->compare_func = (CompareFunc)strcmp;
	} else {
		map->compare_func = compare_func;
	}
	return map;
}

void *hash_map_set(HashMap *map,void *key,void *val) {
	BitBucket *b;
	int hash;
	if((b = hash_map_raw_get(map,key)) == NULL) {
		b = malloc(sizeof(BitBucket));
		hash = map->hash_func(key);
		b->next = map->buckets[hash];
		map->buckets[hash] = b;
	} else {
		void *old_data = b->data;
}

BitBucket *hash_map_raw_get(HashMap *map,void *key) {
	BitBucket *bucket;
	for(bucket = map->buckets[map->hash_func(key)%map->buckets_size]; bucket != NULL; bucket = bucket->next) {
		if(!map->compare_func(key,bucket->name)) {
			return bucket;
		}
	}
	return NULL;
}

void *hash_map_get(HashMap *map,void *key) {
	BitBucket *b = hash_map_raw_get(map,key);
	if(b == NULL) {
		return NULL;
	} else {
		return b->data;
	}
}
