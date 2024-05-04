// C program for implementation of selection sort
#include <stdio.h>


//Function to swap two element
void swap(int *xp, int *yp){
	int temp = *xp;
	*xp = *yp;
	*yp = temp;
}

/* 1. Selection Sort

void selectionSort(int arr[], int n)
{
    int min = 0;

    for (int i = 0; i < n-1; i++){
        min = i;
        for (int j = i+1; j < n; j++){
            if(arr[min] > arr[j]){
                min = j;
            }            
        }
       swap(&arr[min], &arr[i]);
    } 
}
*/

/* 2. Bubble Sort

void bubbleSort(int arr[], int n){

    for (int i = 1; i < n; i++){

        for (int j = 0; j < n-i; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    } 
}
*/

/* 3. *Insertion Sort 
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        // Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}
*/

/* 4. Quick Sort

int partition(int arr[], int start, int end){
    
    // Step 1: Make first element of array as pivot 
    int pivot = arr[start];

    // Step 2: Count the number of smaller element from pivot element
    int count = 0;
    for(int i = start+1; i <= end; i++){
        if(arr[i] <= pivot){
            count++;  
        }
    }
    
    // place pivot at right position
    int pivotIndx = start + count;

    // Swap the pivot element with the element at pivotIndex
    swap(&arr[start], &arr[pivotIndx]);

    int i = start, j = end;
    while(i < pivotIndx && j > pivotIndx){
        while (arr[i] < pivot){
            i++;
        }

        while (arr[j] > pivot){
            j--;
        }
        
        if(i < pivotIndx && j > pivotIndx){
            swap(&arr[i++], &arr[j--]);
        }
    }

    return pivotIndx;
}

void quickSort(int arr[], int start, int end){

    // base case
    if(start > end){
        return;
    }

    // partition
    int p = partition(arr, start, end);

    // recursive call for left array
    quickSort(arr, start, p-1);

    // recursive call for right array
    quickSort(arr, p+1, end);
}
*/

/* 5. Merge Sort

void merge(int arr[], int start, int mid, int end) {

    // Step 1: declare size of temporary arrays
    int Lsize = mid - start + 1;
    int Rsize = end - mid;

    // Step 2: create temporary arrays
    int left[Lsize];
    int right[Rsize];

    // Step 3: copy the data into temporary arrays
    for (int i = 0; i < Lsize; i++) {
        left[i] = arr[start + i];
    }

    for (int j = 0; j < Rsize; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Step 4: merge both the temporary arrays back into arr
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = start; // Initial index of merged subarray

    while (i < Lsize && j < Rsize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Copy the remaining elements of left[] if any
    while (i < Lsize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Copy the remaining elements of right[] if any
    while (j < Rsize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}


void mergeSort(int arr[], int start, int end){

    // base case
    if(start == end){
        return;
    }

    // get the mid of array
    int mid = (start + end)/2;

    // recursive call for left array
    mergeSort(arr, start, mid);

    // recursive call for right array
    mergeSort(arr, mid+1, end);

    // merge the both left and right array
    merge(arr, start, mid, end);
}
*/

/* Function to print an array */
void printArray(int arr[], int size)
{
	int i;
	for (i=0; i < size; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

// Driver program to test above functions
int main()
{
	int arr[] = {64, 25, 12, 29, 11};
	int n = sizeof(arr)/sizeof(arr[0]);

/* 1. SelectionSort
	selectionSort(arr, n);
	printf("Sorted array using selection sort: \n");
	printArray(arr, n);
*/

/* 2. Bubble Sort  
    bubbleSort(arr, n);
    printf("Sorted array using bubble sort: \n");
	printArray(arr, n);
*/

/* 3. Bubble Sort  
    bubbleSort(arr, n);
    printf("Sorted array using bubble sort: \n");
	printArray(arr, n);
*/

/* 4. Insertion Sort  
    insertionSort(arr, n);
    printf("Sorted array using insertion sort: \n");
	printArray(arr, n);
*/

/* 5. Quick Sort  
    quickSort(arr, 0, n-1);
    printf("Sorted array using quick sort: \n");
	printArray(arr, n);
*/

/* 6. Merge Sort  
    mergeSort(arr, 0, n-1);
    printf("Sorted array using merge sort: \n");
	printArray(arr, n);
*/

    return 0;
}
