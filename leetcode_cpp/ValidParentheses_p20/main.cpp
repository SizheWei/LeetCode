//  Leetcode Problem 20
//  Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.

//  main.cpp
//  ValidParentheses
//
//  Created by 魏思哲 on 5/12/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
#include <stack>

using namespace std;

class Solution {
private:
    int num_s=0,num_m=0,num_l=0;
    stack<int> leftchar;
    int latest_char = 0;// the latest char 0:( 1:[ 2:{
    int tmp_char = 0;
public:
    bool isValid(string s) {
        bool result=true;
        for(int i=0;i<s.size();++i){
            switch (s[i]) {
                case '(': {
                    leftchar.push(0);
                    num_s+=1;
                    break;
                }
                case '[': {
                    leftchar.push(1);
                    num_m+=1;
                    break;
                }
                case '{': {
                    leftchar.push(2);
                    num_l+=1;
                    break;
                }
                case ')': {
                    num_s-=1;
                    if(num_s<0||leftchar.top()!=0)
                        return false;
                    leftchar.pop();
                    break;
                }
                case ']': {
                    num_m-=1;
                    if(num_m<0||leftchar.top()!=1)
                        return false;
                    leftchar.pop();
                    break;
                }
                case '}': {
                    num_l-=1;
                    if(num_l<0||leftchar.top()!=2)
                        return false;
                    leftchar.pop();
                    break;
                }
                default: break;
            }
        }
        if(num_l!=0||num_m!=0||num_s!=0)
        return false;
        return result;
    }
};

int main() {
    bool result;
    Solution problem;
    string parameter="{{}";
    result = problem.isValid(parameter);
    cout << result<<endl;
    return 0;
}
