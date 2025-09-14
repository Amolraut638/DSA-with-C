#include<stdio.h>
#include<malloc.h>
struct node{
    int iData;
    struct node *pNext;
};

void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int);

int main(void) {

    int iCount;
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10); 
    InsertFirst(&pFirst, 90); 
    InsertFirst(&pFirst, 30); 
    InsertFirst(&pFirst, 70); 
    InsertFirst(&pFirst, 45); 
    InsertFirst(&pFirst, 76); 
    InsertFirst(&pFirst, 92); 
    InsertFirst(&pFirst, 55); 
    InsertFirst(&pFirst, 20); 

    printf("\n");
    Display(pFirst);   //|20|->|55|->|92|->|76|->|45|->|70|->|30|->|90|->|10|->|NULL|
    
    iCount = CountNodes(pFirst);
    printf("\nThere are total %d nodes are present in the list.", iCount);   //There are total 9 nodes are present in the list.
  
    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    
    printf("\n");
    Display(pFirst);  // List is empty !

    return 0;
}

int CountNodes(struct node *pHead) {

    int iCount = 0;
    while(NULL != pHead) {
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

