#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_LENGTH 12
#define rounds 7

int main() {
    char Player1input[MAX_LENGTH];
    char Player2input;
    char revealed[MAX_LENGTH]; // Create a string to store revealed letters

    // Initialize the revealed string with underscores
    for (int i = 0; i < MAX_LENGTH; i++) {
        revealed[i] = '_';
    }

    // Get the word from Player 1
    while (1) {
        printf("Player 1, enter a word of no more than 12 letters:\n");
        scanf("%s", Player1input);

        // Check if the word length is valid
        int wordLength = strlen(Player1input);

        if (wordLength < 1 || wordLength > 12) {
            printf("Sorry, the word must be between 1 and 12 characters long.\n");
            continue;
        }

        int valid = 1;
        for (int i = 0; Player1input[i] != '\0'; i++) {
            Player1input[i] = tolower(Player1input[i]);

            if (!isalpha(Player1input[i])) {
                valid = 0;
                printf("Sorry, the word must contain only English letters.\n");
                break;
            }
        }

        // If the word is valid, break the loop
        if (valid) {
            break;
        }
    }

    // Start the game loop
    int remaining_rounds = rounds;
    int correctGuess = 0; // Initialize a variable to track correct guesses

    while (remaining_rounds > 0) {
        // Print the guessed letters
        printf("Player 2 has so far guessed: ");
        for (int i = 0; i < strlen(Player1input); i++) {
            printf("%c", revealed[i]);
            if (i < strlen(Player1input) - 1) {
                printf(" ");
            }
        }
        printf("\n");

        // Get a guess from Player 2
        printf("Player 2, you have %d guesses remaining. Enter your next guess:\n", remaining_rounds);
        scanf(" %c", &Player2input);

        Player2input = tolower(Player2input);

        // Check if the player has already guessed the letter
        int guess = 0;
        for (int i = 0; i < strlen(Player1input); i++) {
            if (revealed[i] == Player2input) {
                guess = 1;
                break;
            }
        }

        // If the player has already guessed the letter, let them know
        if (guess) {
            printf("You already guessed that letter.\n");
        } else {
            // If the player guessed a letter that is in the word, reveal it
            for (int i = 0; i < strlen(Player1input); i++) {
                if (Player1input[i] == Player2input) {
                    revealed[i] = Player2input;
                    correctGuess = 1; // Mark a correct guess
                }
            }

            // If the player guessed a letter that is not in the word, decrement the remaining guesses
            if (!guess && !correctGuess) {
                remaining_rounds--;
            }
        }

        // Check if the player has won
        int correct = 1;
        for (int i = 0; i < strlen(Player1input); i++) {
            if (revealed[i] == '_') {
                correct = 0;
                break;
            }
        }

        if (correct) {
            printf("Player 2 has so far guessed: ");
            for (int i = 0; i < strlen(Player1input); i++) {
                printf("%c", revealed[i]);
                if (i < strlen(Player1input) - 1) {
                    printf(" ");
                }
            }
            printf("\nPlayer 2 wins.\n");
            break;
        }
    }

    // If the player has run out of guesses, they lose
    if (remaining_rounds == 0) {
        printf("Player 2 loses. The word was %s.\n", Player1input);
    }

    return 0;
}
