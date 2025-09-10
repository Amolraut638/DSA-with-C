#include<stdio.h>
#include<malloc.h>

// defining structure of doubly linked list
struct node {
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

// declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int);


int main(void){
    
    struct node *pFirst = NULL;

    // function calls to insert node at first position
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);

    // function call to display the nodes from a list
    Display(pFirst);      // |30|->|20|->|10|->|NULL|


    /* 
    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}

// function to insert the node at first position in a list
void InsertFirst(struct node **ppHead, int iNo){

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    // NULL checking
    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pPrev = NULL;

    if(NULL == *ppHead){  //if the new node is the first node to insert or list is empty
        pNewNode -> pNext = NULL;
        *ppHead = pNewNode;
        return; 
    }

    //if control is here means list is not empty
    pNewNode -> pNext = *ppHead;
    (*ppHead) -> pPrev = pNewNode;
    *ppHead = pNewNode;
}


//function to display the all nodes from the list
void Display(struct node *pHead){

    if(NULL == pHead)
        return;

    while(pHead != NULL){ 
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }  
    
    printf("|NULL|");
}

//function to delete all elements from the list
void DeleteAll(struct node **ppHead){
    //code
}