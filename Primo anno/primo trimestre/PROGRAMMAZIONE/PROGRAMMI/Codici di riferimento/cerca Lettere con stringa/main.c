#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 10

int main() {
    char parola[MAX + 1]; // +1 per il terminatore null
    char lettera;
    short vittoria = 0, g = 0;
    printf("\nInserisci una parola di 10 caratteri: ");
    scanf("%s", parola);

    for (g; g < MAX; g++) {
        if (!isalpha(parola[g])) {
            printf("\nDeve contenere solo lettere, si prega di rinserire il carattere: ");
            scanf(" %c", &parola[g]);
        }
    }

    
    for (short i = 0; i < strlen(parola); i++) {
        printf("\nDigita una lettera per provare ad indovinarla: ");
        scanf(" %c", &lettera);

        for (g = 0; g < strlen(parola); g++) {
            if(parola[g]==lettera){
                if (tolower(parola[g]) == tolower(lettera)) {
                    parola[g] = '0';
                    vittoria++;
                    break;
                }
            }
        }
        //printf("Wela");
    }

    if (vittoria >= 7) printf("\nVittoria");
    else if (vittoria >= 4 && vittoria < 7) printf("\nPuoi fare meglio");
    else if (vittoria >= 1 && vittoria < 4) printf("\nPUOI FARCELA\n");
    else printf("\nRiprova\n");

    return 0;
}
