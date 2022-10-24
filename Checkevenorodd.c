#include<stdio.h>
#include<conio.h>
int main()
{
    int num;
    printf("Enter any number: ");
    scanf("%d", &num);
    if(num%2 == 0)
        printf("\nIt's an even number.");
    else
        printf("\nIt's an odd number.");
    getch();
    return 0;
}
