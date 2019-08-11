//
//  main.cpp
//  PalindromeNumber
//
//  Created by 魏思哲 on 10/8/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        bool result=true;
        int mid_x=x;
        int nums;
        vector<int> vec;
        if (mid_x<0)
            return false;
        else{
            while(true){
                vec.push_back(mid_x%10);
                mid_x /= 10;
                if (mid_x==0)
                    break;
            }
            nums=vec.size();
            for(int i=0; i<=(nums-1)/2; i++){
                if(vec[i]==vec[nums-1-i]) continue;
                else{
                    result = false;
                    break;
                }
            }
        }
        return result;
    }
};

int main() {
    Solution problem;
    bool result;
    result = problem.isPalindrome(14566541);
    cout<<result<<endl;
    
    return 0;
}
