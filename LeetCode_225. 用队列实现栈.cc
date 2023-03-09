typedef int QDataType;
typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;

	//size_t size;
}Queue;

void QueueInit(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void QueueDestory(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	while (cur)
	{
		QNode* next = cur->next;
		free(cur);
		cur = next;
	}

	pq->head = pq->tail = NULL;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);
	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	assert(newnode);

	newnode->data = x;
	newnode->next = NULL;

	if (pq->tail == NULL)
	{
		assert(pq->head == NULL);
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head && pq->tail);

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	//return pq->head == NULL && pq->tail == NULL;
	return pq->head == NULL;
}

size_t QueueSize(Queue* pq)
{
	assert(pq);
	QNode* cur = pq->head;
	size_t size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}

	return size;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);

	return pq->head->data;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->tail);

	return pq->tail->data;
}
typedef struct {
    Queue q1;
    Queue q2;
} MyStack;


MyStack* myStackCreate() {
    MyStack* pst = (MyStack*)malloc(sizeof(MyStack));
    assert(pst);
    QueueInit(&pst->q1);
    QueueInit(&pst->q2);
    return pst;
}

void myStackPush(MyStack* obj, int x) {
    assert(obj);
    if(!QueueEmpty(&obj->q1))
    {
        QueuePush(&obj->q1,x);
    }
    else
    {
        QueuePush(&obj->q2,x);
    }
}

int myStackPop(MyStack* obj) {
    assert(obj);
    Queue* emptyQ = &obj->q1;
    Queue* nonemptyQ = &obj->q2;

    if(!QueueEmpty(&obj->q1))
    {
        emptyQ = &obj->q2;
        nonemptyQ = &obj->q1;
    }
    //把非空的前n-1个放进空
    while(QueueSize(nonemptyQ) > 1)
    {
        QueuePush(emptyQ,QueueFront(nonemptyQ));
        QueuePop(nonemptyQ);
    }
    int top = QueueFront(nonemptyQ);
    QueuePop(nonemptyQ);

    return top;
}

int myStackTop(MyStack* obj) {
    assert(obj);
    if(!QueueEmpty(&obj->q1))
    {
        return QueueBack(&obj->q1);
    }
    else
    {
        return QueueBack(&obj->q2);
    }
}

bool myStackEmpty(MyStack* obj) {
    assert(obj);
    return QueueEmpty(&obj->q1) &&  QueueEmpty(&obj->q2);
}

void myStackFree(MyStack* obj) {
    assert(obj);
    QueueDestory(&obj->q1);
    QueueDestory(&obj->q2);
    free(obj);
    obj = NULL;
}