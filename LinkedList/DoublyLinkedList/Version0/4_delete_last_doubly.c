#include<stdio.h>
#include<malloc.h>

struct node{
    struct node*pPrev;
    int iData;
    struct node*pNext;
};

//function declarations
void Display(struct node *);
void DeleteAll(struct node **);
int DeleteLast(struct node **);
void InsertFirst(struct node **, int);

int main(void){

    int iDelData;
    struct node *pFirst = NULL;

    //function calls for Inserting nodes into list
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 50);

    //function call to display nodes before deletion
    printf("\nBefore Deletion: ");
    Display(pFirst);    //Before Deletion: |50|->|80|->|10|->|40|->|20|->|NULL|

    //function call to delete last node
    iDelData = DeleteLast(&pFirst);
    printf("\nThe node %d is deleted from list.", iDelData);   //The node 20 is deleted from list.

    //function call to display nodes After deletion
    printf("\nAfter Deletion: ");
    Display(pFirst);   //After Deletion: |50|->|80|->|10|->|40|->|NULL|


    /*
    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    }
    */

    return 0;
}   

//function to delete last node of doubly linked list
int DeleteLast(struct node**ppHead){

    int iDelData;
    struct node *pTemp = NULL;

    if(NULL == *ppHead){
        return -1;
    }

    pTemp = *ppHead;

    if(NULL == pTemp -> pNext){
        *ppHead = NULL;
    }
    else{
        while(pTemp -> pNext != NULL){
            pTemp = pTemp -> pNext;
        }
 
        pTemp -> pPrev -> pNext = NULL;      
    }

    iDelData = pTemp -> iData;
    pTemp -> pPrev = NULL; 
    free(pTemp);
    pTemp = NULL;

    return iDelData;
}


//function to insert node at first position for doubly linked list
void InsertFirst(struct node **ppHead, int iNo){

    struct node *pNewNode = NULL;
    pNewNode = (struct node*)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pPrev = NULL;

    //if list is empty
    if(NULL == *ppHead){
        pNewNode -> pNext = NULL;
        *ppHead = pNewNode;
        return;
    }

    pNewNode -> pNext = *ppHead;
    (*ppHead) -> pPrev = pNewNode;
    *ppHead = pNewNode;
}


//function to display all nodes from the list
void Display(struct node *pHead){

    if(NULL == pHead){
        return;
    }

    while(NULL != pHead){
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("|NULL|");
}


//Function to delete All nodes from linked list
void DeleteAll(struct node **ppHead){
    //code
}
