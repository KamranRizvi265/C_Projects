#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
    int random, guess;
    int no_of_guess = 0;
    srand(time(NULL)); // Seed the random number generator
    random = rand() % 100 + 1; // Generate a random number between 1 and 100
    
    printf("Welcome to the Guessing Game!\n");

    do
    {
        printf("\nEnter your guess number (1 to 100): ");
        scanf("%d", &guess);
        no_of_guess++;
        if (guess < random)
        {
            printf("Guess larger number!\n");
        }
        else if (guess > random)
        {
            printf("Guess smaller number!\n");
        }
        else
        {
            printf("\nCongratulations!!! You guessed the number in %d attempts.", no_of_guess);
        }
    } while (guess != random);

    printf("\nBye Bye! Thanks for playing.\n");
    printf("Developed by: Kamran Rizvi\n");

    return 0;
}