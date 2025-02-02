#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    cin>>n;
    vector<int> matches(n);
    for (int i=0;i<n; i++) {
        cin>>matches[i];
    }

    int score=0,win_streak=0;

    for (int i = 0; i < n; i++) {
        if (matches[i] == 1) {
            score+= 1;
            win_streak++;
            if(win_streak>=3) {
                score+= 1;
            }
        } else {
            score -= 1;
            win_streak = 0;
        }
    }

    cout<<score<< endl;
    return 0;
}
