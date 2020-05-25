//
//  main.cpp
//  C30_01_SingleNumber
//
//  Created by 魏思哲 on 1/4/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

//class Solution {
//public:
//    int singleNumber(vector<int>& nums) {
//        int result=0;
//        bool flag=true;
//        int length = nums.size();
//        for(int i=0;i<length;i++){
//            flag = true;
//            for(int j=0;j<length;j++){
//                if(j==i) continue;
//                if(nums[j]==nums[i]){
//                    flag = false;
//                    continue;
//                }
//            }
//            if(!flag) continue;
//            if(flag) return nums[i];
//        }
//        return result;
//    }
//};

/**
 * Credits: https://www.geeksforgeeks.org/find-element-appears-array-every-element-appears-twice/
 */
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int length = nums.size();
        if(length==1) return nums[0];
        int result = nums[0];
        for(int i=1;i<length;i++){
            result = result ^ nums[i];
        }
        return result;
    }
};

int main(){
    vector<int> nums{1,2,3,3,2,5,1};
    Solution problem;
    int result = problem.singleNumber(nums);
    cout<<"result = "<<result<<endl;
    return 0;
}
