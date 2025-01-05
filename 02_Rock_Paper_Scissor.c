//Program for rock paper scissor
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void printRock() {
    printf("    _______\n");
    printf("---'   ____)\n");
    printf("      (_____)\n");
    printf("      (_____)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}

void printPaper() {
    printf("    _______\n");
    printf("---'   ____)____\n");
    printf("          ______)\n");
    printf("          _______)\n");
    printf("         _______)\n");
    printf("---.__________)\n");
}

void printScissors() {
    printf("    _______\n");
    printf("---'   ____)____\n");
    printf("          ______)\n");
    printf("       __________)\n");
    printf("      (____)\n");
    printf("---.__(___)\n");
}
void printart(char ch){
    if(ch=='r'){
        printRock();
    }
    else if(ch=='p'){
        printPaper();
    }
    else{
        printScissors();
    }
    printf("\n");
}
void printDraw(){
    printf("  ___    ____    ____  __    __ \n");
    printf(" |   \\  |    \\  /    ||  |__|  |\n");
    printf(" |    \\ |  D  )|  o  ||  |  |  |\n");
    printf(" |  D  ||    / |     ||  |  |  |\n");
    printf(" |     ||    \\ |  _  ||  `  '  |\n");
    printf(" |     ||  .  \\|  |  | \\      / \n");
    printf(" |_____||__|\\_||__|__|  \\_/\\_/  \n");
    printf("                                \n");
}

void printWon(){
    printf("  __ __   ___   __ __      __    __   ___   ____  \n");
    printf(" |  |  | /   \\ |  |  |    |  |__|  | /   \\ |    \\ \n");
    printf(" |  |  ||     ||  |  |    |  |  |  ||     ||  _  |\n");
    printf(" |  ~  ||  O  ||  |  |    |  |  |  ||  O  ||  |  |\n");
    printf(" |___, ||     ||  :  |    |  `  '  ||     ||  |  |\n");
    printf(" |     ||     ||     |     \\      / |     ||  |  |\n");
    printf(" |____/  \\___/  \\__,_|      \\_/\\_/   \\___/ |__|__|\n");
    printf("                                                 \n");
}

void printLose(){
    printf("  __ __   ___   __ __      _       ___   _____   ___ \n");
    printf(" |  |  | /   \\ |  |  |    | |     /   \\ / ___/  /  _]\n");
    printf(" |  |  ||     ||  |  |    | |    |     (   \\_  /  [_ \n");
    printf(" |  ~  ||  O  ||  |  |    | |___ |  O  |\\__  ||    _]\n");
    printf(" |___, ||     ||  :  |    |     ||     |/  \\ ||   [_ \n");
    printf(" |     ||     ||     |    |     ||     |\\    ||     |\n");
    printf(" |____/  \\___/  \\__,_|    |_____| \\___/  \\___||_____|\n");
    printf("                                                    \n");
}

int main(){
    
    
    
    bool flag=true;
    char user_inp;
    char ch;
    while(flag==true){
        //Code for computer to get value
        srand(time(0));
        int random_num = (rand() % 3);
        char arr[3]={'r','p','s'};
        char comp_inp=arr[random_num];

        //User input
        printf("Enter \"r\" for Rock, \"p\" for Paper & \"s\" for scissor: ");
        scanf("%c",&user_inp);
        getchar();

        //Check for draw
        if (user_inp==comp_inp){
            printf("Computer Input: \n");
            printart(comp_inp);
            printf("Your Guess: \n");
            printart(user_inp);
            printf("Result--->\n");
            printDraw();
            printf("\n");
            
        }
        //Check for computer win
        else if((comp_inp=='p' && user_inp=='r') || (comp_inp=='r' && user_inp=='s') ||  (comp_inp=='s' && user_inp=='p')){
             printf("Computer Input: \n");
            printart(comp_inp);
            printf("Your Guess: \n");
            printart(user_inp);
            printf("Result--->\n");
            printLose();
            printf("\n");
        }

        //Activated when user is win
        else{
            printf("Computer Input: \n");
            printart(comp_inp);
            printf("Your Guess: \n");
            printart(user_inp);
            printf("Result--->\n");
            printWon();
            printf("\n");
        }

        //Asking user for continue playing
        printf("Do you want to continue playing 'y' or 'n': ");
        scanf("%c",&ch);
        getchar();
        if(ch!='y') flag=false;
    }
    return 0;
}