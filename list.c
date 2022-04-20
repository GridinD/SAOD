#include <stdlib.h> 
#include <stdio.h> 

typedef struct s_list { 
    int id; 
    char *name; 

    struct s_list *next;
} t_list; 

t_list *create_node(int set_id, char *set_name){ 
    t_list *node = ((t_list *)malloc(sizeof(t_list))); 
    node -> id = set_id; 
    node -> name = set_name; 

    node -> next = NULL; 

    return node;  
}

int main(){ 

    t_list *list = create_node(0, "Name1"); 

    printf("id=%d name=%s\n", list->id, list->name); 

    if (list->next == NULL)
        printf("<list->next == NULL>\n"); 
    return 0;
} 