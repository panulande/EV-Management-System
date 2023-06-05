#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "p.h"



int charging;
int timing;
char username[50];
int counting;
int ID=0;


Station* minmeantimehigh(Station* p1,Station* p2, Station* p3, Node* arr1[], Node* arr2[], Node* arr3[]){
    if(arrayfullhigh(arr1)){
        return p1;
    }
    else if(arrayfullhigh(arr2)){
        return p2;
    }
    else if(arrayfullhigh(arr3)){
        return p3;
    }
     
    if((length(p1->high)==0 && (arrayfullhigh(arr1)==1)) ){
        
        return p1;
         


    }
    else if((length(p2->high)==0) && (arrayfullhigh(arr2)==1)){
        
        return p2;
        
    }
    else if((length(p3->high)==0  && (arrayfullhigh(arr3)==1))){
        
        return p3;
        
    }
    

    
    
    double avg1 = traverse(p1->high) / length(p1->high);
    double avg2 = traverse(p2->high) / length(p2->high);
    double avg3 = traverse(p3->high) / length(p3->high);
   

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
   

    return minStation;

}

Station* minmeantimelow(Station* p1, Station* p2, Station* p3, Node* arr1[], Node* arr2[], Node* arr3[] ) {
    if(arrayfulllow(arr1)){
        return p1;
    }
    else if(arrayfulllow(arr2)){
        return p2;
    }
    else if(arrayfulllow(arr3)){
        return p3;
    }


    if((length(p1->low)==0) && (arrayfulllow(arr1)==1)){
        return p1;
    }
    else if((length(p2->low)==0)&& (arrayfulllow(arr2)==1)){
        return  p2;

    }
    else if((length(p3->low)==0) &&  (arrayfulllow(arr3)==1) ){
        return p3;
    }
    
    
    double avg1 = traverse(p1->low) / length(p1->low);
    double avg2 = traverse(p2->low) / length(p2->low);
    double avg3 = traverse(p3->low) / length(p3->low);


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
    
    return minStation;
}






int main(){
     Hero* root = NULL; //initiating the database
    int choice, id;
    Record record;
    ////////////////////////////////////////////////
    Node* arr1[5];
    for(int i=0;i<5;i++){
        arr1[i]=NULL;
    }
    Node* arr2[5];
    for(int i=0;i<5;i++){
        arr2[i]=NULL;
    }
     Node* arr3[5];
    for(int i=0;i<5;i++){
        arr3[i]=NULL;
    }
   



    ////////////////////////////////////
    int count=0,cunt=0,countros;
    //defined the stations
    Station* s1=(Station*)malloc(sizeof(Station));
    Station* s2=(Station*)malloc(sizeof(Station));
    Station* s3=(Station*)malloc(sizeof(Station));

    //initiating the Priority Queues inside the stations.
    s1->low=initPriorityQueue();
    s1->high=initPriorityQueue();
    s2->low=initPriorityQueue();
    s2->high=initPriorityQueue();
    s3->low=initPriorityQueue();
    s3->high=initPriorityQueue();
   

    while(1){
       char a=getchar();

       //c for comtinue i for input
       if(a=='c'){

        
        do{
            printf("enter the charging :"); //charging
        
            scanf("%d", &charging);
        }while (~(0<=charging<=99));
        
        
        
        printf("enter first name :");

        
        char* pointer=(char*)malloc(50*sizeof(char));
        scanf("%s", pointer);
        printf("enter last name");
        char* ointer=(char*)malloc(50*sizeof(char));
        scanf("%s", ointer);
       

        
        two:
        printf("Enter the amount of charging to be done");
        int tobecharged; //must be greater than that of charging
        scanf("%d",&tobecharged);
        int diff=tobecharged-charging;

        EV* ptr=(EV*)malloc(sizeof(EV));
        initEV(charging, tobecharged,diff,timing, ptr, pointer,ointer);
       
        if(charging<30){
            Station* tempo=minmeantimehigh(s1,s2,s3, arr1, arr2, arr3);
            enqueue(tempo->high,45,timing,charging, ptr);
            tempo=NULL;
        }
        else if(charging>=30){
            Station* tempo=minmeantimelow(s1,s2,s3, arr1, arr2, arr3);
            enqueue(tempo->low,54,timing,charging, ptr);
            tempo=NULL;


        }
        


        }
        



        else if(a=='i'){

            
            ////////////////////////////////////////station 1
            for(int z=0;z<5;z++){
                
                if(arr1[z]==NULL && (z==0 || z==2 ||z==4) ){
                    if( length(s1->high)!=0){
                        arr1[z]=dequeue(s1->high);
                    
                    }
                    
                    else if(length(s1->high)==0 && length(s1->low)==0){
                        continue;

                    
                     

                }
                }

                else if(arr1[z]==NULL && (z==1||z==3) ){
                   
                    if(length(s1->low)!=0){
                        arr1[z]=dequeue(s1->low);
                    }
                    
                    else if(length(s1->high)==0 && length(s1->low)==0){
                        continue;
                    
                    }
                }
            }
            
            
            
            /////////////////////////////////////////station 2
            for(int z=0;z<5;z++){
                
                if(arr2[z]==NULL && (z==0 || z==2 ||z==4) ){
                    if( length(s2->high)!=0){
                        arr2[z]=dequeue(s2->high);
                        
                    }
                    
                    else if(length(s2->high)==0 && length(s2->low)==0){
                        continue;
                        
                    }
                    
                     

                }

                else if(arr2[z]==NULL && (z==1||z==3) ){
                    if(length(s2->low)!=0){
                        arr2[z]=dequeue(s2->low);
                    }
                    
                    else if(length(s2->high)==0 && length(s2->low)==0){
                        continue;
                    
                    }
                }
            }
            
            /////////////////////////////////////////////station 3
            for(int z=0;z<5;z++){
                
                if(arr3[z]==NULL && (z==0 || z==2 ||z==4) ){
                    if( length(s3->high)!=0){
                        arr3[z]=dequeue(s3->high);
                    }
                    
                    else if(length(s3->high)==0 && length(s3->low)==0){
                        continue;
                    }
                    
                     

                }

                else if(arr3[z]==NULL && (z==1||z==3) ){
                    if(length(s3->low)!=0){
                        arr3[z]=dequeue(s3->low);
                    }
                    
                    else if(length(s3->high)==0 && length(s3->low)==0){
                        continue;
                    
                    }
                }
            }
            
            
            ///////////////////////////////////station 4

            
            Node* temp=NULL;
           
            ////////////////////////////////////////////this is done now it is time to make a timer which will increase after every loop and check if the time is equal to
            for(int z=0;z<5;z++){
              temp=arr1[z];
                if(arr1[z]!=NULL && (temp->ev->diff)!=0 ){
                  temp->ev->diff--;
                  
                  }
                  
                else if(arr1[z]!=NULL && temp->ev->diff==0){
                    
                  //into the database
                  record.id=ID;
                  record.arrcharging=temp->ev->charging;
                  record.gocharging=temp->ev->tobecharged;
                  record.money=temp->ev->diff;
                  record.username=temp->ev->username;
                  record.lastname=temp->ev->lastname;
                  root=insert(root, record);
                  
                  
                  arr1[z]=NULL;
                  

                  ID++;
          
                  
                }
                
            }

            
            /////////////////////////////////////////station 2
            for(int z=0;z<5;z++){
              temp=arr2[z];
                if(arr2[z]!=NULL && (temp->ev->diff)!=0 ){
                  temp->ev->diff--;
                  }
                else if(arr2[z]!=NULL &&temp->ev->diff==0){
                  //into the database
                  record.id=ID;
                  record.arrcharging=temp->ev->charging;
                  record.gocharging=temp->ev->tobecharged;
                  record.money=temp->ev->diff;
                  record.username=temp->ev->username;
                  record.lastname=temp->ev->lastname;

                  

                  root=insert(root, record);
                  
                  
                  arr2[z]=NULL;
                  
                  ID++;
                  
                }
            }
            
            /////////////////////////////////////////////station 3
            for(int z=0;z<5;z++){
              temp=arr3[z];
                if(arr3[z]!=NULL && (temp->ev->diff)!=0 ){
                  temp->ev->diff--;
                  }
                else if(arr3[z]!=NULL &&temp->ev->diff==0){
                  //into the database
                  record.id=ID;
                  record.arrcharging=temp->ev->charging;
                  record.gocharging=temp->ev->tobecharged;
                  record.money=temp->ev->diff;
                  record.username=temp->ev->username;
                  record.lastname=temp->ev->lastname;

                  root=insert(root, record);
                  
                  
                  arr3[z]=NULL;
                  
                  ID++;
                  
                }
            }
            
            ///////////////////////////////////station 4

        }
        else if(a=='k'){
            printf("Database contents:\n");
            displayDatabase(root);
        }
        else if(a=='s'){
            for(int z=0;z<5;z++){
                if(arr1[z]!=NULL){
                    printf(" %d ", arr1[z]->ev->charging);
                }
                else if(arr1[z]==NULL){
                    printf(" N ");
                }
                if(z==4){
                    printf("\n");
                }
                 
            }
            for(int z=0;z<5;z++){
                if(arr2[z]!=NULL){
                    printf(" %d ", arr2[z]->ev->charging);
                }
                else if(arr2[z]==NULL){
                    printf(" N ");
                }
                if(z==4){
                    printf("\n");
                }
            }
            for(int z=0;z<5;z++){
                if(arr3[z]!=NULL){
                    printf(" %d ", arr3[z]->ev->charging);
                }
                else if(arr3[z]==NULL){
                    printf(" N ");
                }
                if(z==4){
                    printf("\n");
                }
            }

        }

        }
    }




       
