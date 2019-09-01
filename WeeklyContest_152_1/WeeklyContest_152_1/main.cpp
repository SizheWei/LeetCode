//  leetcode weekly contest # 152 - 1
//  main.cpp
//  WeeklyContest_152_1
//
//  Created by 魏思哲 on 1/9/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;

class Solution {
public:
    int numPrimeArrangements(int n) {
        int result = 0;
        long int temp=0;
        int k=0;
        int j;
        int MAX = pow(10,9)+7;
        int num_p=0;
        int num_r=0;
        for (k=1;k<=n;k++){
            for(j=2;j<k;j++){
                if(k%j==0)
                    break;
            }
            if(j==k)
                num_p+=1;
        }
        num_r = n-num_p;
        int i = 1;
        long int result_1 = 1;
        long int result_2 = 1;
        for(i=1;i<=num_r;i++){
            result_1 = (result_1*i)%MAX;
        }
        for(i=1;i<=num_p;i++){
            result_2 = (result_2*i)%MAX;
        }
        temp = (result_1*result_2)%MAX;
        result = int(temp);
        return result;
    }
};

int main() {
    // insert code here...
    Solution problem;
    int result;
    result=problem.numPrimeArrangements(7);
    cout << result<<endl;
    return 0;
}
