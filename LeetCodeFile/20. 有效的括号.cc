typedef int StackDataType;

typedef struct Stack Stack;
struct Stack
{
	StackDataType* a;
	int top;//栈顶的位置
	int capacity;//容量大小
};

void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	free(ps->a); 
	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void StackPush(Stack* ps, StackDataType x)
{
	assert(ps);
	//满了扩容
	if (ps->top == ps->capacity)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		StackDataType* tmp = (StackDataType*)realloc(ps->a, newCapacity*sizeof(StackDataType));
		if (tmp == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top] = x;
	ps->top++;
}
void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);
	ps->top--;
}

bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->top;
}

StackDataType StackTop(Stack* ps)
{
	assert(ps);
	return ps->a[ps->top - 1];
}


bool isValid(char * s){
    Stack st;
    StackInit(&st);

    while(*s)
    {
        if(*s == '[' || *s == '(' ||*s == '{')
        {
            StackPush(&st,*s);
            s++;
        }
        else
        {
            if(StackEmpty(&st))
            {
                StackDestory(&st);
                return false;
            }
            char top = StackTop(&st);
            StackPop(&st);
            if((*s == ']' && top != '[')
             || (*s == ')' && top != '(') 
             || (*s == '}' && top != '{'))
            {
                StackDestory(&st);
                return false;
            }
            else
            {
                s++;
            }
        }
    }
    //栈为空，说明匹配
    bool ret = StackEmpty(&st);

     StackDestory(&st);
    return ret;
}