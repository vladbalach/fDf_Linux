#include "header.h"





int render(
    SDL_Texture *texture, 
    SDL_Rect *rect_main, 
    SDL_Renderer *renderer, 
    Uint32 *pixels,
    t_map *map) 
{
    // SDL_RenderClear(renderer);
    for (int i = 0; i < WIDTH * HEIGHT; i++) 
		* (pixels + i) = BACKGROUND_COLOR;
        
    draw(pixels, map);
    SDL_UpdateTexture(texture, rect_main, pixels, WIDTH * sizeof(Uint32));
    SDL_RenderCopy(renderer, texture, NULL, NULL);
    SDL_RenderPresent(renderer);
}




int game(SDL_Renderer *renderer, t_map *map) {
    int running = 1;
    Uint32* pixels = (Uint32*)malloc(sizeof(Uint32) * WIDTH * HEIGHT);
    for (int i = 0; i < WIDTH * HEIGHT; i++) 
		* (pixels + i) = BACKGROUND_COLOR;
    SDL_Texture* texture = SDL_CreateTexture(
        renderer, 
        SDL_PIXELFORMAT_ABGR8888, 
        SDL_TEXTUREACCESS_STATIC, 
        WIDTH, 
        HEIGHT
    );
    SDL_Rect rect_main = {0, 0, WIDTH, HEIGHT};
    while (running) {
        running = event_loop(map);
        render(texture, &rect_main, renderer, pixels, map);
        update(map);
        SDL_Delay(100);
    }
}

void usage(int argc, char *argv[]) {
    if (argc != 2) {
        printf("usage: ./sdl [filenae]\n");
        exit(1);
    }
}

int main(int argc, char *argv[]) {
    SDL_Window *window = 0;
    SDL_Renderer *renderer = 0;
    t_map *map = 0;
    pthread_t evloop;

    usage(argc, argv);
    SDL_Init(SDL_INIT_VIDEO);
    pthread_create(&evloop, 0, event_loop, (void*)map);
    window = SDL_CreateWindow("NAME", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);;
    renderer = SDL_CreateRenderer(window, -1, 0);
    init(&map,  argv[1]);

    game(renderer, map);
    
    SDL_DestroyWindow(window);
	SDL_Quit();
    pthread_join(evloop, 0);
}