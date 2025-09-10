#include<stdio.h>
#include<malloc.h>

struct node{
    struct node* pPrev;
    int iData;
    struct node* pNext;
};

//function declarations
void Display(struct node*);
void DeleteAll(struct node**);
void InsertFirst(struct node**, int);
int SearchFirstOccurrence(struct node *, int);


int main(void){

    int iPos;
    struct node* pFirst;

    //function calls to create linked list by inserting node at first position
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 56);
    InsertFirst(&pFirst, 34);
    InsertFirst(&pFirst, 98);
    InsertFirst(&pFirst, 70);
    InsertFirst(&pFirst, 45);

    //function to display list nodes
    Display(pFirst);   //  |45|->|70|->|98|->|34|->|56|->|40|->|NULL|

    //function call to find fist occurrence of the node
    iPos = SearchFirstOccurrence(pFirst, 40);
    printf("\nNode is found at position %d", iPos);   // Node is found at position 6


    //Function to delete All nodes from the list
   /*  
   if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}


//function to find first occurrence in doubly linked list
int SearchFirstOccurrence(struct node *pHead, int iKey){

    int iPos = 0;

    while(NULL != pHead){
        iPos++;
        if(pHead -> iData == iKey)
            return iPos;
        pHead = pHead -> pNext;
    }

    return 0;
}


//function to insert the node at first position 
void InsertFirst(struct node **ppHead, int iNo){

    struct node *pNewNode = NULL;
    pNewNode = (struct node *)malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pPrev = NULL;

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
void Display(struct node* pHead){

    if(NULL == pHead){
        return;
    }

    while(NULL != pHead){
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("|NULL|");
}


//function to delete all nodes from the list
void DeleteAll(struct node** ppHead){
    //code
}