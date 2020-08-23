//
//  main.cpp
//  MedianofTwoSortedArrays_p4
//
//  Created by 魏思哲 on 16/6/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int s1=0, s2=0;
        s1 = nums1.size();
        s2 = nums2.size();
        int len = s1+s2;
        int p1 = 0, p2 = 0;
        vector<int> tmps(len);
        int leno2p1 = ceil(len/2)+1;
        for(int i=0;i<leno2p1;i++){
            if(p1<s1 && p2<s2){
                if(nums1[p1] <= nums2[p2]){
                    tmps[i] = nums1[p1];
                    p1++ ;
                }
                else{
                    tmps[i] = nums2[p2];
                    p2++ ;
                }
            }
            
            else if (p1<s1){
                tmps[i] = nums1[p1];
                p1++ ;
            }
            
            else if (p2<s2){
                tmps[i] = nums2[p2];
                p2++ ;
            }
        }
        
        if(len%2 == 0)
            return (tmps[len/2-1]+tmps[len/2])/2.0;
        else
            return tmps[floor(len/2)];
        
    }
};

int main() {
    Solution problem;
    vector<int> nums1{1,3};
    vector<int> nums2{6,7};
    double result = 0;
    result = problem.findMedianSortedArrays(nums1, nums2);
    cout<<result<<endl;
    return 0;
}
