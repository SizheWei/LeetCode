//
//  main.cpp
//  ContainerWithMostWater_p11
//
//  Created by sizhewei on 2022/10/2.
//  Copyright © 2022 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

//class Solution {
//public:
//    int maxArea(vector<int>& height) {
//        int result = 0;
//        int len = int(height.size());
//        int shorter = 0;
//        for (int le = 0; le < len-1; le++){
//            for (int ri = le+1; ri < len; ri++) {
//                shorter = height[le] < height[ri] ? height[le] : height[ri];
//                int container = (ri - le) * shorter;
//                if (container > result)
//                    result = container;
//            }
//        }
//        return result;
//    }
//};

class Solution {
public:
    int maxArea(vector<int>& height) {
        int result(0), width(0), temp(0), container(0);
        int len = int(height.size());
        int lp = 0;
        int rp = len - 1;
        while (lp != rp) {
            width = rp - lp;
            if(height[lp] < height[rp]){
                temp = height[lp];
                lp++;
            }
            else{
                temp = height[rp];
                rp--;
            }
            container = temp * width;
            if (container > result) {
                result = container;
            }
        }
        return result;
    }
};


int main(int argc, const char * argv[]) {
    vector<int> height{1,2,3};
    Solution problem;
    cout << problem.maxArea(height) << endl;
    return 0;
}
