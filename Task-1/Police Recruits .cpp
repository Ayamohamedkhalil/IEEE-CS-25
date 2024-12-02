#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	int polices = 0;
	int issues = 0;
	for(int i=1;i<=n;i++){
		int num;
		cin>>num;
		if(num == -1){
			if(polices > 0){
				polices--;
			} else {
				issues++;
			}
		} else {
			polices += num;
		}
	}
	cout<<issues<<endl;
}
