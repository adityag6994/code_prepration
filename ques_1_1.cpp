#include <iostream>
#include <string>

using namespace std;
/*
 Program to determine if string has all unique characterstics
*/

bool checkIfUnique1(string s){
	//without using any additioanl ds
	if(s.size() == 1)
		return true;
	
	for(int i=0; i<(s.size()-1); i++){
		for(int j=i+1; j<(s.size()); j++){
			if(s[i] == s[j])
				return false;		
		}	
	}
	return true;
}

bool checkIfUnique2(string s){
	//using ascii lookup table 
	if(s.size() > 128)
		return false;
	
	//array of 128]
	int array[128]={0};
	for(int i=0; i<s.size(); i++){
		if(array[int(s[i])]==1)
			return false;
		array[int(s[i])] = 1;
	}	
	return true;
}

int main(){
	string s = "abc";
	cout << s << " | " << checkIfUnique2(s) << endl;
	s = "1bd3";
	cout << s << " | " << checkIfUnique2(s) << endl;
	s = "1";
	cout << s << " | " << checkIfUnique2(s) << endl;
	s="sdasdasas";
	cout << s << " | " << checkIfUnique2(s) << endl;
	s="ss";
	cout << s << " | " << checkIfUnique2(s) << endl;

	return 0;
}
