#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "stack.h"
#include "sort.h"

#define SWAP(a, b) { Point temp = a; a = b; b = temp; }


// Function to determine orientation
int orientation(Point a, Point b, Point c) {
    double cross_product = (b.y - a.y) * (c.x - b.x) - (b.x - a.x) * (c.y - b.y);
    if (cross_product > 0) return 1;   // Counterclockwise
    if (cross_product < 0) return -1;  // Clockwise
    return 0;                          // Collinear
}

// Graham's Scan Algorithm (Slow - using Bubble Sort)
void grahamScan(Point points[], int n) {
    Stack s;
    create(&s);

    // Step 1: Find the anchor point (minimum y-coordinate, or minimum x if tie)
    Point anchor = points[0];
    int anchorIdx = 0;
    for (int i = 1; i < n; i++) {
        if (points[i].y < anchor.y || (points[i].y == anchor.y && points[i].x < anchor.x)) {
            anchor = points[i];
            anchorIdx = i;
        }
    }

    // Swap anchor to the first position
    SWAP(points[0], points[anchorIdx]);

    // Step 2: Sort points by polar angle using bubble sort
    bubbleSort(points + 1, n - 1, anchor);

    // Step 3: Process points for convex hull
    push(&s, points[0].x, points[0].y);
    push(&s, points[1].x, points[1].y);
    push(&s, points[2].x, points[2].y);

    for (int i = 3; i < n; i++) {
        double x1, y1, x2, y2;
        pop(&s, &x1, &y1); 
        top(&s, &x2, &y2);
        while (orientation((Point){x2, y2}, (Point){x1, y1}, points[i]) != 2) {
            pop(&s, &x1, &y1);
            top(&s, &x2, &y2);
        }
        push(&s, x1, y1);
        push(&s, points[i].x, points[i].y);
    }

    // Write the output (Convex Hull)
    FILE *output_file = fopen("output.txt", "w");
    fprintf(output_file, "%d\n", s.top + 1);
    for (int i = 0; i <= s.top; i++) {
        fprintf(output_file, "%.6lf %.6lf\n", s.x[i], s.y[i]);
    }
    fclose(output_file);
}

int main() {
    clock_t start, end;
    start = clock();

    // Read input
    FILE *input_file = fopen("input.txt", "r");
    int n;
    fscanf(input_file, "%d", &n);

    Point points[n];
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%lf %lf", &points[i].x, &points[i].y);
    }
    fclose(input_file);

    grahamScan(points, n);

    end = clock();
    printf("Elapsed time: %lf ms\n", ((double)(end - start) * 1000) / CLOCKS_PER_SEC);
    return 0;
}
