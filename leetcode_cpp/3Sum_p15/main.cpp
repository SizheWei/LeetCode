//
//  main.cpp
//  3Sum_p15
//
//  Created by sizhewei on 2022/10/5.
//  Copyright © 2022 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> result;
        
        sort(nums.begin(), nums.end());                     // sort nums (greater), to get rid of the problem of repeated results
        
        int lp(0), rp(0);                                   // double pointer
        
        for (int i=0; i<nums.size()-2; i++) {
            if (nums[i] > 0) {                              // if nums[i] > 0, then all the following element is greater than 0
                return result;
            }
            if (i>0 && nums[i]==nums[i-1]) {
                continue;
            }
            lp = i + 1;
            rp = int(nums.size()) - 1;
            while (lp < rp) {
                if(nums[i]+nums[lp]+nums[rp] == 0){         // find a solutioin
                    vector<int> one_solu{nums[i], nums[lp], nums[rp]};
                    result.push_back(one_solu);
                    do{rp--;} while(rp>lp && nums[rp]==nums[rp+1]);
                    do{lp++;} while(lp<rp && nums[lp]==nums[lp-1]);
                }
                
                else if (nums[i]+nums[lp]+nums[rp] > 0) {
                    do{rp--;} while(rp>lp && nums[rp]==nums[rp+1]);
                }
                
                else if (nums[i]+nums[lp]+nums[rp] < 0) {
                    do{lp++;} while(lp<rp && nums[lp]==nums[lp-1]);
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
//    vector<int> nums{-4, -4, -3, -2, -1, 0, 1, 2, 3, 4, 5, 6, 7, 8, 8, 8, 9, 9, 9, 10, 10};
    vector<int> nums{-1, 3, 3};
    Solution problem;
    vector<vector<int>> results = problem.threeSum(nums);
    cout << "result size: " << results.size() << endl;
    for (int i=0; i<results.size(); i++){
        for (int j=0; j<3; j++) {
            cout << results[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
