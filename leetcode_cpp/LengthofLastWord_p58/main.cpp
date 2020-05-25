//
//  main.cpp
//  LengthofLastWord_p58
//
//  Created by 魏思哲 on 25/5/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>

using namespace std;

class Solution {
public:
    int lengthOfLastWord(string s) {
        int tmpcount=0;
        int length = s.length();
        int i=0;
        while(i<length){
            if(s[i]==' '){
                i++;
                continue;
            }
            for(tmpcount=0;(s[i+tmpcount]!=' ')&((i+tmpcount)<length);tmpcount++){
                continue;
            }
            i += (tmpcount+1);
        }
        return tmpcount;
    }
};

int main() {
    // insert code here...
    Solution problem;
    string s = "        hello      my     love     ";
    cout<< problem.lengthOfLastWord(s)<<endl;
    return 0;
}
