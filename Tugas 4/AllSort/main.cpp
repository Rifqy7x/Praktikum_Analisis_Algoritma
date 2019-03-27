/*
Nama    : Muhammad Rifqy Aulia Akbar
NPM     : 140810160055
*/

#include <math.h>
#include <stdio.h>
#include <algorithm>
#include <chrono>
#include <iostream>
#include<stdlib.h>
using namespace std;
using namespace std::chrono;


void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void selectionSort(int arr[], int n)
{
    int i, j, min_idx;

    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;

        // Swap the found minimum element with the first element
        swap(&arr[min_idx], &arr[i]);
    }
}

// A function to implement bubble sort
void bubbleSort(int arr[], int n)
{
   int i, j;
   for (i = 0; i < n-1; i++)

       // Last i elements are already in place
       for (j = 0; j < n-i-1; j++)
           if (arr[j] > arr[j+1])
              swap(&arr[j], &arr[j+1]);
}

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);

        merge(arr, l, m, r);
    }
}

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        /* Move elements of arr[0..i-1], that are
          greater than key, to one position ahead
          of their current position */
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// A utility function to print an array of size n
void printArray(int arr[], int n)
{
    int i;
    for (i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void startcek(int arr[], int n){

    auto start = high_resolution_clock::now();
    bubbleSort(arr, n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout << "Lama waktu bubble sort untuk "<<n<<" data\t\t: "
         << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    insertionSort(arr, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Lama waktu insertion sort untuk "<<n<<" data\t: "
         << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    mergeSort(arr,0, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Lama waktu merge sort untuk "<<n<<" data\t\t: "
         << duration.count() << " microseconds" << endl;

    start = high_resolution_clock::now();
    selectionSort(arr, n);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    cout << "Lama waktu selection sort untuk "<<n<<" data\t: "
         << duration.count() << " microseconds" << endl <<endl;

}

/* Driver program to test insertion sort */
int main()
{
    int arr1[60000];
	int n = sizeof(arr1) / sizeof(arr1[0]);
	for(int i = n; i>=0; i--)
        arr1[i] = i;
	startcek(arr1,n);

    int arr2[70000];
	n = sizeof(arr2) / sizeof(arr2[0]);
	for(int i = n; i>=0; i--)
        arr2[i] = i;
	startcek(arr2,n);

    int arr3[80000];
	n = sizeof(arr3) / sizeof(arr3[0]);
	for(int i = n; i>=0; i--)
        arr3[i] = i;
	startcek(arr3,n);

    int arr4[90000];
	n = sizeof(arr4) / sizeof(arr4[0]);
	for(int i = n; i>=0; i--)
        arr4[i] = i;
	startcek(arr4,n);

    int arr5[100000];
	n = sizeof(arr5) / sizeof(arr5[0]);
	for(int i = n; i>=0; i--)
        arr5[i] = i;
	startcek(arr5,n);

    return 0;
}
