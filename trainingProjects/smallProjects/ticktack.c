#include<stdio.h>
int printBoard(int* table ){
    int usedCells = 0;
    for(int i = 0; i < 9; i++){
        if(table[i] == 1){
            printf("| X ");
            usedCells++;
        }else if(table[i] == 2){
            printf("| O ");
            usedCells++;
        }else{
            printf("| . ");
        }
        if((i+1) % 3 == 0){
        printf("|\n");
        } 
    }
    return usedCells;
}
int main()
{
    int x = 0, c=0;
    for(int i = 0; i < 4; i ++){
        if(c == 3 || i ==0){
            printf("\n");
            x=0;
            c=0;
        } else{
            i--;
        }
        printf("%d", x+i);
        x+=3;
        c++;
    }
    // for(int i = 0; i <= 9; i++){
    //     if(i%3 == 0){
    //         printf("\n");
    //     }
    //     printf("%d",i + x);
    // }
    int table[9]={0};
    int player = 1;
    int cell, won = 0;
    printf("========= Welcome to TickTack game ============\n");
    printBoard(table );
    while( won <= 4){
        if(player == 1){
            printf("Player1 select box from 1-9\n:");
            scanf("%d",&cell);
            if(!table[cell-1]){
                table[cell-1] = player;
                player = 2;
            }else{
                printf("You can't use this cell\n");
            }
            if(printBoard(table ) >=9){
                printf("The table is full. Start new Table\n");
            }
        }
        else{
            printf("Player2 select box from 1-9\n:");
            scanf("%d",&cell);
            if(!table[cell-1]){
                table[cell-1] = player;
                player = 1;
            }else{
                printf("You can't use this cell\n");
            }
            if(printBoard(table ) >=9){
                printf("The table is full. Start new Table\n");
            }
        }
        
    //    won++;
    }
    // table[3]=2;
    // table[1]=1;
    // table[6]=2;

    return 0;
}