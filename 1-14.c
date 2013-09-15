#include <stdio.h>
#include <stdlib.h>
#define MAXLEN 128
#define MAXCOUNT 30

/*打印输入中各字符出现频度直方图*/

int main()
{
    int c, i, n, length, maxle;
    int disp;
    float scale;
    int cl[MAXLEN];

    length = maxle = 0;
    for(i = 0; i < MAXLEN; i++)
        cl[i] = 0;
    while((c = getchar()) != EOF)
    {
        if(isprint(c))
            cl[c]++;
    }
    for(i = 0; i < MAXLEN; i++)
    {
        if(cl[i] > maxle)
            maxle = cl[i];
    }
    for(i = 0; i < MAXLEN; i++)
    {
        if(cl[i] != 0)
        {
            scale = (float) cl[i] / (float) maxle;
            disp = scale * MAXCOUNT;
            printf("%2c--%d--", i, cl[i]);
            for(n = 0; n < disp; n++)
                putchar('*');
            putchar('\n');
        }
    }
}
