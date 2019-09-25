#include <stdio.h>

int arr[100];
int n;

void merge(int low, int mid, int high){
	int temp[n];
	int lo, mi;
	int i = low;
	int k;
	lo = low;
	mi = mid+1;
	while ((lo <= mid) && (mi <= high)){
		if (arr[lo] < arr[mi]){
			temp[i] = arr[lo];
			lo ++;
		}
		else{
			temp[i] = arr[mi];
			mi ++;
		}
		i++;
	}
	if (low > mid){
		for(k = mi; k <= high; k++){
			temp[i] = arr[k];
			i++;
		}
	}
	else{
		for(k = lo; k <= mid; k++){
			temp[i] = arr[k];
			i++;
		}
	}
	for(k = low; k <= high; k++){
		arr[k] = temp[k];
	}
}

void partiton(int low, int high){
	int mid;
	if (low < high){
		mid = (low+high)/2;
		partiton(low,mid);
		partiton(mid+1,high);
		merge(low,mid,high);
	}
}

void printArray(){
	int i;
	for(i = 0; i< n; i++){
		printf("%d ",arr[i]);
	}
}

void getArray(){
	int i;
	printf("Enter size of array: ");
	scanf("%d",&n);
	printf("Elements: ");
	for(i = 0; i< n; i++){
		scanf("%d",&arr[i]);
	}
}

int main(){
	getArray();
	partiton(0,n-1);
	printf("Sorted: ");
	printArray();
	return 0;
}
