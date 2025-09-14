#include<stdio.h>
#include<malloc.h>
struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

//declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
void InsertLast(struct node **, int);


int main(void) {

    struct node *pFirst = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);

    Display(pFirst);    // |10|->|20|->|30|->|NULL|

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 

    printf("\n");
    Display(pFirst); // List is empty !

    return 0;
}


void InsertLast(struct node **ppHead, int iNo) {

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    struct node *pTemp = NULL; // for traversing the list

    //NULL checking 
    if(NULL == pNewNode) {
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = NULL;  //as this is always last node

    //if the list is empty 
    if(NULL == *ppHead) {
        pNewNode -> pPrev = NULL;
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;

    while(pTemp -> pNext != NULL) {
        pTemp = pTemp -> pNext;
    }

    pTemp -> pNext = pNewNode;  //majhya pudhe tu 
    pNewNode -> pPrev = pTemp;  //tujhya mage mi
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