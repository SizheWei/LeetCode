//
//  main.cpp
//  StringtoInteger_atoi_p8
//
//  Created by 魏思哲 on 21/8/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;


//class Solution {
//public:
//    int myAtoi(string str) {
//        return 0;
//    }
//};

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = int(s.size());
        int idealmaxlen = len;
        int curLen = 0;
        for (int i=0; i < len; i++){
            idealmaxlen = len - i;
            string tmp;
            tmp += s[i];
            int j = 0;
            for (j = 1; i + j < len; j++) {
                if(tmp.find(s[i+j]) == string::npos){
                    tmp += s[i+j];
                    continue;
                }
                else break;
            }
            if (j>curLen) {
                curLen = j;
            }
            if (curLen == idealmaxlen){
                break;
            }
        }
        return curLen;
    }
};

int main() {
    Solution problem;
    string s = "Hello,world!";
//    int result = problem.myAtoi(s);
    int result = problem.lengthOfLongestSubstring(s);
    cout << result;
    return 0;
}
