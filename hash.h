#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

struct DataItem {
    double key[3]; // coordinates of a vertex
    double vertex_normal[3]; // sum of all polygon normals
};

struct DataItem** hashArray; 
struct DataItem* dummyItem;
struct DataItem* item;
int num_vertices;

struct DataItem *search(double key[3]);
void insert(double key0, double key1, double key2, double data0, double data1, double data2);
void print_hash();