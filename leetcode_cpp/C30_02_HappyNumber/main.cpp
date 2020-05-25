//
//  main.cpp
//  C30_02_HappyNumber
//
//  Created by 魏思哲 on 2/4/20.
//  Copyright © 2020 SizheWei. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;
// My solution:
class Solution {
private:
    vector<int> nums;
public:
    bool isHappy(int n) {
        while(n!=1){
            // find n in nums, if it exists, return false
            vector<int>::iterator it = find(nums.begin(), nums.end(), n);
            if(it != nums.end()) return false;
            // if it does not exist, push into nums
            nums.push_back(n);
            // renew n
            int isum=0;
            while(true){
                isum += (n%10)*(n%10);
                n /= 10;
                if(n==0) break;
            }

            n = isum;
            // for testing, print n
//            cout<<"new n is: "<<n<<endl;
        }
        return true;
    }
};

// Solution2: use set:
// credits: https://www.geeksforgeeks.org/happy-number/
class Solution2{
private:
    int numDigitalSquare(int n){
        int result=0;
        while(n){
            result += (n%10)*(n%10);
            n/=10;
        }
        return result;
    }
public:
    bool isHappy(int n){
        set<int> nums;
        while(1){
            if(n==1) return true;
            if(nums.find(n) != nums.end()) return false;
            nums.insert(n);
            n = numDigitalSquare(n);
        }
    }
};

//Solution 3:
//find loops in link, do not use any extra space:
class Solution3{
private:
    int numDigitalSquare(int n){
        int result=0;
        while(n){
            result += (n%10)*(n%10);
            n/=10;
        }
        return result;
    }
public:
    bool isHappy(int n){
        int slow, fast;
        slow = n;
        fast = n;
        do{
            slow = numDigitalSquare(slow);
            fast = numDigitalSquare(numDigitalSquare(fast));
        }
        while(slow != fast) ;

        return (slow==1);
    }
};

int main() {
    // insert code here...
    int n = 7;
    bool result = true;
    
    Solution problem;
    result = problem.isHappy(n);
    cout << "result = "<<result<<endl;
    
    Solution2 problem2;
    result = problem2.isHappy(n);
    cout << "result2 = "<<result<<endl;
    
    Solution3 problem3;
    result = problem3.isHappy(n);
    cout << "result3 = "<<result<<endl;
    
    return 0;
}
