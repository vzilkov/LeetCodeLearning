#include "array_training.h"
#include "stdlib.h"
#include "stdio.h"
void d2_arr(){
    int arr_size = 3;
    int *arr;
    arr = (int*)calloc(arr_size*arr_size*arr_size, sizeof(int));
    for(int i=0; i<arr_size; i++){
        for(int j=0; j<arr_size; j++){
            for(int k=0; k<arr_size;k++)
                *(arr + i*arr_size + j*arr_size + k) = i + j + k + 100;
        }
    }
    printf("\n Dyn impl \n");
    for(int i=0; i<arr_size; i++){
        printf("\n");
        for(int j=0; j<arr_size; j++){
            // printf("\n");
            for(int k=0; k<arr_size;k++)
                printf(" [%d][%d][%d]=%d", i,j,k,  *(arr + i*arr_size + j*arr_size + k));
        }
    }
    free(arr);
}

void majorityElement(){
    int nums[] = {2,2,1,1,1,2,2};
    int len = sizeof(nums)/sizeof(*nums);

    int majorElement = 0;
    int majorElement_Cnt = 0;

    for(int k=0; k<len;k++){
        printf(" %d", nums[k]);
        if(majorElement < nums[k]){
            majorElement = nums[k];
            majorElement_Cnt=1;
        }
        else if(majorElement == nums[k]){
            majorElement_Cnt++;
        }
    }
    majorElement;
}