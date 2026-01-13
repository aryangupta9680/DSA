#include <bits/stdc++.h>
using namespace std;

int main()
{
    string s = "Aryan";
    int len = s.size();
    cout << s[0] << endl;
    s[len-1] = 'N';
    cout << s[len-1] << endl;
    return 0;
}