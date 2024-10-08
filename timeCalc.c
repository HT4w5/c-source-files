#include<stdio.h>

int main()
{
    int hr, min, sec, dsec;
    scanf("%d:%d:%d %d",&hr,&min,&sec,&dsec);
    sec = hr * 3600 + min * 60 + sec + dsec;
    if(sec > 86400)
    {
        sec -= 86400;
    }
    hr = sec / 3600;
    sec = sec % 3600;
    min = sec / 60;
    sec = sec % 60;
    printf("%02d:%02d:%02d", hr, min, sec);
    return 0;
}