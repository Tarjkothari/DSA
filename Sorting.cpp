#include <stdio.h>

void selectionSort(int arr[], int n) {
    int i, j, minIndex, temp;

    for (i = 0; i < n - 1; i++) {

        minIndex = i;
        for (j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }

        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}

void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {

            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
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
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
    	
        int m = l + (r - l) / 2;

        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}


int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;

    for (int j = low; j <= high - 1; j++) {

        if (arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }

    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;

    return i + 1;
}

void quickSort(int arr[], int low, int high) {
    if (low < high) {
    	
        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}



void printArray(int arr[], int size) {
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int main() {
    int arr[5],i,select,n,arr_size;
    for(i=0;i<5;i++)
    	{
    		printf("Enter the %d Element : ",i);
    		scanf("%d",&arr[i]);
		}
    do
    {
    	printf("\nMenu:\n");
    	printf("1. Selection Sort\n");
    	printf("2. Bubble Sort\n");
    	printf("3. Merge Sort\n");
    	printf("4. Quick Sort\n");
    
    	printf("Enter your Choise : ");
    	scanf("%d",&select);
    
		switch(select)
		{
			case 1: 
					n = sizeof(arr) / sizeof(arr[0]);
    				printf("Original array: \n");
    				printArray(arr, n);
    				selectionSort(arr, n);
    				printf("Sorted array by Selection Sort Method: \n");
    				printArray(arr, n);    			
    				break;
    		case 2:
    				n = sizeof(arr) / sizeof(arr[0]);
    				printf("Unsorted array: \n");
    				printArray(arr, n);
    				bubbleSort(arr, n);
    				printf("Sorted array by Booble Short Method: \n");
    				printArray(arr, n);    		
    				break;
    		case 3 :
    				arr_size = sizeof(arr) / sizeof(arr[0]);
    				printf("Given array is \n");
    				printArray(arr, arr_size);
    				mergeSort(arr, 0, arr_size - 1);
    				printf("\nSorted array by Merge Sort method: \n");
    				printArray(arr, arr_size);    		
    				break;
    		case 4 :
    				n = sizeof(arr) / sizeof(arr[0]);
    				printf("Original array: ");
    				printArray(arr, n);
    				quickSort(arr, 0, n - 1);
    				printf("Sorted array by Quick Sort Method: ");
    				printArray(arr, n);    		
    				break;
		}
	}while(select<5);
    return 0;
}
