#include "search_alg.h"
#include "stdio.h"
#include "string.h"

int garbageCollection(char** garbage, int garbageSize, int* travel, int travelSize) {
    char garbage1[][20] = {"abcd", "efgh", "ijklmn"};
    for(int i=0; i<3; i++){
        int len = strlen(*(garbage1+i));
        printf("Garbage %d \n",i);
        for(int j=0; j<len; j++){
            printf("%c", *(*(garbage1+i)+j));
        }   
        printf("\n");
    }
    return 0;
}

int missingNumber() {
    int nums[] = {3,0,1};
    int numsSize = sizeof(nums)/sizeof(*nums);
    int n=numsSize+1;

    //values [0,n]
    int max_num = 10*10000;
    int *buf_arr = calloc(n, sizeof(int));
    for(int i=0; i<max_num && i<n; i++){
        buf_arr[i] = 1;
        // printf("%d ", *(ref_arr+i));
    }
    for(int i=0; i<n; i++){
        int buff_val = nums[i];
        buf_arr[buff_val] = 0;
        // ref_arr[buff_val] = 0;
        // *(ref_arr+*(nums+i)) = 0;
        // if(*(ref_arr+*(nums+i))){
        //     return i;
        // }
        // ref_arr[nums[i]] = 0;
    }

    for(int i=0; i<max_num && i<n; i++){
        printf("%d ", *(buf_arr+i));
        if(*(buf_arr+i)){
            free(buf_arr);
            return i;
        }  
    }
    free(buf_arr);
    return 0;
}