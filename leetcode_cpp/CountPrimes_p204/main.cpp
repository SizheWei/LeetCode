//
//  main.cpp
//  DB-Homework01
//
//  Created by 魏思哲 on 2/3/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <math.h>
using namespace std;

//class Solution {
//public:
//    int countPrimes(int n) {
//        if(n==0||n==1||n==2) return 0;
//        if(n==3) return 1;
//        if(n==4||n==5) return 2;
//        if(n==6||n==7) return 3;
//        if(n==8||n==9) return 4;
//        bool isPrime=true;
//        int amount=4;
//        for(int i=9;i<n;i+=2){
//            if((i%3==0)||(i%5==0)) continue;
//            isPrime=true;
//            for(int j=3;j<=sqrt(i);j+=2){
//                if(i%j==0){
//                    isPrime = false;
//                    break;
//                }
//            }
//            if(isPrime){
//                amount += 1;
//            }
//        }
//        return amount;
//    }
//};

int main() {
    int n;
//    Solution problem;
    int amount;
//    amount = problem.countPrimes(N);
    cin>>n;
    if(n==0||n==1||n==2){
        cout<<0;
        return 0;
    }
    if(n==3){
        cout<<1;
        return 0;
    }
    if(n==4||n==5){
        cout<<2;
        return 0;
    }
    if(n==6||n==7){
        cout<<3;
        return 0;
    }
    if(n==8||n==9){
        cout<<4;
        return 0;
    }
    bool isPrime=true;
    amount=4;
    for(int i=9;i<n;i+=2){
        if((i%3==0)||(i%5==0)) continue;
        isPrime=true;
        for(int j=3;j<=sqrt(i);j+=2){
            if(i%j==0){
                isPrime = false;
                break;
            }
        }
        if(isPrime){
            amount += 1;
        }
    }
//    printf("\n-----------\n");
    cout<<amount;
    return 0;
}


