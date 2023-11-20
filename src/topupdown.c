#include "topupdown.h"
#include "stdlib.h"
#include "stdio.h"

static int counter = 0;
static cache[10+1] = {0};
int top_down_alg(int x){// fibonaci
    counter++;
    if(x<=0)
        return 0;
    if(x == 1)
    {
        return x;
    }
    else{
        if(cache[x] == 0){
            cache[x] = top_down_alg(x-1) + top_down_alg(x-2);//counter = 177 for x = 10    
        }
        return cache[x];
    }
}

int brootforce_alg(int x){
    int *result_arr = calloc(x,sizeof(*result_arr));
    counter=0;
    int result=0;
    for(int i=0, buf=0; i<=x; i++, counter++){
        if(i == 0){
            *(result_arr+i) = 0;
        }
        else if(i==1){
            *(result_arr+i) = 1;
        }
        else{
            *(result_arr+i) = *(result_arr+i-1) + *(result_arr+i-2);
            printf("arr[%d]=%d\n", i, *(result_arr+i));
            result = *(result_arr+i);
        }
    }
    free(result_arr);
    return result;
}

int bottom_up_approach(int x){
    int result = 0;

    return result;
}