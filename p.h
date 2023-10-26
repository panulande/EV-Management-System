
#ifndef __P_H__
#define __P_H__
#include<stdio.h>
#include<stdlib.h>



typedef struct EV_user{ 
    char* lastname; //
    char* username;//
    int charging;//
    int timing; //
    int tobecharged;//
    int diff;//

}EV;
//
typedef struct Node {
    int data; //not needed
    int chargingtime;
    int priority;
    struct Node* next;
    EV* ev;
    char* username;//////////////////////////not needed
    char* lastname;////////not needed

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
 


}Station;

// Adds a new element with the given data and priority to the queue
void enqueue(PriorityQueue* queue,int data,int timing,int priority, EV* ptr) {
    Node* new_node = (Node*)malloc(sizeof(Node));
   
    
    new_node->data=data;
    new_node->priority = priority;
    new_node->ev=ptr;
    new_node->chargingtime=timing;

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
    printf("\nThe user named %s %s with charging of ev %d has been added to the queue\n",ptr->username, ptr->lastname,ptr->charging);
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
        printf("\nThe user named %s %s with charging of ev %d has been removed from the queue\n",evv->username,evv->lastname, evv->charging);
        //free(dequeued_node);
       
        return dequeued_node;
    }
}



int traverse(PriorityQueue* queue) {  //charging count

    int count = 0;
    if (queue->head == NULL) {
        return count;
    } else {
        Node* temp = queue->head;
        while (temp != NULL) {
            count += temp->ev->diff;
            temp = temp->next;
        }
        return count;
    }
} //to calculate the charging every vehicle want to do

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



EV* initEV( int charge, int charged, int difference, EV* ptr, char* pointer, char* ointer){

    ptr->charging=charge;
    //ptr->timing=time;
    ptr->tobecharged=charged;
    ptr->diff=difference;
    ptr->username=pointer;
    ptr->lastname=ointer;
    return ptr;
}

typedef struct Record {
    int id;
    int arrcharging;
    int gocharging;
    int money;
    char* username;
    char* lastname;


    // Add more fields as needed
} Record;

// Structure to represent a node in the BST
typedef struct Hero {
    Record data;
    struct Hero* left;
    struct Hero* right;
} Hero;

// Function to create a new node
Hero* createNode(Record data) {
    Hero* newNode = (Hero*)malloc(sizeof(Hero));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a record into the BST
Hero* insert(Hero* root, Record data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data.id < root->data.id) {
        root->left = insert(root->left, data);
    } else if (data.id > root->data.id) {
        root->right = insert(root->right, data);
    }
    return root;
}
Hero* findMinimum(Hero* node) {
    Hero* current = node;

    while (current && current->left != NULL) {
        current = current->left;
    }

    return current;
}
Hero* deleteNode(Hero* root, int id) {
    if (root == NULL) {
        return root; // Empty tree, nothing to delete
    }

    // Search for the node with the specified ID
    if (id < root->data.id) {
        root->left = deleteNode(root->left, id);
    } else if (id > root->data.id) {
        root->right = deleteNode(root->right, id);
    } else {
        // Node with the specified ID found
        if (root->left == NULL) {
            Hero* temp = root->right;
            free(root);
            return temp;
        } else if (root->right == NULL) {
            Hero* temp = root->left;
            free(root);
            return temp;
        }

        // Node has two children
        Hero* temp = findMinimum(root->right); // Find the minimum node in the right subtree
        root->data = temp->data; // Copy the data of the minimum node
        root->right = deleteNode(root->right, temp->data.id); // Delete the minimum node
    }

    return root; // Return the updated tree
}

// Function to delete a record from the BST by ID





// Function to display the contents of the database
void displayDatabase(Hero* root) {
    if (root != NULL) {
        displayDatabase(root->left);
        printf("ID: %d, User: %s %s, ArrivalC: %d, DepartureC: %d, Charges:Rs. %d\n ", root->data.id,root->data.username,root->data.lastname, root->data.arrcharging,root->data.gocharging, (root->data.gocharging,root->data.gocharging-root->data.arrcharging)*17);
        displayDatabase(root->right);
    }
}

int arrayfullhigh(Node* arr[]){
    if ((arr[0] != NULL) && (arr[2] != NULL) && (arr[4] != NULL))
    {
        return 0;
    } else {
        return 1;
    }
}
// Function to search for a node in the BST by ID
Hero* searchNode(Hero* root, int id) {
    if (root == NULL || root->data.id == id) {
        return root;
    }

    if (id < root->data.id) {
        return searchNode(root->left, id); // Search in the left subtree
    } else {
        return searchNode(root->right, id); // Search in the right subtree
    }
}

int arrayfulllow(Node* arr[]){
       if ((arr[1] != NULL) && (arr[3] != NULL))
    {
        return 0;
    } else {
        return 1;
    }
}



    


#endif
<<<<<<< HEAD
=======
#ifndef __P_H__
#define __P_H__




typedef struct EV_user{ 
    char* lastname; //
    char* username;//
    int charging;//
    int timing; //not using this
    int tobecharged;//
    int diff;//

}EV;
//
typedef struct Node {
    int data; //not needed
    int chargingtime;////////////////////Not needed
    int priority;
    struct Node* next;
    EV* ev;
    char* username;//////////////////////////not needed
    char* lastname;////////not needed

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
 


}Station;

// Adds a new element with the given data and priority to the queue
void enqueue(PriorityQueue* queue,int data,int timing,int priority, EV* ptr) {
    Node* new_node = (Node*)malloc(sizeof(Node));
   
    
    new_node->data=data;
    new_node->priority = priority;
    new_node->ev=ptr;
    new_node->chargingtime=timing;

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
    printf("\nThe user named %s %s with charging of ev %d has been added to the queue\n",ptr->username, ptr->lastname,ptr->charging);
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
        printf("\nThe user named %s %s with charging of ev %d has been removed from the queue\n",evv->username,evv->lastname, evv->charging);
        //free(dequeued_node);
       
        return dequeued_node;
    }
}



int traverse(PriorityQueue* queue) {  //charging count

    int count = 0;
    if (queue->head == NULL) {
        return count;
    } else {
        Node* temp = queue->head;
        while (temp != NULL) {
            count += temp->ev->diff;
            temp = temp->next;
        }
        return count;
    }
} //to calculate the charging every vehicle want to do

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



EV* initEV( int charge, int charged, int difference, EV* ptr, char* pointer, char* ointer){

    ptr->charging=charge;
    //ptr->timing=time;
    ptr->tobecharged=charged;
    ptr->diff=difference;
    ptr->username=pointer;
    ptr->lastname=ointer;
    return ptr;
}

typedef struct Record {
    int id;
    int arrcharging;
    int gocharging;
    int money;
    char* username;
    char* lastname;


    // Add more fields as needed
} Record;

// Structure to represent a node in the BST
typedef struct Hero {
    Record data;
    struct Hero* left;
    struct Hero* right;
} Hero;

// Function to create a new node
Hero* createNode(Record data) {
    Hero* newNode = (Hero*)malloc(sizeof(Hero));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

// Function to insert a record into the BST
Hero* insert(Hero* root, Record data) {
    if (root == NULL) {
        return createNode(data);
    } else if (data.id < root->data.id) {
        root->left = insert(root->left, data);
    } else if (data.id > root->data.id) {
        root->right = insert(root->right, data);
    }
    return root;
}


// Function to search for a record in the BST
// Hero* search(Hero* root, int id) {
//     if (root == NULL || root->data.id == id) {
//         return root;
//     } else if (id < root->data.id) {
//         return search(root->left, id);
//     } else {
//         return search(root->right, id);
//     }
// }

// Function to display the contents of the database
void displayDatabase(Hero* root) {
    if (root != NULL) {
        displayDatabase(root->left);
        printf("ID: %d, User: %s %s, ArrivalC: %d, DepartureC: %d, Charges:Rs. %d\n ", root->data.id,root->data.username,root->data.lastname, root->data.arrcharging,root->data.gocharging, (root->data.gocharging,root->data.gocharging-root->data.arrcharging)*17);
        displayDatabase(root->right);
    }
}

int arrayfullhigh(Node* arr[]){
    if ((arr[0] != NULL) && (arr[2] != NULL) && (arr[4] != NULL))
    {
        return 0;
    } else {
        return 1;
    }
}
int arrayfulllow(Node* arr[]){
       if ((arr[1] != NULL) && (arr[3] != NULL))
    {
        return 0;
    } else {
        return 1;
    }
}

    


#endif
>>>>>>> 1c88e7cd6fc13d15274f8ee924be75604995d3c0
=======
>>>>>>> Pranav
