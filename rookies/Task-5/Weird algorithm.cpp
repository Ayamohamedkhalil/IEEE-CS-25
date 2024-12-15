#include <iostream>
using namespace std;

long long number(long long n) {
    if (n == 1) {
        cout<< n;
        return 1;
    }
    cout<<n<<" ";
    if (n % 2 == 0)
        return number(n / 2);
    else
        return number(3*n+1);
}

int main() {
    long long n;
    cin>>n;
    number(n);

    return 0;
}
