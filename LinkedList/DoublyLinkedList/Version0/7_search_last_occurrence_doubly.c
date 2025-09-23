#include<stdio.h>
#include<malloc.h>
struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void Display(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int);
int SearchLastOccurrence(struct node *, int);


int main(void) {

    int iPos;
    struct node *pFirst;

    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 64);
    InsertFirst(&pFirst, 98);
    InsertFirst(&pFirst, 70);

    Display(pFirst);   //  |70|->|98|->|64|->|50|->|40|->|NULL|

    iPos = SearchLastOccurrence(pFirst, 50);
    printf("\nNode is found at position %d", iPos);   //  Node is found at position 4

   if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    
    printf("\n");
    Display(pFirst); // List is empty !

    return 0;
}


int SearchLastOccurrence(struct node *pHead, int iKey) {

    int iPos = 0;

    while(NULL != pHead) {
        iPos++;
        if(pHead -> iData == iKey)
            return iPos;
        pHead = pHead -> pNext;
    }

    return 0;
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

        if(*ppHead != NULL)
            (*ppHead) -> pPrev = NULL;

        free(pTemp);
    }
}
