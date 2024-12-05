#include <iostream>
using namespace std;

int main()
{
    int books,minutes;
    cin>>books>>minutes;
    int books_time[books];
    for (int i = 0; i < books; i++)
    {
        cin >> books_time[i];
    }

    int sum=0,counter=0,Maxbooks=0;
    int start=0;

    for (int j =0;j<books;j++)
    {
        sum += books_time[j];

        while (sum > minutes)
        {
            sum -= books_time[start];
            start++;
        }

        Maxbooks=max(Maxbooks, j-start+1);
    }

    cout << Maxbooks;
    return 0;
}
