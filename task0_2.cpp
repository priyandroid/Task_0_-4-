// C implementation of QuickSort 
#include<iostream> 
#include<stdlib.h>

using namespace std;

// A utility function to swap two elements 
void swap(int* a, int* b) 
{ 
    int t = *a; 
    *a = *b; 
    *b = t; 
} 

/* This function takes last element as pivot and then 
divide the array in smaller subparts by returning index
about which array will be divided*/
int partition (int *arr, int low, int high) 
{ 
	int pivot = arr[high]; // pivot 
	int i = (low - 1); // Index of smaller element 

	for (int j = low; j <= high- 1; j++) 
	{ 
		// If current element is smaller than or 
		// equal to pivot 
		if (arr[j] <= pivot) 
		{ 
			i++; // increment index of smaller element 
			swap(&arr[i], &arr[j]); 
		} 
	} 
	swap(&arr[i + 1], &arr[high]); 
	return (i + 1); 
} 

/*Function to implement QuickSort 
*arr is Array to be sorted, 
low is Starting index, 
high is Ending index */
void quickSort(int *arr, int low, int high) 
{ 
	if (low < high) 
	{ 
		int p = partition(arr, low, high); 
		quickSort(arr, low, p - 1); 
		quickSort(arr, p + 1, high); 
	} 
} 

/* Function to print an array */
void printArray(int *arr, int size) 
{ 
	int i; 
	for (i=0; i < size; i++) 
		cout<<arr[i]<<' ';
	cout<<"\n";
} 

int main() 
{ 
	int *arr,n;
    cout<<"Enter the size of array";
    cin>>n;
    arr=(int*)malloc(sizeof(int)*n);
    cout<<"Enter the array";
    for(int i=0; i<n; i++)
      cin>>arr[i];
    system("clear");
	quickSort(arr, 0, n-1); 
	printf("Sorted array: \n"); 
	printArray(arr, n); 
	return 0; 
} 
