#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 32768

typedef struct {
    int top;
    double x[MAX_SIZE], y[MAX_SIZE];
} Stack;

// Stack Operations
void create(Stack *s);
void push(Stack *s, double x, double y);
void pop(Stack *s, double *x, double *y);
void top(Stack *s, double *x, double *y);
void nextToTop(Stack *s, double *x, double *y);
int isFull(Stack *s);
int isEmpty(Stack *s);

#endif
