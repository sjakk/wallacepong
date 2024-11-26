#include "barra.h"


void player_logic(Barra* player){

	if(player->controls[0] && !player->controls[1]) player->rect.y -= 5;

	if(player->controls[1] && !player->controls[0]) player->rect.y += 5;

	if(player->rect.y <= 0) player->rect.y = 0;
	if(player->rect.y + player->rect.h >= WINDOW_HEIGHT) player->rect.y = WINDOW_HEIGHT - player->rect.h;

}
