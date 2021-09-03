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

int find_letter(char letter, char storaged_attempts[26], int attempts_counter)
{
    int found_letter = 0;
    for(int y = 0; y < attempts_counter; y++){
        if(storaged_attempts[y] == letter){
            found_letter = 1;
            break; 
        }
    }
    return found_letter;
}

void print_word(char secret_word[20], char storaged_attempts[26], int attempts_counter)
{
    for(int x = 0; x < strlen(secret_word); x++){
        int found_letter = find_letter(secret_word[x],  storaged_attempts, attempts_counter);
        if(found_letter){
            printf("%c ", secret_word[x]);
        }else{
            printf("- ");
        }
    }
    printf("\n"); 
}

void pick_word(char secret_word[20])
{
    sprintf(secret_word, "MELANCIA ");//It fills the secret_word variable with the text given
}

int main(void)
{
    char secret_word[20];
    char storaged_attempts[26];
    int attempts_counter = 0;
    int player_won = 0;
    int hanged = 0;

    pick_word(secret_word);
    write_header();
    
    do
    {
        print_word(secret_word, storaged_attempts, attempts_counter);
        requests_user_attempt(storaged_attempts, &attempts_counter);
    }while(!player_won && !hanged);
}
