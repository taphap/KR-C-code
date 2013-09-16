/*颠倒字符串顺序*/
/*注意考虑结尾有换行符和无换行符情况*/

void reverses(char s[])
{
    int i, j, c;

    i = j = 0
    while(s[i] != '\0')
        ++i;
    --i;
    if(s[i] == '\n')    //重要
        --i;
    while(j < i)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
        --i;
        ++j;
    }
}
