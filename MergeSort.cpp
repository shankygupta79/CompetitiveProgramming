#include<iostream.h>


void merge(int *arr, int start, int mid, int end) {

	int temp[end - start + 1];

	int i = start, j = mid+1, k = 0;

	while(i <= mid && j <= end) {
		if(arr[i] <= arr[j]) {
			temp[k] = arr[i];
			k =k+ 1;
			i =i+ 1;
		}
		else {
			temp[k] = arr[j];
			k =k+ 1;
                  j =j+ 1;
		}
	}

	// add elements left in the first interval
	while(i <= mid) {
		temp[k] = arr[i];
		k =k+ 1;
		i =i+ 1;
	}

	// add elements left in the second interval
	while(j <= end) {
		temp[k] = arr[j];
		k =k+ 1;
		j =j+ 1;
	}

	for(i = start; i <= end; i += 1) {
		arr[i] = temp[i - start]
	}
}

void mergeSort(int *Arr, int s, int e) {

	if(start < end) {
		int mid = (s + e) / 2;
		mergeSort(arr, s, mid);
		mergeSort(arr, mid+1, e);
		merge(arr, s, mid, e);
	}
}

void printArray(int A[], int n){
	int i;
	for (i=0; i < n i++){
		cout<<A[i];
	}
	cout<<endl;
}

int main() {
	int arr[] = {12, 11, 13, 5, 6, 7};
	int n=6;
	printArray(arr,n);
	mergeSort(arr, 0, n- 1);
	printArray(arr,n);
	return 0;
}

