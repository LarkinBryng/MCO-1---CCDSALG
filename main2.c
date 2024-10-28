#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

// Prototype for the Graham Scan function
void grahamScan(Point points[], int n);

int main() {
    char input_filename[50], output_filename[50];
    printf("Enter the input file name: ");
    scanf("%s", input_filename);  // Input the file name for reading

    printf("Enter the output file name: ");
    scanf("%s", output_filename);  // Input the file name for writing

    // Open the input file
    FILE *input_file = fopen(input_filename, "r");
    if (input_file == NULL) {
        printf("Error: Could not open input file!\n");
        return 1;
    }

    // Read the number of points
    int n;
    fscanf(input_file, "%d", &n);

    // Allocate memory for the points
    Point *points = (Point *)malloc(n * sizeof(Point));
    if (points == NULL) {
        printf("Memory allocation failed!\n");
        fclose(input_file);
        return 1;
    }

    // Read the points (x, y) from the file
    for (int i = 0; i < n; i++) {
        fscanf(input_file, "%lf %lf", &points[i].x, &points[i].y);
    }

    // Close the input file
    fclose(input_file);

    // Call Graham's Scan to compute the convex hull
    grahamScan(points, n);

    // Free dynamically allocated memory
    free(points);

    return 0;
}
