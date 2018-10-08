//MERGE SORT
#include<stdio.h>
#define SIZE 10

int arr[] = {15,84,96,32,32,32,88,11,20,20};
int brr[SIZE];
void msort(int, int);
void merge(int, int, int);
void display();

int main(){
		msort(0, SIZE-1);
		display();
		printf("\n");
}

void msort(int start, int end){
	if(start != end){
		int mid = (start+end)/2;
		printf("Start = %d\t mid = %d\t end = %d\n", start, mid, end);
		msort(start, mid);
		msort(mid+1, end);
		merge(start, mid, end);
	}
}

void merge(int start, int mid, int end){
	int i = start;
	int j = mid+1;
	int k = start;
	while(i <= mid && j <= end){
		if(arr[i] < arr[j]){
			brr[k] = arr[i];
			k++;	i++;
		}
		else if(arr[i] > arr[j]){
			brr[k] = arr[j];
			k++;	j++;
		}
		else{
			brr[k] = brr[k+1] = arr[i];
			k+=2;	i++;	j++;
		}
	}
		if(i > mid){
			while(j <= end){
				brr[k] = arr[j]; j++; k++;
			}
		}
		if(j > end){
			while(i <= mid){
				brr[k] = arr[i]; i++; k++;
			}
		}
	for(int m = start; m <= end; m++){
		arr[m] = brr[m];
	}
}

void display(){

	printf("\nARRAY : ");
	for(int i = 0; i < SIZE; i++){
		printf("\t%d", arr[i]);
	}	
}
