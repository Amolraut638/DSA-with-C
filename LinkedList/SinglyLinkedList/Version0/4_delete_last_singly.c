#include<stdio.h>
#include<malloc.h>

//defining structure
struct node{
    int iData;
    struct node*pNext;
};

void Display(struct node *);
void DeleteAll(struct node **);
int DeleteLast(struct node **);
void InsertFirst(struct node **, int);


int main(void){

    int iDelData;
    struct node *pFirst = NULL;

    //function calls to insert node at first position
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 10);

    //function call to display all nodes 
    printf("Before Deletion : ");
    Display(pFirst);         //Before Deletion : |10|->|20|->|30|->|40|->|NULL|

    //function call to delete last node from list
    iDelData = DeleteLast(&pFirst);
    printf("\nthe node %d is deleted from list.", iDelData);    //the node 40 is deleted from list.

    printf("\nAfter Deletion : ");
    Display(pFirst);   //After Deletion : |10|->|20|->|30|->|NULL|

   /*
    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}


//function definition to Delete last node of linkedd list
int DeleteLast(struct node**ppHead){

    int iDelData;
    struct node*pTemp = NULL;
    
    if(NULL == *ppHead){
        return -1;
    }

    pTemp = *ppHead;

    if(NULL == pTemp -> pNext){  //only single node is present
        iDelData = pTemp -> iData;
        free(pTemp);
        *ppHead = NULL;
    }
    else{ 
        while(pTemp -> pNext -> pNext != NULL){
        pTemp = pTemp -> pNext;
        }

        iDelData = pTemp -> pNext -> iData;
        free(pTemp -> pNext);
        pTemp -> pNext = NULL;
    }

    return iDelData;
}


//function to insert nodes at first position
void InsertFirst(struct node **ppHead, int iNo){

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Menory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = *ppHead;
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


//functiion to delete all nodes from the list
void DeleteAll(struct node **ppHead){
    //code
}