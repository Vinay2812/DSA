#include <bits/stdc++.h>
using namespace std;

string uniqueCharacterStream(string str)
{
    vector<int> count(26, 0);
    list<char> dq;
    int n = str.size();

    for (int i = 0; i < n; i++)
    {

        count[str[i] - 'a']++;

        if (count[str[i] - 'a'] == 1)
            dq.push_back(str[i]);

        while (!dq.empty() && count[dq.front() - 'a'] > 1)
            dq.pop_front();

        if (dq.empty())
        {
            str[i] = '#';
        }
        else
        {
            str[i] = dq.front();
        }
    }
    return str;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string str;
    cin >> str;

    cout << uniqueCharacterStream(str);

    return 0;
}