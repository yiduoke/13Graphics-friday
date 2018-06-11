#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

typedef struct {
	double key[3];
	double vertex_normal[3];
	UT_hash_handle hh;
} vertex;

vertex *vertex_list = NULL;

int main() {
	vertex *v0 = (vertex *)malloc(sizeof(vertex)), v1;
	double key[3];
	v0->key[0] = key[0] = 20.56;
	v0->key[1] = key[1] = -0.562;
	v0->key[2] = key[2] = 6;
	HASH_ADD_KEYPTR(vertex_list, v0->key, v0);
	HASH_FIND_PTR(vertex_list, key, v1);
	if (v1) {
		printf("Vertex coordinates: %0.3f %0.3f %0.3f\n", v1->key[0], v1->key[1], v1->key[2]);
	}
	free(v0);
	return 0;
}
