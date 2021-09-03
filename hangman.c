#include <stdio.h>
#include <string.h>

char secret_word[20];
char storaged_attempts[26];
int attempts_counter = 0;
 
void write_header(void){
    printf("*****************\n");
    printf("* HANGAMAN GAME *\n");
    printf("*****************\n\n");
}

void requests_user_attempt(){
    char user_attempt;
    scanf(" %c", &user_attempt);

    storaged_attempts[attempts_counter] = user_attempt;
    attempts_counter++;
}

int find_letter(char letter){
    int found_letter = 0;
    for(int y = 0; y < attempts_counter; y++){
        if(storaged_attempts[y] == letter){
            found_letter = 1;
            break; 
        }
    }
    return found_letter;
}

void print_word(){
    for(int x = 0; x < strlen(secret_word); x++){
        int found_letter = find_letter(secret_word[x]);
        if(found_letter){
            printf("%c ", secret_word[x]);
        }else{
            printf("- ");
        }
    }
    printf("\n"); 
}

void pick_word(){
    sprintf(secret_word, "MELANCIA");//It fills the secret_word variable with the text given
}

int hanged()
{
    int errors = 0;
    for(int x = 0; x < attempts_counter; x++){
        int exist = 0;
        for(int y = 0; y < strlen(secret_word); y++){
            //if(storaged_attempts[x] == secret_word[y]){
            if(find_letter(secret_word[y])){
                exist = 1;
                break;
            }
        }
        if(!exist)
            errors++;
    }
    int hanged = (errors >= 5);
    return hanged;
}

int player_won(){
    for(int i = 0; i < strlen(secret_word); i++){
        if(!find_letter(secret_word[i]))
            return 0;
    }
    return 1;
}

int main(void){
    pick_word();
    write_header();
    
    do{
        print_word();
        requests_user_attempt();
    }while(!player_won() && !hanged());
}
