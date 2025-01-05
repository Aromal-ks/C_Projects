/*
Number Guessing Game:
The programm will generate a random number from 1 to 100 and the user want to guess it.
if guess is below print low if high print high if correct print you won
for each guess user will lose each life
there shoul be two modes hard and easy
in hard there is only 5 life
in easy 10 life is provided
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

void printrules()
{
    printf("***     Rules to Follow     ***\n");
    printf("1. The computer generate a random number from 1 to 100 and the user want to guess it.\n");
    printf("2. For each guess user will lose each life\n");
    printf("3. There are  two modes \"Hard\" & \"Easy\" \n");
    printf("4. In \"Hard\" there is only 5 life and for \"Easy\" you get 10.\n");
    printf("\n");
}

int main()
{
    char rule[5];
    printf("Welcome to Number Guessing Game!!!\n");
    printf("Enter \"show\" to see the rules else we will continue: ");
    fgets(rule, sizeof(rule), stdin);
    rule[strcspn(rule, "\n")] = '\0';
    if (strcmp(rule, "show") == 0)
    {
        printrules();
    }
    srand(time(0));
    int randomNumber = (rand() % 100) + 1; // Random number generation
    printf("Random number between 1 and 100: %d\n", randomNumber);

    int life;
    char mode[6];
    printf("Hard or Easy mode: ");
    fgets(mode, sizeof(mode), stdin);
    mode[strcspn(mode, "\n")] = '\0';
    for (int i = 0; mode[i] != '\0'; i++)
    {
        mode[i] = tolower(mode[i]);
    }

    if (strcmp(mode, "easy") == 0)
    {
        printf("You have 10 life\n");
        life = 10;
    }
    else
    {
        printf("You have 5 life\n");
        life = 5;
    }
    bool flag = true;
    int guess_num = 1, guess;
    printf("\n");
    while (flag == true)
    {
        printf("Enter the guess %d: ", guess_num);
        scanf("%d", &guess);
        if (guess == randomNumber)
        {
            printf("Congratulations, You Won The Game\n");
            life--;
            flag = false;
        }
        else if (guess > randomNumber)
        {
            printf("You guessed is high.\n");
            life--;
            printf("Your remaining have %d life remaning.\n", life);
        }
        else if (guess < randomNumber)
        {
            printf("You guessed is Low.\n");
            life--;
            printf("Your remaining have %d life remaning.\n", life);
        }
        if (life == 0)
        {
            printf("\nYou ran out of life\n");
            flag = false;
        }
        guess_num++;
        printf("\n");
    }

    return 0;
}