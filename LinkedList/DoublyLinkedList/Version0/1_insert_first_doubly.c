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

int main(void) {
    
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);

    Display(pFirst);      // |30|->|20|->|10|->|NULL|

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 

    printf("\n");
    Display(pFirst);   //List is empty !

    return 0;
}


void InsertFirst(struct node **ppHead, int iNo) {

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    // NULL checking
    if(NULL == pNewNode) {
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pPrev = NULL;

    if(NULL == *ppHead) {  //if the new node is the first node to insert or list is empty
        pNewNode -> pNext = NULL;
        *ppHead = pNewNode;
        return; 
    }

    //if control is here means list is not empty
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