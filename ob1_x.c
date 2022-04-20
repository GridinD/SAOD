#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct player {
    unsigned char age;
    char nm[60];
    unsigned char nb;
};

void info(struct player *name){

    printf("%s\n", name->nm);
    printf("%d years\n", name->age);
    printf("%d\n", name->nb);
    
}





int main(void)
{
    struct player kirill  = { 24, "Kirill Kaprizov",17 };
    struct player alex = { 36, "Alexander Ovechkin", 8 };
    struct player evgeny = {35 , "Evgeny Malkin", 71 };
    struct player* p_kirill = &kirill;
    struct player* p_alex = &alex;
    struct player* p_evgeny = &evgeny;


    info(p_kirill);
    info(p_alex);
    info(p_evgeny);
    
   
    

    
}


   