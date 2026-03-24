#include<stdio.h>
#include<math.h>
#include<time.h>
#include<stdlib.h>

// In this project we will have 3 fuctions -The computer will play and choose rock(0-33),paper(33-66), and scissors(66-10).
// as normal Rock beats scissors and paper beats Rock while as siscors beats paper.


int game(char user, char computer){
    if(user == computer){
        return 0;
    }
    if(user == 's' && computer == 'p'){
        return 1;
    }
    if(user == 's' && computer == 'r'){
        return -1;
    }
    if(user == 'p' && computer == 's'){
        return -1;
    }
    if(user == 'p' && computer == 'r'){
        return 1;
    }
    if(user == 'r' && computer == 'p'){
        return -1;
    }
    if(user == 'r' && computer == 's'){
        return 1;
    }
    return 2;
}

char getComputer(int n){
    if(n>=0 && n<33){
        return 'r';
    }
    if(n>=33 && n<66){
        return 'p';
    }
    if(n>=66 && n<100){
        return 's';
    }
    return 'y';
}

int main(){
    char user, comp;
    int n, score = 0;
    srand(time(NULL));
    while(1){
        printf("Enter p(paper), r(rock), s(scissors), or z(exit)\n\n:");
        comp = getComputer(rand()%100);
        scanf("%c",&user);
        while(getchar() != '\n');
        if(user == 'z'){
            break;
        }
        switch (game(user, comp))
        {
        case 1:
            score++;
            printf("\nYou Win\n");
            printf("\nYou chosee:%c , and comuter chosee:%c\n  score:%d\n",user, comp, score);
            break;
        case -1:
            score--;
            if(score<0){
                score =0;
            }
            printf("\nYou Loss\n");
            printf("\nYou chosee:%c , and comuter chosee:%c\n  score:%d\n",user, comp, score);
            break;
        case 0:
            printf("\nIts a draw\n");
            printf("\nYou chosee:%c , and comuter chosee:%c\n  score:%d\n",user, comp, score);
            break;
        default:
            printf("\nInvalide Input\n");
            break;
        }     
    }
    return 0;
}