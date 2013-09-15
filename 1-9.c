#include <stdio.h>
#include <stdlib.h>

int main()
{
    int c, nb;

    nb = 0;
    while((c = getchar()) != EOF)
    {
        if(c != ' ')
        {
            nb = 0;
            putchar(c);
        }
        else
        {
            nb++;
            if(nb == 1)
                putchar(c);
        }
    }
}
