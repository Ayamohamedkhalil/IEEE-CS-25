#include <iostream>
#include <set>
#include <string>
#include <algorithm>
using namespace std;
//By searching

void generatePermutations(string &s, int start, set<string> &results) {
    if (start==s.size()- 1) {
        results.insert(s);
        return;
    }

    for (int i=start;i<s.size(); i++) {
        swap(s[start], s[i]);
        generatePermutations(s,start+1, results);
        swap(s[start], s[i]);
    }
}

int main() {
    string input;
    cin >> input;

    set<string> results;
    generatePermutations(input, 0, results);

    cout << results.size() << endl;
    for (const string &str : results) {
        cout<<str<<endl;
    }

    return 0;
}
