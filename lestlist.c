#include <stdlib.h> 
#include <stdio.h> 

typedef struct Slist { 
    int id; 
    char *name; 

    struct Slist *next; 
} Tlist; 

Tlist *create_node(int set_id, char *set_name){ 
    Tlist *node = ((Tlist *)malloc(sizeof(Tlist)));
    node -> id = set_id; 
    node ->name = set_name; 

    node -> next = NULL; 
    
    return node;
}

int main(){ 
    Tlist *list = create_node(0, "Name1");

    printf("id=%d name=%s\n", list->id, list->name); 

    if (list->next == NULL)
        printf("<list->next == NULL>\n"); 
    return 0;
}