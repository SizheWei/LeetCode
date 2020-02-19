//
//  main.cpp
//  twoSum
//
//  Created by 魏思哲 on 8/8/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j,n;
        vector<int> list;
        n=nums.size();
        for(i=0;i<n-1;i++){
            for(j=i+1;j<n;j++){
                if ((nums[i]+nums[j])==target){
                    list.push_back(i);
                    list.push_back(j);
                    return list;
                }
            }
        }
        return list;
    }
};

int main() {
    Solution problem;
    vector<int> numarr,result;
//    for(int i=0; i<5; i++){
//        numarr.push_back(3*i);
//    }
    numarr.push_back(3);
    numarr.push_back(2);
    numarr.push_back(4);
    result = problem.twoSum(numarr, 6);
    cout<<result[0]<<'\r';
    cout<<result[1]<<endl;
    return 0;
}

