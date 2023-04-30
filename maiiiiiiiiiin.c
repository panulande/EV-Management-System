#include<stdio.h>
#include<stdlib.h>
#include "p.h"

typedef struct Station{
    PriorityQueue* high;
    PriorityQueue* low;
    int *chargingpoint;


}Station;
struct EV_user{

};
int main(){
    //defined the stations
    Station* s1=malloc(sizeof(Station));
    Station* s2=malloc(sizeof(Station));
    Station* s3=malloc(sizeof(Station));
    Station* s4=malloc(sizeof(Station));
    //initiating the Priority Queues inside the stations.
    s1->low=initPriorityQueue();
    s1->high=initPriorityQueue();
    s2->low=initPriorityQueue();
    s2->high=initPriorityQueue();
    s3->low=initPriorityQueue();
    s3->high=initPriorityQueue();
    s4->low=initPriorityQueue();
    s4->high=initPriorityQueue();

    enqueue(s1->low, 45,49);
    printf("%d",dequeue(s1->low));

    



    
    
    


return 0;
}
