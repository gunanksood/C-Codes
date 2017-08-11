          /* C program for Memoized version for nth Fibonacci number */
#include<stdio.h>
#include<time.h>

#define MAX 100

int lookup[MAX];

          /* Function to initialize NIL values in lookup table */
void constructor()
{
    int i;
    for (i = 0; i < MAX; i++)
    {
        lookup[i] = -1;
    }
}

         /* function for nth Fibonacci number */
int fib(int n)
{
    if (lookup[n] == -1)
    {
        if (n <= 1)
        lookup[n] = n;
    else
        lookup[n] = fib(n-1) + fib(n-2);
    }

    return lookup[n];
}

int main ()
{
    int n = 40;

    clock_t begin, end;

    double time_spent;

    constructor();

    begin = clock();

    printf("Fibonacci number is %d \n", fib(n));

    end = clock();

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime Taken %lf", time_spent);

    return 0;
}

