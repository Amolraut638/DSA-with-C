#include <stdio.h>
#include <malloc.h>
struct node {
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

    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);

    printf("Before Deletion : ");
    Display(pFirst);         //Before Deletion : |10|->|20|->|30|->|40|->|NULL|

    iDelData = DeleteLast(&pFirst);
    printf("\nthe node %d is deleted from list.", iDelData);    //the node 40 is deleted from list.

    printf("\nAfter Deletion : ");
    Display(pFirst);      //After Deletion : |10|->|20|->|30|->|NULL|

    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    
    printf("\n");
    Display(pFirst); // List is empty !

    return 0;
}


int DeleteLast(struct node**ppHead) {

    int iDelData;
    struct node*pTemp = NULL;
    
    if(NULL == *ppHead) {
        return -1;
    }

    pTemp = *ppHead;

    if(NULL == pTemp -> pNext) {  
        iDelData = pTemp -> iData;
        free(pTemp);
        *ppHead = NULL;
    }
    else { 
        while(pTemp -> pNext -> pNext != NULL)
             pTemp = pTemp -> pNext;
        
        iDelData = pTemp -> pNext -> iData;
        free(pTemp -> pNext);
        pTemp -> pNext = NULL;
    }

    return iDelData;
}


void InsertFirst(struct node **ppHead, int iNo) {

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode) {
        printf("Menory allocation failed !");
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