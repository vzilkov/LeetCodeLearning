#include "stdlib.h"
#include "stdio.h"
#include "string.h"
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.
Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 2 is written as II in Roman numeral, just two one's added together. 12 is written as XII, which is simply X + II. The number 27 is written as XXVII, which is XX + V + II.
Roman numerals are usually written largest to smallest from left to right. However, the numeral for four is not IIII. Instead, the number four is written as IV. Because the one is before the five we subtract it making four. The same principle applies to the number nine, which is written as IX. There are six instances where subtraction is used:
I can be placed before V (5) and X (10) to make 4 and 9. 
X can be placed before L (50) and C (100) to make 40 and 90. 
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, convert it to a roman numeral.
Example 1:
Input: num = 3
Output: "III"
Explanation: 3 is represented as 3 ones.
Example 2:
Input: num = 58
Output: "LVIII"
Explanation: L = 50, V = 5, III = 3.
Example 3:
Input: num = 1994
Output: "MCMXCIV"
Explanation: M = 1000, CM = 900, XC = 90 and IV = 4.
*/
typedef struct node_t{
    int val;
    struct node_t* next;
}node_tdf;

node_tdf *root_node = NULL;
void push(int val){
    node_tdf *temp = malloc(sizeof(node_tdf));
    temp->next = root_node;
    temp->val = val;
    root_node = temp;
}
int pop(){
    int val = -1;
    if(root_node){
        val = root_node->val;
        node_tdf *temp = root_node;
        root_node = root_node->next;
        free(temp);
    }
    return val;
}

char* intToRoman(int num) {
    int el_num = 30;
    char *string = calloc(el_num, sizeof(char));
    char str_buf[el_num];
    memset(str_buf,0,el_num);
    int dig = num;
    int mul = 1;
    
    // 58
    while(dig){
        int modulo = dig % (mul*10);
        dig -= modulo;

        while(modulo){

            if(modulo >= 1000){
                //add M
                strncat(str_buf, "M", 1);
                modulo -= 1000;
            }
            else if(modulo >= 500){
                //add D
                if(modulo == 900){
                    strncat(str_buf, "MC", 2);
                    modulo -= 900;    
                }
                else{
                    strncat(str_buf, "D", 1);
                    modulo -= 500;
                }
            }
            else if(modulo >= 100){
                //add C
                if(modulo == 400){
                    strncat(str_buf, "DC", 2);
                    modulo -= 400;    
                }
                else{
                    strncat(str_buf, "C", strlen("C"));
                    modulo -= 100;
                }
            }
            else if(modulo >= 50){
                //add L
                if(modulo == 90){
                    strncat(str_buf, "CX", strlen("XC"));
                    modulo -= 90;    
                }
                else{
                    strncat(str_buf, "L", strlen("L"));
                    modulo -= 50;
                }
                
            }
            else if(modulo >= 10){
                //add X
                if(modulo == 40){
                    strncat(str_buf, "LX", strlen("XL"));
                    modulo -= 40;    
                }
                else{
                    strncat(str_buf, "X", strlen("X"));
                    modulo -= 10;
                }
            }
            else if(modulo >= 5){
                //add V
                if(modulo == 9){
                    strncat(str_buf, "XI", strlen("IX"));
                    modulo -= 9;    
                }
                else{
                    strncat(str_buf, "V", strlen("V"));
                    modulo -= 5;
                }
            }
            else if(modulo >= 1){
                //add I
                if(modulo == 4){
                    strncat(str_buf, "VI", strlen("IV"));
                    modulo -= 4;    
                }
                else{
                    strncat(str_buf, "I", strlen("I"));
                    modulo -= 1;
                }
            }
        }
        mul *= 10;
    }
    for(int i=0, j=strlen(str_buf)-1; i<strlen(str_buf); i++, j--){
        string[i] = str_buf[j];
    }
    return string;
}

typedef struct _node{
    char val;
    struct _node *next;
}node_char;

node_char* root = NULL;

void push_char(char value){
    node_char* node = malloc(sizeof(node_char));
    node->val = value;
    node->next = NULL;
    node->next = root;
    root = node;
}

char pop_char(){
    char val = 0;
    if(root){
        node_char* node = root;
        val = root->val;
        root = root->next;
        free(node);
    }
    return val;
}

struct ListNode {
    int val;
    struct ListNode *next;
 };

struct ListNode *root_int = NULL;
void push_int(int val){
    struct ListNode *node = malloc(sizeof(*node));
    node->val = val;
    node->next = root_int;
    root_int = node;
}

struct ListNode* deleteDuplicate(struct ListNode* head){
    struct ListNode* node_buf = head->next;
    if(head->val == node_buf->val){
        head->next = node_buf->next;
        free(node_buf);
    }
    return head;
}

struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* node_buf = head;
    
    while(node_buf){//check full chain
        struct ListNode* comp_buf = node_buf;
        while(comp_buf != NULL && comp_buf->val == node_buf->val){//comp eq values
            struct ListNode *temp = node_buf->next;
            comp_buf = comp_buf->next;
            free(temp);
        }
        node_buf->next = comp_buf;
        node_buf = node_buf->next;
    }
    return head;
}

void lists_main(){
    printf("\n");

    intToRoman(58);

    printf("\n");
    for(int i=0; i<10; i++)
        push(i);
    int i=0;

    push_int(2);
    push_int(1);
    push_int(1);

    root_int = deleteDuplicates(root_int);
    while (root_int)
    {
        root_int = deleteDuplicate(root_int);
        root_int = root_int->next;
    }
    
    
}
/*
struct ListNode* deleteDuplicates(struct ListNode* head) {
    struct ListNode* root = head;
    
    while(head != NULL)
    {
        // struct ListNode* next_node = head->next;
        // next_node = head->next;
        // if(head->val == next_node->val){
        //     head->next = next_node->next;
        //     // free(next_node);
        // }

        
        // if(head->next != NULL)
        //     next_node = head->next;
        printf("val %d\n", head->val);
        head = head->next;
    }
    
    return root;
}
*/