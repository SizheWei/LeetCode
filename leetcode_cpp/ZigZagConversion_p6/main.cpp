#include <iostream>
#include <string>
//#include <algorithm>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;
        bool goingdown = false;
        vector<string> board( min( numRows, int(s.size())) );
        int curRow = 0;
        for (char c:s) {
            board[curRow] += c;
            if (curRow==0 || curRow==numRows-1) goingdown = !goingdown;
                curRow += goingdown ? 1:-1;
        }
        
        string result;
        for(string row:board){
            result += row;
        }
        
        return result;
    }

};

int main()
{
    Solution problem;
    string s = "Hello,world!";
    int numRows = 3;
    string result = problem.convert(s, numRows);
    
    cout << "result = "<<result<<endl;
    
    return 0;
}

