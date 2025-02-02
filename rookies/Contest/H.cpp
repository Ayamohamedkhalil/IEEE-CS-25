#include <bits/stdc++.h>
using namespace std;

void solve() {
    int n,m, k;
    cin >>n>>m>>k;
    vector<int> a(n), b(m);

    for (int &x : a) cin >> x;
    for (int &x : b) cin >> x;

    unordered_map<int, int> b_freq, window_freq;
    for (int x : b) b_freq[x]++;

    int match_count = 0, result = 0;

    for (int i = 0; i < n; i++) {
        if (i >= m) {
            int to_remove = a[i - m];
            if (b_freq.count(to_remove)) {
                if (window_freq[to_remove] <= b_freq[to_remove]) match_count--;
                window_freq[to_remove]--;
            }
        }

        int to_add = a[i];
        if (b_freq.count(to_add)) {
            if (window_freq[to_add] < b_freq[to_add]) match_count++;
            window_freq[to_add]++;
        }

        if (i >= m - 1 && match_count >= k) result++;
    }

    cout << result << "\n";
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}
