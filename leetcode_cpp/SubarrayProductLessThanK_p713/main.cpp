//
//  main.cpp
//  SubarrayProductLessThanK_p713
//
//  Created by 魏思哲 on 2021/3/31.
//  Copyright © 2021 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

/*
 //  自己的方法，time limit exceed
class mySolution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int result = 0;
        int numsLen = int(nums.size());
        for (int i = 0; i < numsLen; i++) {
            int temp = 1;
            for (int j = 0; j < numsLen - i; j++) {
                temp *= nums[i+j];
                if (temp >= k) {
                    break;
                }
                else result++;
            }
        }
        return result;
    }
};
*/
class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k == 0) return 0;
        int result = 0;
        int numsLen = int(nums.size());
        for (int i = 0; i < numsLen; i++) {
            int temp = 1;
            for (int j = 0; j < numsLen - i; j++) {
                temp *= nums[i+j];
                if (temp >= k) {
                    break;
                }
                else result++;
            }
        }
        return result;
    }
};

int main() {
    vector<int> nums{1, 1, 1, 1, 1};
    int k = 2;
    Solution problem;
    int result = problem.numSubarrayProductLessThanK(nums, k);
    cout << result << endl;
    return 0;
}
