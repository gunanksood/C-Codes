#include<stdio.h>

int bitxor(int x,int y)
{
    return ~(~x & ~y) & ~(x & y);
}
int main(void)
{
    int x, y;
    printf("enter the first input");
    scanf("%d", &x);
    printf("enter the second input");
    scanf("%d", &y);
    int c = bitxor(x, y);
    printf("output : %d\n", c);
    return 0;
}
