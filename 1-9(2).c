#include <stdio.h>
#include <stdlib.h>
#define NONBLANK 'a'

/*���븴�Ƶ������������ո���һ���ո����*/
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
