#include "stack.h" 
#include <stdio.h>

// Function to create the stack
void create(Stack *s) {
    s->top = -1; //index -1 means the stack array is still empty
}

// Function to push an element onto the stack
void push(Stack *s, double x, double y) {
    if (s->top < MAX_SIZE - 1) {  // Check if the stack is not full
        s->top++;
        s->x[s->top] = x;
        s->y[s->top] = y;
    } else {
        printf("Stack is full, cannot push element.\n");
    }
}

// Function to pop an element from the stack
void pop(Stack *s, double *x, double *y) {
    if (s->top >= 0) {  // Check if the stack is not empty
        *x = s->x[s->top];
        *y = s->y[s->top];
        s->top--;
    } else {
        printf("Stack is empty, cannot pop element.\n");
    }
}

// Function to get the top element without popping it
void top(Stack *s, double *x, double *y) {
    if (s->top >= 0) {  // Check if the stack is not empty
        *x = s->x[s->top];
        *y = s->y[s->top];
    } else {
        printf("Stack is empty, no top element.\n");
    }
}

// Function to get the element below the top (next-to-top)
void nextToTop(Stack *s, double *x, double *y) {
    if (s->top > 0) {  // Ensure there is more than one element in the stack
        *x = s->x[s->top - 1];
        *y = s->y[s->top - 1];
    } else {
        printf("Stack does not have enough elements for next-to-top.\n");
    }
}

// Check if the stack is full
int isFull(Stack *s) {
    return s->top == MAX_SIZE - 1;
}

// Check if the stack is empty
int isEmpty(Stack *s) {
    return s->top == -1;
}
