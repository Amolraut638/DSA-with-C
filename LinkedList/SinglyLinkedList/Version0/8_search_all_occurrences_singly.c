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
int SearchAllOccurrences(struct node *, int);


int main(void){

    int iCount;
    struct node* pFirst;

    //function calls to create linked list by inserting node at first position
    InsertFirst(&pFirst, 90);
    InsertFirst(&pFirst, 30);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 80);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 40);
    InsertFirst(&pFirst, 50);
    InsertFirst(&pFirst, 55);

    //function call to display list nodes
    Display(pFirst);   //  |55|->|50|->|40|->|50|->|80|->|50|->|30|->|90|->|NULL|

    //function call to find fist occurrence of the node
    iCount = SearchAllOccurrences(pFirst, 50);
    printf("\nFound %d times", iCount);   //  Found 3 times


    //Function to delete All nodes from the list
   /*  
   if(NULL != pFirst){
        DeleteAll(&pFirst);
        pFirst = NULL;
    } 
    */

    return 0;
}


//function to find All occurrences in singly linked list
int SearchAllOccurrences(struct node *pHead, int iKey){

    int iCount = 0;

    while(NULL != pHead){
        if(pHead -> iData == iKey)
            iCount++;
        
        pHead = pHead -> pNext;
    }

    return iCount;
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