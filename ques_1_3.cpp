#include <iostream>
#include <string>

using namespace std;

//brute force : saving in new string
string URLify(string s1){
	if(s1.size()==0)
		return "";

	string s1_new;
	for(int i=0; i<s1.size(); i++){
		if(s1[i] == ' '){
			s1_new.push_back('%');
			s1_new.push_back('2');
			s1_new.push_back('0');
			// s1_new.append(3,"%20");
		}else{
			s1_new.append(1,s1[i]);
		}
	}
	return s1_new;
}

//inplace 
string URLifyInPlace(string s1){
	if(s1.size()==0)
		return "";

	// string s1_new;
	for(int i=0; i<s1.size(); i++){
		if(s1[i] == ' '){
			s1[i] = '%';
			s1.push_back(' ');
			s1.push_back(' ');
			for(int j=s1.size()-3; j>i; j--){
				s1[j+2] = s1[j];
			}
			s1[i+1] = '2';
			s1[i+2] = '0';
		}
	}
	return s1;
}

int main(){
	cout << URLifyInPlace("adi") << endl;
	cout << URLifyInPlace("adi ") << endl;
	cout << URLifyInPlace("dia adi") << endl;
	// cout << URLify("") << endl;
	// cout << URLify(" ") << endl;
	// cout << URLify(" a ") << endl;
	return 0;
}