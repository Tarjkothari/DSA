#include <stdio.h>

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target) {
            return mid;
        }

        if (arr[mid] < target) {
            left = mid + 1;
        }
        
        else {
            right = mid - 1;
        }
    }

    return -1;
}

int sequentialSearch(int arr[], int n, int target) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == target) {
            return i;
        }
    }
    return -1;
}

int main() {
    int arr[6],i,choice;
    
    printf("\n Enter the elements into the array \n");
    for(i=0;i<6;i++)
    {
    	printf("\n Enter the element at index %d \t",i);
    	scanf("\n %d",&arr[i]);
	}
    
    int n = sizeof(arr) / sizeof(arr[0]);
    int target,result,ans;
    
    do
    {
    	printf("\n Enter your Choice for the search : \n Press 1 For : Sequential Search \n Press 2 For : Binary Search \t");
    	scanf("\n %d",&choice);
    
    
    	switch(choice)
    	{
    		case 1:
    			printf("\n Enter the element to search \t");
    			scanf("%d",&target);
				    		
    			result = sequentialSearch(arr, n, target);
				
    			if (result != -1) 
				{
	        		printf("Element %d found at index %d.\n", target, result);
    			} 
				else 
				{
	        		printf("Element %d not found in the array.\n", target);
    			}
    			break;
    		
    		case 2:
				printf("\n Enter the element to search \t");
    			scanf("%d",&target);
				
    			result = binarySearch(arr, 0, n - 1, target);
	
    			if (result == -1) 
				{
        			printf("\n Element not found in the array\n");
    			} 
				else 
				{
        			printf("\n Element found at index %d\n", result);
    			}
    			break;
		}
		printf("Do you want to continue the search ? \n (Press 1 : YES   Press 0 : NO) : \t");
		scanf("\n%d",&ans);
	}while(ans == 1);
    return 0;
}

