#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_WORD_LENGTH 50
#define MAX_TRIES 7

typedef struct
{
    char word[MAX_WORD_LENGTH];
    char wordHint[MAX_WORD_LENGTH];
} wordList_t;
bool guessedLetter(char guess, int wordLength, char* selectWord, char* guessedWord);
void displayGuess(char* guessedWord, int wordLength);
void drawHangMan(int tries);

int main(){
    wordList_t listWithHints[] = {
     {"phone", "A device everyone must have."},
     {"pizza", "A popula italian dish"},
     {"electricity","The world greatest investion 18s century"},
     {"africa", "The largest continent"}
    };
    
    srand(time(NULL));
    int rword = rand()%4;
    char* selectWord = listWithHints[rword].word;
    char* hint = listWithHints[rword].wordHint;
    int wordLength = strlen(selectWord);
    char guessedWord[MAX_WORD_LENGTH] = {0};
    bool guessedLetters[26] = {0};
    
    
    printf("\n===== Welcome to hange man =====\n");
    printf("\n===== Hint: %s =====\n", hint);
    printf("Guess the word\n");
    int tries = 0; 
    
    while (tries <= MAX_TRIES)
    {
        printf("Word:");
        displayGuess(guessedWord, wordLength);
        drawHangMan(tries);
        if(strcmp(selectWord, guessedWord) == 0)
        {
            printf("\nYou guessed the word.\n The word was: %s",selectWord);
            break;
        } 
        if(tries >= MAX_TRIES)
        {
            printf("\nSorry runed out of tries.\n The word was: %s\n",selectWord);
            break;
        }
        char guess;
        printf("Enter a letter:");
        scanf("%c", &guess);
        while(getchar() != '\n');
        guess = tolower(guess);
        if(guessedLetters[guess - 'a']){
            printf("This letter was selected.\n Try another guess.\n");
        }
        else{
            guessedLetters[guess - 'a'] = true;
            if(!guessedLetter(guess, wordLength, selectWord, guessedWord)){
                tries ++;
            }
        }   
    }

    return 0;
}
bool guessedLetter(char guess, int wordLength, char* selectWord, char* guessedWord){
    bool state = false;
    for(int i = 0; i < wordLength; i++){
        if(guess == selectWord[i]){
            guessedWord[i] = guess;
            printf("Good Guess!\n");
            state = true;
        }
    }
    if(!state){
        printf("Wrong Guess, Try again.\n");
    }
    return state;
}
void displayGuess(char* guessedWord, int wordLength){
    for(int i = 0; i < wordLength; i++)
    {
        if(guessedWord[i] != '\0'){
            printf("%c",guessedWord[i]);
        }
        else printf("_");
    }
    printf("\n\n");
    // return 0;
}
void drawHangMan(int tries){
    char* hangManParts[] = {"+____", "|   |", "|   o", "|   /+\\", "|    |", "|   / \\", "|" };
    for(int i=0; i<tries; i++){
        printf("%s\n",hangManParts[i]);
    }
    printf("\n");
}

