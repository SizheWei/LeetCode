//
//  DiceRolls.cpp
//  WeeklyContest_149
//
//  Created by 魏思哲 on 11/8/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int result=0;
        result = caculate(d, f, target);
        return result;
    }
    int caculate(int dive, int face, int nums, int solutions=0){
        if(dive>1){
            for(int i=1; i<=face; i++){
                solutions+=caculate(dive-1, face, nums-i);
            }
        }
        else
            if(nums<=face)
                solutions+=1;
        solutions %= int((pow(10, 9)+7));
        return solutions;
    }
};

int main(){
    Solution problem;
    int finalresult=0; //the result we wanna get finally;
    finalresult = problem.caculate(30, 30, 500);
    cout<<finalresult<<endl;
    return 0;
}
