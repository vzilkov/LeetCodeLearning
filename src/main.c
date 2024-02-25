#include "stdio.h"
#include "string.h"
#include "time.h"
#include "stdlib.h"

#include "palindrome.h"
#include "topupdown.h"
#include "search_alg.h"
#include "stack_training.h"
#include "strings.h"
#include "sorts.h"
#include "array_training.h"
#include "lists.h"

struct ListNode_t {
     int val;
     struct ListNode_t *next;
};

char* rec(char *val);
int search_fun(int *arr, int len, int search_val);
void func();
void two_sum_brootforce_func(int *nums, int numLen, int target);
void two_sum_pointer_cursors_func(int *nums, int numLen, int target);
int check_palindrome_int_to_str(int x);
int check_palindrome_int_digits(int x);

struct ListNode_t a = {.next=NULL, .val=1};
struct ListNode_t b = {.next=&a, .val=2};
struct ListNode_t c = {.next=&b, .val=1};

int isPalindromeStruct(struct ListNode_t* head);

void main(){
    volatile clock_t time1,time2;
    time1 = clock();
    int result_top_down_alg = top_down_alg(30);
    time2 = clock();
    printf("time 1st method = %d ms, result = %d\n", (time2-time1)*1000/CLOCKS_PER_SEC, result_top_down_alg);
    result_top_down_alg = 0;

    check_palindrome_int_to_str((int) 121);
    check_palindrome_int_digits(121);
    int result = isPalindromeStruct(&c);
    
    time1 = clock();
    result_top_down_alg = dynamic_prog_alg(30);
    time2 = clock();
    printf("time 2nd method = %d ms, result = %d\n", (time2-time1)*1000/CLOCKS_PER_SEC, result_top_down_alg);

    isPalindromeRealloc(&c);

    check_weather_temp_dif();
    
    garbageCollection((int*)1, 10, (int*)1, 1);
    numFactoredBinaryTrees((int*) 1, 1);
    bottom_up_approach(0);

    result = 0;
    // char s[] = "a#c";
    // char t[] = "b";
    char s[] = "aaa###a";
    char t[] = "aaaa###a";
    result = backspaceCompare(s, t);

    int cost[] = {10,15,20};

    // result = minCostClimbingStairs(cost, sizeof(cost)/sizeof(*cost));

    int cost1[] = {1,100,1,1,1,100,1,1,100,1};
    result = minCostClimbingStairs(cost1, sizeof(cost1)/sizeof(*cost1));

    int cost2[] = {1,100,1,1,1,100,1,1,100,1};
    result = minCostClimbingStairs(cost2, sizeof(cost2)/sizeof(*cost2));

    int nums[] = {3,1,2,4};
    int *returnSize;
    result = sortArrayByParity(nums, sizeof(nums)/sizeof(*nums), returnSize);

    missingNumber();

    int buf_arr[] =  {0,0,0,0,1,3,0,5,0,15,2};
    int buf_arr1[] = {0,0,0,0,1,3,0,5,0,15,2};
    int buf_arr_len = sizeof(buf_arr)/sizeof(*buf_arr);
    // lomuto_alg(buf_arr, sizeof(buf_arr)/sizeof(*buf_arr));

    // sort_alg_bubles(buf_arr, buf_arr_len);
    sort_alg_lomuto(buf_arr, buf_arr_len);
    sort_dyn_impl(buf_arr1, buf_arr_len);

    d2_arr();
    majorityElement();

    lists_main();
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

int check_palindrome_int_to_str(int x){
    int result_flag = 1;
    char arr[15] = {0};
    sprintf(arr, "%d", x);
    for(int i=0, j=strlen(arr)-1; i<j; i++, j--){
        if(*(arr+i) != *(arr+j)){
            result_flag = 0;
        }
    }
    return result_flag;
}

int check_palindrome_int_digits(int x){
    int result_flag = 1;
    // 121;
    int reversed = 0, x_buf = x;
    while(x_buf != 0){
        int r = x_buf % 10;
        reversed = reversed * 10 + r;
        x_buf /= 10;
    }
    return result_flag;
}

struct ListNode_t* ListNode_top = NULL;
void push(int item_value){
    struct ListNode_t* ListNode_var = malloc(sizeof(struct ListNode_t));
    ListNode_var->val = item_value;
    ListNode_var->next = ListNode_top;
    ListNode_top = ListNode_var;
}
void pop(){
    if(ListNode_top){
        struct ListNode_t* ListNode_temp;
        ListNode_temp = ListNode_top;
        ListNode_top = ListNode_top->next;
        free(ListNode_temp);
    }    
}

int isPalindromeStruct(struct ListNode_t* head){
    int result_flag = 1;
    struct ListNode_t* head_buf = NULL;
    head_buf = head;
    int values_counter = 0, values_counter_ref = 0;
    while(head != NULL){
        printf("Struct: val %d, adr 0x%x\n", head->val, head->next);
        push(head->val);
        head = head->next;
        values_counter++;
    }
    values_counter_ref = values_counter/2;
    while(ListNode_top != NULL && head_buf != ListNode_top && values_counter_ref < values_counter){
        if(ListNode_top->val != head_buf->val){
            return 0;
        }
        pop();
        head_buf = head_buf->next;
        values_counter--;
    }

    return result_flag;
}

int isPalindromeDynamicArr(struct ListNode_t* head){
    while(head != NULL){

    }
    return 1;
}