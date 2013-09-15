#include <stdio.h>
#include <stdlib.h>
#define NONBLANK 'a'

/*输入复制到输出，将多个空格用一个空格代替*/
/*version 2*/

int main()
{
    int c, lastc;

    lastc = NONBLANK;
    while((c = getchar()) != EOF)
    {
        if(c != ' ')
            putchar(c);
        else if(lastc != ' ')
            putchar(c);
        lastc = c;
    }
}
