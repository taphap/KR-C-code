/*�ߵ��ַ���˳��*/
/*ע�⿼�ǽ�β�л��з����޻��з����*/

void reverses(char s[])
{
    int i, j, c;

    i = j = 0
    while(s[i] != '\0')
        ++i;
    --i;
    if(s[i] == '\n')    //��Ҫ
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
