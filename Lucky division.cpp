#include<bits/stdc++.h>
using namespace std;
int main()
{
	int listofluckynumbers[14]={4,7,44,77,47,74,444,447,474,477,777,774,744,747};
	int num;
	cin>>num;
	int flag = false;
	for(int i=0;i<14;i++){
		if(num % listofluckynumbers[i] == 0){
			flag = true;
			break;
		}
	}
	if(flag ){
		cout<<"YES"<<endl;
	} else {
		cout<<"NO"<<endl;
	}
}
