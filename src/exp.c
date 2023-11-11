#include "exp.h"

void verify_exp(Player *player)
{
    if (player->exp >= player->exp_next) {
        player->level++;
        player->exp = 0;
        player->exp_next = (int)(player->level * 1.5);
        player->max_health += 10;
        player->health = player->max_health;
        player->mana += 10;
        player->attack_min += 2;
        player->attack_max += 2;
        player->money += 3*player->level;
    }
}