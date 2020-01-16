#include <iostream>
using namespace std;
 
void Merge(int Array[], int begin, int middle, int end){
	int n1 = middle - begin;
	int n2 = end - middle;
	
	int *left = new int[n1];
	int *right = new int[n2];
	
	for(int i = 0; i < n1; i++)
		left[i] = Array[begin + i];    
	for(int i = 0; i < n2; i++)
		right[i] = Array[middle + i];  
	
 
	int i = 0, j = 0, key;
	for(key = begin; key < end; key++){
		if(i < n1 && left[i] <= right[j])
			Array[key] = left[i++];
		
		else if(j < n2 && left[i] >= right[j])
			Array[key] = right[j++];
		
		else if(i == n1 && j < n2){
			Array[key] = right[j++];
		}
			
		else if(j == n2 && i < n1){
			Array[key] = left[i++];
		}	
			
	}
}
 
void MergeSort(int Array[], int begin, int end){
	
	if(begin + 1 < end){     		 
		int middle = (end + begin) / 2;  
		MergeSort(Array, begin, middle);
		MergeSort(Array, middle, end);
		Merge(Array, begin, middle, end);
	}
}
 
int main(int argc, char** argv){
 
	int n;
	cin>>n;
	int Array[n];
 
	for(int i = 0; i < n; i++)
		cin>>Array[i];
	MergeSort(Array, 0, n); 
	
	for(int i =  0; i < n; i++)
		cout<<Array[i]<<" ";
	cout<<endl;
	
	return 0;
}
