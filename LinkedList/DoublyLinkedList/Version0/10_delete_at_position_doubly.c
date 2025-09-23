#include <stdio.h>
#include <malloc.h>

struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};


void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);
int DeleteFirst(struct node **);
void InsertFirst(struct node **, int);
int DeleteAtPosition(struct node **, int);


int main(void) {

    int iDelData;  
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 70);
    InsertFirst(&pFirst, 90);
    InsertFirst(&pFirst, 40);

    printf("before deleting the node : ");
    Display(pFirst);   // |40|->|90|->|70|->|20|->|30|->|NULL|

    iDelData = DeleteAtPosition(&pFirst, 5);    
    printf("\nThe node %d is deleted from linked list\n", iDelData);  // The node 30 is deleted from linked list

    printf("after deleting the node : ");
    Display(pFirst);   // |40|->|90|->|70|->|20|->|NULL|

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 

    printf("\n");
    Display(pFirst); // List is empty ! 

    return 0;
}


int DeleteAtPosition(struct node **ppHead, int iPos) {

    int iCount;
    struct node *pTemp = NULL;
    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount) {
        printf("Invalid Position !");
        return -1;
    }

    if(iPos == 1) {
        return DeleteFirst(ppHead);
    }

    pTemp = *ppHead;
    iCount = 1;

    while(iCount < iPos) {
        iCount++;
        pTemp = pTemp -> pNext;
    }  //pTemp pointing to deleting node

    pTemp -> pPrev -> pNext = pTemp -> pNext;
    if(pTemp -> pNext != NULL)
        pTemp -> pNext -> pPrev = pTemp -> pPrev;
    iCount = pTemp -> iData;
    pTemp -> pPrev = NULL;
    pTemp -> pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iCount;
}


int DeleteFirst(struct node **ppHead) {

    int iDelData;

    if(NULL == *ppHead)
        return -1;

    iDelData = (*ppHead) -> iData;

    if(NULL == (*ppHead) -> pNext) {  //only single node is present
        free(*ppHead);
        ppHead = NULL;
    }
    else {    //multiple nodes are present
        *ppHead = (*ppHead) -> pNext;
        free((*ppHead) -> pPrev);
        (*ppHead) -> pPrev = NULL;
    }

    return iDelData;
}


void InsertFirst(struct node **ppHead, int iNo) {

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode) {
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pPrev = NULL;

    if(NULL == *ppHead) {  
        pNewNode -> pNext = NULL;
        *ppHead = pNewNode;
        return; 
    }

    pNewNode -> pNext = *ppHead;
    (*ppHead) -> pPrev = pNewNode;
    *ppHead = pNewNode;
}


int CountNodes(struct node *pHead) {

    int iCount = 0;

    while(NULL != pHead){
        iCount++;
        pHead = pHead -> pNext;
    }

    return iCount;
}


void Display(struct node *pHead) {
    
    if(NULL == pHead) {
        printf("List is empty !");
        return;
    }
        
    while(NULL != pHead) { 
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("|NULL|");
}


void DeleteAll(struct node **ppHead) {
    
    struct node *pTemp = NULL;

    while(*ppHead != NULL) {
        pTemp = *ppHead;
        *ppHead = pTemp -> pNext;

        if(*ppHead != NULL)
            (*ppHead) -> pPrev = NULL;

        free(pTemp);
    }
}
