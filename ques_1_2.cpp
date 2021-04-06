#include <iostream>
#include <string>

using namespace std;

bool checkIfPermutation(string s1, string s2){
	cout << s1 << " | " << s2 << " = ";

	//check is empty
	if(s1.size()==0 || s2.size()==0)
		return false;

	//check if size is not same
	if(s1.size()!=s2.size())
		return false;

	int arr1[128]={0};
	for(int i=0; i<s1.size(); i++){
		arr1[int(s1[i])]+=1;
	}
	int arr2[128]={0};
	for(int i=0; i<s2.size(); i++){
		arr2[int(s2[i])]+=1;
	}

	for(int i=0; i<128; i++){
		if(arr1[i]!=arr2[i])
			return false;
	}
	return true;
}

//more optimised version of above, where instead of having two seperate
//hash tables, I can use first one and decrease value while giong though
//second array
bool checkIfPermutationOpt(string s1, string s2){
	cout << s1 << " | " << s2 << " = ";

	//check is empty
	if(s1.size()==0 || s2.size()==0)
		return false;

	//check if size is not same
	if(s1.size()!=s2.size())
		return false;

	int arr1[128]={0};
	for(int i=0; i<s1.size(); i++){
		arr1[int(s1[i])]+=1;
	}

	// int arr2[128]={0};
	for(int i=0; i<s2.size(); i++){
		arr1[int(s2[i])]-=1;
		if(arr1[int(s2[i])]<0)
			return false;
	}

	return true;
}


int main(){
	cout << checkIfPermutationOpt("ab c", "cab") << endl;
	cout << checkIfPermutationOpt("abc", "cab") << endl;
	cout << checkIfPermutationOpt("aabc", "Acab") << endl;
	cout << checkIfPermutationOpt("abc", "caa") << endl;
	cout << checkIfPermutationOpt("abc", "caasda") << endl;
	cout << checkIfPermutationOpt("abc", "casa") << endl;
	cout << checkIfPermutationOpt("abc", "") << endl;
	cout << checkIfPermutationOpt("abc", "abc") << endl;
	cout << checkIfPermutationOpt("abc", "abcabc") << endl;
	cout << checkIfPermutationOpt("", "") << endl;
	return 0;
}