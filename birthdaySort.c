// birthdaySort.c: Print date and name in sorted order.

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct infmt
{
    char s[51];
    int year, month, day;
};

void printSortedBirthdays(struct infmt a[], int n);
int birthdayCompare(const void *a, const void *b);
void parseInput(struct infmt a[], int n);

int main(void)
{
    int n;
    struct infmt a[50003];

    // Input.
    scanf("%d", &n);
    parseInput(a, n);

    printSortedBirthdays(a, n);

    return 0;
}

void parseInput(struct infmt a[], int n)
{
    char dateBuf[11];
    char parseBuf[11];
    char *dlim = NULL;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%s", &a[i].s, &dateBuf);

        // Find first colon.
        dlim = strstr(dateBuf, ":");
        // Copy year to buffer.
        strncpy(parseBuf, dateBuf, dlim - dateBuf);
        // Null terminate.
        parseBuf[dlim - dateBuf] = '\0';
        a[i].year = atoi(parseBuf);
        // Remove year from buffer.
        strcpy(dateBuf, dlim + 1);

        // Find second colon.
        dlim = strstr(dateBuf, ":");
        // Copy month to buffer.
        strncpy(parseBuf, dateBuf, dlim - dateBuf);
        // Null terminate.
        parseBuf[dlim - dateBuf] = '\0';
        a[i].month = atoi(parseBuf);
        // Remove month from buffer.
        strcpy(dateBuf, dlim + 1);

        // Copy day to struct.
        a[i].day = atoi(dateBuf);
    }
}

int birthdayCompare(const void *a, const void *b)
{
    struct infmt *c, *d;
    c = (struct infmt *)a;
    d = (struct infmt *)b;

    int cToken, dToken;

    cToken = c->day + c->month * 100;
    dToken = d->day + d->month * 100;

    if (cToken == dToken) // Same date, sort by name.
    {
        for (int i = 0; 1; i++)
        {
            if (c->s[i] != d->s[i])
            {
                return c->s[i] - d->s[i];
            }
        }
    }
    else
    {
        return cToken - dToken;
    }
}

void printSortedBirthdays(struct infmt a[], int n)
{
    // Sort in acsending order.
    qsort(a, n, sizeof(struct infmt), birthdayCompare);

    int dateToken = a[0].month * 100 + a[0].day;
    int lastDateToken;

    // Print birthdays.
    // Print LF on next output if token is different.
    printf("%d:%d %s", a[0].month, a[0].day, a[0].s);
    for (int i = 1; i < n; i++)
    {
        lastDateToken = dateToken;
        dateToken = a[i].month * 100 + a[i].day;
        if (lastDateToken == dateToken) // Same date.
        {
            printf(" %s", a[i].s);
        }
        else
        {
            printf("\n%d:%d %s", a[i].month, a[i].day, a[i].s);
        }
    }
    printf("\n");
}
