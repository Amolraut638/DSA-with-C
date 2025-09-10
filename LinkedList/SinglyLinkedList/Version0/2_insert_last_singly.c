#include<stdio.h>
#include<malloc.h>

// defining structure of singly linked list
struct node {
    int iData;
    struct node *pNext;
};

//Declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
void InsertLast(struct node **, int);


int main(void){

    struct node *pFirst = NULL;

    //function calls to insert nodes at last position in a list
    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);

    //function call to display all elements from a list
    Display(pFirst);      // |10|->|20|->|30|->|NULL|

    /* 
    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    }  
    */

    return 0;
}


//function definition to insert the element at a last position in a list
void InsertLast(struct node **ppHead, int iNo){

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    struct node *pTemp = NULL;  //for traversing till last node 

    //NULL checking
    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = NULL;

    if(NULL == *ppHead){
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;

    while(pTemp -> pNext != NULL){
        pTemp = pTemp -> pNext;
    } // at this point pTemp is pointing to the last node

    pTemp -> pNext = pNewNode;
}


//function definition to display all elements(nodes) from a list
void Display(struct node *pHead){

    if(NULL == pHead)
        return;

    while(pHead != NULL){
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("|NULL|");
}


//functiom to delete All nodes from a list
void DeleteAll(struct node **ppHead){
    //code
}