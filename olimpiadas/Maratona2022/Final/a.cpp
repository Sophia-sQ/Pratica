#include <bits/stdc++.h>
using namespace std;

int main()
{
    char c;
    vector<char> str;
    int f = 0;
    while (cin.get(c))
    {
        str.push_back(c);
    }
    int i = 0;
    while (i < str.size())
    {
        if (str[i] == ':')
        {
            if (i != (str.size()) - 1 && (str[i + 1] == 'D' || str[i + 1] == ')' || str[i + 1] == 'O' || str[i + 1] == '('))
            {
                f++;
            }
        }

        if (str[i] == 'D' || str[i] == ')' || str[i] == 'O' || str[i] == '(')
        {
            if (i != (str.size()) - 1 && str[i + 1] == ':')
            {
                f++;
            }
        }

        i++;
    }

    printf("%d\n", f);

    return 0;
}