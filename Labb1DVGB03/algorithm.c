#include "algorithm.h"

//
// Private
//

int temp,i,j,k;

//
// Public
//
void bubble_sort(int *a, int n)
{	k=0;
	while (k==0){
		k=1;	
		for (i=0;i<n-1;i++) {
			if (a[i]>a[i+1]){
				
				temp=a[i];
				a[i]=a[i+1];
				a[i+1]=temp;
				k=0;
				
			}
		}
	}
}

void insertion_sort(int *a, int n)
{
	for (i=1;i<n;i++){
			
			j=i;
			while (j>0 && a[j-1]>a[j]){
				
				temp=a[j];
				a[j]=a[j-1];
				a[j-1]=temp;
				j--;	
			}
		
	}
}

void quick_sort(int *a, int n)
{
	QuickSort(a,0,n-1);
}

void QuickSort(int *a,int a2,int b)
{
	
	
	
	int pivot=a[a2];
	int low=a2+1;
	int high=b;
	
	if ( a2<b) {
	
		while (low<=high){
			while (a[low] <= pivot && low<=high) low++;
			while (a[high] > pivot && low<=high) high--;
			
			if (low<=high) {
				
				temp=a[low];
				a[low]=a[high];
				a[high]=temp;
				low++;
				high--;	
				
			}
		}
	
			temp=a[high];
			a[high]=a[a2];
			a[a2]=temp;

		QuickSort(a,a2,high-1);
		QuickSort(a,high+1,b);	
	}
	
}

bool linear_search(const int *a, int n, int v)
{
	for (i=0;i<n;i++){
		
		if (a[i]==v) return true;
		
		}
	
	return false; 
	
}

bool binary_search(const int *a, int n, int v)
{
	int low=0;
	int high=n-1;
	while (low<=high){
		
		k=(low+high)/2;
		if (a[k]<v) low=k+1;
		
		else if (a[k]>v) high=k-1;
		
		else return true;
	}
	
	return false;
}



	

