//
//  main.cpp
//  MergeSortedArray_p88
//
//  Created by 魏思哲 on 23/7/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        vector<int> tmp = nums1;
        int i = 0;
        int j = 0;
        int k = 0;
        for(k=0 ; k<m+n ; k++){
            if(i<m&&j<n){
                if(nums2[j]<=nums1[i]){
                    tmp[k] = nums2[j];
                    j++;
                }
                else if (nums2[j]>nums1[i]){
                    tmp[k] = nums1[i];
                    i++;
                }
            }
            else if (i<m){
                tmp[k] = nums1[i];
                i++;
            }
            else if (j<n){
                tmp[k] = nums2[j];
                j++;
            }
        }
        nums1 = tmp;
    }
};

int main() {
    Solution problem;
    vector<int> nums1{1,2,3,0,0,0};
    vector<int> nums2{2,5,6};
    int n = nums2.size();
    int m = nums1.size() - n;
    problem.merge(nums1, m, nums2, n);
    for(int i=0;i<nums1.size();i++){
        cout<<nums1[i]<<endl;
    }
//    int i,j,k = 0;
//    cout<<"i="<<i;
    return 0;
}

