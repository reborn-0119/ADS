#include<iostream>
#include<cstdlib>

using namespace std;

int count = 0;

int Partition(int arr[], int l, int h){
	int pivot = arr[h];
	int i = l-1;
	
	for(int j = l; j<h; j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
		count=count+1;
	}
	swap(arr[i+1],arr[h]);
	return i+1;
	
}

int RandomPartition(int arr[], int l, int h){
	int random_pivot = l + rand() % (h-l+1);
	swap(arr[random_pivot],arr[h]);
	return Partition(arr,l,h);
	
	
}


int RandomQuickSort(int arr[], int l, int h){
	if(l<h){
		int pi=RandomPartition(arr,l,h);
		RandomQuickSort(arr,l,pi-1);
		RandomQuickSort(arr,pi+1,h);
	}
}


int main(){
	int arr[] = {10,9,8,7,6,5,4,3,2,1,1,2,3,4,5,6,7,8,9,10};
	
	int r = sizeof(arr)/sizeof(arr[0]);
	int h = r-1;
	
	RandomQuickSort(arr,0,h);
	
	for(int i = 0; i<r; i++){
		cout<<arr[i]<<" ";
	}
	
	cout<<endl<<"Total No. of elements : "<<r;
	cout<<endl<<"Count : "<<count;
	
	return 0;
}
