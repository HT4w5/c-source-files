#include<stdio.h>

double getRevenue(double capital, double interest, int time)
{
    return capital * (interest * time + 1);
}

int main(void)
{
    double capital;
    double a, b, c, d, e;
    scanf("%lf", &capital);

    //a
    a = getRevenue(capital, 0.03, 5);

    //b
    b = getRevenue(capital, 0.021, 2);
    b = getRevenue(b, 0.0275, 3);

    //c
    c = getRevenue(capital, 0.0275, 3);
    c = getRevenue(c, 0.021, 2);

    //d
    d = capital;
    for(int i = 1; i <=5; i++)
    {
        d = getRevenue(d, 0.015, 1);
    }

    //e
    e = capital;
    for(int i = 1; i <=20; i++)
    {
        e = getRevenue(e, 0.0035 / 4, 1);
    }

    printf("%f %f %f %f %f", a, b, c, d, e);
    return 0;
}