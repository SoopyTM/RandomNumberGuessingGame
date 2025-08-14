#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"
#include "ctype.h"

int getUserGuess(void){
        char guess_str[32];
        int guess_int;

        printf("Enter Your Guess: ");

        if (fgets(guess_str, sizeof(guess_str), stdin) == NULL) {
                fprintf(stderr, "Error reading input.\n");
                return -1;
        }

        guess_str[strcspn(guess_str, "\n")] = '\0';

        for (size_t i = 0; guess_str[i] != '\0'; i++) {
                if (!isdigit((unsigned char)guess_str[i])) {
                        printf("Invalid input. Please enter a number.\n");
                        getUserGuess();
                        return -1;
                }
        }

        return atoi(guess_str);
}

int generateRandomNumber(void){
        srand(time(NULL));
        int randValue = (rand() % 1000) + 1;
        return randValue;
}

int main(int argc, char **argv){
        int randomNumber = generateRandomNumber();
        int guess = getUserGuess();

        while(guess != randomNumber){
                if(guess < randomNumber){
                        printf("Try a bit higher!\n");
                        guess = getUserGuess();
                }

                else if(guess > randomNumber){
                        printf("Try a bit lower!\n");
                        guess = getUserGuess();
                }
        }
        printf("Well done you fucking nerd!\n");

        return 0;
}