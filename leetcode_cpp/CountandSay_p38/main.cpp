//
//  main.cpp
//  CountandSay_p38
//
//  Created by 魏思哲 on 26/2/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string result;
        result = read(n);
        return result;
    }
    string read(int level){
        if(level==1) return "1";
        string thislevel;
        string uplevel;
        uplevel = read(level-1);
        
        int i=0,j=0;
        for(i=0;i<uplevel.size();i++){
            for(j=0;(j+i)<uplevel.size();j++){
                if(uplevel[j+i]!=uplevel[i]) break;
            }
//            thislevel+=('0'+j); //ok use
            thislevel += to_string(j);
//            thislevel += to_string(uplevel[i]); //wrong use, note that uplevel is a string already
            // to_string() needs C++11, #include <string>
            // credit: https://stackoverflow.com/questions/191757/how-to-concatenate-a-stdstring-and-an-int
            thislevel.append(1, uplevel[i]);
            // wrong use: thislevel.append(uplevel[i]), which leads to add a string from uplevel[i]
            i = i+j-1;
        }
        return thislevel;
    }
};

int main() {
    int target=7;
    Solution problem;
    string result;
    result = problem.countAndSay(target);
    cout<<result<<endl;
    return 0;
}
