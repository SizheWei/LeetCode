//
//  main.cpp
//  SquaresofaSortedArray_p977
//
//  Created by 魏思哲 on 4/12/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& A) {
        int n = int(A.size());
        int negative = -1;
        for (int i = 0; i < n; ++i) {
            if (A[i] < 0) {
                negative = i;
            }
            else {
                break;
            }
        }

        vector<int> ans;
        int i = negative, j = negative + 1;
        while (i >= 0 || j < n) {
            if (i < 0) {
                ans.push_back(A[j] * A[j]);
                ++j;
            }
            else if (j == n) {
                ans.push_back(A[i] * A[i]);
                --i;
            }
            else if (A[i] * A[i] < A[j] * A[j]) {
                ans.push_back(A[i] * A[i]);
                --i;
            }
            else {
                ans.push_back(A[j] * A[j]);
                ++j;
            }
        }

        return ans;

    }
};

int main(int argc, const char * argv[]) {
    vector<int> nums;
    int temp = 0;
    do {
        cin >> temp;
        nums.push_back(temp);
    } while(cin.get()!='\n');
    Solution problem;
    vector<int> result = problem.sortedSquares(nums);
    int length = int(result.size());
    for (int i = 0; i < length - 1; ++i) {
        cout << result[i] << " " ;
    }
    cout << result[length-1];
    return 0;
}
