#include "hash.h" 

void create(int number){
    num_vertices = number;
    hashArray = (struct DataItem**)calloc(number, sizeof(struct DataItem *));
}

struct DataItem *search(double key[3]) {
    int hashIndex = 0;  
	
    //move in array until empty 
    while(hashArray[hashIndex]) {
	
        if(hashArray[hashIndex]->key[0] == key[0] && hashArray[hashIndex]->key[1] == key[1] && hashArray[hashIndex]->key[2] == key[2]){
            return hashArray[hashIndex]; 
        }
        
        //go to next cell
        hashIndex++;
    }        
	
    return NULL;        
}

void insert(double key0, double key1, double key2, double data0, double data1, double data2){
    int i, j;
    for (i = 0; i < num_vertices; i++){
        if (!hashArray[i]){//empty spot (1st one), put this in
            struct DataItem *item = (struct DataItem*)malloc(sizeof(struct DataItem));
            item->key[0] = key0;
            item->key[1] = key1;
            item->key[2] = key2;
            item->data[0][0] = data0;
            item->data[1][0] = data1;
            item->data[2][0] = data2;
            hashArray[i] = item;
            return;
        }
        else{
            // printf("match? %d\n", key0==hashArray[i]->key[0]);
            if (hashArray[i]->key[0] == key0 && hashArray[i]->key[1] == key1 && hashArray[i]->key[2] == key2){
                // find the first empty spot in this key's data
                j = 0;
                while (hashArray[i]->data[0][j] || hashArray[i]->data[1][j] || hashArray[i]->data[2][j]){
                    j++;
                }
                hashArray[i]->data[0][j] = data0;
                hashArray[i]->data[1][j] = data1;
                hashArray[i]->data[2][j] = data2;
                return;
            }
        }
    }
}

void print_hash() {
    int i, j;
    for (i = 0; i<num_vertices; i++){
        if (hashArray[i]){
            printf("key:\n(%f, %f, %f)\n", hashArray[i]->key[0], hashArray[i]->key[1], hashArray[i]->key[2]);
            j = 0;
            printf("data:\n");
            while (hashArray[i]->data[0][j] || hashArray[i]->data[1][j] || hashArray[i]->data[2][j]){
                printf("(%f, %f, %f)\n", hashArray[i]->data[0][j], hashArray[i]->data[1][j], hashArray[i]->data[2][j]);
                j++;
            }
            printf("\n\n");
        }
        else{
            printf(" ~~ ");
        }
    }
    printf("\n");
}

int main() {

    create(500);
    insert(24, 25, 26, 2, 3, 4);
    insert(24, 25, 26, 22, 33, 44);

    insert(4, 5, 6, 24, 34, 44);
    insert(4, 5, 6, 0, 2, 0);
    insert(4, 5, 6, 64, 64, 64);

    print_hash();
}