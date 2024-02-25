#include "topupdown.h"
#include "stdlib.h"
#include "stdio.h"
#include "math.h"

static int counter = 0;
static int cache[50+1] = {0};
int top_down_alg(int x){// fibonaci
    counter++;
    if(x<=0)
        return 0;
    if(x == 1)
    {
        return x;
    }
    else{
        if(cache[x] == 0)
            cache[x] = top_down_alg(x-1) + top_down_alg(x-2);//counter = 177 for x = 10  
        return *(cache+x);  
    }
}

int dynamic_prog_alg(int x){
    int* result_arr = (int*)calloc(x+1,sizeof(int));
    counter=0;
    int result=0;
    for(int i=0; i<=x; i++){
        if(i == 0){
            *(result_arr+i) = 0;
        }
        else if(i==1){
            *(result_arr+i) = 1;
        }
        else{
            *(result_arr+i) = *(result_arr+i-1) + *(result_arr+i-2);
            // printf("arr[%d]=%d\n", i, *(result_arr+i));
            result = *(result_arr+i);
        }
    }
    free(result_arr);
    return result;
}

typedef struct tree_node_t{
    int val;
    struct tree_node_t* left;
    struct tree_node_t* right;
} tree_node;
// Constraints:
// 1 <= arr.length <= 1000
// 2 <= arr[i] <= 10^9
// All the values of arr are unique.
// Given an array of unique integers, arr, where each integer arr[i] is strictly greater than 1.
// We make a binary tree using these integers, and each number may be used for any number of times. 
// Each non-leaf node's value should be equal to the product of the values of its children.

tree_node* create_node(int key){
    tree_node* node_buf = malloc(sizeof(tree_node));
    node_buf->val=key;
    node_buf->left = NULL;
    node_buf->right = NULL;

    return node_buf;
}

tree_node* insert_val_to_tree(tree_node* parent_node, int val){
    if(parent_node == NULL){
       parent_node = create_node(val);
       return parent_node;
    }

    tree_node* node = malloc(sizeof(tree_node));

    if(parent_node->val > val){
        parent_node->left = node;
        node->val = val;
        
    }
    else if(parent_node->val < val){
        parent_node->right = node;
        node->val = val;
    }
    parent_node = node;
    return parent_node;
}

int bottom_up_approach(int x){
    int result = 0;
    tree_node* root = NULL;
    // int arr[] = {2,4,5,10};
    // int arr[] = {2,4};
    int arr[] = {18,3,6,2};
    int arrSize = sizeof(arr)/sizeof(*arr);

    root = create_node(arr[0]);

    for(int i=1; i<arrSize; i++)//fill out the tree
    {
        insert_val_to_tree(root, *(arr+i));
    }

    // struct node_t *node_compare = root;
    // for(; node_compare->next; node_compare = node_compare->next)
    // {
    //     for(root = node_compare;root; root = root->next)
    //     {
    //         if(node_compare->val / node_compare->next->val == root->val){
    //             printf("[%d %d %d]\n", node_compare->val, node_compare->next->val, root->val);
    //             result++;
    //         }
    //         if(node_compare->val / root->val == node_compare->next->val && root->val != node_compare->next->val){
    //             printf("[%d %d %d]\n", node_compare->val, root->val, node_compare->next->val);
    //             result++;
    //         }
    //     }
    // }
    
    
    result += arrSize;
    long modulo = 1e9+7;
    result %= modulo;
    return result;
}

void swap(int *val1, int* val2){
    int temp = *val2;
    *val2 = *val1;
    *val1 = temp;
}

void lomuto_alg(int* input_buf, int len){
    int high = len-1;

    printf("\nInput arr\n");
    for(int j=0; j<=high; j++){
        printf("[ %d ]", input_buf[j]);
    }

    int pivot = input_buf[high];
    int i=-1;
    for(int j=0; i<=high; j++){
        if(input_buf[j] < pivot){
            i++;
            swap(&input_buf[i], &input_buf[j]);
        }
    }
    swap(&input_buf[i+1], &input_buf[high]);
    printf("\nSorted arr\n");
    for(int j=0; j<=high; j++){
        printf("[ %d ]", input_buf[j]);
    }
}