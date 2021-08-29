#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // your code goes here
    int hh_hand, mm_hand;
    cin >> hh_hand >> mm_hand;

    float theta_hour = (hh_hand - 0) * 30;
    float theta_minute;

    float extra_min_degree, extra_min_degree_2;

    extra_min_degree = (mm_hand) * (0.5);
    theta_hour = theta_hour + extra_min_degree;

    if (mm_hand % 5 == 0)
    {
        theta_minute = (mm_hand / 5) * 30;
    }
    else
    {
        theta_minute = (mm_hand / 5) * 30 + (mm_hand % 5) * 0.5;
    }

    cout << theta_hour << endl;
    cout << theta_minute << endl;

    cout << abs(theta_minute - theta_hour) << endl;
    return 0;
}
