#include<stdio.h>
void bubble_sort(int* arr,int size){
	int bound=0;
	int temp=0;
	for(bound=0;bound<size;++bound){
		int cur=size-1;
		for(cur=size-1;cur>bound;--cur){
			if(arr[cur-1]>arr[cur]){
				temp=arr[cur-1];
				arr[cur-1]=arr[cur];
				arr[cur]=temp;
			}
		}
	}
}

int main(){
	int arr[]={1,4,8,9,5,-5,6};
	int size=0;
	int i=0;
	size=sizeof(arr)/sizeof(arr[0]);
	bubble_sort(arr,size);
	for(i=0;i<size;i++){
		printf("%d ",arr[i]);
	}
}
