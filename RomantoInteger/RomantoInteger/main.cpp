//
//  main.cpp
//  RomantoInteger
//
//  Created by 魏思哲 on 13/8/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//
// Leetcode # 13

//  Symbol       Value
//  I             1
//  V             5         IV 4
//  X             10        IX 9
//  L             50        XL
//  C             100       XC
//  D             500       CD
//  M             1000      CM

#include <iostream>
#include <string> // for the build-in function : strlen

using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        int result =0 ;
//        enum romanletter {I, V, X, L, C, D, M};
        for (int i=0; i<s.length(); i++){
            switch (s[i]) {
                case 'I':
                    if(s[i+1]=='V'){
                        result+=4;
                        i++;
                    }
                    else if (s[i+1]=='X'){
                        result+=9;
                        i++;
                    }
                    else result +=1;
                    break;
                case 'V':
                    result+=5;
                    break;
                case 'X':
                    if(s[i+1]=='L'){
                        result+=40;
                        i++;
                    }
                    else if (s[i+1]=='C'){
                        result+=90;
                        i++;
                    }
                    else result +=10;
                    break;
                case 'L':
                    result+=50;
                    break;
                case 'C':
                    if(s[i+1]=='D'){
                        result+=400;
                        i++;
                    }
                    else if (s[i+1]=='M'){
                        result+=900;
                        i++;
                    }
                    else result +=100;
                    break;
                case 'D':
                    result+=500;
                    break;
                case 'M':
                    result+=1000;
                    break;
            }
        }
        return result;
    }
};

int main() {
    Solution problem;
    int result = problem.romanToInt("III");
    cout<<result<<endl;
    return 0;
}
