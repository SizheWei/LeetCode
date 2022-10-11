//
//  main.cpp
//  IntegertoRoman_p12
//
//  Created by sizhewei on 2022/10/3.
//  Copyright © 2022 SizheWei. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string result;
        int tmp = num;
        
        vector<int> numarr;
        // 将 num 放到一个vector里面，方便后面处理
        while (tmp!=0) {
            numarr.insert(numarr.begin(), tmp%10);
            tmp /= 10;
        }
        int bits = int(numarr.size()); // 有多少位
        
        for (int i=0; i < bits; i++) {
            if (numarr[i] == 0) {           // 0
                continue;
            }
            else if (numarr[i] == 4) {      // 4
                if ((bits-i)==3){           // 百位
                    result = result + "CD";
                }
                else if ((bits-i)==2){      // 十位
                    result = result + "XL";
                }
                else {                      // 个位
                    result = result + "IV";
                }
            }
            else if (numarr[i] == 9){       // 9
                if ((bits-i)==3){           // 百位
                    result = result + "CM";
                }
                else if ((bits-i)==2){      // 十位
                    result = result + "XC";
                }
                else {                      // 个位
                    result = result + "IX";
                }
            }
            else if (numarr[i] == 5){       // 5
                if ((bits-i)==3){           // 百位
                    result = result + "D";
                }
                else if ((bits-i)==2){      // 十位
                    result = result + "L";
                }
                else {                      // 个位
                    result = result + "V";
                }
            }
            else if (numarr[i] < 5){        // 1, 2, 3
                int temp = numarr[i];
                while (temp>0) {
                    if ((bits-i)==4){           // 千位
                        result = result + "M";
                    }
                    else if ((bits-i)==3){      // 百位
                        result = result + "C";
                    }
                    else if ((bits-i)==2){      // 十位
                        result = result + "X";
                    }
                    else {                      // 个位
                        result = result + "I";
                    }
                    temp--;
                }
            }
            else{                           // 6, 7, 8
                if ((bits-i)==3){           // 百位
                    result = result + "D";
                }
                else if ((bits-i)==2){      // 十位
                    result = result + "L";
                }
                else {                      // 个位
                    result = result + "V";
                }
                int temp = numarr[i];
                while (temp>5) {
                    if ((bits-i)==3){           // 百位
                        result = result + "C";
                    }
                    else if ((bits-i)==2){      // 十位
                        result = result + "X";
                    }
                    else {                      // 个位
                        result = result + "I";
                    }
                    temp--;
                }
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution problem;
    cout << problem.intToRoman(2900) << endl;
    return 0;
}
