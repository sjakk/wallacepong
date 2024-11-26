#include "barra.h"
#include "bola.h"


void player_logic(Barra* player){

	if(player->controls[0] && !player->controls[1]) player->rect.y -= 5;

	if(player->controls[1] && !player->controls[0]) player->rect.y += 5;

	if(player->rect.y <= 0) player->rect.y = 0;
	if(player->rect.y + player->rect.h >= WINDOW_HEIGHT) player->rect.y = WINDOW_HEIGHT - player->rect.h;

}




void cpu_logic(Barra *cpu, Bola *ball){

if(ball->rect.y >= cpu->rect.y && ball->rect.x > WINDOW_WIDTH - WINDOW_WIDTH / 4) cpu->rect.y += 5;
	else if(ball->rect.y <= cpu->rect.y + cpu->rect.h && ball->rect.x > WINDOW_WIDTH - WINDOW_WIDTH / 4) cpu->rect.y -= 5;
	else{
		if(cpu->rect.y + (cpu->rect.h / 2) > (WINDOW_HEIGHT / 2) + 10) cpu->rect.y -= 5;
		else if(cpu->rect.y + (cpu->rect.h / 2) < (WINDOW_HEIGHT / 2) - 10) cpu->rect.y += 5;
	}
	if(cpu->rect.y <= 0) cpu->rect.y = 0;
	else if(cpu->rect.y + cpu->rect.h >= WINDOW_HEIGHT) cpu->rect.y = WINDOW_HEIGHT - cpu->rect.h;


}
