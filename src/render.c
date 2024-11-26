#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include "render.h"


bool init(SDL_Window** window, SDL_Renderer** renderer,TTF_Font** font){

	if(SDL_Init(SDL_INIT_EVERYTHING) != 0){
		fprintf(stderr,"Erro inicializando SDL: %s",SDL_GetError());
		return true;
}

if(init_window(window) != 0) return true;
if(init_render(renderer,*window) != 0) return true;
if(init_font(font,*renderer,*window)!=0) return true;



return false;
}



bool init_window(SDL_Window** window){

*window = SDL_CreateWindow("wallacepong",SDL_WINDOWPOS_CENTERED,SDL_WINDOWPOS_CENTERED,WINDOW_WIDTH,WINDOW_HEIGHT,SDL_WINDOW_OPENGL);

if(!*window){
	fprintf(stderr,"Falha ao inicializar janela: %s\n",SDL_GetError());

SDL_Quit();
return true;
}


return false;
}






bool init_render(SDL_Renderer** renderer,SDL_Window* window){
Uint32 render_flags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;

*renderer = SDL_CreateRenderer(window,-1,render_flags);

if(!*renderer){
	fprintf(stderr,"Falha ao inicializar render %s\n",SDL_GetError());
	SDL_DestroyWindow(window);
	SDL_Quit();
	return true;
}


return false;

};




bool init_font(TTF_Font** font, SDL_Renderer* renderer,SDL_Window* window){

TTF_Init();
*font = TTF_OpenFont("assets/Sans.ttf",24);
if(!*font){
	fprintf(stderr,"falha ao inicializar fonte: %s\n",SDL_GetError());
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	return true;
}

return false;
}



void draw_menu(SDL_Renderer *renderer, TTF_Font* font, int players){

SDL_Color color;
	SDL_Color White = { 255, 255, 255 };
	SDL_Color Grey = { 169, 169, 169};
	SDL_Surface * surface = TTF_RenderText_Solid(font, "Wallace-Pong!", White);
	SDL_Texture * texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect pong_rect = {(WINDOW_WIDTH / 2) - 150, 0, 300, 200};
	SDL_RenderCopy(renderer, texture, NULL, &pong_rect);
	if(players==1)
		color=White;
	else
		color=Grey;
	surface = TTF_RenderText_Solid(font, "1 Player", color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect oneplayer_rect = {50, WINDOW_HEIGHT/2, WINDOW_WIDTH/2 - 100, 100};
	SDL_RenderCopy(renderer, texture, NULL, &oneplayer_rect);
	if(players==2)
		color=White;
	else
		color=Grey;
	surface = TTF_RenderText_Solid(font, "2 Players", color);
	texture = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_Rect twoplayer_rect = {WINDOW_WIDTH/2 + 50, WINDOW_HEIGHT/2, WINDOW_WIDTH/2 - 100, 100};
	SDL_RenderCopy(renderer, texture, NULL, &twoplayer_rect);
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}


void redraw(SDL_Renderer *renderer){

SDL_RenderPresent(renderer);

SDL_SetRenderDrawColor(renderer,0,0,0,255);
SDL_RenderClear(renderer);
SDL_Delay(1000/60);
}


void draw_game(SDL_Renderer *renderer, Barra player, Barra cpu, Bola ball){

SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255 );
	SDL_Rect* player_rect = &player.rect;
	SDL_Rect* cpu_rect = &cpu.rect;
	SDL_Rect* ball_rect = &ball.rect;
	SDL_RenderFillRect(renderer, player_rect);
	SDL_RenderFillRect(renderer, cpu_rect);
	SDL_RenderFillRect(renderer, ball_rect);
	SDL_RenderDrawLine(renderer, WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
}


void render_score(SDL_Renderer *renderer, const char *score_str, TTF_Font *font, SDL_Rect *rect, SDL_Color *color){

SDL_Surface *surface;
    SDL_Texture *texture;
    surface = TTF_RenderText_Solid(font, score_str, *color);
    texture = SDL_CreateTextureFromSurface(renderer, surface);
    rect->x = (WINDOW_WIDTH / 2) - 20;
    rect->y = 0;
    rect->w = surface->w;
    rect->h = surface->h;
    SDL_FreeSurface(surface);
    SDL_RenderCopy(renderer, texture, NULL, rect);
    SDL_DestroyTexture(texture);

}
