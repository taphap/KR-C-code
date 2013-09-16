#include <stdio.h>
#include <stdlib.h>
#define MAXLINE 1000

/*getline 函数要考虑到各种情况*/

int getline(char s[], int maxline);
void copyline(char to[], char from[]);

int main()
{
    int len;
    int maxline;
    char line[MAXLINE];
    char save[MAXLINE];

    maxline = 0;
    while((len = getline(line, MAXLINE)) > 0)
        if(len > maxline)
        {
            copyline(save, line);
            maxline = len;
        }
    printf("%s", save);
}

int getline(char s[], int maxline)
{
    int c, i;

    for(i = 0; i < maxline-1 && (c = getchar()) != EOF && c != '\n'; ++i)
        s[i] = c;
    if(c == '\n')
    {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}

void copyline(char to[], char from[])
{
    int i;

    i = 0;
    while((to[i] = from[i]) != '\0')
        ++i;
}
