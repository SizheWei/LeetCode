//
//  main.cpp
//  msra
//
//  Created by 魏思哲 on 3/6/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

//1. Given a recursively defined sequence s_n = {s_{n-1}, n+1, s_{n-1}}, s_0 = {1}, tell me:
//(1) How many terms in s_n; (Just a formula)
//(2) Write a piece of code to get the value of s_n[i], where i in [0, |s_n|-1]
//Note: from the definition of s_n, we get s_1={1,2,1}, s_2={1,2,1,3,1,2,1}, etc.

// $$ S_{n} = 2^{n+1} - 1 $$

#include <iostream>
#include "string"
using namespace std;

class Solution{
private:
    string getsn(int level){
            string tmp;
            if(level == 0){
                tmp = "1";
            }
            else{
                store.append(getsn(level - 1));
                store.append(string(level));  //
    //            cout<<level<<" ";
                store.append(getsn(level - 1));
            }
            
            return tmp;
    }
public:
    string s0 = "1";
    string store;
    void getone(int level, int count){
        string result;
        result = getsn(level);
        cout<<result[count];
    }
    
};

int main() {
    // insert code here...
    Solution problem;
    int n = 1;
    int count = 0;
    problem.getone(n,count);

    return 0;
}


