#include<stdio.h>
#include<malloc.h>

struct node{
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
    InsertFirst(&pFirst, 90);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 20);
    InsertFirst(&pFirst, 70);

    //function call to display list nodes
    Display(pFirst);   // |70|->|20|->|80|->|50|->|30|->|90|->|NULL|

    //function call to find fist occurrence of the node
    iPos = SearchFirstOccurrence(pFirst, 50);
    printf("\nNode is found at position %d", iPos);   //Node is found at position 4


    //Function to delete All nodes from the list
   /*  
   if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}


//function to find first occurrence in singly linked list
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

    struct node* pNewNode = NULL;
    pNewNode = (struct node*) malloc(sizeof(struct node));

    if(NULL == pNewNode){
        printf("Memory allocation failed !");
        return;
    }

    pNewNode -> iData = iNo;
    pNewNode -> pNext = *ppHead;
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