#include<stdio.h>
#include<stdlib.h>

// always use const quantizier with pointers
// • const qualifier
// – Variable	cannot	be	changed
// – Use const if	function	does	not	need	to	change	a	variable
// – Attempting	to	change	a const variable	produces	an	error

// • const pointers
// – Point	to	a	constant	memory	location
// – Must	be	initialized	when	defined
// – int *const myPtr = &x;
// • Type int *const – constant	pointer	to	an int
// – const int *myPtr = &x;
// • Regular	pointer	to	a	const int
// – const int *const Ptr = &x;
// • const pointer	to	a const int
// • x	can	be	changed,	but	not *Ptr



int main(){

    int *array, *p;
    int i, array_size;
    printf("Enter teh array size ");
    scanf("%d",&array_size);

    array = (int*)malloc(array_size*(sizeof(int)));

    for (p=array, i=0; i<array_size; i++,p++){
        scanf("%d",p);
    }

    printf("Elements: ");
    for(p=array,i=0; i<array_size; i++, p++)
    printf("%d ",*p);
    printf("\n");

    return 0;
}