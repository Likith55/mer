#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 500000

int a[MAX];

void merge(int low, int mid, int high) {
    int i, j, k;
    int b[MAX];  // Temporary array
    i = low;
    j = mid + 1;
    k = low;

    // Merge the two halves into temporary array b[]
    while (i <= mid && j <= high) {
        if (a[i] <= a[j]) {
            b[k++] = a[i++];
        } else {
            b[k++] = a[j++];
        }
    }

    // Copy the remaining elements of the first half, if any
    while (i <= mid) {
        b[k++] = a[i++];
    }

    // Copy the remaining elements of the second half, if any
    while (j <= high) {
        b[k++] = a[j++];
    }

    // Copy the sorted elements back into original array a[]
    for (i = low; i <= high; i++) {
        a[i] = b[i];
    }
}

void merge_sort(int low, int high) {
    if (low < high) {
        int mid = (low + high) / 2;

        // Recursively sort the first and second halves
        merge_sort(low, mid);
        merge_sort(mid + 1, high);

        // Merge the sorted halves
        merge(low, mid, high);
    }
}

int main() {
    int n, i;
    double clk;
    clock_t starttime, endtime;

    printf("MERGE SORT\n");
    printf("Enter the number of employee records (max %d):\n", MAX);
    scanf("%d", &n);

    if (n > MAX) {
        printf("Number of records exceeds the maximum limit of %d.\n", MAX);
        return 1;
    }

    printf("The Employee IDs are:\n");
    for (i = 0; i < n; i++) {
        a[i] = rand() % 100;  // Generating random employee IDs
        printf("%d\t", a[i]);
    }
    printf("\n");

    starttime = clock();
    merge_sort(0, n - 1);
    endtime = clock();

    clk = (double)(endtime - starttime) / CLOCKS_PER_SEC;

    printf("Employee IDs in sorted order:\n");
    for (i = 0; i < n; i++) {
        printf("%d\t", a[i]);
    }
    printf("\nThe run time is %f seconds\n", clk);

    return 0;
}
