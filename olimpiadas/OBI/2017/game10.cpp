#include <bits/stdc++.h>
#include <iostream>

using namespace std;

int main(int argc, char const *argv[])
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N, D, A, btn=0;
    cin>>N>>D>>A;
    while (A!=D)
    {
        A++; btn++;
        if (A>N)
        {
            A=1;
        }


    }

    cout<<btn<<"\n";
    return 0;
}