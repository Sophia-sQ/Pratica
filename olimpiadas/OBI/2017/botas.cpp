#include <bits/stdc++.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int N;
    int botasD[61]={0};
    int botasE[61]={0};
    char lado;
    int num;
    int pares = 0;
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        cin >> num >> lado;
        if (lado == 'E'){
            botasE[num]++;
        } else{
            botasD[num]++;
        }

        if (botasD[num]>0 && botasE[num]>0){
            botasD[num]--;
            botasE[num]--;
            pares++;
        }
    }

    cout << pares<<"\n";
    return 0;
}