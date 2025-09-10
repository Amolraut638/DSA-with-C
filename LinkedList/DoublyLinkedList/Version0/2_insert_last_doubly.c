#include<stdio.h>
#include<malloc.h>

//defining the structure of doubly linked list 
struct node{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

//declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
void InsertLast(struct node **, int);


int main(void){

    struct node *pFirst = NULL;

    //function calls to insert elements(nodes) at last in Doubly linked list
    InsertLast(&pFirst, 10);
    InsertLast(&pFirst, 20);
    InsertLast(&pFirst, 30);

    //function call to display all nodes from a list
    Display(pFirst);    // |10|->|20|->|30|->|NULL|

    /* 
    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}


//function definition to insert the elements at last position in a list 
void InsertLast(struct node **ppHead, int iNo){

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    struct node *pTemp = NULL; // for traversing the list

    //NULL checking 
    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = NULL;  //as this is always last node

    //if the list is empty 
    if(NULL == *ppHead){
        pNewNode -> pPrev = NULL;
        *ppHead = pNewNode;
        return;
    }

    pTemp = *ppHead;

    while(pTemp -> pNext != NULL){
        pTemp = pTemp -> pNext;
    }

    pTemp -> pNext = pNewNode;  //majhya pudhe tu 
    pNewNode -> pPrev = pTemp;  //tujhya mage mi
}


//function definition to display all nodes from a list
void Display(struct node *pHead){

    if(NULL == pHead){
        return;
    }

    while(pHead != NULL){
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("|NULL|");
}


void DeleteAll(struct node **ppHead){
    //code
}