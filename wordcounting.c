#include<stdio.h>
#define in 1
#define out 0

int main(void)
{
    int c, nl, nc, nw,state;
    nl = nc = nw = 0;
    while((c = getchar()) != EOF)
    {
        nc++;
        if(c == '\n')
            nl++;
        if(c == ' ' || c == '\n' || c == '\t')
            state=out;
        else if(state == out)
        {
            state = in;
            ++nw;
        }
    }
    printf(" no. of new lines is : %d \n",nl);
    printf(" no. of characters is : %d \n",nc);
    printf(" no. of words is : %d \n",nw);
    return 0;
}
