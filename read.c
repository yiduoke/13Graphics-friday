#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "parser.h"
#include "symtab.h"

#include "matrix.h"
#include "ml6.h"
#include "display.h"
#include "draw.h"
#include "stack.h"
#include "gmath.h"
#include "draw.h"

struct matrix *parse_mesh(char *file) {
	int num_columns = 999999;
	struct matrix *polygons = new_matrix(4, num_columns);
	FILE *fp;
	char str[256];
	double *meow; // for vertices
	int meower[4]; // for faces
	char command[10];
	int num_vertices = 0;
	
	fp = fopen(file, "r");
	if (!fp){
		perror("cannot open this mesh file");
		exit(0);
	}
	
	meow = (double *)calloc(num_columns, sizeof(double));

	while (fgets(str, sizeof(str), fp)) {
		//printf("%s", str);
		if (num_vertices > num_columns) {
			meow = grow_array(meow, num_columns, 2 * num_columns);
			num_columns *= 2;
		}
		if (!strncmp(str, "v", 1)) { // vertex command
			printf("vertex: ");
			sscanf(str, "%s %lf %lf %lf", command, meow+num_vertices, meow+num_vertices+1, meow+num_vertices+2);
			printf("%lf, %lf, %lf\n", meow[num_vertices], meow[num_vertices+1], meow[num_vertices+2]);
			num_vertices += 3;
		}
		else if (!strncmp(str, "f", 1)) { // vertex command
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

	return polygons;
}

int main(){
	parse_mesh("airboat.obj");
}
