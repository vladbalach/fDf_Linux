#include "header.h"

void init_basis(t_basis **basis) {
    *basis = malloc(sizeof(t_basis));
    (*basis)->i = malloc (sizeof(t_vector));
    (*basis)->j = malloc (sizeof(t_vector));
    (*basis)->k = malloc (sizeof(t_vector));
    (*basis)->i->x = 1.256410;
    (*basis)->i->y = 0.100422;
    (*basis)->i->z = 0.42;

    (*basis)->j->x = -0.437226;
    (*basis)->j->y = 0.411928;
    (*basis)->j->z = 1.187733;

    (*basis)->k->x = -0.042749;
    (*basis)->k->y = -1.261662;
    (*basis)->k->z = 0.421832;
}

void init_camera(t_camera **camera, int x,  int y, int z) {
    (*camera) = malloc(sizeof(t_camera));
    (*camera)->x = x;
    (*camera)->y = y;
    (*camera)->z = z;
}

void init_map(t_map **map, char* filename) {
    (*map) = malloc(sizeof(t_map));
    init_basis(&((*map)->basis));
    init_objects(&(*map)->objects, filename);
    init_camera(&(*map)->camera, 100, 300, 0);
}

void init(t_map **map, char *filename) {
    init_map(map, filename);
    
}
