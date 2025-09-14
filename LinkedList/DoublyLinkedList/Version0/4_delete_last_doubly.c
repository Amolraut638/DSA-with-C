#include<stdio.h>
#include<malloc.h>
struct node {
    struct node*pPrev;
    int iData;
    struct node*pNext;
};

void Display(struct node *);
void DeleteAll(struct node **);
int DeleteLast(struct node **);
void InsertFirst(struct node **, int);

int main(void) {

    int iDelData;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 50);

    printf("\nBefore Deletion: ");
    Display(pFirst);    //Before Deletion: |50|->|80|->|10|->|40|->|20|->|NULL|

    iDelData = DeleteLast(&pFirst);
    printf("\nThe node %d is deleted from list.", iDelData);   //The node 20 is deleted from list.

    printf("\nAfter Deletion: ");
    Display(pFirst);   //After Deletion: |50|->|80|->|10|->|40|->|NULL|

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n");
    Display(pFirst);  //List is empty !

    return 0;
}   


int DeleteLast(struct node**ppHead) {

    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead) {
        return -1;
    }

    pTemp = *ppHead;

    if(NULL == pTemp -> pNext) {
        *ppHead = NULL;
    }
    else {
        while(pTemp -> pNext != NULL) {
            pTemp = pTemp -> pNext;
        }
 
        pTemp -> pPrev -> pNext = NULL;      
    }

    iDelData = pTemp -> iData;
    pTemp -> pPrev = NULL; 
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}


void InsertFirst(struct node **ppHead, int iNo) {

    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode) {
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pPrev = NULL;

    //if list is empty
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