             //Fibonacci Series using Recursion
#include<stdio.h>
#include<time.h>

int fibonacci(int n)
{
if (n <= 1)
    return n;
return fibonacci(n-1) + fibonacci(n-2);
}

int main ()
{
int n = 40;

clock_t begin, end;

double time_spent;

begin = clock();

printf("%d\n", fibonacci(n));

end = clock();

time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("\nTime Taken %lf ", time_spent);

getchar();
return 0;
}

