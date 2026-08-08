#include <bits/stdc++.h>

using namespace std;

int main()
{

    int grupos[5] = {0};
    vector<int> mesas;
    mesas.clear();
    double m = 0, total = 0;
    cin >> grupos[1] >> grupos[2] >> grupos[3] >> grupos[4];
    
    m=grupos[4];
    mesas.resize((grupos[1] + grupos[2] + grupos[3] + grupos[4])-1);

    int i=3; int j=1;
    while (grupos[3])
    {
        if (grupos[3] && grupos[1]){
            grupos[3]--;
            grupos[1]--;
        } else {
            grupos[3]--;
        }
        m++;
    }
    while (grupos[2])
    {
        if (grupos[2] >=2){
            grupos[2]-=2;
        } else if (grupos[1]>=2 && grupos[2] > 1){
            grupos[2]--;
            grupos[1]-=2;
        } else if (grupos[1] > 1 && grupos[2] > 1){
            grupos[2]--;
            grupos[1]--;
        } else {
            grupos[2]--;
        }
        m++;
    }
    while (grupos[1])
    {
        total+=1;
        grupos[1]--;
    }
    m+=ceil(total/4);
    
    cout << m << '\n';
    return 0;
}