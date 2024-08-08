#include <bits/stdc++.h>
using namespace std;


/* 1. Bubble Sort */
void bubbleSort(vector<int> arr, int size){
    cout << "\n1. Bubble Sort Algorithm\n";
    bool isSort;
    for (int i = 0; i < size-1; i++){
        isSort = false;
        for (int j = 0; j < size - 1 - i; j++){
            if(arr[j] > arr[j+1]){
                swap(arr[j],arr[j+1]);
                isSort = true;
            }
        }
        // swap does not perform a means array is sorted break the 'j' loop.
        if(!isSort){
            break;
        }
        
    }
    cout << "Array after sort: " ;
    for(auto n: arr){
        cout << n << " ";
    }
    
}

/* 2. Selection Sort */
void selectionSort(vector<int> arr, int size){
    cout << "\n\n2. Selection Sort Algorithm\n";
    
    int min_indx;
    for (int i = 0; i < size; i++){
        min_indx = i;
        for (int j = i+1; j < size; j++){
            if(arr[j] < arr[min_indx]){
                min_indx = j;
            }
        }
        // get the minimum index, now swap i and min_indx
        swap(arr[i],arr[min_indx]);
    }
    cout << "Array after sort: " ;
    for(auto n: arr){
        cout << n << " ";
    }
    
}

/* 3. Insertion Sort */
void insertionSort(vector<int> arr, int size){
    cout << "\n\n3. Insertion Sort Algorithm\n";
    
    int min = 0;
    for (int i = 1; i < size; i++){
        min = arr[i];
        int j = i - 1;
        while(j >= 0){
            if(arr[j] > min){
                // shift the array element to one place
                arr[j+1] = arr[j];
            }
            else{
                // array is sorted
                break;
            }
            j--;
        }
        arr[j+1] = min;
    }
    cout << "Array after sort: " ;
    for(auto n: arr){
        cout << n << " ";
    } 
}

/* Merge Sort */
void merge(vector<int>& arr, int start, int mid, int end) {
    // Step 1: Calculate the sizes of the temporary arrays
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    // Step 2: Create temporary arrays to store both halves of arr
    vector<int> left(leftSize);
    vector<int> right(rightSize);

    // Step 3: Copy the data into temporary arrays
    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[start + i];
    }
    for (int j = 0; j < rightSize; j++) {
        right[j] = arr[mid + 1 + j];
    }

    // Step 4: Merge both temporary arrays back into arr
    int i = 0; // Initial index of left subarray
    int j = 0; // Initial index of right subarray
    int k = start; // Initial index of merged subarray

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    // Step 5: Copy the remaining elements of left[] if any
    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    // Step 6: Copy the remaining elements of right[] if any
    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergeSort(vector<int>& arr, int start, int end) {
    // Base case
    if (start >= end) {
        return;
    }

    int mid = start + (end - start) / 2;

    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);

    // Merge both halves of the array
    merge(arr, start, mid, end);
}

/* 5. Quick Sort */
int partition(vector<int>&arr, int start, int end){
    // first element as pivot
    int pivot = arr[start];

    // count the element smaller than pivot
    int count = 0;
    for (int i = start+1; i <= end; i++){
        if(arr[i] <= pivot){
            count++;
        }
    }

    // get the index of pivot element
    int pivotIndx = count + start;

    // place the pivot at right index
    swap(arr[start], arr[pivotIndx]);

    // arrange the left and right of array as [ele <= pivot <= ele]
    while(start < pivotIndx && end > pivotIndx){
        while(arr[start] <= pivot){
            start++;
        }
        while(arr[end] > pivot){
            end--;
        }
        if(start < pivotIndx && end > pivotIndx){
            swap(arr[start++], arr[end--]);
        }
    }
    return pivotIndx;
}


void quickSort(vector<int>& arr, int start, int end){    
      // base case
    if(start > end){
        return;
    }
    
    int pivotIndx = partition(arr, start, end);

     // `arr` is a copy of the original vector
    quickSort(arr, start, pivotIndx-1);
    quickSort(arr, pivotIndx+1, end);   
}



int main(){

    vector<int> arr = {10, 4, 9, 4, 1, 5};

    int size = arr.size();
    cout << "Size  == " << size << endl;

    cout << "Array: " ;
    for(auto n: arr){
        cout << n << " ";
    }
    cout << endl;

    // call the bubble sort
    bubbleSort(arr, size);

    // call the selection sort
    selectionSort(arr, size);

    // call the insertion sort
    insertionSort(arr,size);

    // call the quick start
    cout << "\n\n4. Quick Sort Algorithm\n";
    quickSort(arr, 0, size-1);
    cout << "Array: " ;
    for(auto q: arr){
        cout << q << " ";
    }

    // new arr for merge sort
    vector<int> brr = {10, 4, 9, 4, 1, 5};

    int bSize = brr.size();
    // call the merge sort
    cout << "\n\n4. Merge Sort Algorithm\n";
    mergeSort(brr, 0, bSize-1);
    cout << "Array: ";
    for(auto m: brr){
        cout << m << " ";
    }

    return 0;
}