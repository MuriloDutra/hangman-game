#include <stdio.h>
#include <string.h>
#include "hangman.h"
#include <time.h>
#include <stdlib.h>

char secret_word[WORD_SIZE];
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
    FILE* f;
    int quantity_of_words;

    f = fopen("words.txt", "r");//r -> read
    if(f == 0){
        printf("Sorry, it wasn't possible to read from the file\n");
        exit(1);
    }

    fscanf(f, "%d", &quantity_of_words);//It reads the content of a file
   
    srand(time(0));
    int random_number = rand() % quantity_of_words; 

    for(int i = 0; i <= random_number; i++){
        fscanf(f, "%s", secret_word);
    }

    fclose(f);
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

void add_new_word(){
    char user_choice;
    printf("Do you want to add a new word to the game? (Y/N)\n");
    scanf(" %c", &user_choice);
    
    if(user_choice == 'Y'){
        char new_word[WORD_SIZE];
        printf("Qual a nova palavra?\n");
        scanf("%s", new_word);

        FILE* f;
        f = fopen("words.txt", "r+");//r+ -> read and write
        if(f == 0){
            printf("Sorry, it wasn't possible to read from the file\n");
            exit(1);
        }

        int quantity_of_words;
        fscanf(f, "%d", &quantity_of_words);//It reads the content of a file
        quantity_of_words++;

        fseek(f, 0, SEEK_SET);
        fprintf(f, "%d", quantity_of_words);//Updates the number of words in the file

        fseek(f, 0, SEEK_END);
        fprintf(f, "\n%s", new_word);//Adds the new word to the end of file

        fclose(f);
    }
}

void print_trophy(){
    printf("      You WON. Congrats!!!          \n");
    printf("         ___________                \n");
    printf("        '._==_==_=_.'               \n");
    printf("        .-\\:      /-.              \n");
    printf("       | (|:.     |) |              \n");
    printf("        '-|:.     |-'               \n");
    printf("          \\::.    /                \n");
    printf("           '::. .'                  \n");
    printf("             ) (                    \n");
    printf("           _.' '._                  \n");
    printf("          `\"\"\"\"\"\"\"`          \n");
}

void print_skull(){
    printf("      You LOST. The secret word was: %s\n\n            ", secret_word);
    printf("       ______                                           \n");
    printf("                .-\"      \"-.                          \n");
    printf("               /            \\                          \n");
    printf("   _          |              |          _               \n");
    printf("  ( \\         |,  .-.  .-.  ,|         / )             \n");
    printf("   > \"=._     | )(__/  \\__)( |     _.=\" <            \n");
    printf("  (_/\"=._\"=._ |/     /\\     \\| _.=\"_.=\"\\_)       \n");
    printf("         \"=._ (_     ^^     _)\"_.=\"                  \n");
    printf("             \"=\\__|IIIIII|__/=\"                      \n");
    printf("            _.=\"| \\IIIIII/ |\"=._                     \n");    
    printf("  _     _.=\"_.=\"\\          /\"=._\"=._     _         \n");
    printf(" ( \\_.=\"_.=\"     `--------`     \"=._\"=._/ )        \n");
    printf("  > _.=\"                            \"=._ <            \n");
    printf(" (_/                                    \\_)            \n");
}

int main(void){
    pick_word();
    write_header();

    do{
        print_word();
        requests_user_attempt();
    }while(!player_won() && !hanged());

    if(player_won()){
        print_trophy();
    }else{
        print_skull();
    }
    add_new_word();
}
