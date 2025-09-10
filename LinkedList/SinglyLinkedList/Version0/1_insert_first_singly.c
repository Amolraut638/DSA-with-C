#include<stdio.h>
#include<malloc.h>

// defining structure of singly linked list
struct node {
    int iData;
    struct node *pNext;
};

// declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int);


int main(void){
    
    struct node *pFirst = NULL;

    // function calls to insert the node at first position in a list
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);

    // function call to display all nodes from a list
    printf("\nList elements are : ");
    Display(pFirst);  // List elements are : |30|->|20|->|10|->|NULL|

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

    struct node *pNewNode = NULL;  //creating pointer for new node
    pNewNode = (struct node *)malloc(sizeof(struct node));  //allocating memory to that pointer of type struct node 

    // null checking 
    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = *ppHead; 
    *ppHead = pNewNode;

}

// function to display all nodes from a linked list 
void Display(struct node *pHead){
    
    if(NULL == pHead)
        return;

    while(pHead != NULL){ 
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("|NULL|");

}

// function to delete all nodes from the list
void DeleteAll(struct node **ppHead){
    //code
}