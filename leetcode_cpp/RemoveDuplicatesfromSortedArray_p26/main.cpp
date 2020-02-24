//  p26
//  Remove Duplicates from Sorted Array
//
//  main.cpp
//  RemoveDuplicatesfromSortedArray_p26
//
//  Created by 魏思哲 on 20/2/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//  主要是vector的一些操作，比如迭代器、插入删除函数，这些要是都会的话 还是挺有用的

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int i=0;
        std::vector<int>::iterator it = nums.begin();
        while(it!=nums.end()){
            if(it+1!=nums.end()){
                if(nums[i+1]==nums[i]){
                    nums.erase(it+1);
                }
                else{
                    i+=1;
                    it = nums.begin()+i;
                }
            }
            else break;
        }

        int result;
        result = nums.size();

        return result;
    }
};

// 尝试双指针失败
//class Solution {
//public:
//    int removeDuplicates(vector<int>& nums) {
//        for(int i=0;i<nums.size();i++){
//            for(int j=1;nums[i+j]==nums[i];j++){
//                nums[i]=nums[i+j];
//            }
//        }
//
//        int result;
//        result = nums.size();
//
//        return result;
//    }
//};


int main() {
    Solution problem;
    vector<int> nums;
    for (int i=0; i<6; i++) {
        nums.push_back(0);
    }
    for(int i=0;i<7;i++){
        nums.push_back(i);
    }
    for(int i=0;i<4;i++){
           nums.push_back(7);
    }
    for(int i=0;i<4;i++){
        nums.push_back(8);
    }
    for(int j=0;j<nums.size();j++) cout<<nums[j]<<',';
    
    int result;
    result = problem.removeDuplicates(nums);
    
    printf("\n**********************************\n");
    for(int j=0;j<nums.size();j++) cout<<nums[j]<<',';
    cout<<"result="<<result<<endl;
    
    return 0;
}


