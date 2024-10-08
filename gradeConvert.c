#include<stdio.h>

int main()
{
    int score;
    scanf("%d", &score);
    switch (score)
    {
        case 0 ... 59:
            printf("E");
            break;

        case 60 ... 69:
            printf("D");
            break;

        case 70 ... 79:
            printf("C");
            break;

        case 80 ... 89:
            printf("B");
            break;

        case 90 ... 94:
            printf("A");
            break;

        case 95 ... 100:
            printf("A+");
            break;

        default:
            printf("Invalid score");
            break;
    }
    return 0;
}