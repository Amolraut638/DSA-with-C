#include<stdio.h>
#include<malloc.h>
struct node {
    int iData;
    struct node* pNext;
};

void Display(struct node*);
void DeleteAll(struct node**);
void InsertFirst(struct node**, int);
int SearchAllOccurrences(struct node *, int);


int main(void) {

    int iCount;
    struct node* pFirst;

    InsertFirst(&pFirst, 90);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 55);

    Display(pFirst);   //  |55|->|50|->|40|->|50|->|80|->|50|->|30|->|90|->|NULL|

    iCount = SearchAllOccurrences(pFirst, 50);
    printf("\nFound %d times", iCount);   //  Found 3 times
 
   if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 

    printf("\n");
    Display(pFirst); // List is empty !

    return 0;
}


int SearchAllOccurrences(struct node *pHead, int iKey) {

    int iCount = 0;

    while(NULL != pHead) {
        if(pHead -> iData == iKey)
            iCount++;
        
        pHead = pHead -> pNext;
    }

    return iCount;
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