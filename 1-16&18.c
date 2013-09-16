#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 10

/*打印任意长度输入行的长度，同时打印尽可能多的输入文本*/
/*可打印的最大输入行是 MAXLINE，如果输入超出MAXLINE ，则打印输入的长度值 和 前MAXLINE长度的字符串*/
/*removes 函数负责处理输入行末尾的空格和制表符，还有空白行*/

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
