#include "hash.h" 

void create_hash(int number){
    num_vertices = number;
    free(hashArray);
    hashArray = (struct DataItem**)calloc(number, sizeof(struct DataItem *));
}

double* search(double key0, double key1, double key2) {
    int hashIndex = 0;  
	
    //move in array until empty 
    while(hashArray[hashIndex]) {
        if(hashArray[hashIndex]->key[0] == key0 && 
		   hashArray[hashIndex]->key[1] == key1 &&
		   hashArray[hashIndex]->key[2] == key2) {
            return hashArray[hashIndex]->vertex_normal;
        }
        
        //go to next cell
        hashIndex++;
    }        
	
    return NULL;        
}

void insert(double key0, double key1, double key2, double data0, double data1, double data2) {
    int i, j;
    for (i = 0; i < num_vertices; i++){
        if (!hashArray[i]){//empty spot (1st one), put this in
            struct DataItem *item = (struct DataItem *)malloc(sizeof(struct DataItem));
            item->key[0] = key0;
            item->key[1] = key1;
            item->key[2] = key2;
            item->vertex_normal[0] = data0;
			item->vertex_normal[1] = data1;
			item->vertex_normal[2] = data2;
            hashArray[i] = item;
            return;
        }
        else{
            if (hashArray[i]->key[0] == key0 && hashArray[i]->key[1] == key1 && hashArray[i]->key[2] == key2) {
                hashArray[i]->vertex_normal[0] += data0;
                hashArray[i]->vertex_normal[1] += data1;
                hashArray[i]->vertex_normal[2] += data2;
                // printf("repeat offender; keys are %f %f %f\n", key0, key1, key2);
                // printf("repeat offender; keys already here are %f %f %f\n\n", hashArray[i]->key[0], hashArray[i]->key[1], hashArray[i]->key[2]);
                return;
            }
        }
    }
}

void print_hash() {
    int i;
    for (i = 0; i<num_vertices; i++){
        if (hashArray[i]){
            printf("key:\n(%0.2f, %0.2f, %0.2f)\n", hashArray[i]->key[0], hashArray[i]->key[1], hashArray[i]->key[2]);
            printf("data:\n");
			printf("(%0.2f, %0.2f, %0.2f)\n", hashArray[i]->vertex_normal[0], hashArray[i]->vertex_normal[1], hashArray[i]->vertex_normal[2]);
            printf("\n\n");
        }
        else{
            printf(" ~~ ");
        }
    }
    printf("\ni is %d\n", i);
}

// int main() {

//     create_hash(4);
//     insert(24, 25, 26, 2, 3, 4);
//     insert(24, 25, 26, 22, 33, 44);

//     insert(4, 5, 6, 24, 34, 44);
//     insert(4, 5, 6, 0, 2, 0);
//     insert(4, 5, 6, 64, 64, 64);

//     printf("searching from (24, 25, 26): (%f, %f, %f)\n", search(24, 25, 26)[0], search(24, 25, 26)[1], search(24, 25, 26)[2]);
//     print_hash();
// }