#include <stdio.h>
#include <malloc.h>

struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

void Display(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int);
void ConcatLists(struct node **, struct node **);

int main(void) {

    struct node *pFirst = NULL;
    struct node *pSecond = NULL;

    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);

    Display(pFirst);  // |10|->|20|->|30|->|NULL|

    InsertFirst(&pSecond, 60);
    InsertFirst(&pSecond, 50);
    InsertFirst(&pSecond, 40);

    printf("\n");
    Display(pSecond);  // |40|->|50|->|60|->|NULL|

    ConcatLists(&pFirst, &pSecond);

    printf("\n");
    Display(pFirst);  // |10|->|20|->|30|->|40|->|50|->|60|->|NULL|

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    }

    printf("\n");
    Display(pFirst);  // List is empty !

    return 0;
}


void ConcatLists(struct node **ppHead1, struct node **ppHead2) {

    struct node *pTemp = NULL;

    if(NULL == *ppHead2) {
        return;
    }

    if(NULL == *ppHead1) {
        *ppHead1 = *ppHead2;
        *ppHead2 = NULL;
        return;
    }

    //both lists are present
    pTemp = *ppHead1;
    while(pTemp -> pNext != NULL) 
        pTemp = pTemp -> pNext;

    pTemp -> pNext = *ppHead2;
    (*ppHead2) -> pPrev = pTemp;  
    *ppHead2 = NULL;
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