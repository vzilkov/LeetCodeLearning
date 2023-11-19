#include "stdio.h"
#include "string.h"
#include "time.h"

char* rec(char *val);
int search_fun(int *arr, int len, int search_val);
void func();
void two_sum_brootforce_func(int *nums, int numLen, int target);
void two_sum_pointer_cursors_func(int *nums, int numLen, int target);

void main(){
    char word[] = "abcdefghijk";
    printf("Entered string: \n%s\n", word);
    rec(word);
    printf("Output val: %s\n", word);

    // func();
    int nums[] = {2,7,11,15};
    int numLen = sizeof(nums)/sizeof(*nums);
    int target = 9;
    two_sum_brootforce_func(nums, numLen, target);
    two_sum_pointer_cursors_func(nums, numLen, target);
}

char* rec(char *val){
    if(*val != '\0'){
        rec(val+1);
        printf_s(val, "%c",*val);
    }
    return val;
}

void func(){
    int nums[] = {-1,0,1,2,-1,-4};
    int numsSize = sizeof(nums)/sizeof(*nums);
    for(int i=0; i<numsSize; i++)
        for(int j=1; j<numsSize; j++)
            for(int k=2; k<numsSize; k++)
            {
                if(i != j 
                && i != k
                && j != k)
                if(nums[i]+nums[j]+nums[k] == 0){
                    printf("[%d,%d,%d]\n", nums[i],nums[j],nums[k]);
                }
            }
}

void two_sum_brootforce_func(int *nums, int numLen, int target){
    int cycle_cnt = 0;
    for(int i=0; i<numLen; i++){
        for(int k=i+1; k<numLen; k++){ //N!
        cycle_cnt++;
            if(target == *(nums+i)+*(nums+k)){
                printf("[%d,%d], cycles counter: %d", i,k, cycle_cnt);
                *nums = i;
                *(nums+k) = k;
                return;
            }
        }
    }
}

void two_sum_pointer_cursors_func(int *nums, int numLen, int target){
    int i=0, j=numLen-1;
    int cycle_cnt = 0;
    while(i != j){
        cycle_cnt++;
        // int nums[] = {2,7,11,15};
        // target = 9
    }
}
