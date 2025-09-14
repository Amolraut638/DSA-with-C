#include<stdio.h>
#include<malloc.h>
struct node {
    int iData;
    struct node *pNext;
};

// declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int);


int main(void) {
    
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);

    printf("\nList elements are : ");
    Display(pFirst);  // List elements are : |30|->|20|->|10|->|NULL|

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 

    printf("\n");
    Display(pFirst);   // List is empty !

    return 0;
}


void InsertFirst(struct node **ppHead, int iNo) {

    struct node *pNewNode = NULL;  //creating pointer for new node
    pNewNode = (struct node *)malloc(sizeof(struct node));  //allocating memory to that pointer of type struct node 

    if(NULL == pNewNode) {
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = *ppHead; 
    *ppHead = pNewNode;
}


void Display(struct node *pHead) {
    
    if(NULL == pHead){
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