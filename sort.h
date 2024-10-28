#ifndef SORT_H
#define SORT_H

typedef struct {
    double x, y;
} Point;

// Function prototypes
void bubbleSort(Point points[], int n, Point anchor);
void mergeSort(Point points[], int low, int high, Point anchor);
double polarAngle(Point p0, Point p1);
double distance(Point p0, Point p1);

#endif
