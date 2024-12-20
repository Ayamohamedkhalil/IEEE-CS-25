#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> t(n);
    for (int i=0; i<n;i++) {
        cin>>t[i];
    }
    int low=0, high=n-1;
    int time_alice=0, time_bob = 0;
    int a=0,b=0;
    while (low<= high) {
        if (time_alice <= time_bob) {
            time_alice += t[low];
            low++;
            a++;
        } else {
            time_bob+=t[high];
            high--;
            b++;
        }
    }

    cout<<a<<" "<<b<<endl;

    return 0;
}
