#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>

SDL_Window* window;
SDL_Renderer* renderer;
bool is_running = true;

void process_input(void){
	SDL_Event event;
	SDL_PollEvent(&event);


	switch(event.type){
		case SDL_QUIT:
			is_running = false;
			break;
		case SDL_KEYDOWN:
			if(event.key.keysym.sym == SDLK_ESCAPE) is_running = false;
			break;
	}
}



int main(void){

if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
	fprintf(stderr,"Erro ao inicializar SDL");
	return -1;
}

window = SDL_CreateWindow(NULL,SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,800,600,SDL_WINDOW_BORDERLESS);
renderer = SDL_CreateRenderer(window,-1,0);



while(is_running){

process_input();

SDL_SetRenderDrawColor(renderer,255,0,0,255);
SDL_RenderClear(renderer);
SDL_RenderPresent(renderer);
}


printf("Hello Wallace\n");

}
