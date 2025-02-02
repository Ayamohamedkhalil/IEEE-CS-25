#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        while (true) {
            int temp = n;
            bool nice = true;
            while (temp > 0) {
                int digit = temp % 10;
                if (digit != 6 && digit != 9) {
                    nice = false;
                    break;
                }
                temp /= 10;
            }
            if (nice) {
                cout << n << "\n";
                break;
            }
            n++;
        }
    }
    return 0;
}
