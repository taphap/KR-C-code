#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0

/*每行一个单词打印输入*/
/*设置状态标志*/

int main()
{
    int c, state;

    state = OUT;
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(state == IN)         /*finish the word*/
            {
                putchar('\n');
                state = OUT;
            }
        }
        else if(state == OUT)       /*beginning the word*/
        {
            state = IN;
            putchar(c);
        }
        else                        /*inside the word*/
            putchar(c);
    }
}
