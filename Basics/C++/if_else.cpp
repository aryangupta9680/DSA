#include <bits/stdc++.h>
using namespace std;

int main()
{
    // example 1:
    // int age;
    // cout << "Enter age: ";
    // cin >> age;
    // if(age>18)
    // {
    //     cout << "Eligible to vote" << endl;
    // }
    // else if(age==18)
    // {
    //     cout << "Eligible to vote" << endl;
    // }
    // else
    // {
    //     cout << "Not eligible to vote" << endl;
    // }


    // example 2:
    int marks;
    cout << "Enter marks: ";
    cin >> marks;
    if(marks>=90)
    {
        cout << "A grade" << endl;
    }
    else if(marks>=80 && marks<90)
    {
        cout << "B grade" << endl;
    }
    else if(marks>=70 && marks<80)
    {
        cout << "C grade" << endl;
    }
    else if(marks>=60 && marks<70)
    {
        cout << "D grade" << endl;
    }
    else
    {
        cout << "Fail" << endl;
    }


    // Example 3:
    int age;
    cout << "Enter age: ";
    cin >> age;
    if(age<18)
    {
        cout << "Not eligible for job" << endl;
    }
    else if(age<=60)
    {
        cout << "Eligible for job ";
        if(age>=55)
        {
            cout << "but Retirement soon" << endl;
        }
    }
    else
    {
        cout << "Retirement time" << endl;
    }

    return 0;
}