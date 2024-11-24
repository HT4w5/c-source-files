// kDaysDate.c: Outputs new date k days after given date.

#include <stdio.h>

typedef struct Date
{
    int yr;
    char mon;
    char day;
} date_t;

/* Prototypes */

// Return date of the next day of given date.
date_t get_next_date(date_t date);
// Return date k days after given date.
date_t get_date_after_k_days(date_t date, int k);
// Print date.
void print_date(date_t date);
// Determine whether a year is leap year.
int is_leap(int yr);

/* Definitions */

int main(void)
{
    date_t date;
    int k;

    // Input.
    scanf("%d%d%d%d", &date.yr, &date.mon, &date.day, &k);

    // Print results.
    print_date(get_date_after_k_days(date, k));
    return 0;
}

date_t get_next_date(date_t date)
{
    // Find number of days in current month.
    int max_days;
    if (date.mon == 2) // On February, set max_days according to year.
    {
        if (is_leap(date.yr))
        {
            max_days = 29;
        }
        else
        {
            max_days = 28;
        }
    }
    else
    {
        if (date.mon <= 7) // Jan-July. Expt Feb.
        {
            if (date.mon % 2)
            {
                // Odd month.
                max_days = 31;
            }
            else
            {
                // Even month.
                max_days = 30;
            }
        }
        else // Aug-Dec.
        {
            if (date.mon % 2)
            {
                // Odd month.
                max_days = 30;
            }
            else
            {
                // Even month.
                max_days = 31;
            }
        }
    }
    // Finish finding max_days.

    // Compare and increase d/m/y.
    // Check day carry.
    if (date.day == max_days)
    {
        // Carry exists.
        date.day = 1;
        // Check month carry.
        if (date.mon == 12)
        {
            // Carry exists.
            date.mon = 1;
            // Increase year by 1.
            date.yr++;
        }
        else
        {
            // No carry.
            date.mon++;
        }
    }
    else
    {
        // No carry.
        date.day++;
    }
    // Finish compare and increase d/m/y.
    return date;
}

date_t get_date_after_k_days(date_t date, int k)
{
    // Iterate k times to simulate k days.
    for (int i = 0; i < k; i++)
    {
        date = get_next_date(date);
    }
    return date;
}

void print_date(date_t date)
{
    printf("%d-%d-%d\n", date.yr, date.mon, date.day);
}

int is_leap(int yr)
{
    if (!(yr % 4))
    {
        if (!(yr % 100))
        {
            if (!(yr % 400))
            {
                return 1;
            }
            else
            {
                return 0;
            }
        }
        else
        {
            return 1;
        }
    }
    else
    {
        return 0;
    }
}