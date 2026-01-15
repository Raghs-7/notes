#include<stdio.h>
#include<ctype.h>

void convertToUppercase(char *sptr){

    char *p = sptr;
    while (*p != '\0'){
        if (islower(*p)) *p = toupper(*p);
        p++;
    }
    return;
}

void PrintCharacter(char *sptr){

    char* p = sptr;
    while (*p!='\0'){
        printf("%c",*p);
        p++;
    }
    printf("\n");
    return ;
}

int main(){
    
    char string[] = "character and $32.98";
    PrintCharacter(string);
    // printf( "The string before conversion is: %s", string );
    convertToUppercase( string );
    PrintCharacter(string);
    // printf( "\nThe string after conversion is: %s\n", string );

    return 0;
}