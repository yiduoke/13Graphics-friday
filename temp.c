void gouraud_shading(struct matrix *polygons, screen s, zbuffer zb,
                   double *view, double light[2][3], color ambient,
                   double *areflect,
                   double *dreflect,
                   double *sreflect) {
  if (polygons->lastcol < 3) {
    printf("Need at least 3 points to draw a polygon!\n");
    return;
  }
  
  int point;
  double *normal;
  create_hash(polygons->lastcol);
  for (point = 0; point < polygons->lastcol - 2; point += 3) {
    normal = calculate_normal(polygons, point);
    insert(polygons->m[point][0], polygons->m[point][1], polygons->m[point][2],
           normal[0], normal[1], normal[2]);
    insert(polygons->m[point+1][0], polygons->m[point+1][1], polygons->m[point+1][2],
           normal[0], normal[1], normal[2]);
    insert(polygons->m[point+2][0], polygons->m[point+2][1], polygons->m[point+2][2],
           normal[0], normal[1], normal[2]);
  }
  for (point = 0; point < polygons->lastcol - 2; point += 3) {
    if (dot_product(normal, view) > 0) {
    }
  }
}