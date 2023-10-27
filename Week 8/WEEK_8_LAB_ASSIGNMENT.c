#include <stdio.h>

int main() {

    int Player1number, Player2number;
    int rounds = 10;

    // This prompts player 1 to input the number within the range required
    while (1) {
        printf("Player 1, enter a number between 1 and 1000:\n");
        scanf("%d", &Player1number);

        if (Player1number >= 1 && Player1number <= 1000) {
            break;
        } else {
            printf("That number is out of range.\n");
        }
    }

    while (rounds > 0) {
        printf("Player 2, you have %d guesses remaining.\n", rounds);
        printf("Enter your guess: \n");
        scanf("%d", &Player2number);

        if (Player1number == Player2number) {
            printf("Player 2 wins.\n");
            break;
        } else if (Player2number < Player1number) {
            printf("Too low.\n");
            rounds--;
        } else if (Player2number > Player1number) {
            printf("Too high.\n");
            rounds--;
        } else {
            printf("The number is out of range.\n");
        }


    }

    if (rounds == 0) {
            printf("Player 1 wins.\n");
    }

    return 0;
    
}