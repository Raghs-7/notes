#include<stdio.h>

// int b[5];
// int* bptr = b;    
// bptr[3] same as b[3] and also same as *(bptr+3)

int main(){

    int i, offset, b[4]={10,20,30,40};
    int *bPtr = b;

    /* Array is printed with array subscript notation */
    for (i=0; i < 4; i++)
    printf("b[%d] = %d\n", i, b[i]);

    /* Pointer/offset notation where the pointer is
    the array name */
    for (offset=0; offset < 4; offset++)
    printf("*(b + %d) = %d\n",offset,*(b + offset));
    /* Pointer subscript notation */
    for (i=0; i < 4; i++)
    printf("bPtr[%d] = %d\n", i, bPtr[i]);
    /* Pointer offset notation */
    for (offset = 0; offset < 4; offset++)
    printf("*(bPtr + %d) = %d\n", offset,"*(bPtr + offset)");

    return 0;
}