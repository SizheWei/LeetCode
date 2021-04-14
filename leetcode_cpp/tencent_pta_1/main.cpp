//
//  main.cpp
//  tencent_pta_1
//
//  Created by 魏思哲 on 2021/4/13.
//  Copyright © 2021 SizheWei. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;

vector<bool> flag;

int main()
{
    int T = 0;
    cin >> T;
    while (T > 0) {
        int n;
        cin >> n;
        int count_p = 0, count_n = 0, count_0 = 0;
        for (int i = 0; i < n; i++) {
            int item;
            cin >> item;
            if (item > 0) count_p++;
            else if (item == 0) count_0++;
            else count_n++;
        }
        bool item;
        if (count_p == count_n) {
            item = true;
        }
        else if (count_p > count_n) {
            item = (count_0 >= abs(count_p-count_n-1));
        }
        else item = (count_0 >= abs(count_n-count_p-1));
        flag.push_back(item);
        T--;
    }
    int len = int(flag.size());
    for (int i = 0; i < len; i++) {
        if (i==len-1) {
            if (flag[i]) {
                cout << "Yes";
            }
            else cout << "No";
        }
        else{
            if (flag[i]) {
                cout << "Yes" << endl;
            }
            else cout << "No" << endl;
        }
        
    }
    return 0;
}

