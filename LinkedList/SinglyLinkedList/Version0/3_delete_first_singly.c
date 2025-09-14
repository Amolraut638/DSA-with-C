#include<stdio.h>
#include<malloc.h>
struct node {
    int iData;
    struct node *pNext;
};

//Declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
int DeleteFirst(struct node **);
void InsertFirst(struct node **, int);


int main(void) {

    int iDelData;  //to store the data from deleted node
    struct node *pFirst = NULL;

    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 60);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 40);

   
    printf("before deleting first node : ");
    Display(pFirst);   // |40|->|80|->|30|->|20|->|60|->|10|->NULL

   
    iDelData = DeleteFirst(&pFirst);    
    printf("\nThe node %d is deleted from linked list\n", iDelData);  // The node 40 is deleted from linked list

   
    printf("after deleting the first node : ");
    Display(pFirst);   // |80|->|30|->|20|->|60|->|10|->NULL

    if(NULL != pFirst) {
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 

    printf("\n");
    Display(pFirst); // List is empty ! 

    return 0;
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