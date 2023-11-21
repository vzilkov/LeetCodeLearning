#include "stdlib.h"
struct Node_t{
    int val;
    struct Node_t *left;
    struct Node_t *right;
};

struct Node_t* create_new_node(int val){
    struct Node_t* node = malloc(sizeof(struct Node_t));
    node->val = val;
    node->left = NULL;
    node->right = NULL;
    return node;
}

struct Node_t* insert_val_to_tree_fun(struct Node_t* node, int val){
    if(node == NULL){
        //create new node
        return create_new_node(val);
    }

    if(val < node->val){
        node->left = insert_val_to_tree_fun(node->left, val);
    }
    else if(val > node->val){
        node->right = insert_val_to_tree_fun(node->right, val);
    }

    return node;
}

int search_in_bin_tree(struct Node_t* root, int search_val){
        while(root != NULL){
            if(root->val > search_val){
                root = root->left;
            }
            else if(root->val < search_val){
                root = root->right;
            }
            else{
                return 1;
            }
        }

        return 0;
}

int numFactoredBinaryTrees(int* arr, int arrSize) {
    struct Node_t *root = NULL;
    root = insert_val_to_tree_fun(root, 10);
    insert_val_to_tree_fun(root, 15);
    insert_val_to_tree_fun(root, 5);
    insert_val_to_tree_fun(root, 30);
    insert_val_to_tree_fun(root, 2);

    int buf[] = {10,15,5,30,2};
    for(int i=0, result=0; i<5; i++){
        result = search_in_bin_tree(root, buf[i]);
        result = 0;
    }
    

    int len = sizeof(buf)/sizeof(*buf);

    int dest_val = 2;
    int cnt=dest_val=7;
    for(int i=len/2; i<len && i>=1; cnt++){
        if(dest_val > *(buf+i)){
            i=(i+len)/2;
            if(dest_val < *(buf+i)){
                return 0;
            }
        }
        else if(dest_val < *(buf+i)){
            i/=2;
            if(dest_val > *(buf+i)){
                return 0;
            }
        }
        else{
            return 1;
        }
    }
    return 0;
}