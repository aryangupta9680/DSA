#include <bits/stdc++.h>
using namespace std;

// void -> which does not return anything
// return -> 
// parameterised ->
// non-parameterised ->

// void printName(string name)
// {
//     cout << "Hey " << name << "!" << endl;
// }

// int sum(int num1, int num2)
// {
//     return num1+num2;
// }

// int maxx(int a, int b)
// {
//     if(a>=b) return a;
//     else return b;
// }

// pass by value
// void doSomething(int num)
// {
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
//     num += 5;
//     cout << num << endl;
// }

// pass by reference
void doSomething(int &num)
{
    cout << num << endl;
    num += 5;
    cout << num << endl;
    num += 5;
    cout << num << endl;
}

void printArray(int arr[])
{
    for(int i = 0; i < 5;i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    // string name;
    // cout << "Enter your name: ";
    // cin >> name;
    // printName(name);

    // int num1, num2;
    // cout << "Enter num1: ";
    // cin >> num1;
    // cout << "Enter num2: ";
    // cin >> num2;
    // cout << sum(num1, num2) << endl;

    // int a, b;
    // cout << "Enter a: ";
    // cin >> a;
    // cout << "Enter b: ";
    // cin >> b;
    // int minimum = min(a, b);
    // int maximum = maxx(a, b);
    // cout << minimum << endl;
    // cout << maximum << endl;


    // int num = 10;
    // doSomething(num);
    // cout << num << endl;
    
    int arr[5];
    for(int i = 0; i < 5;i++)
    {
        cin >> arr[i];
    }
    printArray(arr);
    
    return 0;
}