#include "header.h"

void draw_object(Uint32 *pixels, t_list *list, t_map *map) {
    t_object *obj = (t_object*)list->data;
    
    draw_line(obj->vectors[0], obj->vectors[1], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
    draw_line(obj->vectors[1], obj->vectors[2], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
    draw_line(obj->vectors[2], obj->vectors[3], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
    draw_line(obj->vectors[0], obj->vectors[3], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
    if (list->down) {
        t_object *obj_d = (t_object*)list->down->data;
        draw_line(obj->vectors[2], obj_d->vectors[1], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
        draw_line(obj->vectors[3], obj_d->vectors[0], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
    }
    if (list->up) {
        t_object *obj_u = (t_object*)list->up->data;
        draw_line(obj->vectors[0], obj_u->vectors[3], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
        draw_line(obj->vectors[1], obj_u->vectors[2], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
    }
    if (list->left) {
        t_object *obj_l = (t_object*)list->left->data;
        draw_line(obj->vectors[0], obj_l->vectors[1], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
        draw_line(obj->vectors[3], obj_l->vectors[2], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
    }
    if (list->right) {
        t_object *obj_r = (t_object*)list->right->data;
        draw_line(obj->vectors[1], obj_r->vectors[0], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
        draw_line(obj->vectors[2], obj_r->vectors[3], map->basis, WIDTH, HEIGHT, LINE_COLOR, pixels, map->camera);
    }
}

int  draw(Uint32 *pixels, t_map *map) {
    t_list *tmp = map->objects;

    while (tmp)
    {
        draw_object(pixels, tmp, map);
        tmp = tmp->next;
    }
    
}
