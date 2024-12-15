#include <iostream>
#include<algorithm>
using namespace std;



long long totalSum = 0;
long long  findMinsum(long long arr[], int r, long long currSum) {

    if (r == 0)
        return abs((totalSum - currSum) - currSum);


    return min(findMinsum(arr, r-1, currSum + arr[r-1]),
               findMinsum(arr, r-1, currSum));
}



int main() {

     int n;
    cin>>n;
    long long a[n];
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
        totalSum += a[i];
    }
    cout << findMinsum(a, n, 0) << endl;
}
