typedef struct Stack Stack;
typedef int StackDataType;
struct Stack
{
	StackDataType *a;
	StackDataType top;
	StackDataType capacity;

};

void StackInit(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->top = 0;
	ps->capacity = 0;
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
	if (ps->top == ps->capacity)
	{
		StackDataType newcapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		StackDataType * newA= (StackDataType*)realloc(ps->a, newcapacity*sizeof(StackDataType));
		if (newA == NULL)
		{
			printf("realloc faile\n");
			exit(-1);
		}
		ps->a = newA;
		ps->capacity = newcapacity;
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
	assert(!StackEmpty(ps));

	return ps->a[ps->top - 1];
}

typedef struct {
    Stack PushStack;
    Stack PopStack;
} MyQueue;


MyQueue* myQueueCreate() {
    MyQueue* obj = (MyQueue*)malloc(sizeof(MyQueue));
    assert(obj);
    StackInit(&obj->PushStack);
    StackInit(&obj->PopStack);
    return obj;
}

void myQueuePush(MyQueue* obj, int x) {
    assert(obj);
    StackPush(&obj->PushStack,x);
}

int myQueuePop(MyQueue* obj) {
    assert(obj);
    if(StackEmpty(&obj->PopStack))
    {
        while(!StackEmpty(&obj->PushStack))
        {
            StackPush(&obj->PopStack,StackTop(&obj->PushStack));
            StackPop(&obj->PushStack);
        }
    }

    int front = StackTop(&obj->PopStack);
    StackPop(&obj->PopStack);
    return front;
}

int myQueuePeek(MyQueue* obj) {
       assert(obj);
    if(StackEmpty(&obj->PopStack))
    {
        while(!StackEmpty(&obj->PushStack))
        {
            StackPush(&obj->PopStack,StackTop(&obj->PushStack));
            StackPop(&obj->PushStack);
        }
    }

    
    return StackTop(&obj->PopStack);
    
}

bool myQueueEmpty(MyQueue* obj) {
    assert(obj);
    return StackEmpty(&obj->PushStack) && StackEmpty(&obj->PopStack);
}

void myQueueFree(MyQueue* obj) {
    assert(obj);

    StackDestory(&obj->PushStack);
    StackDestory(&obj->PopStack);

    free(obj);
}