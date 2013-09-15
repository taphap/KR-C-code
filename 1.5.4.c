#include <stdio.h>
#include <stdlib.h>
#define OUT ' '

/*单词计数*/
/*nl 行数，nw 单词数，nc 字符数*/

int main()
{
    int c, nl, nw, nc, lastc;

    lastc = OUT;
    nl = nw = nc =0;
    while((c = getchar()) != EOF)
    {
        if(c != ' '&&c != '\t'&&c != '\n')
        {
            nc++;
            if(lastc == ' ' || lastc == '\t'||lastc == '\n')
                nw++;
        }
        else if(c == '\n')
            nl++;
        lastc = c;
    }
    printf("lines %d, words %d, characters %d", nl, nw, nc);
}
