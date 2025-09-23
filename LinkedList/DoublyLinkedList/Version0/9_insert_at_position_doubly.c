#include<stdio.h>
#include<malloc.h>

struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void Display(struct node *);
void DeleteAll(struct node **);
int CountNodes(struct node *);
void InsertFirst(struct node **, int);
void InsertAtPosition(struct node **, int, int);


int main(void) {

    struct node* pFirst = NULL;

    InsertFirst(&pFirst, 70);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 90);
    InsertFirst(&pFirst, 75);
    InsertFirst(&pFirst, 30);

    Display(pFirst);   //  |30|->|75|->|90|->|80|->|50|->|70|->|NULL|
    
    InsertAtPosition(&pFirst, 10, 4);

    printf("\n");
    Display(pFirst);   //  |30|->|75|->|90|->|10|->|80|->|50|->|70|->|NULL|

    printf("\n");
    InsertAtPosition(&pFirst, 45, 9);  // Invalid Position !

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    
    printf("\n");
    Display(pFirst); // List is empty !

    return 0;
}


void InsertAtPosition(struct node **ppHead, int iNo, int iPos) {

    int iCount;
    struct node *pTemp = NULL;
    struct node *pNewNode = NULL;
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
        printf("Memory Allocation Failed !");
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
    if(pTemp -> pNext != NULL)
        pTemp -> pNext -> pPrev = pNewNode;  //pTemp chya next madhe NULL nasel tevhach hi line chalnar
    pNewNode -> pPrev = pTemp;
    pTemp -> pNext = pNewNode;

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
