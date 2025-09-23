#include <stdio.h>
#include <malloc.h>
struct node {
    int iData;
    struct node* pNext;
};

//function declarations
void Display(struct node*);
void DeleteAll(struct node**);
void InsertFirst(struct node**, int);
int SearchLastOccurrence(struct node *, int);


int main(void) {

    int iPos;
    struct node* pFirst;

    InsertFirst(&pFirst, 90);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 20);

    Display(pFirst);     // |20|->|80|->|50|->|20|->|90|->|NULL|

    iPos = SearchLastOccurrence(pFirst, 20);
    printf("\nLast occurrence of the node is at position %d", iPos);   // Last occurrence of the node is at position 4

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
    int iLastPos = 0;

    while(NULL != pHead) {
        iPos++;
        if(pHead -> iData == iKey)
            iLastPos = iPos;
        pHead = pHead -> pNext;
    }

    return iLastPos;
}


void InsertFirst(struct node **ppHead, int iNo) {

    struct node* pNewNode = NULL;
    pNewNode = (struct node*) malloc(sizeof(struct node));

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