#include <stdio.h>
#include <stdlib.h>

// Linked list.
typedef struct linkNode
{
    // int value[3];
    int *value;
    struct linkNode *next;
} node;
// FIFO pipe.
typedef struct linkPipe
{
    node *firstPtr;
    // node *lastPtr;
    int length;
} pipe;

node *createLinkNode()
{
    node *newNode = malloc(sizeof(node));
    /*
    for (int i = 0; i < 3; i++)
    {
        newNode->value[i] = 0;
    }
    */
    newNode->value = malloc(sizeof(int) * 3); // Modify value allocation and pointer type to change content of node.
    newNode->next = 0;
    return newNode;
}

pipe *createPipe()
{
    pipe *newPipe = malloc(sizeof(pipe));
    newPipe->firstPtr = 0;
    // newPipe->lastPtr = 0;
    newPipe->length = 0;
    return newPipe;
}

void destroyLinkNode(node *tgtNode)
{
    free(tgtNode->value);
    free(tgtNode);
}

void destroyPipe(pipe *tgtPipe)
{
    for (int i = 0; i < tgtPipe->length; i++)
    {
        destroyLinkNode(tgtPipe->firstPtr + i);
    }
    free(tgtPipe);
}

void forwardNodePtr(node **ptr)
{
    *ptr = (*ptr)->next;
}

int *pipeRead(pipe *tgtPipe)
{
    if (tgtPipe->length == 0)
    {
        return 0;
    }
    else
    {
        // int *value = tgtPipe->firstPtr->value; Can't return pointer of what's about to be destroyed.
        int *value = malloc(sizeof(int) * 3); // Don't forget to free this after use.
        for (int i = 0; i < 3; i++)
        {
            *(value + i) = *(tgtPipe->firstPtr->value + i);
        }
        node *oldPtr = tgtPipe->firstPtr;
        forwardNodePtr(&(tgtPipe->firstPtr));
        destroyLinkNode(oldPtr);
        tgtPipe->length--;
        return value;
    }
}

void pipeWrite(int *input, pipe *tgtPipe)
{
    if (tgtPipe->length == 0)
    {
        tgtPipe->firstPtr = createLinkNode();
    }
    else
    {
        (tgtPipe->firstPtr + tgtPipe->length - 1)->next = createLinkNode();
    }
    tgtPipe->length++;
    for (int i = 0; i < 3; i++)
    {
        *((tgtPipe->firstPtr + tgtPipe->length - 1)->value + i) = *(input + i);  // TODO: Syntex error.
    }
}

int isQualified(int a, int b, int c)
{
    if (a > b && b > c)
    {
        if (a + c > 2 * b)
        {
            return 1;
        }
    }
    return 0;
}

int main()
{
    int n, num[50], value[3];
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &num[i]);
    }
    pipe *triTuples = createPipe();

    // Three layers of for.
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int k = j; k < n; k++)
            {
                if (isQualified(num[i], num[j], num[k]))
                {
                    value[0] = num[i];
                    value[1] = num[j];
                    value[2] = num[k];
                    pipeWrite(value, triTuples);
                }
            }
        }
    }

    // Print result.

    printf("%d", triTuples->length);
    int *triTuple;
    for (int i = 1; i <= triTuples->length; i++)
    {
        triTuple = pipeRead(triTuples);
        printf("%d %d %d\n", *(triTuple + 0), *(triTuple + 1), *(triTuple + 2));
        free(triTuple);
    }
    destroyPipe(triTuples);
    return 0;
}