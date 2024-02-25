struct ht_t
{
    int key;
    int val;
};

struct hash_list_map_t
{
    struct ht_t* entered_val;
    int len;
    int capacity;
    struct hash_list_map_t* next;
};
#define MAP_SIZE 7

// static struct hash_list_map_t map[MAP_SIZE];

struct ht_t* ht_init(){
    struct hash_list_map_t* table = malloc(sizeof(struct hash_list_map_t));
    table->len = 0;
    table->capacity = MAP_SIZE;

    table->entered_val = calloc(table->capacity, sizeof(struct ht_t));
    return table;
}

void ht_destroy(struct hash_list_map_t* table){
    for(int i=0; i<table->capacity; i++){
        free(table->entered_val[i].key);
    }
    free(table->entered_val);
    free(table);
}



void ht_insert(int val){

}