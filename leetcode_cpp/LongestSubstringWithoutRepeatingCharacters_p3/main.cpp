//
//  main.cpp
//  LongestSubstringWithoutRepeatingCharacters_p3
//
//  Created by 魏思哲 on 28/2/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int result=0, tmplen=0;
        int pos;
        for(int i=0;i<s.size();i++){
            int end = s.size(), tmplen = 1;
            for(int j=1;(i+j)<end;j++){
                if(s[i+j]==s[i]){
                    break;
                }
                if(i+j+1>=s.size()){
                    tmplen += 1;
                    if(tmplen>result){
                        result = tmplen;
                        return result;
                    }
                    else break;
                }
                pos = s.find_first_of(s[i+j],i+j+1);
                if (pos == -1) {
                    tmplen += 1;
                }
                else if(pos<end){
                    end = pos;
                    tmplen += 1;
                }
                else{
                    tmplen += 1;
                }
            }
            if(tmplen>result){
                result = tmplen;
            }
        }
        
        return result;
    }
};

int main() {
    string s = "";
    Solution problem;
    int result = 0;
    result = problem.lengthOfLongestSubstring(s);
    cout<<"result="<<result<<endl;
    return 0;
}
