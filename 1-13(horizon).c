#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
#define MAXWORD 20
#define MAXCOUNT 20

/*打印输入单词水平长度直方图*/
/*c 输入字符；length 单词长度计数；i,n 循环变量；state 单词状态；maxwl 最长单词长度；
disp， scale 显示比例；wl[] 单词长度数组；*/

int main()
{
    int c, length, i, state, maxwl;
    int disp, n;
    float scale;
    int wl[MAXWORD];

    length = 0;
    maxwl = 0;
    state = OUT;
    for(i = 0; i < 20; i++)
        wl[i] = 0;
/*单词长度存入数组*/
    while((c = getchar()) != EOF)
    {
        if(c == ' ' || c == '\t' || c == '\n')
        {
            if(state == IN)
            {
                if(length <= MAXWORD)
                {
                    wl[length-1]++;
                    length = 0;
                    state = OUT;
                }
                else
                    printf("input over max input\n"); //加入异常处理
            }
        }
        else if(state == OUT)
        {
            length++;
            state = IN;
        }
        else
            length++;
    }
//测试统计结果
    for(i = 0; i < MAXWORD; i++)
        printf("%d, count %d\n", i+1, wl[i]);

/*找出出现次数最多的长度的单词数*/
    for(i = 0; i < MAXWORD; i++)
    {
        if(wl[i] > maxwl)
            maxwl = wl[i];
    }

    printf("max-word-count %d\n", maxwl); //测试最多数目单词

    for(i = 0; i < MAXWORD; i++)
    {
        if(wl[i] != 0)
        {
            scale = (float)wl[i] / (float)maxwl;
            printf("scale %f\n", scale);//test
            disp = scale * MAXCOUNT;
            printf("disp %d\n", disp);//test
            printf("%4d----", i+1);
            for(n = 0; n < disp; n++)
                putchar('*');
            putchar('\n');
        }
    }
}
