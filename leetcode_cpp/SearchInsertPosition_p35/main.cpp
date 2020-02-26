//
//  main.cpp
//  SearchInsertPosition_p35
//
//  Created by 魏思哲 on 26/2/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int i=0;
        for(i=0;i<nums.size();i++){
            if(target<=nums[i]) return i;
        }
        return i;
    }
};

int main() {
    vector<int> nums;
    for(int i=0;i<5;i++) nums.push_back(i*3);
//    nums.push_back(1);
//    nums.push_back(3);
//    nums.push_back(5);
//    nums.push_back(6);
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<",";
    int target=7;
    
    Solution problem;
    int result;
    
    result = problem.searchInsert(nums, target);
    printf("\n********\n");
    cout<<"result="<<result<<endl;
    
    return 0;
}
