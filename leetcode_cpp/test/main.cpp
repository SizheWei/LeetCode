//
//  main.cpp
//  test
//
//  Created by 魏思哲 on 20/2/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>

using namespace std;

int main() {
    int N;
    bool isPrime = true;
    
    cin>>N;
    
    for(int i=2; i<=N/2; i++){
        if(N%i==0)
            isPrime = false;
    }
    
    cout<<isPrime<<endl;
    
    return 0;
}
