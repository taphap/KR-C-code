#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0

/*单词计数*/
/*设立状态标志*/

int main()
{
    int c, nl, nw, nc, state;

    nl = nw = nc = 0;
    state = OUT;
    while((c = getchar()) != EOF)
    {
        nc++;
        if(c == '\n')
            nl++;
        if(c == ' '||c == '\t'||c == '\n')
            state = OUT;
        else if(state == OUT)
        {
            state = IN;
            nw++;
        }
    }
    printf("lines %d, words %d, charaters %d", nl, nw, nc);
}
