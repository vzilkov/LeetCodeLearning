
/*
//insertions sort
void merge(int* nums1, int nums1Size, int m, int* nums2, int nums2Size, int n) {
    memcpy(nums1+m, nums2, sizeof(*nums2)*n);
    int arr_len = m+n;
    
    //sort arr insertions
    for(int i=1; i<arr_len; i++){
        int x = nums1[i];
        int j=i;
        while(j>0 && nums1[j-1] > x){
            nums1[j] = nums1[j-1];
            j--;
        }
        nums1[j] = x;
    }
}
*/

/*
Buble sort:

*/

static void swap(int* val1, int* val2){
    int temp = *val1;
    *val1=*val2;
    *val2=temp;
}

void sort_alg_bubles(int* input_arr, int len){
    printf("\n Input arr\n");
    for(int i =0; i<len; i++){
        printf(" [%d]", input_arr[i]);
    }

    for(int i=0; i<len; i++)
        for(int j=i+1; j<len;j++){
            if(input_arr[j-1] > input_arr[j]){
                swap(&input_arr[j-1], &input_arr[j]);
            }
        }
    printf("\n Input arr sorted bubles\n");
    for(int i =0; i<len; i++){
        printf(" [%d]", input_arr[i]);
    }
}

int partition(int* input_arr, int l, int r){
    if(l>=r)
    return;

    int pivot = input_arr[r-1];
    int less = 0;
    for(int i=l; i < r-1; i++){
        if(input_arr[i] <= pivot){
            swap(&input_arr[i], &input_arr[less]);
            less++;
        }
    }
    swap(&input_arr[r-1], &input_arr[less]);
    return less;
}

static int partition_new(int* input_arr, int l, int r){
    int highest_val_num = r-1;
    int less_num = l;
    int pivot_val = input_arr[highest_val_num];
    for(int i=l; i<highest_val_num; i++){
        if(input_arr[i] <= pivot_val){
            swap(&input_arr[i], &input_arr[less_num]);
            less_num++;
        }
    }
    swap(&input_arr[less_num], &input_arr[highest_val_num]);
    return less_num;
}

static void quick_sort(int* input_arr, int l, int r){
    int cursor;
    if(l>=r)
        return;

    cursor = partition_new(input_arr, l, r);
    quick_sort(input_arr, l, cursor);
    quick_sort(input_arr, cursor+1, r);
}

void sort_alg_lomuto(int* input_arr, int len){

    printf("\n Input arr Lomuto's alg\n");
    for(int i =0; i<len; i++){
        printf(" [%d]", input_arr[i]);
    }
/*
    int q = partition(input_arr, 0, len);
    partition(input_arr, 0, q-1);
    partition(input_arr, q, len);
*/

    quick_sort(input_arr, 0, len);

    printf("\n Output arr Lomuto's alg\n");
    for(int i =0; i<len; i++){
        printf(" [%d]", input_arr[i]);
    }
    
}

void sort_dyn_impl(int *arr, int len){
    int* buf = calloc(len, sizeof(*buf));
    for(int i=len-1, j=i; i>=0 && j>=0; i--,j--){
        if(arr[j])
            buf[i] = arr[j];
        else
         i++;
    }
    memcpy(arr, buf, len*sizeof(*arr));
    free(buf);
    printf("\nDyn implementation\n");
    for(int i=0; i<len; i++){
        printf(" [%d]", arr[i]);
    }
    printf("\n");
}
