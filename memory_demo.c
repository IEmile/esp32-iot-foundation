#include <stdio.h>
#include <stdlib.h>

int global_var = 100;
// The commented variables where used for observations
// int global_var2 = 100;

void stack_demo()
{
    // The commented variables where used for observations
    int stack_var = 10;
    // int stack_var2 = 10;
    printf("Stack variable: %d\n", stack_var);
    printf("SV1: %p\n", &stack_var);
    // printf("Stack variable2: %d\n", stack_var2);
    // printf("SV2: %p\n", &stack_var2);
}

void heap_demo()
{
    // The commented variables where used for observations
    int *heap_var = malloc(sizeof(int));
    *heap_var = 50;
    // int *heap_var2 = malloc(sizeof(int));
    // *heap_var2 = 50;

    printf("Heap variable: %d\n", *heap_var);
    printf("HV: %p\n", heap_var);

    
    // printf("Heap variable: %d\n", *heap_var2);
    // printf("HV2: %p\n", heap_var2);

    // free(heap_var2);
    free(heap_var);
}

void static_demo()
{
    // The commented variables where used for observations
    static int counter = 0;
    // static int recounter = 4;
    counter++;
    // recounter--;
    printf("Static counter: %d\n", counter);
    printf("CM: %p\n", &counter);
    // printf("Static counter: %d\n", recounter);
    // printf("RCM: %p\n", &recounter);
}

int main()
{
    printf("Global variable: %d\n", global_var);
    printf("GV1: %p\n", &global_var);
    // printf("Global variable: %d\n", global_var2);
    // printf("GV2: %p\n", &global_var2);

    stack_demo();
    heap_demo();

    static_demo();
    static_demo();
    static_demo();

    return 0;
}