int maxDepth(char *s)
{
    //利用栈来
    int len = strlen(s);

    char *stack = (char *) malloc(len + 1);
    int top = 0;
    int max = 0;
    for (int i = 0; i < len; i++)
    {
        if (s[i] == '(')
        {
            stack[top++] = s[i];
            max = max > top ? max : top;
        }
        
        if (s[i] == ')')
        {
            top--;
        }
        
    }

    free(stack);

    return max;
}