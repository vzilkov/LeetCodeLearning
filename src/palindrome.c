#include "string.h"
#include "stdlib.h"

#include "palindrome.h"

void isPalindromeRealloc(struct ListNode* head){
    int *arr_dynamic_buf = malloc(sizeof(int));
    *arr_dynamic_buf = 1;
    int size = 5;
    for(int i=0; i<size; i++){
        arr_dynamic_buf = realloc(arr_dynamic_buf,sizeof(int)*(i+1));
        *(arr_dynamic_buf+i) = i+100;
    }
    for(int i=0; i<size; i++)
    {
        printf("Arr[%d] = %d\n", i, *(arr_dynamic_buf+i));
    }
    free(arr_dynamic_buf);
}
