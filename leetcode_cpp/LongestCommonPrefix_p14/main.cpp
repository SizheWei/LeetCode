//
//  main.cpp
//  LongestCommonPrefix
//
//  Created by 魏思哲 on 13/8/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//
//  leetcode # 14

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        string result="";
        if(strs.size()!=0){
            string tmp=strs[0];
            for(int j=0;j<strs.size();j++){
                int i=0;
                result="";
                while(i<min(tmp.size(),strs[j].size())){
                    if(tmp[i]==strs[j][i]){
                        result=result+tmp[i];
                        i++;
                    }
                    else break;
                }
                tmp=result;
            }
        }
        return result;
    }
};

int main() {
    Solution problem;
    string result;
    vector<string> prem = {"a"};
    result = problem.longestCommonPrefix(prem);
    cout<<result<<endl;
    return 0;
}
