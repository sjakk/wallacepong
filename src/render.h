#ifndef __RENDER__
#define __RENDER__

#include <stdio.h>
#include <stdbool.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>


#include "barra.h"
#include "helpers.h"

bool init(SDL_Window** window, SDL_Renderer** renderer, TTF_Font** font);
bool init_window(SDL_Window** window);
bool init_render(SDL_Renderer** renderer, SDL_Window* window);
bool init_font(TTF_Font** font, SDL_Renderer* renderer,SDL_Window* window);
void quit(SDL_Renderer* renderer,SDL_Window* window,TTF_Font* font);
void render_score(SDL_Renderer* renderer,const char* score_str, TTF_Font* font, SDL_Rect* rect, SDL_Color* color);
void redraw(SDL_Renderer* renderer);
void draw_game(SDL_Renderer* renderer, Barra player, Barra cpu, Bola ball);
void draw_menu(SDL_Renderer* renderer,TTF_Font* font, int players);

#endif








