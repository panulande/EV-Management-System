#include<stdio.h>
#include<stdlib.h>
#include "p.h"



int charging;
int timing;
int username;
int counting;




/*Station* minmeantimehigh(Station* p1,Station* p2, Station* p3, Station* p4, int count, int){
    int k;
    if((traverse(p1->high)/length(p1->high)) <= (traverse(p2->high)/length(p2->high)) && (traverse(p1->high)/length(p1->high))<= (traverse(p3->high)/length(p3->high)) && (traverse(p1->high)/length(p1->high))<=(traverse(p4->high)/length(p4->high))){
        return p1;
    }
    else if((traverse(p2->high)/length(p2->high))<=(traverse(p1->high)/length(p1->high)) && (traverse(p2->high)/length(p2->high))<=(traverse(p3->high)/length(p3->high)) && (traverse(p2->high)/length(p2->high))<=(traverse(p4->high)/length(p4->high))){
        return p2;
    }
    else if((traverse(p3->high)/length(p3->high))<(traverse(p1->high)/length(p1->high)) && (traverse(p3->high)/length(p3->high))<(traverse(p2->high)/length(p2->high)) && (traverse(p3->high)/length(p3->high))<(traverse(p4->high)/length(p4->high))){
        return p3;
    }
    else if ((traverse(p4->high)/length(p4->high))<(traverse(p1->high)/length(p1->high)) && (traverse(p4->high)/length(p4->high))<(traverse(p3->high)/length(p3->high)) && (traverse(p4->high)/length(p4->high))<(traverse(p2->high)/length(p2->high))){
        return p4;

    }
    }*/

/*Station* minmeantimehigh(Station* p1, Station* p2, Station* p3, Station* p4, int count) {
    if((traverse(p1->high,count)/length(p1->high)) <= (traverse(p2->high,count)/length(p2->high)) && (traverse(p1->high,count)/length(p1->high))<= (traverse(p3->high,count)/length(p3->high)) && (traverse(p1->high,count)/length(p1->high))<=(traverse(p4->high,count)/length(p4->high))){
        return p1;
    }
    else if((traverse(p2->high,count)/length(p2->high))<=(traverse(p1->high,count)/length(p1->high)) && (traverse(p2->high,count)/length(p2->high))<=(traverse(p3->high,count)/length(p3->high)) && (traverse(p2->high,count)/length(p2->high))<=(traverse(p4->high,count)/length(p4->high))){
        return p2;
    }
    else if((traverse(p3->high,count)/length(p3->high))<(traverse(p1->high,count)/length(p1->high)) && (traverse(p3->high,count)/length(p3->high))<(traverse(p2->high,count)/length(p2->high)) && (traverse(p3->high,count)/length(p3->high))<(traverse(p4->high,count)/length(p4->high))){
        return p3;
    }
    else if ((traverse(p4->high,count)/length(p4->high))<(traverse(p1->high,count)/length(p1->high)) && (traverse(p4->high,count)/length(p4->high))<(traverse(p3->high,count)/length(p3->high)) && (traverse(p4->high,count)/length(p4->high))<(traverse(p2->high,count)/length(p2->high))){
        return p4;

    }
    return NULL; // in case no station meets the criteria
}


Station* minmeantimelow(Station* p1,Station* p2, Station* p3, Station* p4, int count){
    int k;
    if((traverse(p1->low,count)/length(p1->low)) <= (traverse(p2->low,count)/length(p2->low)) && (traverse(p1->low,count)/length(p1->low))<= (traverse(p3->low,count)/length(p3->low)) && (traverse(p1->low,count)/length(p1->low))<=(traverse(p4->low,count)/length(p4->low))){
        return p1;
    }
    else if((traverse(p2->low,count)/length(p2->low))<=(traverse(p1->low,count)/length(p1->low)) && (traverse(p2->low,count)/length(p2->low))<=(traverse(p3->low,count)/length(p3->low)) && (traverse(p2->low,count)/length(p2->low))<=(traverse(p4->low,count)/length(p4->low))){
        return p2;
    }
    else if((traverse(p3->low,count)/length(p3->low))<(traverse(p1->low,count)/length(p1->low)) && (traverse(p3->low,count)/length(p3->low))<(traverse(p2->low,count)/length(p2->low)) && (traverse(p3->low,count)/length(p3->low))<(traverse(p4->low,count)/length(p4->low))){
        return p3;
    }
    else if ((traverse(p4->low,count)/length(p4->low))<(traverse(p1->low,count)/length(p1->low)) && (traverse(p4->low,count)/length(p4->low))<(traverse(p3->low,count)/length(p3->low)) && (traverse(p4->low,count)/length(p4->low))<(traverse(p2->low,count)/length(p2->low))){
        return p4;

    }
}

/*Station* minmeantimelow(Station* p1,Station* p2, Station* p3, Station* p4, Station* p5){
    return;


}

int minmeantimelow(Station* p1,Station* p2, Station* p3, Station* p4 ){
    double ptr1=(traverse(p1->low)/length(p1->low));
    double ptr2=(traverse(p2->low)/length(p2->low));
    double ptr3=(traverse(p3->low)/length(p3->low));
    double ptr4=(traverse(p4->low)/length(p4->low));

    double minimum = ptr1;

    if (ptr2 < minimum)
        minimum = ptr2;
    if (ptr3 < minimum)
        minimum = ptr3;;
    if (ptr4 < minimum)
        minimum = ptr4;
    
    if(minimum==ptr1){
        return 5;
    }
    else if(minimum ==ptr2){
        return 6;

    }
    else if(minimum==ptr3){
        return 7;
    }
    else if(minimum == ptr4){
        return 8;
    }
    else{
        return 0;
    }

}*/

Station* minmeantimehigh(Station* p1,Station* p2, Station* p3, Station* p4 ){
    if(length(p1->high)==0){
        return p1; 


    }
    else if(length(p2->high)==0){
        return p2;
    }
    else if(length(p3->high)==0){
        return p3;
    }
    else if(length(p4->high)==0){
        return p4;
    }

    double avg1 = traverse(p1->low) / length(p1->low);
    double avg2 = traverse(p2->low) / length(p2->low);
    double avg3 = traverse(p3->low) / length(p3->low);
    double avg4 = traverse(p4->low) / length(p4->low);

    double minimum = avg1;
    Station* minStation = p1;

    if (avg2 < minimum) {
        minimum = avg2;
        minStation = p2;
    }
    if (avg3 < minimum) {
        minimum = avg3;
        minStation = p3;
    }
    if (avg4 < minimum) {
        minimum = avg4;
        minStation = p4;
    }

    return minStation;

}
    
Station* minmeantimelow(Station* p1, Station* p2, Station* p3, Station* p4) {
    if(length(p1->low)==0){
        return p1;
    }
    else if(length(p2->low)==0){
        return  p2;

    }
    else if(length(p3->low)==0){
        return p3;
    }
    else if(length(p4->low)==0){
        return p4;
    }
    double avg1 = traverse(p1->low) / length(p1->low);
    double avg2 = traverse(p2->low) / length(p2->low);
    double avg3 = traverse(p3->low) / length(p3->low);
    double avg4 = traverse(p4->low) / length(p4->low);

    double minimum = avg1;
    Station* minStation = p1;

    if (avg2 < minimum) {
        minimum = avg2;
        minStation = p2;
    }
    if (avg3 < minimum) {
        minimum = avg3;
        minStation = p3;
    }
    if (avg4 < minimum) {
        minimum = avg4;
        minStation = p4;
    }

    return minStation;
}






int main(){
    ////////////////////////////////////////////////
    EV* arr1[3];
    for(int i=0;i<3;i++){
        arr1[i]=NULL;
    }
    EV* arr2[3];
    for(int i=0;i<3;i++){
        arr2[i]=NULL;
    }
     EV* arr3[3];
    for(int i=0;i<3;i++){
        arr3[i]=NULL;
    }
     EV* arr4[3];
    for(int i=0;i<3;i++){
        arr4[i]=NULL;
    }
    EV* hp1[2];
    EV* hp2[2];
    EV* hp3[2];
    EV* hp4[2];

    for(int i=0;i<2;i++){
        hp1[i]=NULL;
    }
    for(int i=0;i<2;i++){
        hp2[i]=NULL;
    }
    for(int i=0;i<2;i++){
        hp3[i]=NULL;
    }
    for(int i=0;i<2;i++){
        hp4[i]=NULL;
    }



    ////////////////////////////////////
    int count=0,cunt=0,countros;
    //defined the stations
    Station* s1=(Station*)malloc(sizeof(Station));
    Station* s2=(Station*)malloc(sizeof(Station));
    Station* s3=(Station*)malloc(sizeof(Station));
    Station* s4=(Station*)malloc(sizeof(Station));
    //initiating the Priority Queues inside the stations.
    s1->low=initPriorityQueue();
    s1->high=initPriorityQueue();
    s2->low=initPriorityQueue();
    s2->high=initPriorityQueue();
    s3->low=initPriorityQueue();
    s3->high=initPriorityQueue();
    s4->low=initPriorityQueue();
    s4->high=initPriorityQueue();

    while(1){
       char a=getchar();

       //c for comtinue i for input
       if(a=='c'){

        printf("enter the charging");
        scanf("%d", &charging);
        timing=charging%10;

        printf("enter the time you want the vehicle to be charged");
        scanf("%d",&timing);
        printf("enter name of the user");
        scanf("%d",&username);
        EV* ptr=(EV*)malloc(sizeof(EV));
        initEV(charging, username, timing, ptr);
        printf("enter the priority if the vehicle");
        int prio;
        scanf("%d",&prio);
        //////////////////////////////////////////////c
        enqueue(s1->low, 43,timing, prio,ptr);
        /*printf("%d/n",dequeue(s1->low));*/

        

        if(prio>50){
            Station* tempo=minmeantimehigh(s1,s2,s3,s4);
            enqueue(tempo->high, 45,timing, prio, ptr);
            printf("%d",dequeue(s1->high));






        }
        else{
            Station* tempo=minmeantimelow(s1,s2,s3,s4);
            enqueue(tempo->low, 54,timing, prio, ptr);
            printf("%d", dequeue(tempo->low));
           
        }




        
        
       
          
        }
        
        else if(a=="i"){
            countros=1;
            ////////////////////////////////////////station 1
            for(int z=0;z<3;z++){
                if(arr1[z]==NULL && countros==1 ){
                    arr1[z]=dequeue(s1->low);
                    countros=0;

                }
                else if(arr1[z]==NULL && countros==0){
                    arr1[z]=dequeue(s1->high);
                    countros=0;
                }
            }
            for(int k=0;k<2;k++){
                if(hp1[k]==NULL){
                    hp1[k]=dequeue(s1->high);
                }
            }
            /////////////////////////////////////////station 2
            for(int z=0;z<3;z++){
                countros=0;
                if(arr2[z]==NULL && countros==1 ){
                    arr2[z]=dequeue(s2->low);
                    countros=0;

                }
                else if(arr2[z]==NULL && countros==0){
                    arr2[z]=dequeue(s2->high);
                    countros=1;
                }
            }
            for(int k=0;k<2;k++){
                if(hp2[k]==NULL){
                    hp2[k]=dequeue(s2->high);
                }
            }
            /////////////////////////////////////////////station 3
            for(int z=0;z<3;z++){
                countros=0;
                if(arr3[z]==NULL && countros==1 ){
                    arr3[z]=dequeue(s3->low);
                    countros=0;

                }
                else if(arr3[z]==NULL && countros==0){
                    arr3[z]=dequeue(s3->high);
                    countros=1;
                }
            }
            for(int k=0;k<2;k++){
                if(hp3[k]==NULL){
                    hp3[k]=dequeue(s3->high);
                }
            }
            ///////////////////////////////////station 4

            for(int z=0;z<3;z++){
                countros=0;
                if(arr4[z]==NULL && countros==1 ){
                    arr4[z]=dequeue(s4->low);
                    countros=0;

                }
                else if(arr4[z]==NULL && countros==0){
                    arr4[z]=dequeue(s4->high);
                    countros=1;
                }
            }
            for(int k=0;k<2;k++){
                if(hp4[k]==NULL){
                    hp4[k]=dequeue(s4->high);
                }
            }
            ////////////////////////////////////////////this is done now it is time to make a timer which will increase after every loop and check if the time is equal to



            
            



            
            

            counting++;
        }
        


        }



       }

       
