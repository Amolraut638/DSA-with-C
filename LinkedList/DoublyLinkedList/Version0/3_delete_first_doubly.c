#include<stdio.h>
#include<malloc.h>
struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

//function declarations
void Display(struct node *);
void DeleteAll(struct node **);
int DeleteFirst(struct node **);
void InsertFirst(struct node **, int);


int main(void) {

    int iDelData;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 90);
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 60);

    printf("The List nodes before deletion : ");
    Display(pFirst);   // |60|->|80|->|40|->|10|->|90|->|NULL|
    
    iDelData = DeleteFirst(&pFirst);
    printf("\nThe node %d is deleted from the list");  // The node 60 is deleted from the list

    printf("\nThe List nodes After deleting first node : ");
    Display(pFirst);   // |80|->|40|->|10|->|90|->|NULL|
  

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    
    printf("\n");
    Display(pFirst);  // List is empty !

    return 0;
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

    if(NULL == *ppHead) {  //if the new node is the first node to insert
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