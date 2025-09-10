#include<stdio.h>
#include<malloc.h>

//extern int iCounter   variable declaration

struct demo
{
    int iNo;
    float fNo;
};

int main(void){

    int iCounter;    //variable definition
    struct demo *pPtr = NULL;

    pPtr = (struct demo *) malloc(5 * sizeof(struct demo));

    if(NULL == pPtr){
        printf("Memory allocation failed !");
        return -1;
    }

    for(iCounter = 0; iCounter < 5; iCounter++){
        printf("Object%d values :\n", iCounter + 1);
        printf("Enter Integer value:");
        scanf("%d", &pPtr[iCounter].iNo);
        printf("Enter Float value: ");
        scanf("%f", &pPtr[iCounter].fNo);
    }

    for(iCounter = 0; iCounter < 5; iCounter++){
        printf("\nObject%d values are :\n", iCounter + 1);
        printf("Interger value is %d\n", pPtr[iCounter].iNo);
        printf("Float value is %f", pPtr[iCounter].fNo);
    }

    if(pPtr != NULL){
        free(pPtr);
        pPtr = NULL;  //if we cant assign null to the PPtr then the pointer will be dangling pointer
    }

    return 0;
}
