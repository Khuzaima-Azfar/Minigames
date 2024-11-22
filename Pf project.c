#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>
#include<time.h>

int SNL(){
    int dice,userpos=0,cpupos=0,snake;
    srand(time(NULL));
    printf("first to reach a hundred wins!\n\n");
    while (0<1){
        printf("player turn (press enter)");
        getchar();
        dice=(rand()%6)+1;
        printf("you rolled %d\n\n", dice);
        userpos+=dice;
        if (userpos%13==0){
            snake=rand()%20;
            userpos-=snake;
            if (userpos<0)
                userpos=0;
            printf("You landed on a snake and fell down %d steps\n\n", snake);
        }
        else if (userpos%7==0 && userpos%13!=0 ){
            snake=rand()%20;
            userpos+=snake;
            printf("you found a ladder and went up %d steps\n\n", snake);
        }
        dice=(rand()%6)+1;
        printf("CPU turn: rolled %d\n\n", dice);
        cpupos+=dice;
        if (cpupos%13==0){
            snake=rand()%20;
            cpupos-=snake;
            printf("the cpu stepped on a snake and went down %d steps\n\n", snake);
            if (cpupos<0)
            cpupos=0;
        }
        else if (cpupos%7==0){
            snake=rand()%20;
            userpos+=snake;
            printf("the cpu found a ladder and went up %d steps\n\n", snake);
        }
        printf("The User is at position: %d\nThe CPU is at position:%d\n\n",userpos,cpupos);
        if (userpos>=100 && cpupos<userpos){
            printf("The user won!\n\n");
            return 0;
            break;
        }
        else if (cpupos>=100 && userpos<cpupos){
            printf("The CPU won!\n\n");
            return 1;
            break;
        }

    }    
}
int Drace(){
    int user_roll, computer_roll;
    int rounds, user_wins = 0, computer_wins = 0;
    srand(time(NULL));
    printf("Enter the number of rounds you want to play: ");
    scanf("%d", &rounds);

    for (int i = 0; i < rounds; i++) {
            printf("Round %d: Throw the dice (press any key)", i + 1);
            getchar(); getc(stdin);
            user_roll=(rand()%6)+1;
		computer_roll = (rand() % 6) + 1;
        while (user_roll==computer_roll)
        {
            computer_roll=(rand()%6)+1;
        }
        
        printf("You rolled: %d\n", user_roll);
        printf("Computer rolled: %d\n", computer_roll);
        if (user_roll > computer_roll) {
            printf("You won this round\n");
            user_wins++;
        } else if (user_roll < computer_roll) {
            printf("You lost this round\n");
            computer_wins++;
        } else 
            printf("It's a tie this round");
        printf("\n");
    }
    if (user_wins > computer_wins) {
        printf("Congratulations! You won the game\n");
        return 0;
    } else if (user_wins < computer_wins) {
        printf("You lost the game.\n");
        return 1;
    } else {
        printf("It is a tie");
        return 2;
    }
}
int guess(){  
    int chosen=(rand()%25)+1, guessed;
    int result=1;
    printf("\n\nA number between 1 and 25 has been chosen.\nYou have 5 tries.\nInput your guess:");
    for(int i=0;i<5;i++){
        scanf("%d",&guessed);
        if (guessed==chosen){
            printf("\nYou guessed correctly!!!");
            result=0;
            break;
        }
        else if(guessed<chosen){
        printf("\nThe guess is smaller than the chosen number");
        if (i<4)
        printf("\nTry again.\n");
        }
        else if(guessed>chosen){
        printf("\nthe guess is bigger than the chosen number");
        if (i<4)
        printf("\nTry again.\n");}
    }
    if (result!=0)
    printf("\nThe number was %d\nYou Lost.",chosen);
    return result;
}
int rps(){
    int bestof, won=0,lost=0;
    printf("\n\n\n\n\n\n Best of: ");
    scanf("%d", &bestof); if(bestof%2==0) bestof--;
    for (int i=1; i<=bestof; i++)
    {
        int cpu_play=rand()%3, player_play;
        printf("\n Rock(0), Paper(1) or Scissors(2)? (choose any other option to lose the round)  ");
        scanf("%d",&player_play);
        if(cpu_play==0)         printf("\nCPU chose Rock");
        else if (cpu_play==1)   printf("\nCPU chose paper");
        else                    printf("\nCPU chose scissors");
        if (player_play==0)     printf("\nPlayer: Rock!");
        else if(player_play==1) printf("\nPlayer: Paper!");
        else if(player_play==2) printf("\nPlayer: Scissors!");
        else printf("\nPlayer: i don't know");
        if ((player_play==0 && cpu_play==1) || (player_play==1 && cpu_play==2) || (player_play==2 && cpu_play==0)||(player_play<0 || player_play>2)){
            printf("\nyou lost this round :(");
            lost++;
        }
        else if ((player_play==1 && cpu_play==0) || (player_play==2 && cpu_play==1) || (player_play==2 && cpu_play==0)){
            printf("\nyou won this round!!!!");
            won++;
        }
        else{
            printf("\nYou drew a tie");
        }
        if (won==bestof/2+1 || lost==bestof/2+1){
            break;
        }
    }
    if (won>lost){
        printf("\n\n\n                                      you won the game!!!!!!!!!!!!!");
        return 0;
    }
    else if (lost>won){
        printf("\n\n\n                                      you lost the game :(");
         return 1;
         }
    else{
    printf("\n\n\n                                          the game ended in a tie");
    return 2;
    }


}
int main(){
    int input=1, win=0, loss=0, result;
    while (input!=0){
        printf("\f\n\nCT-112:Masarrat Fatima\t\t\t\t\t\t                      Win-loss: %d-%d \nCT-111:Sana\t\t\t\t\t\t Main Menu\nCT-146:M. Khuzaima Azfar Khan\n\n Pick a Game from the list using the list number:\n1.Rock Paper Scissors.\n2.Guess The Number.\n3.Dice Race.\n4.Snakes and Ladders.\n0.quit\n",win,loss);
        scanf("%d", &input);
        system("cls");
        switch (input){


            case 1:
            result=rps();
            if (result==0)
            win++;
            else if(result==1)
            loss++;
            break;

            case 2:
            result=guess();
            if (result==0)
            win++;
            else if(result==1)
            loss++;
            break;

            case 3:
            result=Drace();
            if (result==0)
            win++;
            else if (result==1)
            loss++;
            break;
            
            case 4:
            result=SNL();
            if (result==0)
            win++;
            else if (result==1)
            loss++;
            break;

        }
    }
}