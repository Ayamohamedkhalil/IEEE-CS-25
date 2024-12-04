#include <iostream>
#include <algorithm>
using namespace std;

int Binary_search_count(int arr[], int sizee, int val) {
    int low = 0;
    int high = sizee - 1;
    int result = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] <= val) {
            result = mid;
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }

    return result + 1;
}

int main() {
    int Num_shops, days;
    cin >> Num_shops;
    int Pricesofdrink[Num_shops];
    for (int i = 0; i < Num_shops; i++) {
        cin >> Pricesofdrink[i];
    }

    cin >> days;
    int Hiscoins[days];
    for (int j = 0; j < days; j++) {
        cin >> Hiscoins[j];
    }
    sort(Pricesofdrink, Pricesofdrink + Num_shops);
    for (int m = 0; m < days; m++) {
        int count = Binary_search_count(Pricesofdrink, Num_shops, Hiscoins[m]);
        cout << count << endl;
    }

    return 0;
}
