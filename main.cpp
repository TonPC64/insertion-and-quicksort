#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include <time.h>
#include <sys/time.h>
#include <conio.h>
#include "quick_sort.h"

using namespace std;
bool flag=true; 

long long getCurrentMiliSec() {
	struct timeval tp;
    gettimeofday(&tp, NULL);
    long long mslong = (long long) tp.tv_sec * 1000L + tp.tv_usec / 1000;
    return mslong;
}

double runningTime(long long start, long long end) {
	long long durations = end - start;
	double seconds = (double)(durations);
	return seconds/1000;
}

int main() {
	srand (time(NULL));
	vector<int> original;
	vector<int> cloningData;
	string choice;
	bool exit = true;
	bool create = false;
//	int myints[] = {22, 2, 13, 56, 5, 32, 7, 89, 56, 99};
//	original.assign(myints, myints+10);

	long long startTime;
	long long endTime;
	
	do{
		system("cls");		
		cout << "\n\t\t\t===============================\n";
		cout << "\t\t\t.:: Assignment4 [ Sorting ] ::.\n";
		cout << "\t\t\t===============================\n";
		cout << "\t\t\t1.) Enter Element\n";
		cout << "\t\t\t2.) Insertion Sort\n";
		cout << "\t\t\t3.) Quick Sort\n";
		cout << "\t\t\t4.) Exit\n";
		cout << "\t\t\t===============================\n\n";
		cout <<"\t\t\tEnter Choice : ";
		
		cin >> choice;
		switch (choice[0])
		{
		case '1':
			system("cls");
		 	int num;
			cout<<"\t\tHow many for input : ";
			cin>>num;
			original.resize(num);
			for(int i=0;i<num;i++){
				cout<<"\t\tInput Data ["<<i+1<<"] : ";
				cin>>original[i];
			}
			cout << "\n\t\t| DATA |";
			for(int i=0;i<original.size();i++) {
				cout << setw(3) << original[i];
			}
			cout << endl << endl;
			create = true;
			system("pause");
			break;	
		case '2':
			system("cls");
			cloningData = original;
			startTime = getCurrentMiliSec();
			
			if (create) {
				cout << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << "\t\t\t\tInsertion Sort" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << "| Original |";
				for (int i = 0; i<original.size(); i++) {
					cout << setw(3) << original[i];
				}
				cout << " | PM |" << endl << "-------------------------------------------------------------------------------" << endl;
				insertionSort(cloningData, 0, cloningData.size()-1, true);
				cout << "-------------------------------------------------------------------------------" << endl;
				endTime = getCurrentMiliSec();
				cout<<"Running Time = "<<runningTime(startTime, endTime)<<" seconds"<<endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				system("pause");
			} else {
				cout << "\n\t\t\t!!!Must Insert before sort!!!\n\n";
				system("pause");
			}
			break;
		case '3':
			system("cls");
			cloningData = original;
			startTime = getCurrentMiliSec();
			
			if (create) {	
				cout << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << "\t\t\t\tQuick Sort" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				cout << "| Original |";
				for (int i = 0; i<original.size(); i++) {
					cout << setw(3) << original[i];
				}
				cout << endl << "-------------------------------------------------------------------------------" ;
				quicksort(cloningData, 0, cloningData.size()-1, true);
				cout << endl << "-------------------------------------------------------------------------------" << endl;
				cout<<"| Final    |";
				for(int i=0;i<cloningData.size();i++) {
					cout << setw(3) << cloningData[i];
				}
				cout << " |" << endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				endTime = getCurrentMiliSec();
				cout<<"| Running Time = "<<runningTime(startTime, endTime)<<" seconds"<<endl;
				cout << "-------------------------------------------------------------------------------" << endl;
				system("PAUSE");
			} else {
				cout << "\n\t\t\t!!!Must Insert before sort!!!\n\n";
				system("pause");
			}
			break;
		case '4':
			exit=false;
			break;
		}
	} while (exit);
	return 0;
}

