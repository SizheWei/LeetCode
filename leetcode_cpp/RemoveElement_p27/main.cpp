//  Remove Element p27
//  main.cpp
//  RemoveElement_p27
//
//  Created by 魏思哲 on 24/2/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>

#include <stdlib.h>
#include <time.h>

using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int result;
        vector<int>:: iterator it=nums.begin();
        int i=0;
        while(it!=nums.end()){
            if(nums[i]==val){
                nums.erase(it);
            }
            else{
                i++;
                it++;
            }
        }
        
        result = nums.size();
        return result;
    }
};

int main() {
    vector<int> nums;
    srand(time(NULL));
    int tmp;
    for(int i=0;i<20;i++){
        tmp = rand()%(5 - 0 + 1) + 0;
        nums.push_back(tmp);
    }

    printf("\n****origin vector*****\n");
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<",";
    Solution problem;
    int result;
    
    int val=3;
    
    result = problem.removeElement(nums, val);
    printf("\n****modified vector*****\n");
    for(int i=0;i<nums.size();i++) cout<<nums[i]<<",";
    printf("\n****result*****\n");
    cout << "result=" << result<<endl;
    
    return 0;
}
