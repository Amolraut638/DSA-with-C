#include <stdio.h>
#include <malloc.h>

struct node {
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
 
    iDelData = DeleteAtPosition(&pFirst, 4);    
    printf("\nThe node %d is deleted from linked list\n", iDelData);  // The node 20 is deleted from linked list

    printf("after deleting the node : ");
    Display(pFirst);   // |40|->|90|->|70|->|30|->|NULL|

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
    struct node *pTemp1 = NULL;
    struct node *pTemp2 = NULL;
    iCount = CountNodes(*ppHead);
    
    if(iPos <= 0 || iPos > iCount) {
        printf("Invalid Position !");
        return -1;
    }

    if(iPos == 1) {
        return DeleteFirst(ppHead);
    }

    pTemp1 = *ppHead;
    iCount = 1;

    while(iCount < iPos -1) {
        iCount++;
        pTemp1 = pTemp1 -> pNext;
    }

    pTemp2 = pTemp1 -> pNext;
    pTemp1 -> pNext = pTemp2 -> pNext;
    iCount = pTemp2 -> iData;
    free(pTemp2);
    pTemp2 = NULL;
    
    return iCount;
}


int DeleteFirst(struct node **ppHead) {

    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead)
        return -1; 

    pTemp = *ppHead;
    iDelData = pTemp -> iData;
    *ppHead = pTemp -> pNext;

    pTemp -> pNext = NULL;
    free(pTemp);
    pTemp = NULL;

    return iDelData;
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
    pNewNode = (struct node *)malloc(sizeof(struct node));  

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