#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <sys/types.h>
#include <math.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <pthread.h>


#define WIDTH 900
#define HEIGHT 800
#define BLOCKSIZE 5
#define BACKGROUND_COLOR (255 << 24) | 0
#define LINE_COLOR (255 << 24) | (0 << 16) | (255 << 8) + 0

typedef struct s_list {
    void* data;
    struct s_list *up;
    struct s_list *down;
    struct s_list *right;
    struct s_list *left;
    struct s_list *next;
} t_list;

typedef struct s_point {
    float x;
    float y;
    float z;
} t_point;

typedef struct s_vector {
    float x;
    float y;
    float z;
} t_vector;

typedef struct s_basis {
    t_vector *i;
    t_vector *j;
    t_vector *k;
} t_basis;

typedef struct s_poligon {
    t_vector *a;
    t_vector *b;
    t_vector *c;
} t_poligon;

typedef struct s_object {
    t_vector **vectors;
    int size;
} t_object;

typedef struct s_camera{
    int x;
    int y;
    int z;
} t_camera;

typedef struct s_map {
    t_list *objects;
    t_basis *basis;
    t_camera *camera;
} t_map;


t_list *mx_create_node(void *data);
void mx_pop_index(t_list **list, int index);
void mx_push_top(t_list **list, void *data);

void draw_line(t_vector *v1, t_vector *v2, t_basis *basis, int w, int h ,Uint32 color ,Uint32* pixels, t_camera *camera);
void fill_circle(int x, int y, int r, int w, int h, Uint32 color, Uint32* pixels);
void rotate_basis_x(t_basis *basis, float angle);
void rotate_basis_y(t_basis *basis, float angle);
void rotate_basis_z(t_basis *basis, float angle);
// cycle 
void init(t_map **map, char *filename);
void init_objects(t_list **objects, char *filename);
void* event_loop(t_map *map);
int  draw(Uint32 *pixels, t_map *map);

#endif