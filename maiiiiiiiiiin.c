#include<stdio.h>
#include<stdlib.h>
#include "p.h"

int main(){
    PriorityQueue q1;
    initPriorityQueue(&q1);
    
    PriorityQueue q2;
    initPriorityQueue(&q2);
    
    enqueue(&q1,44,42);
    enqueue(&q1,45,49);


return 0;
}
