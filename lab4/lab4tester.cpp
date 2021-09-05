/************************************************************/
/*  Lab 4 tester                                            */
/*  To compile:                                             */
/*     g++ lab4tester.cpp -std=c++0x                        */
/*  To run:                                                 */
/*     ./a.out                                              */
/************************************************************/

#include "lab4.h"
#include <iostream>

int main(void){
	DList<int> regular;
	Sentinel<int> sentinel;
	DList<int>::iterator a = regular.begin();
	Sentinel<int>::iterator b = sentinel.begin();
	bool isGood=true;
	if(a != regular.end() || a != regular.cend() ||
	   !(a==regular.end()) || !(a==regular.cend())){
		std::cout << "error: c/begin() or c/end() is not correctly written for DList" << std::endl;
		std::cout << "error could also be in == or !=" << std::endl;
		isGood=false;
		return 1;
	}
	else{
		std::cout << "test 1 pass" << std::endl;
	}
	if(b != sentinel.end() || b != sentinel.cend() || 
	   !(b==sentinel.end()) || !(b==sentinel.cend())){
		std::cout << "error: c/begin() or c/end() is not correctly written for Seninel" << std::endl;
		std::cout << "error could also be in == or !=" << std::endl;
		isGood=false;
		return 1;
	}
	else{
		std::cout << "test 2 pass" << std::endl;
	}
	if(isGood){
		int listValues[5]={4,3,2,1,0};

		for(int i=0;i<5;i++){
			regular.push_front(i);
		}
		DList<int>::const_iterator it;
		int j=0;
		for(it=regular.cbegin();isGood && it!=regular.cend();++it,j++){
			if(*it != listValues[j]){
				isGood=false;
			}
		}
	
		it=regular.cend();
		j=5;
		while(isGood && it != regular.cbegin()){
			if(*(--it)!=listValues[--j]){
				isGood=false;
			}
		}
		j=0;
		a=regular.begin();
		while(isGood && a!= regular.end()){
			*(a++)+=1;
			listValues[j++]+=1;
		}
		j=0;
		for(it=regular.cbegin();isGood && it!=regular.cend();it++,j++){
			if(*it != listValues[j]){
				isGood=false;
			}
		}
	
		a=regular.begin();
		j=0;
		while(++a!= regular.end()){
			++j;
			*(a)+=1;
			listValues[j]+=1;
		}
	
		j=5;
		it=regular.cend();
		while(isGood && it != regular.cbegin()){
			j--;
			it--;
			if(*it != listValues[j]){
				isGood=false;
			}
		}
		if(!isGood){
			std::cout << "error: problems with iterator/const_iterator operators for  Dlists" << std::endl
			return 1;
		}
		else{
			std::cout << "test 3 pass" << std::endl;
		}
	}

	if(isGood){
		int listValues[5]={4,3,2,1,0};
		for(int i=0;i<5;i++){
			sentinel.push_front(i);
		}
		Sentinel<int>::const_iterator it2;
		j=0;
		for(it2=sentinel.cbegin();isGood && it2!=sentinel.cend();++it2,j++){
			if(*it2 != listValues[j]){
				isGood=false;
			}
		}
	
		it2=sentinel.cend();
		j=5;
		while(isGood && it2 != sentinel.cbegin()){
			if(*(--it2)!=listValues[--j]){
				isGood=false;
			}
		}
		j=0;
		b=sentinel.begin();
		while(isGood && b!= sentinel.end()){
			*(b++)+=1;
			listValues[j++]+=1;
		}
		j=0;
		for(it2=sentinel.cbegin();isGood && it2!=sentinel.cend();it2++,j++){
			if(*it2 != listValues[j]){
				isGood=false;
			}
		}
	
		b=sentinel.begin();
		j=0;
		while(++b!= sentinel.end()){
			++j;
			*(b)+=1;
			listValues[j]+=1;
		}
	
		j=5;
		it2=sentinel.cend();
		while(isGood && it2 != sentinel.cbegin()){
			j--;
			it2--;
			if(*it2 != listValues[j]){
				isGood=false;
			}
		}
		if(!isGood){
			std::cout << "error: problems with iterator/const_iterator operators for sentinel lists" << std::endl
			return 1;
		}
		else{
			std::cout << "test 4 pass" << std::endl;
		}
		return 0;
	}
}
