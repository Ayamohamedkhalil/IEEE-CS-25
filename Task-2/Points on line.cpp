#include <bits/stdc++.h>
using namespace std;

int main() {
    long points, d;
    cin >> points >> d;
    long long arr[points];

    for (long i = 0; i < points; i++) {
        cin >> arr[i];
    }
    long long result = 0;
    for (long i = 0; i < points; i++) {
        long long comp = arr[i] + d;
        long ans = i;

        long low = i, high = points - 1;
        while (low <= high) {
            long long mid = (low+high) / 2;
            if (arr[mid] <= comp) {
                ans = mid;
                low = mid + 1;
            } else
                high = mid - 1;

        }
        long long numPoints = ans - i;

        if (numPoints >= 2) {
            result += (numPoints * (numPoints - 1)) / 2;
    }
    }

    cout << result;
    return 0;
}
