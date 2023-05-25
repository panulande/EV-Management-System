#ifndef __P_H__
#define __P_H__




typedef struct EV_user{
    int id;
    int battery_capacity;
    int charging_rate;

}EV;
typedef struct Node {
    int data;
    int chargingtime;
    int priority;
    struct Node* next;
    EV* ev;

} Node;




typedef struct PriorityQueue {
    Node* head;
} PriorityQueue;

// Initializes a new priority queue
PriorityQueue* initPriorityQueue() {
    PriorityQueue * queue = malloc(sizeof(PriorityQueue));
    queue->head = NULL;
    return queue;
}
typedef struct Station{
    PriorityQueue* high;
    PriorityQueue* low;
    int *chargingpoint;


}Station;

// Adds a new element with the given data and priority to the queue
void enqueue(PriorityQueue* queue,int data,int chargingtime, int priority, EV* ptr) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->chargingtime = chargingtime;

    new_node->priority = priority;
    new_node->ev=ptr;

    if (queue->head == NULL || priority < queue->head->priority) {
        new_node->next = queue->head;
        queue->head = new_node;
    } else {
        Node* current_node = queue->head;
        while (current_node->next != NULL && current_node->next->priority <= priority) {
            current_node = current_node->next;
        }
        new_node->next = current_node->next;
        current_node->next = new_node;
    }
}

// Removes and returns the element with the highest priority from the queue
Node* dequeue(PriorityQueue* queue) {
    if (queue->head == NULL) {
        printf("Error: Queue is empty.\n");
        return NULL;
    } else {
        Node* dequeued_node = queue->head;
        int dequeued_data = dequeued_node->data;
        EV* evv=dequeued_node->ev;
        queue->head = queue->head->next;
        dequeued_node->next=NULL;
        //free(dequeued_node);
        return dequeued_node;
    }
}

// Returns the data of the element with the highest priority in the queue without removing it
int peek(PriorityQueue* queue) {
    if (queue->head == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    } else {
        return queue->head->data;
    }
}
/*int traverse(PriorityQueue* queue) {
    int count=0;
    if(queue->head == NULL) {
        return 0;
    } else {
        Node* temp = queue->head;
        while(temp != NULL) {
            count += temp->chargingtime;
            temp = temp->next;
        }
    }
    return count;
}



int length(PriorityQueue* queue) {
    if(queue->head == NULL) {
        return 0;
    } else {
        Node* temp = queue->head;
        int count = 0;
        while(temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
}*/

int traverse(PriorityQueue* queue) {
    int count = 0;
    if (queue->head == NULL) {
        return count;
    } else {
        Node* temp = queue->head;
        while (temp != NULL) {
            count += temp->chargingtime;
            temp = temp->next;
        }
        return count;
    }
}

int length(PriorityQueue* queue) {
    int count = 0;
    if (queue->head == NULL) {
        return count;
    } else {
        Node* temp = queue->head;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
    }
}


// Returns 1 if the queue is empty, 0 otherwise
int isPriorityQueueEmpty(PriorityQueue* queue) {
    return (queue->head == NULL);
}

EV* initEV( int charging, int username, int time_counter,EV* ptr){

    ptr->battery_capacity=charging;
    ptr->charging_rate=time_counter;
    ptr->id=username;
    return ptr;



}

#endif
       