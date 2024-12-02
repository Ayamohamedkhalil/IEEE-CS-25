#include<bits/stdc++.h>
using namespace std;
int main() {
	int n;
	string dir;
	cin>>n>>dir;
	long long particals[n];
	for(int i=0;i<n;i++){
		cin>>particals[i];
	}

	long long time = 0,minTime = 100000000000;
	//                          0 1 2 3  01 12 23
	//to reach to final pair of R L R L

	for(int i=0;i<n-1;i++){
		if(dir[i] == 'R' && dir[i+1] == 'L'){
			time = (particals[i+1] - particals[i]) / 2;
			//to calculate the exact time between them
			if(time < minTime){
				minTime = time;
			}
		}
	}
	if(minTime == 100000000000){
		cout<<-1<<endl;
	} else {
		cout<<minTime<<endl;
	}
}
