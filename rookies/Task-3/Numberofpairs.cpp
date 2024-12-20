#include <bits/stdc++.h>
using namespace std;

long long count_pairs(vector<int>& a, int l, int r) {
    int n = a.size();
    long long counter = 0;
    int low,high;
    for (int i = 0; i < n; i++) {
        low= i+1,high=n-1;

        while (low<=high) {
            int mid=(low + high) / 2;
            if (a[i]+ a[mid] >= l) {
                high=mid-1;
            } else {
                low=mid+ 1;
            }
        }
        int s=low;

        low = i+ 1,high =n -1;
        while (low<=high) {
            int mid =(low+high)/2;
            if (a[i]+a[mid]<= r) {
                low= mid + 1;
            } else {
                high= mid - 1;
            }
        }
        int e = high;

        if (s<= e) {
            counter += (e-s+ 1);
        }
    }

    return counter;
}

int main() {

    int t;
    cin >> t;
    while (t--) {
        int n, l, r;
        cin >>n>>l>>r;
        vector<int> a(n);
        for (int i=0; i < n; i++) {
            cin>>a[i];
        }

        sort(a.begin(), a.end());
        cout<<count_pairs(a, l, r) << endl;
    }

    return 0;
}
