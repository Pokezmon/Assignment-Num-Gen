#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame();

int main() {
    char choice;
    srand(time(NULL)); // Seed the random number generator

    do {
        playGame();
        printf("\nWould you like to play again? (y/n): ");
        scanf_s(" %c", &choice);
    } while (choice == 'y' || choice == 'Y');

    printf("Thanks for playing! Goodbye.\n");
    return 0;
}

void playGame() {
    int randomNumber = (rand() % 100) + 1; // Generate number between 1-100
    int guess, attempts = 0;

    printf("Guess the number (between 1 and 100):\n");

    while (1) {
        printf("Enter your guess: ");
        if (scanf_s("%d", &guess) != 1) { // Validate input
            printf("Invalid input. Please enter a number between 1 and 100.\n");
            while (getchar() != '\n'); // Clear input buffer
            continue;
        }

        attempts++;

        if (guess < 1 || guess > 100) {
            printf("Out of range! Please enter a number between 1 and 100.\n");
        }
        else if (guess < randomNumber) {
            printf("Too low! Try again.\n");
        }
        else if (guess > randomNumber) {
            printf("Too high! Try again.\n");
        }
        else {
            printf("Congratulations! You guessed the correct number in %d attempts.\n", attempts);
            break;
        }
    }
}
