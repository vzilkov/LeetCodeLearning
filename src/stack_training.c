#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "stack_training.h"

// [13,12,15,11,9,12,16]
//  2   1  4  2 1  1  0
int isValid(char* s);
void check_weather_temp_dif(){ // brute force
    int days_temp[] = {13,12,15,11,9,12,16,17,4,12,14,17,9,16};
    int len = sizeof(days_temp)/sizeof(*days_temp);
    int *days_diff = calloc(len, sizeof(int));
    int counter=0;
    for(int i=0; i<len; i++){
        for(int j=i+1; j<len; j++){
            counter++;
            if(days_temp[i] < days_temp[j]){
                days_diff[i] = j-i;
                break;
            }
        }
        printf("%d ",*(days_diff+i));
    }
    printf("\nCounter %d \n",counter);

    isValid("{[]}");// another task
}
struct day_temp_t{
    int diff_days;
    int day_temp;
    struct day_temp_t* next;
};
static struct day_temp_t *day_values_root = NULL;

void push(struct day_temp_t* day_values){
    struct day_temp_t* day_values_buf = malloc(sizeof(struct day_temp_t));
    day_values_buf->next = day_values_root;
    day_values_root = day_values_buf;
}

void check_weather_temp_diff_with_stack(){//stack

}

typedef struct _node{
    char val;
    struct _node* next;
}node_t;
node_t *root = NULL;

void push_char(char val){
    node_t *temp = malloc(sizeof(*temp));
    temp->val = val;
    temp->next = root;
    root = temp;
}

char pop(){
    char val = root->val;
    root->val = 0;
    node_t *temp = root;
    root = root->next;
    free(temp);
    return val; 
}

char check_top(){
    char val = 0;
    if(root)
    val = root->val;
    return val;
}

int isValid(char* s) {
    //check str
    //add parenthesises to stack
    for(int i=0; s[i] != '\0'; i++)
    {
        if((check_top() == '(' && s[i] == ')')
        || (check_top() == '{' && s[i] == '}')
        || (check_top() == '[' && s[i] == ']')
        && check_top() != 0){
            pop();
        }
        else{
            push_char(s[i]);//{
        }
    }
    if(check_top() == 0){
        return 1;
    }
    else{
        return 0;
    }
}