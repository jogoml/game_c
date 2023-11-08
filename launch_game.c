#include <stdio.h>
#include "launch_game.h"

void launch_game() {
    char *monologue[] = {
        "Bienvenue, brave guerrier !",
        "Le monde est en danger, des monstres terrifiants ont envahi le dongeon.",
        "Votre mission est de les vaincre et de sauver notre royaume.",
        "Préparez-vous, équipez-vous de votre épée, et aventurez-vous dans le dongeon sombre.",
        "Que la chance vous accompagne dans cette quête héroïque !"
    };

    int num_texts = sizeof(monologue) / sizeof(monologue[0]);

    printf("L'aventure commence...\n");

    for (int i = 0; i < num_texts; i++) {
        printf("\n[Appuyez sur Entrée pour continuer]");
        while (getchar() != '\n');
        printf("%s\n", monologue[i]);
    }


    printf("\nQue l'aventure commence !\n");
}
