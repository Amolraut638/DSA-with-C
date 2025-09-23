#include <stdio.h>
#include <malloc.h>

struct node {
    int iData;
    struct node *pNext;
};

void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int);
void InsertAtPosition(struct node **, int, int);


int main(void) {

    struct node *pFirst = NULL;
    
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 60);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 90);

    Display(pFirst);    // |90|->|50|->|60|->|40|->|80|->|20|->|NULL|

    InsertAtPosition(&pFirst, 55, 3);

    printf("\n");
    Display(pFirst);  // |90|->|50|->|55|->|60|->|40|->|80|->|20|->|NULL|

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n");
    Display(pFirst);   // List is empty !

    return 0;
}


void InsertAtPosition(struct node **ppHead, int iNo, int iPos) {

    int iCount;
    struct node *pNewNode = NULL;
    struct node *pTemp = NULL;
    iCount = CountNodes(*ppHead);

    if(iPos <= 0 || iPos > iCount + 1) {
        printf("Invalid Position !");
        return;
    }

    if(iPos == 1) {
        InsertFirst(ppHead, iNo);
        return;
    }

    pNewNode = (struct node *) malloc(sizeof(struct node));

    if(NULL == pNewNode) {
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;

    pTemp = *ppHead;
    iCount = 1;

    while(iCount < iPos - 1) {
        iCount++; 
        pTemp = pTemp -> pNext;
    }

    pNewNode -> pNext = pTemp -> pNext;
    pTemp -> pNext = pNewNode;
}


int CountNodes(struct node *pHead) {

    int iCount = 0;

    while(NULL != pHead){
        iCount++;
        pHead = pHead -> pNext;
    }

    return iCount;
}


void InsertFirst(struct node **ppHead, int iNo) {

    struct node *pNewNode = NULL;
    pNewNode = (struct node *) malloc(sizeof(struct node));

    if(NULL == pNewNode) {
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = *ppHead;
    *ppHead = pNewNode;
}


void Display(struct node *pHead) {
    
    if(NULL == pHead) {
        printf("List is empty !");
        return;
    }
        
    while(pHead != NULL) { 
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
        free(pTemp);
    }
}