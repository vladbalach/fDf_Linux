#include "header.h"
#include "stdbool.h"

void* event_loop(t_map *map) {
    static bool left_pressed = false;
    static bool right_pressed = false;
    static int prev_x = 0;
    static int prev_y = 0;
    SDL_Event event;

    while(SDL_PollEvent(&event)) {
        if ((SDL_QUIT == event.type)
            || (event.key.keysym.scancode == SDL_SCANCODE_ESCAPE))
            exit(0);
    }
    if (event.type == SDL_MOUSEBUTTONDOWN) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            prev_x = event.motion.x;
            prev_y = event.motion.y;
            left_pressed = true;
        }
        if (event.button.button == SDL_BUTTON_RIGHT) {
            prev_x = event.motion.x;
            prev_y = event.motion.y;
            right_pressed = true;
        }
    }
    if(event.type == SDL_MOUSEWHEEL)
    {
        if(event.wheel.y > 0) // scroll up
        {
             map->basis->i->x *= 1.1;
            map->basis->i->y *= 1.1;
            map->basis->i->z *= 1.1;
            map->basis->j->x *= 1.1;
            map->basis->j->y *= 1.1;
            map->basis->j->z *= 1.1;
            map->basis->k->x *= 1.1;
            map->basis->k->y *= 1.1;
            map->basis->k->z *= 1.1;
        }
        else if(event.wheel.y < 0) // scroll down
        {
            map->basis->i->x *= 0.9;
            map->basis->i->y *= 0.9;
            map->basis->i->z *= 0.9;
            map->basis->j->x *= 0.9;
            map->basis->j->y *= 0.9;
            map->basis->j->z *= 0.9;
            map->basis->k->x *= 0.9;
            map->basis->k->y *= 0.9;
            map->basis->k->z *= 0.9;
        }
    }
    if (event.type == SDL_MOUSEBUTTONUP) {
        if (event.button.button == SDL_BUTTON_LEFT) {
            left_pressed = false;
        }
        
        if (event.button.button == SDL_BUTTON_RIGHT) {
            right_pressed = false;
        }
    }
    if (event.type == SDL_MOUSEMOTION) {
        if (left_pressed) {
            int delta = event.motion.x - prev_x;
            map->camera->x += delta;
            prev_x = event.motion.x;
            delta = event.motion.y - prev_y;
            map->camera->y += delta;
            prev_y = event.motion.y;
        }
        if (right_pressed) {
            int delta = event.motion.x - prev_x;
            rotate_basis_z(map->basis, delta);
            prev_x = event.motion.x;
            delta = event.motion.y - prev_y;
            rotate_basis_x(map->basis, delta);
            prev_y = event.motion.y;
        }
    }
            
    return (void*)1;
}