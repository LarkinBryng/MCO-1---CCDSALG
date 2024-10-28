#include "sort.h"
#include <math.h>

#define SWAP(a, b) { Point temp = a; a = b; b = temp; }

// Function to calculate polar angle with respect to anchor
double polarAngle(Point p0, Point p1) {
    return atan2(p1.y - p0.y, p1.x - p0.x);
}

double distance(Point p0, Point p1) {
    return (p1.x - p0.x) * (p1.x - p0.x) + (p1.y - p0.y) * (p1.y - p0.y);
}

// Bubble Sort
void bubbleSort(Point points[], int n, Point anchor) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (polarAngle(anchor, points[j]) > polarAngle(anchor, points[j + 1])) {
                SWAP(points[j], points[j + 1]);
            }
        }
    }
}

// Merge combines two sorted subarrays into one
void merge(Point points[], int low, int mid, int high, Point anchor) {
    int n1 = mid - low + 1, n2 = high - mid;
    Point L[n1], R[n2]; // n1 for left half, n2 for right half

    for (int i = 0; i < n1; i++){
        L[i] = points[low + i]; // copy elements to left side 
    }
    for (int i = 0; i < n2; i++){
        R[i] = points[mid + 1 + i]; // copy elements to right side
    } 

    int i = 0, j = 0, k = low;
    while (i < n1 && j < n2) {
        if (polarAngle(anchor, L[i]) <= polarAngle(anchor, R[j])) {
            points[k++] = L[i++];
        } else {
            points[k++] = R[j++];
        }
    }

    while (i < n1) points[k++] = L[i++];
    while (j < n2) points[k++] = R[j++];
}

// Merge Sort
void mergeSort(Point points[], int low, int high, Point anchor) {
    if (low < high) {
        int mid = (low + high) / 2;
        mergeSort(points, low, mid, anchor); // Sorts first half
        mergeSort(points, mid + 1, high, anchor); // Sorts second half
        merge(points, low, mid, high, anchor); // Merge the two halves
    } 
}
