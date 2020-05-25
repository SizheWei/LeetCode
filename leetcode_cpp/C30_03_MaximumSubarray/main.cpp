//
//  main.cpp
//  C30_03_MaximumSubarray
//
//  Created by 魏思哲 on 4/4/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int result=nums[0],tmp=0;
        int length = nums.size();
        for(int i=0;i<length;i++){
//            if(nums[i]<=0) continue; // if numbers are all negtive, then this clause is wrong.
            tmp = 0;
            for(int j=0;(i+j)<length;j++){
                tmp += nums[i+j];
                if(tmp>result) result = tmp;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{-2,-1};
    Solution problem;
    int result = problem.maxSubArray(nums);
    cout<<"result="<<result<<endl;
    return 0;
}
