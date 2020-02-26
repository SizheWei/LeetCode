//
//  main.cpp
//  ImplementstrStr_p28
//
//  Created by 魏思哲 on 24/2/20.
//  Copyright © 2020 SizheWei. All rights reserved.

//  Note: 1. what about empty haystack?
//        2. what about empty needle?
//        3. what about haystack.size()<needle.size() ?

#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if(needle.size()==0) return 0;
        if(haystack.size()<needle.size()) return -1;
        for(int i=0;i<(haystack.size()-needle.size()+1);i++){
            int j=0;
            for(j=0;j<needle.size();j++){
                if(haystack[i+j]!=needle[j]) break;
            }
            if(j==needle.size()) return i;
        }
        
        return -1;
    }
};

int main() {
    string hay = "abb";
    string nee = "abb";
    
    Solution problem;
    int result;
    result = problem.strStr(hay, nee);
    
    cout<<"result="<<result<<endl;
    
    return 0;
}
