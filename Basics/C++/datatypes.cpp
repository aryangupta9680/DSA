#include <bits/stdc++.h>
using namespace std;

int main()
{
    // int
    int x = 10;
    cout << x << endl;

    // long
    long y = 20;
    cout << y << endl;

    long long amount = 2974629990000;
    cout << amount << endl;

    // float
    float z = 102.47;
    cout << z << endl;
    float a = 78;
    cout << a << endl;

    // double
    double b = 34.3826;
    cout << b << endl;

    // string and getline
    string name = "Aryan";
    cout << name << endl;
    string s1;
    string s2;
    cin >> s1;
    cin >> s2;
    cout << "string is: " << s1 << " " << s2 << endl;

    string str;
    cout << "Enter string: ";
    getline(cin, str);
    cout << "String is: " << str << endl;

    // char
    char c = 't';
    cout << c << endl;
    char ch;
    cin >> ch;
    cout << ch << endl;

    // bool
    bool IsValid = true;
    bool IsValidName = 0;
    cout << IsValid << endl;
    cout << IsValidName << endl;

    return 0;
}