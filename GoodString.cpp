#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int calc(const string &s, char c)
{
    if (s.size() == 1)
    {
        return s[0] != c;
    }
    int move1 = calc(s.substr(0, s.size() / 2), c + 1);
    move1 += s.size() / 2 - count(s.begin() + s.size() / 2, s.end(), c);
    int move2 = calc(s.substr(s.size() / 2), c + 1);
    move2 += s.size() / 2 - count(s.begin(), s.begin() + s.size() / 2, c);
    return min(move1, move2);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string s;
        cin >> n >> s;
        cout << calc(s, 'a') << endl;
    }
    return 0;
}
