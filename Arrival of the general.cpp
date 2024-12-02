#include<iostream>
using namespace std;
int main(){
	int n;
	cin>>n;
	int minn = 101;
	//Range of numbers is 1 to 100
	int minindex = 0;
	int maxx = 0;
	int maxindex = 0;

	for(int i =1;i<=n;i++){

		int num;
		cin>>num;
		if(num > maxx){
			maxx = num;
			maxindex = i;
		}
		if(num <= minn){
			minn = num;
			minindex = i;
		}
	}
	if(maxindex > minindex){
		cout<<(maxindex-1) + (n - ++minindex)<<endl;
	} else {
		cout<<(maxindex-1) + (n - minindex)<<endl;
	}
}
