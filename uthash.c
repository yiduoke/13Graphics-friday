#include <string.h>  /* strcpy */
#include <stdlib.h>  /* malloc */
#include <stdio.h>   /* printf */
#include "uthash.h"

struct vertex {
	double key[3];
	double norm[3];
	UT_hash_handle hh;         /* makes this structure hashable */
};

void set_key(struct vertex *v, double x, double y, double z) {
	v->key[0] = x;
	v->key[1] = y;
	v->key[2] = z;
}

void add_norm(struct vertex *v, double x, double y, double z) {
	v->norm[0] = x;
	v->norm[1] = y;
	v->norm[2] = z;
}

int main(int argc, char *argv[]) {
	struct vertex *vertex_list = NULL, *v0, *v1, *v2;
	v0 = (struct vertex *)calloc(1, sizeof(struct vertex));
	v2 = (struct vertex *)calloc(1, sizeof(struct vertex));
	double key[3];
	v0->key[0] = key[0] = -5;
	v0->key[1] = key[1] = 3;
	v0->key[2] = key[2] = 7.5;
	v0->norm[0] = 7;
	v0->norm[1] = 8;
	v0->norm[2] = 9;
	key[0] = 10;
	key[1] = 63;
	key[2] = -5.5;
	set_key(v2, 10, 63, -5.5);
	HASH_ADD_KEYPTR(hh, vertex_list, v0->key, sizeof(v0->key), v0);
	HASH_ADD_KEYPTR(hh, vertex_list, v2->key, sizeof(v2->key), v2);

	HASH_FIND(hh, vertex_list, key, sizeof(key), v1);
	add_norm(v1, 10, 20, 30);
	if (v1) printf("v1 normal: %0.2f %0.2f %0.2f\n", v1->norm[0], v1->norm[1], v1->norm[2]);

	/* free the hash table contents */
	HASH_ITER(hh, vertex_list, v1, v0) {
		HASH_DEL(vertex_list, v1);
		free(v1);
	}
	return 0;
}