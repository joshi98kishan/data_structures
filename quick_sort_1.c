//Quick Sort
#include<stdio.h>

void swap(int*, int*);
int partition(int[], int, int);
void qsort(int[], int, int);
void display(int[]);

int main(){
	int arr[] = {7,6,5,8,9,1,2,3,4};
	int SIZE = 9;
	display(arr);
	qsort(arr, 0, SIZE-1);
	display(arr);
	
}

void swap(int* x, int* y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

void qsort(int arr[], int lo, int hi){
	if(lo < hi){
		int p;
		p = partition(arr, lo, hi);
		qsort(arr, lo, p-1);
		qsort(arr, p+1, hi);
	}
}

int partition(int arr[], int lo, int hi){
	int pivot = arr[lo];
	int i = lo+1;
	int j = hi;
	
	while(i <= j){
		while(i <= j && arr[i] <= pivot){i++;}
		while(i <= j && arr[j] >= pivot){j--;}
		
		if(i < j){
			swap(&arr[i], &arr[j]);
			display(arr);
		}
	}	
	swap(&arr[lo], &arr[j]);
	display(arr);
	return j;
}
void display(int arr[]){
	for(int k = 0; k < 9; k++){
		printf("%d\t", arr[k]);
	}
	printf("\n");
}
