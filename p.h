
typedef struct Node {
    int data;
    int priority;
    struct Node* next;
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

// Adds a new element with the given data and priority to the queue
void enqueue(PriorityQueue* queue,int data, int priority) {
    Node* new_node = malloc(sizeof(Node));
    new_node->data = data;
    new_node->priority = priority;

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
int dequeue(PriorityQueue* queue) {
    if (queue->head == NULL) {
        printf("Error: Queue is empty.\n");
        return -1;
    } else {
        Node* dequeued_node = queue->head;
        int dequeued_data = dequeued_node->data;
        queue->head = queue->head->next;
        free(dequeued_node);
        return dequeued_data;
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

// Returns 1 if the queue is empty, 0 otherwise
int isPriorityQueueEmpty(PriorityQueue* queue) {
    return (queue->head == NULL);
}


