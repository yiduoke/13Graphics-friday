#include <string.h>
#include <stdio.h>
#include "draw.h"

struct matrix *polygons parse_mesh(char* file){
	int num_columns = 3000000;
	struct matrix* polygons = new_matrix(4, num_columns);
	FILE *fp;
	char str[256];
	double meow[num_columns];// for vertices
	int meower[4];// for faces
	char command[10];
	int num_vertex = 0;
	
	fp = fopen(file, "r");
	if (!fp){
		perror("cannot open this mesh file");
		return NULL;
	}
	
	while (fgets(str, sizeof(str), fp)){
//		printf("%s", str);
		if (!strncmp(str, "v", 1)){ // vertex command
			printf("vertex: ");
			
			if (num_vertex > num_columns){
				meow = grow_array(meow, num_columns, num_columns * 2);
				num_columns *= 2;
			}
			sscanf(str, "%s %lf %lf %lf", command, meow+num_vertex, meow+num_vertex+1, meow+num_vertex+2);
			printf("%lf, %lf, %lf\n", meow[num_vertex], meow[num_vertex+1], meow[num_vertex+2]);
			num_vertex += 3;
		}
		else if (!strncmp(str, "f", 1)){ // vertex command
			printf("face made from vertices: ");
			sscanf(str, "%s %d %d %d %d", command, meower, meower+1, meower+2, meower+3);
			printf("%d, %d, %d, %d\n", meower[0], meower[1], meower[2], meower[3]);
			
			add_polygon(polygons, polygons->m[0][meower[0]], polygons->m[1][meower[0]], polygons->m[2][meower[0]],
														polygons->m[0][meower[1]], polygons->m[1][meower[1]], polygons->m[2][meower[1]],
														polygons->m[0][meower[2]], polygons->m[1][meower[2]], polygons->m[2][meower[2]]);
														
			add_polygon(polygons, polygons->m[0][meower[0]], polygons->m[1][meower[0]], polygons->m[2][meower[0]],
														polygons->m[0][meower[1]], polygons->m[1][meower[1]], polygons->m[2][meower[1]],
														polygons->m[0][meower[2]], polygons->m[1][meower[2]], polygons->m[2][meower[2]]);
		}
	}
	
	fclose(fp);
	
	return null
}

int main(){
	parse_mesh("airboat.obj");
}
