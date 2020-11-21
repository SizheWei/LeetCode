//
//  main.cpp
//  RegularExpressionMatching_p10
//
//  Created by 魏思哲 on 24/8/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

// DP:
class Solution {
public:
    bool isMatch(string s, string p) {
        // for the case of empty set:
        if (s.empty() ^ p.empty()) return false; // only one of strings is empty
        if (s.empty() & p.empty()) return true; // both empty
        
        s = ' ' + s;
        p = ' ' + p;
        
        int ssize, psize;
        ssize = int(s.size());
        psize = int(p.size());
        
        // initialization:
        bool dp[ssize+1][psize+1];
        memset(dp, false, (ssize+1)*(psize+1));
        dp[0][0] = true;
        
        // DP
        for (int i=1; i<=ssize; ++i) {
            for (int j=1; j<=psize; ++j) {
                if (s[i-1]==p[j-1] || p[j-1]=='.')
                    dp[i][j] = dp[i-1][j-1];
                else if (p[j-1]=='*'){
                    dp[i][j] = dp[i][j-2] // preceding char repeat 0 time
                    || ( (p[j-2]==s[i-1] || p[j-1]=='.') && dp[i][j-1] ) // 1 time
                    || ( (p[j-2]==s[i-1] || p[j-1]=='.') && dp[i-1][j] ); // 2+ times
                }
                else dp[i][j] = false;
            }
        }
        return dp[ssize][psize];
    }
};

int main() {
    Solution problem;
    string s="ab", p=".*";
    cout<<problem.isMatch(s, p)<<endl;
    return 0;
}


