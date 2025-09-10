#include<stdio.h>
#include<malloc.h>

//defining structure for singly linked list
struct node{
    int iData;
    struct node *pNext;
};

//Declaring functions
void Display(struct node *);
void DeleteAll(struct node **);
int DeleteFirst(struct node **);
void InsertFirst(struct node **, int);


int main(void){

    int iDelData;  //to store the data from deleted node
    struct node *pFirst = NULL;

    //function calls to insert the nodes into list
    InsertFirst(&pFirst, 10);
    InsertFirst(&pFirst, 60);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 40);

    //function call to display all list nodes before deletion
    printf("before deleting first node : ");
    Display(pFirst);   // |40|->|80|->|30|->|20|->|60|->|10|->NULL

    //function call for deleting first node from list
    iDelData = DeleteFirst(&pFirst);    
    printf("\nThe node %d is deleted from linked list\n", iDelData);  // The node 40 is deleted from linked list

    //function call to display list nodes after deletion
    printf("after deleting the first node : ");
    Display(pFirst);   // |80|->|30|->|20|->|60|->|10|->NULL


    /* 
    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}


//function to delete the first node from linked list
int DeleteFirst(struct node **ppHead){

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


//function to add the list node at the first position
void InsertFirst(struct node **ppHead, int iNo){

    struct node *pNewNode = NULL; 
    pNewNode = (struct node *)malloc(sizeof(struct node));  

    //null checking 
    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = *ppHead; 
    *ppHead = pNewNode;
}


//function to display the linked list
void Display(struct node *pHead){

    if(NULL == pHead)
        return;

    while(pHead != NULL){
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("NULL");
}


void DeleteAll(struct node **ppHead){
    //code
}