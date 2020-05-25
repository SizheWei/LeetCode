//
//  main.cpp
//  C30_05_BestTimetoBuyandSellStock2
//
//  Created by 魏思哲 on 6/4/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        bool mytype;
        int total = 0;
        total -= prices[0];
        mytype = true;
        int length = prices.size();
        int i=0;
        for(i=1;i<length;i++){
            if(mytype){
                if(prices[i]<prices[i-1]){
                    total += (prices[i-1] - prices[i]);
                    continue;
                }
                else if(prices[i]>prices[i-1]){
                    total += prices[i];
                    mytype = false;
                    continue;
                }
                else continue;
            }
            if (prices[i]>prices[i-1]) {
                total += (prices[i]-prices[i-1]);
                continue;
            }
            else{
                total -= prices[i];
                mytype = true;
                continue;
            }
        }
        if (mytype) {
            total += prices[i-1];
            mytype = false;
        }
        return total;
    }
};

int main() {
    vector<int> nums{};
    Solution problem;
    int result = problem.maxProfit(nums);
    cout<<"result = "<<result<<endl;
    return 0;
}
