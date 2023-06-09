#include "total.h"

struct Queue *createQueue() {
    struct Queue *queue = malloc(sizeof(struct Queue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

// Function to check if the queue is empty
int empty(struct Queue *queue) {
    return (queue->front == NULL);
}

// Function to add an element to the rear of the queue
void enqueue(struct Queue *queue, char re_name[], char book_name[]) {
    struct history *newNode = malloc(sizeof(struct history));
    strcpy(newNode->re_name, re_name);
    strcpy(newNode->book_name, book_name);

    // If the queue is empty, make the new node both the front and rear
    if (empty(queue)) {
        queue->front = newNode;
        queue->rear = newNode;
    } else {
        // Otherwise, add the new node to the rear and update the rear pointer
        queue->rear->next = newNode;
        queue->rear = newNode;
    }
}

// Function to remove an element from the front of the queue
void dequeue(struct Queue* queue) {
    // If the queue is empty
    if (empty(queue)) 
    {
        printf("Error: Queue is empty.\n");
    }

    // Store the front node
    struct history *frontNode = queue->front;

    // Move the front pointer to the next node
    queue->front = queue->front->next;

    // If the front becomes NULL, update the rear pointer as well
    if (queue->front == NULL) 
    {
        queue->rear = NULL;
    }

    // Free the memory occupied by the dequeued node
    free(frontNode);
}