#include<stdio.h>
#include<malloc.h>

struct node{
    struct node *pPrev;
    int iData;
    struct node *pNext;
};

//function declarations
void Display(struct node *);
int CountNodes(struct node *);
void DeleteAll(struct node **);
void InsertFirst(struct node **, int);

int main(void){

    int iCount;
    struct node *pFirst = NULL;

    //function calls to insert node at first position
    InsertFirst(&pFirst, 10); 
    InsertFirst(&pFirst, 90); 
    InsertFirst(&pFirst, 30); 
    InsertFirst(&pFirst, 70); 
    InsertFirst(&pFirst, 45); 
    InsertFirst(&pFirst, 76); 
    InsertFirst(&pFirst, 92); 


    //function to display nodes
    printf("\n");
    Display(pFirst);   // |92|->|76|->|45|->|70|->|30|->|90|->|10|->|NULL|
    

    //Function call to count the total number of nodes present in the list
    iCount = CountNodes(pFirst);
    printf("\nThere are total %d nodes are present in the list.", iCount);   // There are total 7 nodes are present in the list.


    //function call to delete the all nodes from the list  
    /*   
    if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}


//function to count the number  of nodes in the list
int CountNodes(struct node *pHead){

    int iCount = 0;
    while(NULL != pHead){
        iCount++;
        pHead = pHead -> pNext;
    }

    return iCount;
}


//function to insert nodes in the list at first position 
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

    if(NULL == *ppHead){  
        pNewNode -> pNext = NULL;
        *ppHead = pNewNode;
        return; 
    }

    pNewNode -> pNext = *ppHead;
    (*ppHead) -> pPrev = pNewNode;
    *ppHead = pNewNode;
}


//function to display all nodes in the list
void Display(struct node *pHead){

    if(NULL == pHead)
        return;

    while(NULL != pHead){
        printf("|%d|->", pHead -> iData);
        pHead = pHead -> pNext;
    }

    printf("|NULL|");
}


//function to delete all nodes from linked list
void DeleteAll(struct node **ppHead){
    //code
}

