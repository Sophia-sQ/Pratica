#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    vector<char> str;
    vector<char> f;
    vector<char> del;
    int i = -1;
    int d = 0;
    while (cin.get(c))
    {
        i++;
        if (c == '>' && toupper(str[i - 1]) == 'B' && str[i - 2] == '<')
        {
            //printf("acha <B>\n%c", str[i-3]);
            del.push_back(str[i - 3]);
            str.push_back(c);
            str.pop_back();
            str.pop_back();
            str.pop_back();
            str.pop_back();
            i-=4;
        }
        else if (c == '>' && toupper(str[i - 1]) == 'Z' && str[i - 2] == '<')
        {
            //printf("acha <Z>\n");
            str.pop_back();
            str.pop_back();
            //str.pop_back();
            i-=2;
            str.push_back(del[d]);
            d++;
        } else {
            str.push_back(c);
        }

    }

    i = 0;
    while (i < str.size())
    {
        cout << str[i];
        i++;
    }
    //printf("\n");

    return 0;
}