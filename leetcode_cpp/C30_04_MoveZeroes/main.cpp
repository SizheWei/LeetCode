//
//  main.cpp
//  C30_04_MoveZeroes
//
//  Created by 魏思哲 on 4/4/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int zerocount = 0;
        do{
            vector<int>::iterator it = find(nums.begin(),nums.end(),0);
            if(it != nums.end()){
                nums.erase(it);
                zerocount++;
            }
            else break;
        }while(1);
//        cout<<zerocount<<endl;
        while(zerocount){
            nums.push_back(0);
            zerocount--;
        }
    }
};
int main() {
    // insert code here...
    vector<int> nums{1,3,5};
    Solution problem;
    problem.moveZeroes(nums);
    for(int i=0;i<nums.size();i++){
        cout<<nums[i]<<",";
    }
    return 0;
}
