#include <stdio.h>
#include <malloc.h>
struct node {
    int iData;
    struct node *pNext;
};

//Declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
void InsertLast(struct node **, int);


int main(void) {

    struct node *pFirst = NULL;

    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);

    Display(pFirst);      // |10|->|20|->|30|->|NULL|

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }  

    printf("\n");
    Display(pFirst);  // List is empty !

    return 0;
}


void InsertLast(struct node **ppHead, int iNo) {

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    struct node *pTemp = NULL;  //for traversing till last node 

    //NULL checking
    if(NULL == pNewNode) {
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = NULL;

    if(NULL == *ppHead) {
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;

    while(pTemp -> pNext != NULL) {
        pTemp = pTemp -> pNext;
    } // at this point pTemp is pointing to the last node

    pTemp -> pNext = pNewNode;
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

    while(*ppHead != NULL){
        pTemp = *ppHead;
        *ppHead = pTemp -> pNext;
        free(pTemp);
    }
}