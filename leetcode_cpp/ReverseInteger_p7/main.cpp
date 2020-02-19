//
//  main.cpp
//  reverseInteger
//
//  Created by 魏思哲 on 9/8/19.
//  Copyright © 2019 SizheWei. All rights reserved.
//
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        long mid_x;
        mid_x=long(x);
        int result=0;
        long mid_res=0;
        bool flag=true;
        if(mid_x<0){
            flag=false;
            mid_x=abs(mid_x);
        }
        while(true){
            mid_res = mid_res*10 + mid_x%10;
            mid_x /= 10;
            if(mid_x==0)
                break;
        }
        if(flag&&(mid_res>int(0x7fffffff)))
            return 0;
        if(!flag){
            mid_res=0-mid_res;
            if(mid_res<int(0x80000000))
                return 0;
        }
        result = int(mid_res);
        return result;
    }
};

int main() {
    Solution problem;
    int num;
    num = problem.reverse(214748364);
    cout<<num<<endl;
    return 0;
}

    
//int main(){
//    cout<<int(0x7fffffff)<<endl;
////    cout<<0x00000000<<endl;
//}
