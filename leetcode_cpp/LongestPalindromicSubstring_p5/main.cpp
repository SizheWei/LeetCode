//
//  main.cpp
//  LongestPalindromicSubstring_p5
//
//  Created by 魏思哲 on 17/8/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>

using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string result;
        int n = s.length();
        bool **f = new bool*[n];
        for(int i=0; i<n; i++){
            f[i] = new bool [n];
        }
        int head = 0, tail = 0, tmp = 0;
        int i = 0, j = 0;
        for(i = n-1 ; i >= 0 ; i--){
            for(j = i ; j < n ; j++){
                if(i==j){
                    f[i][j] = 1;
                }
                else if (s[i] == s[j]){
                    if ((j-i)==1)
                        f[i][j] = true;
                    else
                        f[i][j] = f[i+1][j-1];
                }
                else if (s[i] != s[j]){
                    f[i][j] = 0;
                }
                
                if (f[i][j] == 1 && (j-i)>tmp) {
                    head = i;
                    tail = j;
                    tmp = j - i;
                }
                
            }
        }
        result = s.substr(head, tail-head+1);
        return result;
    }
};

int main() {
    Solution problem;
    string s = "abbbbba";
    string result;
    result = problem.longestPalindrome(s);
    cout<<"The result is: \n"<<result<<endl;
    return 0;
}
