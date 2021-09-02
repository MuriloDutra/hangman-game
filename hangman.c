#include <stdio.h>
#include <string.h>
 
void write_header(void)
{
    printf("*****************\n");
    printf("* HANGAMAN GAME *\n");
    printf("*****************\n\n");
}

void requests_user_attempt(char storaged_attempts[26], int* attempts_counter)
{
    char user_attempt;
    scanf(" %c", &user_attempt);

    storaged_attempts[(*attempts_counter)] = user_attempt;
    (*attempts_counter)++;
}

int main(void)
{
    char secret_word[20];
    char storaged_attempts[26];
    int attempts_counter = 0;
    int player_won = 0;
    int hanged = 0;

    sprintf(secret_word, "MELANCIA ");//It fills the secret_word variable with the text given
    write_header();
    
    do
    {
        for(int x = 0; x < strlen(secret_word); x++){
            int found_letter = 0;
            for(int y = 0; y < attempts_counter; y++){
                if(storaged_attempts[y] == secret_word[x]){
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

        requests_user_attempt(storaged_attempts, &attempts_counter);
    }while(!player_won && !hanged);
}
