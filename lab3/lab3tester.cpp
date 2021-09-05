/************************************************************/
/*  Lab 3 tester                                            */
/*  To compile:                                             */
/*     g++ lab3tester.cpp -std=c++0x                        */
/*  To run:                                                 */
/*     ./a.out                                              */
/************************************************************/

#include "lab3.h"
#include <iostream>
const int numChecks = 36;
int getData(int data[]);
int getReverseData(int data[]);
bool isSame(int array1[],int array2[],int size1,int size2);

int main(void){
	DList<int> regular;
	Sentinel<int> sentinel;

	int correctLength[numChecks]={1,2,3,3,4,5,6,6,5,4,3,2,1,1,0,0,1,2,3,3,4,5,6,6,5,4,3,2,1, 0,0,0,1,2, 3,3};
	int correct[numChecks][6]={{0}, {1, 0}, {2, 1, 0}, {0, 1, 2}, {2, 1, 0, 3},
				{2, 1, 0, 3, 4}, {2, 1, 0, 3, 4, 5}, {5, 4, 3, 0, 1, 2}, 
				{1, 0, 3, 4, 5}, {1, 0, 3, 4}, {0, 3, 4}, {0, 3}, {3}, {3},{},{},
				{0}, {0, 1}, {0, 1, 2}, {2, 1, 0}, {3, 0, 1, 2}, {4, 3, 0, 1, 2}, 
				{5, 4, 3, 0, 1, 2}, {2, 1, 0, 3, 4, 5}, {5, 4, 3, 0, 1}, 
				{4, 3, 0, 1}, {4, 3, 0}, {3, 0}, {3}, 
				{},{},{},{0}, {1, 0}, {2, 1, 0}, {0, 1, 2}};

	int data[6];
	int numInList;
	bool isGood=true;
	int check=0;
	std::cout << "Testing regular doubly linked list" << std::endl;


	for(int i=0;isGood && i<3;i++){
		regular.push_front(i);
		numInList=regular.getData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		numInList=regular.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;

		for(int i=3;isGood && i<6;i++){
			regular.push_back(i);
			numInList=regular.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;
		}
	}
	if(isGood){
		numInList=regular.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
		for(int i=0;isGood && i<7;i++){
			if(i%2==0){
				regular.pop_front();
			}
			else{
				regular.pop_back();
			}
			numInList=regular.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}
	}
	if(isGood){
		numInList=regular.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;

		for(int i=0;isGood && i<3;i++){
			regular.push_back(i);
			numInList=regular.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}
		numInList=regular.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		for(int i=3;isGood && i<6;i++){
			regular.push_front(i);
			numInList=regular.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}
		numInList=regular.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		for(int i=0;isGood && i<7;i++){
			if(i%2){
				regular.pop_front();
			}
			else{
				regular.pop_back();
			}
			numInList=regular.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}
		numInList=regular.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		for(int i=0;isGood && i<3;i++){
			regular.push_front(i);
			numInList=regular.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}	
		numInList=regular.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		std::cout << "Regular list passes testing" << std::endl;
	}
	else{
		std::cout << "Regular list had some flaws" << std::endl;
		return 1;
	}

	std::cout << "Testing sentinel list" << std::endl;

	for(int i=0;isGood && i<3;i++){
		sentinel.push_front(i);
		numInList=sentinel.getData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		numInList=sentinel.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;

		for(int i=3;isGood && i<6;i++){
			sentinel.push_back(i);
			numInList=sentinel.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;
		}
	}
	if(isGood){
		numInList=sentinel.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
		for(int i=0;isGood && i<7;i++){
			if(i%2==0){
				sentinel.pop_front();
			}
			else{
				sentinel.pop_back();
			}
			numInList=sentinel.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}
	}
	if(isGood){
		numInList=sentinel.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;

		for(int i=0;isGood && i<3;i++){
			sentinel.push_back(i);
			numInList=sentinel.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}
		numInList=sentinel.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		for(int i=3;isGood && i<6;i++){
			sentinel.push_front(i);
			numInList=sentinel.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}
		numInList=sentinel.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		for(int i=0;isGood && i<7;i++){
			if(i%2){
				sentinel.pop_front();
			}
			else{
				sentinel.pop_back();
			}
			numInList=sentinel.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}
		numInList=sentinel.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		for(int i=0;isGood && i<3;i++){
			sentinel.push_front(i);
			numInList=sentinel.getData(data);
			isGood=isSame(data,correct[check],numInList,correctLength[check]);
			check++;

		}	
		numInList=sentinel.getReverseData(data);
		isGood=isSame(data,correct[check],numInList,correctLength[check]);
		check++;
	}
	if(isGood){
		std::cout << "Sentinel list passes testing" << std::endl;
		return 0;
	}
	else{
		std::cout << "Sentinel list had some flaws" << std::endl;
		return 1;
	}
}

bool isSame(int array1[],int array2[],int size1,int size2){
	bool rc=true;
	if(size1!=size2){
		rc=false;
	}
	else{

		for(int i=0;rc && i<size1;i++){
			if(array1[i]!=array2[i]){
				rc=false;
			}
		}
	}
	return rc;
}


