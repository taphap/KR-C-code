#include <stdio.h>
#include <stdlib.h>
#define IN 1
#define OUT 0
#define MAXWORD 20
#define MAXCOUNT 20

/*��ӡ���뵥��ˮƽ����ֱ��ͼ*/
/*c �����ַ���length ���ʳ��ȼ�����i,n ѭ��������state ����״̬��maxwl ����ʳ��ȣ�
disp�� scale ��ʾ������wl[] ���ʳ������飻*/

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
/*���ʳ��ȴ�������*/
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
                    printf("input over max input\n"); //�����쳣����
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
//����ͳ�ƽ��
    for(i = 0; i < MAXWORD; i++)
        printf("%d, count %d\n", i+1, wl[i]);

/*�ҳ����ִ������ĳ��ȵĵ�����*/
    for(i = 0; i < MAXWORD; i++)
    {
        if(wl[i] > maxwl)
            maxwl = wl[i];
    }

    printf("max-word-count %d\n", maxwl); //���������Ŀ����

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
