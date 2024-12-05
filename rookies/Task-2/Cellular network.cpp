#include <bits/stdc++.h>
using namespace std;


int main()
{
    long long n,m;
    cin>>n>>m;
    long long  city[n],tower[m];
    for(int i=0; i<n; i++)
    {
        cin>>city[i];
    }

    for(int i=0; i<m; i++)
    {
     cin>>tower[i];
    }
    long long d,p,r=0;
    for(int i=0; i<n; i++)
    {
        p=lower_bound(tower,tower+m,city[i])-tower;
        if(p == 0)

            d=abs(tower[p]-city[i]);

        else if(p==m)

            d = abs(city[i]-tower[p-1]);

        else
        {
            long long right_d = abs(tower[p]-city[i]);
            long long  left_d = abs(city[i]-tower[p-1]);
            d = min(right_d,left_d);
        }
        r=max(r,d);
    }
    cout<<r;
    return 0;
}
