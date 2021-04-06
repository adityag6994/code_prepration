#include <iostream>
#include <string>

using namespace std;

bool checkIfPermutationOfPelindrome(string s1){
	if(s1.size() == 0)
		return false;
	if(s1.size() == 1)
		return true;
	if(s1.size() == 2){
		if(s1[0] == s1[1])
			return true;
		return false;
	}

	int array1[128]={};
	for(int i=0; i<s1.size(); i++){
		array1[int(s1[i])]+=1;
	}

	int oddCount=0;
	// for(int i=65; i<91; i++){
	// 	if(array1[i]%2==1)
	// 		oddCount++;
	// 	if(oddCount>1)
	// 		return false;
	// }
	for(int i=97; i<123; i++){
		if(array1[i]%2==1)
			oddCount++;
		if(oddCount>1)
			return false;
	}
	return true;
}

int main(){
	// [a,z]:[97,122] || [A,Z]:[65,90]
	cout << checkIfPermutationOfPelindrome("aditya")    << endl;    //0
	cout << checkIfPermutationOfPelindrome("adiida")    << endl;    //1
	cout << checkIfPermutationOfPelindrome("adidia")    << endl;    //1
	cout << checkIfPermutationOfPelindrome("adidias")   << endl;   //1
	cout << checkIfPermutationOfPelindrome("adidiasq")  << endl;  //0
	cout << checkIfPermutationOfPelindrome("adidiasq ") << endl; //0
	cout << checkIfPermutationOfPelindrome("adidias ")  << endl;  //1
	return 0;
}