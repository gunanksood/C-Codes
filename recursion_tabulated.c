        /* C program for Tabulated version */
#include<stdio.h>
#include<time.h>

int fibonacci(int n)
{
    int f[n+1];
    int i;

    double time_spent ;

    f[0] = 0; f[1] = 1; 
    for (i = 2; i <= n; i++)
        f[i] = f[i-1] + f[i-2];

    return f[n];
}

int main ()
{
    int n = 40;

    clock_t begin, end;
    double time_spent;

    begin = clock(); // Time before calculating Fib number

    printf("Fibonacci number is %d \n", fibonacci(n));

    end = clock();  // Time before calculating Fib number

    time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

    printf("\nTime Taken %lf ", time_spent);

    return 0;
}

