#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
struct player {
    unsigned char age;
    char nm[60];
    unsigned char nb;
};

int main(void)
{
    struct player kirill  = { 24, " Kirill Kaprizov",17 };
    struct player alex = { 36, "Alexander Ovechkin", 8 };
    struct player evgeny = {35 , "Evgeny Malkin", 71 };
    struct player* p_kirill = &kirill;
    struct player* p_alex = &alex;
    struct player* p_evgeny = &evgeny;


    char* nm = p_kirill->nm;
    int a = 1;
   
    printf("\n\n");

    func(p_kirill, p_alex, p_evgeny);
}

void func(struct player* p_kirill, struct player* p_alex, struct player* p_evgeny, int a) {
    unsigned char age;
    char nm[60];
    unsigned char nb;
    int c;
    
    printf(" 1 kirill \n 2 alex\n 3 evgeny\n\n");

    scanf("%d", &c);


    switch (c) {
    case 1:  
       printf("%s%d,%d years\n", p_kirill->nm, p_kirill->nb, p_kirill->age);   
        break;
    case 2: 
        printf("%s%d,%d years\n", p_alex->nm, p_alex->nb, p_alex->age);  
        break;
    case 3:
        printf("%s%d,%d years\n", p_evgeny->nm, p_evgeny->nb, p_evgeny->age);
        break;
       
}
}
   
