#include <iomanip>
#include <iostream>
#include <vector>
#include "insertion_sort.h"
using namespace std;

int n=0;


template<class Comparable>
const Comparable &median3(vector<Comparable> &a,int left,int right){
	int center=(left+right)/2;
	if(a[center]<a[left])
		swap(a[left],a[center]);
	if(a[right]<a[left])
		swap(a[left],a[right]);
	if(a[right]<a[center])
		swap(a[right],a[center]);
	swap(a[center],a[right-1]);
	return a[right-1];
}

template<class Comparable>
void quicksort(vector<Comparable> &a,int left,int right, bool start){
	if (start) {
		n = 0;
	}
	++n;
	if(left+3<=right){
		Comparable pivot=median3(a,left,right);
		int i=left,j=right-1;
		for(;;){
			while(a[++i]<pivot){}
			while(a[--j]>pivot){}
			if(i<j) {
				swap(a[i],a[j]);
			} else {
				break;
			}
		}
		swap(a[i],a[right-1]);
		cout<<endl<<"| Round  "<<n<<" |";
		for(int i=0;i<a.size();i++) {
			cout << setw(3) <<a[i];
		}
		cout<<" |  Left: "<<left<<", Right: "<<right<<", Pivot: " <<pivot;
		quicksort(a,left,i-1, false);
		quicksort(a,i+1,right, false);
	} else {
		insertionSort(a,left,right,false);		
		cout<<endl<<"| Round  "<<n<<" |";
		for(int i=0;i<a.size();i++) {
			cout << setw(3) << a[i];	
		}
		cout << " |";
	}
}

template<class Comparable>
void swap(int &num1,int &num2){
	int tmp=num1;
	num1=num2;
	num2=tmp;
}
