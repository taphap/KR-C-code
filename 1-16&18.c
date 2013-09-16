#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 10

/*��ӡ���ⳤ�������еĳ��ȣ�ͬʱ��ӡ�����ܶ�������ı�*/
/*�ɴ�ӡ������������� MAXLINE��������볬��MAXLINE �����ӡ����ĳ���ֵ �� ǰMAXLINE���ȵ��ַ���*/
/*removes ����������������ĩβ�Ŀո���Ʊ�������пհ���*/

int getline(char s[], int maxline);
void copyline(char to[], char from[]);
int removes(char s[]);

int main()
{
    int len;
    int maxline;
    char line[MAXLINE];
    char save[MAXLINE];

    len = maxline = 0;
    while((len = getline(line, MAXLINE)) > 0)
    {
        printf("%d, %s", len, line);
        if(len > maxline)
        {
            copyline(save, line);
            maxline = len;
        }
    }
    if(maxline > 0)
        printf("%s", save);
}

int getline(char s[], int maxline)
{
    int c, i, j;

    j = 0;
    for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
        if(i < maxline-2)
        {
            s[j] = c;
            ++j;
        }
    if(c == '\n')
    {
        s[j] = c;
        ++j;
        ++i;
    }
    s[j] = '\0';
    return i;
}

int removes(char s[])
{
    int i;

    i = 0;
    while(s[i] != '\n')
        ++i;
    --i;
    while(i >= 0 && (s[i] == ' ' || s[i] == '\t'))
        --i;
    if(i > 0)
    {
        ++i;
        s[i] = '\n';
        ++i;
        s[i] = '\0';
    }
    return i;
}

void copyline(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
