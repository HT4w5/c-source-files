#include <stdio.h>
#include <stdlib.h>

// Linked list.
typedef struct linkNode
{
    int value;
    struct linkNode *next;
} node;

// FIFO queue.
typedef struct linkQueue
{
    node *firstPtr;
    node *lastPtr;
    int sum;
} queue;

void forwardNodePtr(node **ptr)
{
    *ptr = (*ptr)->next;
}

node *createLinkNode()
{
    node *newNode = (node *)malloc(sizeof(node));
    newNode->value = 0;
    newNode->next = NULL;
    return newNode;
}

queue *createQueue()
{
    queue *newQueue = (queue *)malloc(sizeof(queue));
    newQueue->firstPtr = NULL;
    newQueue->lastPtr = NULL;
    newQueue->sum = 0;
    // newQueue->length = 0;
    return newQueue;
}

void destroyLinkNode(node *tgtNode)
{
    // free(tgtNode->value);
    free(tgtNode);
}

void destroyQueue(queue *tgtQueue)
{
    if (tgtQueue != NULL)
    {
        if (tgtQueue->firstPtr != NULL)
        {
            if (tgtQueue->firstPtr->next != NULL)
            {
                node *currentNode;
                while (tgtQueue->firstPtr->next != NULL)
                {
                    currentNode = tgtQueue->firstPtr;
                    forwardNodePtr(&(tgtQueue->firstPtr));
                    destroyLinkNode(currentNode);
                }
            }
            destroyLinkNode(tgtQueue->firstPtr);
        }
        free(tgtQueue);
    }
    else
    {
        perror("Queue not initialized");
    }
}

int queuePop(queue *tgtQueue) // Same as pop + front.
{
    if (tgtQueue != NULL)
    {
        if (tgtQueue->firstPtr == NULL)
        {
            perror("Empty Queue");
        }
        else
        {
            int value = tgtQueue->firstPtr->value;
            node *oldPtr = tgtQueue->firstPtr;
            forwardNodePtr(&(tgtQueue->firstPtr));
            if (tgtQueue->firstPtr == NULL)
            {
                tgtQueue->lastPtr = NULL;
            }
            destroyLinkNode(oldPtr);
            // tgtQueue->length--;
            tgtQueue->sum -= value;
            return value;
        }
    }
    else
    {
        perror("Queue not initialized");
        return 0;
    }
}

void queuePush(int input, queue *tgtQueue)
{
    if (tgtQueue != NULL)
    {
        if (tgtQueue->firstPtr == NULL)
        {
            tgtQueue->firstPtr = createLinkNode();
            tgtQueue->lastPtr = tgtQueue->firstPtr;
        }
        else
        {
            tgtQueue->lastPtr->next = createLinkNode();
            tgtQueue->lastPtr = tgtQueue->lastPtr->next;
        }
        // tgtQueue->length++;
        tgtQueue->lastPtr->value = input;
        tgtQueue->sum += input;
    }
    else
    {
        perror("Queue not initialized");
    }
}

int getMonth(int n, int t)
{
    int count = 0;
    int income;
    queue *incomeQueue = createQueue();
    for (int i = 0; i < n ; i++)
    {
        scanf("%d", &income);
        queuePush(income, incomeQueue);

        while (incomeQueue->sum >= t)
        {
            queuePop(incomeQueue);
        }
        ++count;
    }

    return count;
}

int main(void)
{
    int n, t;
    scanf("%d%d", &n, &t);
    printf("%d", getMonth(n, t));
    return 0;
}