#include<stdio.h>
#include<ctype.h>

float calculate(float num1, float num2, char ope);
// void getInput(int* num1, int* num2, char* ope);
int main()
{
    printf("========= Simple Calulator =========\n");
    printf("            Number\nuse format: +\n            Number\n");
    float num1, num2;
    char ope;
    printf(":  ");
    scanf("%f",&num1);
    while(getchar() != '\n');
    printf(":");
    scanf("%c",&ope);
    printf(":  ");
    scanf("%f",&num2);
    printf("----------\n= %.2f\n",calculate(num1, num2, ope));
    return 0;
}
// void getInput(int* num1, int* num2, char* ope)
// {
//     printf("Enter")
// }
float calculate(float num1, float num2, char ope)
{
    switch (ope)
    {
    case '+':
        return num1 + num2;
        break;
    case '-':
        return num1 - num2;
        break;
    case 'x':
        return num1 * num2;
        break;
    case '*':
        return num1 * num2;
        break;
    }
}