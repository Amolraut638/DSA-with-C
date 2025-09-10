#include<stdio.h>
#include<malloc.h>

//defining structure of doubly linked list
struct node{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

//function declarations
void Display(struct node *);
void DeleteAll(struct node **);
int DeleteFirst(struct node **);
void InsertFirst(struct node **, int);


int main(void){

    int iDelData;
    struct node *pFirst = NULL;

    //function calls to add nodes in list
    InsertFirst(&pFirst, 90);
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 60);

    //function call to display list nodes before deletion
    printf("The List nodes before deletion :\n");
    Display(pFirst);   // |60|->|80|->|40|->|10|->|90|->|NULL|
    
    //Function call to delete first node
    iDelData = DeleteFirst(&pFirst);
    printf("\nThe node %d is deleted from the list");  // The node 60 is deleted from the list

    //Function call to display list nodes after deletion
    printf("\nThe List nodes After deleting first node : ");
    Display(pFirst);   // |80|->|40|->|10|->|90|->|NULL|
  
    /* 
    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}


//Function to delete the first node from doubly linked list
int DeleteFirst(struct node **ppHead){

    int iDelData;

    if(NULL == *ppHead)
        return -1;

    iDelData = (*ppHead) -> iData;

    if(NULL == (*ppHead) -> pNext){  //only single node is present
        free(*ppHead);
        ppHead = NULL;
    }
    else{    //multiple nodes are present
        *ppHead = (*ppHead) -> pNext;
        free((*ppHead) -> pPrev);
        (*ppHead) -> pPrev = NULL;
    }

    return iDelData;
}


//fuction for inserting the elements in doubly linked list at first position
void InsertFirst(struct node **ppHead, int iNo){

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pPrev = NULL;

    if(NULL == *ppHead){  //if the new node is the first node to insert
        pNewNode -> pNext = NULL;
        *ppHead = pNewNode;
        return; 
    }

    pNewNode -> pNext = *ppHead;
    (*ppHead) -> pPrev = pNewNode;
    *ppHead = pNewNode;
}


//function to display the list nodes
void Display(struct node *pHead){

    if(NULL == pHead)
        return;

    while(pHead != NULL){
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("|NULL|");
}
