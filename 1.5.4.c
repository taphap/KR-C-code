#include <stdio.h>
#include <stdlib.h>
#define OUT ' '

/*���ʼ���*/
/*nl ������nw ��������nc �ַ���*/

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
