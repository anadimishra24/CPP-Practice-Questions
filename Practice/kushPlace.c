/*#include <stdio.h>

int maximumInPlace(int A_count, int* A) {
    int sortedA[A_count];
    for (int i = 0; i < A_count; i++) {
        sortedA[i] = A[i];
    }

    // for (int i = 0; i < A_count; i++) {
    //     for (int j = i + 1; j < A_count; j++) {
    //         if (sortedA[j] > sortedA[i]) {
    //             int temp = sortedA[i];
    //             sortedA[i] = sortedA[j];
    //             sortedA[j] = temp;
    //         }
    //     }
    // }

            int i=0,j=0;
            while( i < A_count && j < A_count ){
                if (sortedA[j] > sortedA[i]) {
                    int temp = sortedA[i];
                    sortedA[i] = sortedA[j];
                    sortedA[j] = temp;
                }
                else{
                    i++;
                    j = i+1;
                }
            }
    

    int count = 0;
    int f = 0;
    while(f < A_count){
        if (A[f] == sortedA[f]) {
            count++;
        }
        f++;
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int result = maximumInPlace(n, A);
    printf("%d\n", result);

    return 0;
}

*/



#include <stdio.h>

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] >= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int maximumInPlace(int A_count, int* A) {
    int sortedA[A_count];
    for (int i = 0; i < A_count; i++) {
        sortedA[i] = A[i];
    }

    mergeSort(sortedA, 0, A_count - 1);

    int count = 0;
    int f = 0;
    while (f < A_count) {
        if (A[f] == sortedA[f]) {
            count++;
        }
        f++;
    }

    return count;
}

int main() {
    int n;
    scanf("%d", &n);

    int A[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &A[i]);
    }

    int result = maximumInPlace(n, A);
    printf("%d\n", result);

    return 0;
}
