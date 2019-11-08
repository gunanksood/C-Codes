             //Fibonacci Series using Recursion
#include<stdio.h>
#include<time.h>

int fibo(int);

int main ()
{
int n = 40;

clock_t begin, end;

double time_spent=0.0;

begin = clock();

printf("%d \n", fibo(n));

end = clock();

time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

printf("\nTime Taken %lf ", time_spent);

getchar();
return 0;
}

int fibo(int n)
{
if (n <= 1)
    return n;
  else
return fibo(n-1) + fibo(n-2);
}

