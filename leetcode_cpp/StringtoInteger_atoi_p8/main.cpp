//
//  main.cpp
//  StringtoInteger_atoi_p8
//
//  Created by 魏思哲 on 21/8/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
#include <limits>
#include <vector>

using namespace std;


class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int i=0;
        int len = int(str.size());
        bool findnum = false;
        bool plusmins = 1;
        long long int result = 0;
        for (i=0;i<len;i++){
            if(!findnum){
                if (str[i]==' ') {
                    continue;
                }
                else if (!((str[i] == '+' || str[i] == '-')||(str[i]>='0' && str[i]<='9'))) {
                    return 0;
                }
                else if (str[i] == '+' || str[i] == '-') {
                    if ((i+1 < len) & (str[i+1]<='9' && str[i+1]>='0')) {
                        findnum = true;
                        plusmins = str[i]=='-' ? 0 : 1;
                        i++;
                        result = 10*result + int(str[i]-'0');
                        continue;
                    }
                    else break;
                }
                else if((str[i]>='0' && str[i]<='9')){
                    findnum = true;
                    result = 10*result + int(str[i]-'0');
                    continue;
                }
            }
            else if (str[i]>='0' && str[i]<='9'){
                result = 10*result + int(str[i]-'0');
                if (plusmins && result > INT_MAX) {
                    return INT_MAX;
                }
                if (!plusmins && -result < INT_MIN) {
                    return INT_MIN;
                }
            }
            else
                break;
        }
        
        if (!findnum) {
            return 0;
        }
        
        return plusmins ? int(result):int(-result);
    }
};


int main() {
    Solution problem;
    string s = "91283472332";
    int result = problem.myAtoi(s);
    cout << result;
    return 0;
}
