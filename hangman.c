#include <stdio.h>
#include <string.h>
 
int main(void)
{
    char secret_word[20];
    char storage_attempts_values[26];
    int attempts_quantity = 0;
    int player_won = 0;
    int hanged = 0;

    sprintf(secret_word, "MELANCIA ");

    do
    {
        for(int x = 0; x < strlen(secret_word); x++){
            int found_letter = 0;
            for(int y = 0; y < attempts_quantity; y++){
                if(storage_attempts_values[y] == secret_word[x]){
                    found_letter = 1;
                    break; 
                }
            }

            if(found_letter){
                printf("%c ", secret_word[x]);
            }else{
                printf("- ");
            }
        }
        printf("\n"); 

        char user_attempt;
        scanf(" %c", &user_attempt);

        storage_attempts_values[attempts_quantity] = user_attempt;
        attempts_quantity++;
    }while(!player_won && !hanged);
}
