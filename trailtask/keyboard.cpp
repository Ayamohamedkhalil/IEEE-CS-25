#include<bits/stdc++.h>
using namespace std;
int main() {
	string keyboard = "qwertyuiopasdfghjkl;zxcvbnm,./",input,out;
	char direction;
	cin>>direction>>input;

	for(int i=0;i<input.size();i++){
		int index = keyboard.find(input[i]);
		if(direction == 'R'){
			out+=keyboard[index - 1];
		} else {
			out+=keyboard[index + 1];
		}
	}
	cout<<out<<endl;
}

