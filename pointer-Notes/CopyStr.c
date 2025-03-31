#include<stdio.h>

void CopyString(char *sptr1, char *sptr2) { // copy sptr2 into sptr1
    int idx = 0;
    while (sptr2[idx] != '\0') { // Copy until sptr2's null terminator
        sptr1[idx] = sptr2[idx];
        idx++;
    }
    sptr1[idx] = '\0'; // Explicitly add null terminator to sptr1
    return;
}

void PrintStr(char* sptr) {
    while (*sptr != '\0') {
        printf("%c", *sptr);   
        sptr++;
    }
    printf("\n");
    return;
}

int main() {
    char string1[10];        /* create array string1 */
    char *string2 = "Hello"; /* create a pointer to a string */
    char string3[10];        /* create array string3 */
    char string4[] = "Good Bye"; /* create an array initialized with a string */

    CopyString(string1, string2);
    PrintStr(string1);

    return 0;
}