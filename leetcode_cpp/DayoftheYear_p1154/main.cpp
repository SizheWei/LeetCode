//
//  main.cpp
//  WeeklyContest_149
//
//  Created by 魏思哲 on 11/8/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int dayOfYear(string date) {
        int result=0;
        bool flag=false; //false 代表平年 true 代表闰年
        int yy=0,mm=0,dd=0;
        char standard ='0';
        for(int i=0; i<4; i++){
            yy=10*yy+int(date[i]-standard);
        }
        for(int i=5;i<7;i++){
            mm=10*mm+int(date[i]-standard);
        }
        for (int i=8; i<10; i++){
            dd = 10*dd + int(date[i]-standard);
        }
        if((yy%4==0 && yy%100!=0) || yy%400==0) flag=true;
        for (int j=1;j<mm;j++){
            switch (j) {
                case 1:
                case 3:
                case 5:
                case 7:
                case 8:
                case 10:
                    result+=31;
                    break;
                case 2:
                    if(flag){
                        result+=29;
                        break;
                    }
                    result+=28;
                    break;
                case 4:
                case 6:
                case 9:
                case 11:
                    result += 30;
                    break;
            }
        }
        result+=dd;
        return result;
    }
};

int main() {
    Solution problem;
    int result;
    result=problem.dayOfYear("2004-03-01");
    cout << result<<endl;
    return 0;
}
