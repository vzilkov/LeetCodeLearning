
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

int transform_string(char* str, int len){
    char bs_symbol = '#';
    int count_symbols_in_str = len;
    for(int i=len, bs_counter=0; 
                i >= 0; 
                i--)
    {
        if(str[i] == bs_symbol)
        {
            bs_counter++;
            str[i] = 0;
            count_symbols_in_str--;
        }
        else if(bs_counter){
            bs_counter--;
            str[i] = 0;
            count_symbols_in_str--;
        }
    }
    return count_symbols_in_str;
}

int backspaceCompare(char* s, char* t) {
    int result = 1;
    int s_len = strlen(s);
    int t_len = strlen(t);

    // char s[] = "aaa###a";
    // char t[] = "aaaa###a";
    int len_s_tran_str = 0, len_t_tran_str = 0;
    len_s_tran_str = transform_string(s, s_len);
    len_t_tran_str = transform_string(t, t_len);

    if(len_s_tran_str != len_t_tran_str){
        return 0;
    }

    for(int i=0,j=0; i<s_len && j<t_len; i++,j++){
        while(s[i] == 0 && i<s_len){
            i++;
        }
        while(t[j] == 0 && j<t_len){
            j++;
        }
        if(s[i] != t[j]){
            return 0;
        }
    }
    
    return result;
}

int check_min_val(int* arr){
    int min_val = 0;
    if(*arr < *(arr+1)){
        min_val = *arr;
    }
    else{
        min_val = *(arr+1);
    }
    return min_val;
}

// int cost2[] =                    {1,100,1,1,1,100,1,1,100,1};
// [1,2,2,0]                        i=0                        constSize-1

int min(int a, int b)  { return (a < b ? a : b); }

int minCostClimbingStairs(int* cost, int costSize){
    int minus_1_cost = 0;
    int minus_2_cost = 0;
    int cur_cost = 0;
    int i = 2;
    for(;i<costSize;i++) {
        cur_cost = min(minus_1_cost + cost[i-1], minus_2_cost + cost[i-2]);
        minus_2_cost = minus_1_cost;
        minus_1_cost = cur_cost;
    }
    return min(minus_1_cost + cost[i-1], minus_2_cost + cost[i-2]);
}

typedef struct node_t_{
    int val;
    struct node_t_* left;
    struct node_t_* right;
}node_t;

node_t * create_root_tree(int val){
    node_t *tree = malloc(sizeof(node_t));
    tree->left=NULL;
    tree->right=NULL;
    tree->val=val;
    return tree;
}

node_t * new_node(int val){
        node_t *new_node = malloc(sizeof(node_t));
        new_node->val = val;
        new_node->left = NULL;
        new_node->right = NULL;
    return new_node;
}
node_t * insertNode(node_t *tree, int val){

    node_t *buf = new_node(val);
    if(val %2 == 0){
        while(tree->left != NULL){
            tree = tree->left;
        }
        tree->left = buf;
        tree = tree->left;
    }
    else{
        while(tree->right != NULL){
            tree = tree->right;
        }
        tree->right = buf;
        tree = tree->right;
    }
    
    return tree;
}

void print_tree(node_t* tree, int* return_arr){
    static int counter = 0;
    if(tree != NULL) {
        print_tree(tree->left, return_arr);
        print_tree(tree->right, return_arr);
        
        printf("\nTree val = %d", tree->val);
        *(return_arr+ counter) = tree->val;
        counter++;
    }
}

// nums = [3,1,2,4]
int sortArrayByParity(int* nums, int numsSize, int* returnSize) {
    node_t *tree = new_node(*(nums));
    node_t *current_node = tree;
    for(int i=1; i<numsSize; i++){
        printf("[%d] ",*(nums+i));
        current_node = insertNode(tree, nums[i]);
    }
    int *return_arr = calloc(numsSize, sizeof(int));
    memset(return_arr, 0, numsSize);
    print_tree(tree, return_arr);
    printf("\nCalloc buf:\n");
    for(int i=0; i<numsSize; i++){
        printf("%d ", *(return_arr+i));
    }
    return 0;
}