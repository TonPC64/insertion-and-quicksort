#include <iomanip>
#include <iostream>
#include <vector>
using namespace std;

template<class Comparable>
void insertionSort(vector<Comparable> & a,int left,int right, bool info){
	for(int p=left+1;p<=right;p++){
		if (info) {
			cout << "|after P=" << setw(2) << p << "|";
		}
		Comparable tmp=a[p];
		int j;
		int pm = 0;
		for(j=p;j>left&&tmp<a[j-1];j--){
			a[j]=a[j-1];
			pm++;
		}
		a[j]=tmp;
		
		if (info) {
			for (int i = 0; i<=right; i++) {
				cout << setw(3) << a[i];
			}	
			cout << " | " << setw(2) << pm << " |" << endl;
		}
	}
}

