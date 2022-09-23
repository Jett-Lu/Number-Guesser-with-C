/*
    program: Number Guesser Game (PRG155)
    author: Jett Lu
    date: 11-27-2021
    purpose: program that generates a secret (whole) number in the range of 1 to 100
*/

#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int GetGuess() {
    int userGuess, i;

    for (i = 0; i <= 0; i++) {

        printf("Enter your guess\n");

        scanf("%d", & userGuess);

        if ((userGuess < 0) || (userGuess > 100))
            printf("Invalid input . Please guess again\n");

        else if ((userGuess >= 0) && (userGuess <= 100))
            return userGuess;

    }
}

void DisplayGameSummary(int secretNum, int lastGuess, int tooHigh, int tooLow) {

    printf("Guessing Game Summary\n");

    if (secretNum == lastGuess)
        printf("Congratulations. You guessed the secret number!\n");

    else
    printf("The secret number is: %d\n", secretNum);
    printf("Number of guesses that were too high: %2.d\n", tooHigh);
    printf("Number of guesses that were too low: %3.d\n", tooLow);
    printf("Total number of guesses: %15.d", (tooHigh + tooLow));
}

int main() {

    int secretNumber, finalGuess, high = 0, low = 0;
    srand(time(NULL));
    secretNumber = rand() % 100 + 1;

    printf("Welcome to Number Guessing Game\n");
    printf("Start guessing the Secret Number\n");

    finalGuess = GetGuess();

    while (finalGuess != 0) {

        if (finalGuess < secretNumber) {

            printf("Your guess is too low, guess again!!\n");
            low++;
        }
        else if (finalGuess > secretNumber) {

            printf("Your guess is too high, guess again!!\n");
            high++;
        }
        else if (finalGuess == 0 || finalGuess == secretNumber) {

            DisplayGameSummary(secretNumber, finalGuess, high, low);
            break;
        }

        finalGuess = GetGuess();
    }

    return 0;
}